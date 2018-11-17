/* File: ast_decl.cc
 * -----------------
 * Implementation of Decl node classes.
 */
#include "ast_decl.h"
#include "ast_type.h"
#include "ast_stmt.h"
#include "errors.h"
        
         
Decl::Decl(Identifier *n) : Node(*n->GetLocation()) {
    Assert(n != NULL);
    (id=n)->SetParent(this); 
}
void Decl::Check(List< Hashtable<Decl*> *> *ST) {
    return;
}

VarDecl::VarDecl(Identifier *n, Type *t) : Decl(n) {
    Assert(n != NULL && t != NULL);
    (type=t)->SetParent(this);
}
void VarDecl::Check(List< Hashtable<Decl*> *> *ST) {/*check the type of the varDecl*/
    Type::CheckType(type, ST);
}

ClassDecl::ClassDecl(Identifier *n, NamedType *ex, List<NamedType*> *imp, List<Decl*> *m) : Decl(n) {
    // extends can be NULL, impl & mem may be empty lists but cannot be NULL
    Assert(n != NULL && imp != NULL && m != NULL);     
    extends = ex;
    if (extends) extends->SetParent(this);
    (implements=imp)->SetParentAll(this);
    (members=m)->SetParentAll(this);
}
void ClassDecl::Check(List< Hashtable<Decl*> *> *ST) {
    if(ST->NumElements()!=1)
        printf("Class not In global scope\n");
    /*get prepared for the variables in base class*/
    classST = new Hashtable<Decl*>; 
    /*check if the extends field has been defined, as a class*/
    Decl * result;
    ClassDecl *baseClass;
    bool flag = false;
    if(extends) {// the base type should be of above scope  
        for(int i = ST->NumElements()-1; i>=0; --i) 
        {   
            result = ST->Nth(i)->Lookup(extends->GetName());
            if(result && (baseClass = dynamic_cast<ClassDecl *>(result)))// if what is found in ST is not ClassDecl, Dynamic_cast returns NULL
            {   
                ResolveInherit(baseClass, classST);
                flag = true;
                break;
            }
        } 
        if(false == flag) 
            ReportError::IdentifierNotDeclared(extends->GetIdentifier(), LookingForClass);
    }
    /*check the fields in class*/
    /*should not add current ST until now*/
    ST->Append(classST);
    CheckList(classST, members);
    /*check if any item in the implements has not been defined*/
    NamedType * impItem;
    InterfaceDecl *interface;
    result = NULL;
    flag = false;

    for(int j = 0; j< implements->NumElements(); ++j)
    {
        impItem = implements->Nth(j);
        for(int i = ST->NumElements()-1; i>=0; --i) 
        {   
            result = ST->Nth(i)->Lookup(impItem->GetName());
            if(result && (interface=dynamic_cast<InterfaceDecl *>(result)))// if what is found in ST is not ClassDecl, Dynamic_cast returns NULL
            {   
                ResolveImplements(interface, impItem);
                flag = true;
                break;
            }
        }
        if(false == flag) 
            ReportError::IdentifierNotDeclared(impItem->GetIdentifier(), LookingForInterface);
        flag = false;
    }
    //After checking the block, delete the ST for this scope
    RemoveST(ST);
}
void ClassDecl::ResolveInherit(ClassDecl *baseClass, Hashtable<Decl *>*classST) {
    FnDecl * baseFn, *deriveFn;
    VarDecl * baseVar;
    List<VarDecl*> * bFormals, *dFormals;
    List<Decl*> *bMembers = baseClass->GetMembers(),
                *dMembers = GetMembers();
    bool flag = false;
    /*find about every member in base class*/
    for (int i = 0; i < bMembers->NumElements(); ++i)
    {   /*fun decl*/
        if((baseFn = dynamic_cast<FnDecl *>(bMembers->Nth(i)))) {
            flag = false;
            for(int j = 0; j < dMembers->NumElements(); ++j)
            {   /*the func name matches*/
                if(!strcmp(dMembers->Nth(j)->GetName(), baseFn->GetName())){
                    if((deriveFn = dynamic_cast<FnDecl *>(dMembers->Nth(j)))){
                        flag = true;
                        bFormals = baseFn->GetFormals();
                        dFormals = deriveFn->GetFormals();
                        if(*(deriveFn->GetReturnType())!=*(baseFn->GetReturnType()))
                            ReportError::OverrideMismatch(deriveFn);
                        else if(dFormals->NumElements()!=bFormals->NumElements())
                            ReportError::OverrideMismatch(deriveFn);
                        else for(int k = 0; k < dFormals->NumElements(); ++k)
                        {
                            if(*(dFormals->Nth(k)->GetType())!=*(bFormals->Nth(k)->GetType()))    
                            {
                                ReportError::OverrideMismatch(deriveFn);
                                break;
                            }
                        }
                    }
                    else ReportError::OverrideMismatch(deriveFn);
                }
            }
            if(false == flag) {
                classST->Enter(baseFn->GetName(), baseFn, false);
            }
        }
        /*Var decl*/
        else if((baseVar = dynamic_cast<VarDecl *>(bMembers->Nth(i)))){
            const char *name = baseVar->GetName();
            if(classST->Lookup(name)){
                ReportError::DeclConflict(baseVar, classST->Lookup(name));
            }
            else{
                classST->Enter(name, baseVar, false);
            }
        }
    }
}
void ClassDecl::ResolveImplements(InterfaceDecl *interface, NamedType *impItem) {
    List<Decl*> *interfaceMembers = interface->GetMembers();
    FnDecl * proto, *definition;
    List<VarDecl*> * pFormals, *dFormals;
    bool flag = false;
    for (int i = 0; i < interfaceMembers->NumElements(); ++i)
    {
        flag = false;
        proto = dynamic_cast<FnDecl *>(interfaceMembers->Nth(i));
        for(int j = 0; j < members->NumElements(); ++j)
        {
            if((definition = dynamic_cast<FnDecl *>(members->Nth(j)))){
                if(!strcmp(definition->GetName(), proto->GetName()))//matches
                {
                    flag = true;
                    pFormals = proto->GetFormals();
                    dFormals = definition->GetFormals();
                    if(*(definition->GetReturnType())!=*(proto->GetReturnType()))
                        ReportError::OverrideMismatch(definition);
                    else if(dFormals->NumElements()!=dFormals->NumElements())
                        ReportError::OverrideMismatch(definition);
                    else for(int k = 0; k < dFormals->NumElements(); ++k)
                    {
                        if(*(dFormals->Nth(k)->GetType())!=*(pFormals->Nth(k)->GetType()))    
                        {
                            ReportError::OverrideMismatch(definition);
                            break;
                        }
                    }
                }
            }
        }
        if(false == flag)
        {
            NamedType * intT = new NamedType(interface->GetIdentifier());
            ReportError::InterfaceNotImplemented(this, impItem);
            break;
        }
    }
}
InterfaceDecl::InterfaceDecl(Identifier *n, List<Decl*> *m) : Decl(n) {
    Assert(n != NULL && m != NULL);
    (members=m)->SetParentAll(this);
}
void InterfaceDecl::Check(List< Hashtable<Decl*> *> *ST) {// without checking if they are all FnDecl
    Hashtable<Decl*> *interfaceST = new Hashtable<Decl*>; 
    ST->Append(interfaceST);
    CheckList(interfaceST, members);
    //After checking the block, delete the ST for this scope
    RemoveST(ST);
}
	
FnDecl::FnDecl(Identifier *n, Type *r, List<VarDecl*> *d) : Decl(n) {
    Assert(n != NULL && r!= NULL && d != NULL);
    (returnType=r)->SetParent(this);
    (formals=d)->SetParentAll(this);
    body = NULL;
}

void FnDecl::SetFunctionBody(Stmt *b) { 
    (body=b)->SetParent(this);
}

void FnDecl::Check(List< Hashtable<Decl*> *> *ST){
    fnST = new Hashtable<Decl*>; 
    ST->Append(fnST);
    CheckList(fnST, formals);
    StmtBlock* bodyBlock = dynamic_cast<StmtBlock *>(body);
    if(bodyBlock) {
        CheckList(fnST, bodyBlock->decls);
    } 
    Stmt *stmt;
    for (int i = 0;body &&( i <  bodyBlock->stmts->NumElements()); ++i){
        if((stmt =  bodyBlock->stmts->Nth(i))){
                stmt->Check(ST);
        }

    }
    //if(body) dynamic_cast<StmtBlock *>(body)->Check(ST);
    //After checking the function block, delete the ST for this function scope
    RemoveST(ST);
}

void VarDecl::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST)
{
    //printf("VarDecl::Emit\n");
    if(NULL!=GetParent()->GetParent())
        varloc = cg->GetNewLocationOnStack(id->GetName());
    else
    {
        varloc = cg->GenGlobalVar(id->GetName());
    }
}

void ClassDecl::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST)
{
    ST->Append(classST);
    
    RemoveST(ST);
}

void FnDecl::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST){
    //printf("FnDecl::Emit\n");
    ST->Append(fnST);
    Assert(body != NULL);
    if(strcmp(id->GetName(), "main") == 0)
        cg->GenLabel("main");
    else
    {
        string tmp = "__";
        tmp += id->GetName();
        cg->GenLabel(tmp.c_str());
    }
    cg->currentStackSize = 0;
    BeginFunc* bf = cg->GenBeginFunc();
    for (int i = formals->NumElements() - 1; i >=0 ; --i){
            formals->Nth(i)->varloc = new Location(fpRelative, 4 + ( i) * 4, formals->Nth(i)->GetName());
        }
    /*go through the decls and  stmts*/
    StmtBlock* bodyBlock = dynamic_cast<StmtBlock *>(body);
    Decl *decl;
    if(bodyBlock) {
        for (int i = 0; i <  bodyBlock->decls->NumElements(); ++i){
            bodyBlock->decls->Nth(i)->Emit(cg, ST);
        }
        for (int i = 0; i <  bodyBlock->stmts->NumElements(); ++i){
            bodyBlock->stmts->Nth(i)->Emit(cg, ST);

        }
    } 
    bf->SetFrameSize(cg->currentStackSize * 4);
    cg->GenEndFunc();
    RemoveST(ST);
}
