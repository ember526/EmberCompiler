/* File: ast_stmt.cc
 * -----------------
 * Implementation of statement node classes.
 */
#include "ast_stmt.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "ast_expr.h"

#include "errors.h"
#include <sstream>  
List< Hashtable<Decl*> *> *ST = new List< Hashtable<Decl*> *>;

Program::Program(List<Decl*> *d) {
    Assert(d != NULL);
    (decls=d)->SetParentAll(this);
}

void Program::Check() {
    /* pp3: here is where the semantic analyzer is kicked off.
     *      The general idea is perform a tree traversal of the
     *      entire program, examining all constructs for compliance
     *      with the semantic rules.  Each node can have its own way of
     *      checking itself, which makes for a great use of inheritance
     *      and polymorphism in the node classes.
     */
    globalST = new Hashtable<Decl*>; 
    ST->Append(globalST);
    CheckList(globalST, decls);
}

void CheckList(Hashtable<Decl*> *currentST, List<Decl*> *declList, bool reportFlag) {
    for (int i = 0; i < declList->NumElements(); ++i)
    {
        const char *name = declList->Nth(i)->GetName();
        if(currentST->Lookup(name)&&reportFlag){
            ReportError::DeclConflict(declList->Nth(i), currentST->Lookup(name));
        }
        else{
            currentST->Enter(name, declList->Nth(i), false);
        }
    }
    //check each decl
    if(reportFlag)
    for (int i = 0; i < declList->NumElements(); ++i){
        declList->Nth(i)->Check(ST);
    }
     
}
void CheckList(Hashtable<Decl*> *currentST, List<VarDecl*> *declList) {
    for (int i = 0; i < declList->NumElements(); ++i)
    {
        const char *name = declList->Nth(i)->GetName();
        if(currentST->Lookup(name)){
            ReportError::DeclConflict(declList->Nth(i), currentST->Lookup(name));
        }
        else{
            currentST->Enter(name, declList->Nth(i), false);
        }
    }
    //check each decl
    for (int i = 0; i < declList->NumElements(); ++i)
        declList->Nth(i)->Check(ST);
}
/*void ScanSTForDecl(Identifier *ident, reasonT whyNeeded, Type *declType)  {
    bool flag = false;
    Decl * result;
    for(int i = ST->NumElements()-1; i>=0; --i) 
    {   
        result = ST->Nth(i)->Lookup(ident->GetName());
        if(result && dynamic_cast<declType>(result))// if what is found in ST is not declType, Dynamic_cast returns NULL
            {   flag = true; break; }
    }
    if(false == flag) 
        ReportError::IdentifierNotDeclared(ident->GetIdentifier(), whyNeeded);
}*/
void RemoveST(List< Hashtable<Decl*> *> *ST) {
    Hashtable<Decl *> *STtoRemove = ST->Nth(ST->NumElements()-1);
    ST->RemoveAt(ST->NumElements()-1);
    //delete STtoRemove;
}
StmtBlock::StmtBlock(List<VarDecl*> *d, List<Stmt*> *s) {
    Assert(d != NULL && s != NULL);
    (decls=d)->SetParentAll(this);
    (stmts=s)->SetParentAll(this);
}
void StmtBlock::Check(List< Hashtable<Decl*> *> *ST){
    blockST = new Hashtable<Decl*>; 
    Stmt *stmt;
    ST->Append(blockST);
    CheckList(blockST, decls);
    for (int i = 0; i < stmts->NumElements(); ++i){
        if((stmt = stmts->Nth(i))){
                stmt->Check(ST);
        }
    }
    //After checking the block, delete the ST for this scope
    RemoveST(ST);
}
ConditionalStmt::ConditionalStmt(Expr *t, Stmt *b) { 
    Assert(t != NULL && b != NULL);
    (test=t)->SetParent(this); 
    (body=b)->SetParent(this);
}
void ConditionalStmt::Check(List< Hashtable<Decl*> *> *ST) {
    StmtBlock *block = dynamic_cast<StmtBlock *>(body);
    if(block)
        block->Check(ST);
}
ForStmt::ForStmt(Expr *i, Expr *t, Expr *s, Stmt *b): LoopStmt(t, b) { 
    Assert(i != NULL && t != NULL && s != NULL && b != NULL);
    (init=i)->SetParent(this);
    (step=s)->SetParent(this);
}
void ForStmt::Check(List< Hashtable<Decl*> *> *ST) {
    init->Check(ST);
    test->Check(ST);
    if(test->exprType&&*(test->exprType)!=*Type::boolType) 
        ReportError::TestNotBoolean(test);
    step->Check(ST);
    body->Check(ST);
}
IfStmt::IfStmt(Expr *t, Stmt *tb, Stmt *eb): ConditionalStmt(t, tb) { 
    Assert(t != NULL && tb != NULL); // else can be NULL
    elseBody = eb;
    if (elseBody) elseBody->SetParent(this);
}
void IfStmt::Check(List< Hashtable<Decl*> *> *ST) {
    test->Check(ST);
    if(test->exprType&&*(test->exprType)!=*Type::boolType) 
        ReportError::TestNotBoolean(test);
    body->Check(ST);
    if(elseBody) elseBody->Check(ST);
}
void BreakStmt::Check(List< Hashtable<Decl*> *> *ST) {
    //printf("this check:\n");
    Node* p = this;
    while((p = p->GetParent()) != NULL) {
        if(dynamic_cast<WhileStmt *>(p) || dynamic_cast<ForStmt *>(p)) { 
            return ;
        }
    }
    ReportError::BreakOutsideLoop(this);
    return;
}
ReturnStmt::ReturnStmt(yyltype loc, Expr *e) : Stmt(loc) { 
    Assert(e != NULL);
    (expr=e)->SetParent(this);
}
void ReturnStmt::Check(List< Hashtable<Decl*> *> *ST) {
    //printf("this check:\n");
    expr->Check(ST);
    if(NULL==expr->exprType) return;
    Node* p = this;
    FnDecl *function;
    while((p = p->GetParent()) != NULL) {
        if((function = dynamic_cast<FnDecl *>(p))) {
            if (*(function->GetReturnType())!=*(expr->exprType))
                if(!expr->exprType->CompatibleWith(function->GetReturnType(), ST))
                    ReportError::ReturnMismatch(this, expr->exprType, function->GetReturnType());
            return ;

        }
    }
    printf("Fatal Error Syntax error Has not been detected(return)!\n");;
    return;
} 
PrintStmt::PrintStmt(List<Expr*> *a) {    
    Assert(a != NULL);
    (args=a)->SetParentAll(this);
}
void PrintStmt::Check(List< Hashtable<Decl*> *> *ST) {
    Type *t;
    for(int i = 0; i < args->NumElements(); ++i)
    {
        args->Nth(i)->Check(ST);
        t = args->Nth(i)->exprType;
        if(t==NULL) continue;
        if(*t==*Type::intType||*t==*Type::boolType||*t==*Type::stringType){
            continue;
        }
        else
            ReportError::PrintArgMismatch(args->Nth(i), i+1, t);
    }
} 

void Program::Emit() {
    CodeGenerator* cg = new CodeGenerator();
    Hashtable<Location *>* next = new Hashtable<Location *>(); 
    //cg->varLocs->Append(next);
    for(int i = 0; i < decls->NumElements(); ++i)    
    {
        decls->Nth(i)->Emit(cg, ST);
    }
    if(!globalST->Lookup("main"))
        ReportError::NoMainFound();
    else
        cg->DoFinalCodeGen();
}
void StmtBlock::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    ST->Append(blockST);
    for(int i = 0; i < decls->NumElements(); ++i)    
    {
        decls->Nth(i)->Emit(cg, ST);
    }
    for(int i = 0; i < stmts->NumElements(); ++i)    
    {
        stmts->Nth(i)->Emit(cg, ST);
    }
    RemoveST(ST);
}

void ForStmt::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    init->Emit(cg, ST);
    char *inlabel = cg->NewLabel();
    outlabel = cg->NewLabel();
    cg->GenLabel(inlabel);
    test->Emit(cg, ST);
    cg->GenIfZ(test->varloc, outlabel);
    body->Emit(cg, ST);
    step->Emit(cg, ST);
    cg->GenGoto(inlabel);
    cg->GenLabel(outlabel);
}

void WhileStmt::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    char *inlabel = cg->NewLabel();
    outlabel = cg->NewLabel();
    cg->GenLabel(inlabel);
    test->Emit(cg, ST);
    cg->GenIfZ(test->varloc, outlabel);
    body->Emit(cg, ST);
    cg->GenGoto(inlabel);
    cg->GenLabel(outlabel);

}

void IfStmt::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    char *outlabel = cg->NewLabel();
    test->Emit(cg, ST);
    if(elseBody)
    {
        char *elselabel = cg->NewLabel();
        cg->GenIfZ(test->varloc, elselabel);
        body->Emit(cg, ST);
        cg->GenGoto(outlabel);
        cg->GenLabel(elselabel);
        elseBody->Emit(cg, ST);
        cg->GenLabel(outlabel);
    }
    else 
    {
        cg->GenIfZ(test->varloc, outlabel);
        body->Emit(cg, ST);
        cg->GenLabel(outlabel);
    }
}

void BreakStmt::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    Node* p = this;
    while((p = p->GetParent()) != NULL)
        if(dynamic_cast<WhileStmt *>(p) != NULL || dynamic_cast<ForStmt *>(p) != NULL)
        {
             cg->GenGoto(dynamic_cast<LoopStmt *>(p)->outlabel);
             break;
        }
}

void ReturnStmt::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    if(dynamic_cast<EmptyExpr *>(expr)) {
        cg->GenReturn();
    } 
    else {
        expr->Emit(cg, ST);
        cg->GenReturn(expr->varloc);
    }
}

void PrintStmt::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST)
{//print_ST(ST);
    for(int i = 0; i < args->NumElements(); ++i)
    {
        args->Nth(i)->Emit(cg, ST);
        if(*(args->Nth(i)->exprType)==*Type::intType)
        {
            cg->GenBuiltInCall(PrintInt, args->Nth(i)->varloc, NULL);
        }

        if(*(args->Nth(i)->exprType)==*Type::stringType)
        {
            cg->GenBuiltInCall(PrintString, args->Nth(i)->varloc, NULL);
        }
        if(*(args->Nth(i)->exprType)==*Type::boolType)
        {
            cg->GenBuiltInCall(PrintInt, args->Nth(i)->varloc, NULL);
        }
    }
    
}
void print_ST(List< Hashtable<Decl*> *> *ST)
{
    Decl *decl;
    printf("*********************************\n");
    for(int i = ST->NumElements()-1; i>=0; --i) 
    {
      printf("-------------------------------\n");
      Iterator<Decl*> iter = ST->Nth(i)->GetIterator();
      printf("The %dth Symbol Table\n", i+1);
      while ((decl = iter.GetNextValue()) != NULL) {
           printf("**%s\n", decl->GetName());
      }
      printf("-------------------------------\n");
    }
}