/* File: ast_expr.cc
 * -----------------
 * Implementation of expression node classes.
 */

#include <string.h>
#include "ast_expr.h"
#include "ast_type.h"
#include "ast_decl.h"
#include "errors.h"

IntConstant::IntConstant(yyltype loc, int val) : Expr(loc) {
    value = val;
}

DoubleConstant::DoubleConstant(yyltype loc, double val) : Expr(loc) {
    value = val;
}

BoolConstant::BoolConstant(yyltype loc, bool val) : Expr(loc) {
    value = val;
}

StringConstant::StringConstant(yyltype loc, const char *val) : Expr(loc) {
    Assert(val != NULL);
    value = strdup(val);
}

Operator::Operator(yyltype loc, const char *tok) : Node(loc) {
    Assert(tok != NULL);
    strncpy(tokenString, tok, sizeof(tokenString));
}
CompoundExpr::CompoundExpr(Expr *l, Operator *o, Expr *r) 
  : Expr(Join(l->GetLocation(), r->GetLocation())) {
    Assert(l != NULL && o != NULL && r != NULL);
    (op=o)->SetParent(this);
    (left=l)->SetParent(this); 
    (right=r)->SetParent(this);
}

CompoundExpr::CompoundExpr(Operator *o, Expr *r) 
  : Expr(Join(o->GetLocation(), r->GetLocation())) {
    Assert(o != NULL && r != NULL);
    left = NULL; 
    (op=o)->SetParent(this);
    (right=r)->SetParent(this);
}
void ArithmeticExpr::Check(List< Hashtable<Decl*> *> *ST) 
{
    if(left)
    {
        left->Check(ST);
        right->Check(ST);
        if(!left->exprType||!right->exprType) return;
        if(((*(left->exprType)==*Type::intType)&&(*(right->exprType)==*Type::intType))||
            (((*(left->exprType)==*Type::doubleType)&&(*(right->exprType)==*Type::doubleType))))
            exprType = left->exprType;
        else 
            ReportError::IncompatibleOperands(op, left->exprType, right->exprType);
    }
    else 
    {   
        right->Check(ST);
        if(!right->exprType) return;
        if((*(right->exprType)==*Type::intType)||(*(right->exprType)==*Type::doubleType))
            exprType = right->exprType;
        else ReportError::IncompatibleOperand(op, right->exprType);
    }
    //printf("ArithmeticExpr Check\n");
}
void RelationalExpr::Check(List< Hashtable<Decl*> *> *ST) 
{
    left->Check(ST);
    right->Check(ST);
    if(!left->exprType || !right->exprType) return;
    if(!((*(left->exprType)==*Type::intType)&&(*(right->exprType)==*Type::intType))&&
        !((*(left->exprType)==*Type::doubleType)&&(*(right->exprType)==*Type::doubleType))){
        ReportError::IncompatibleOperands(op, left->exprType, right->exprType);
    }
    else 
    {
        exprType = Type::boolType;
        //printf("RelationalExpr Checked\n");
    }
}
void EqualityExpr::Check(List< Hashtable<Decl*> *> *ST) 
{
    exprType = Type::boolType;
    left->Check(ST);
    right->Check(ST);
    if(!left->exprType || !right->exprType) return;
    if(dynamic_cast<NamedType *>(left->exprType)&&(*(right->exprType)==*Type::nullType))
    {
        //exprType = Type::boolType;
        return;
    }
    if( *(left->exprType) != *(right->exprType)||*(left->exprType)==*Type::voidType){
        ReportError::IncompatibleOperands(op, left->exprType, right->exprType);
    }
    else 
    {
        //exprType = Type::boolType;
       // printf("EqualityExpr Checkd\n");
    }
}
void LogicalExpr::Check(List< Hashtable<Decl*> *> *ST) 
{//对于结果已经肯定的 提前确定类型 之后再向下检查

    exprType = Type::boolType;
    if(left)
    {
        left->Check(ST);
        right->Check(ST);
        if(!left->exprType||!right->exprType) return;
        if((*(left->exprType)==*Type::boolType)&&(*(right->exprType)==*Type::boolType)){
            //printf("LogicalExpr Check\n");
            //exprType = Type::boolType;
        }
        else {
            ReportError::IncompatibleOperands(op, left->exprType, right->exprType);
            return;
        }
    }
    else
    {
        right->Check(ST);
        if(!right->exprType) return;
        if(*(right->exprType)==*Type::boolType){
            //printf("LogicalExpr Check\n");
            //exprType = Type::boolType;
        }
        else {
            ReportError::IncompatibleOperand(op, right->exprType);
            return;
        }
    } 
}
void AssignExpr::Check(List< Hashtable<Decl*> *> *ST) 
{
    left->Check(ST);
    right->Check(ST);
    if(!left->exprType || !right->exprType) return;
    if(dynamic_cast<NamedType *>(left->exprType)&&(*(right->exprType)==*Type::nullType))
    {
        exprType = dynamic_cast<NamedType *>(left->exprType);
        return;
    }
    if(*(left->exprType)!=*(right->exprType)) {
        if(!right->exprType->CompatibleWith(left->exprType, ST))
            ReportError::IncompatibleOperands(op, left->exprType, right->exprType);
    }
    else 
    {
        exprType = left->exprType;
    }
    //printf("AssignExpr Check\n");
} 

//make use of syntax structure instead of Symbol table
void This::Check(List< Hashtable<Decl*> *> *ST) {
    //printf("this check:\n");
    Node* p = this;
    while((p = p->GetParent()) != NULL) {
        if(dynamic_cast<ClassDecl *>(p) != NULL) { 
            exprType = new NamedType((dynamic_cast<ClassDecl *>(p))->GetIdentifier());
            return ;
        }
    }
    ReportError::ThisOutsideClassScope(this);
    return;
}
ArrayAccess::ArrayAccess(yyltype loc, Expr *b, Expr *s) : LValue(loc) {
    (base=b)->SetParent(this); 
    (subscript=s)->SetParent(this);
}
void ArrayAccess::Check(List< Hashtable<Decl*> *> *ST) {//arr[1]
    base->Check(ST);
    subscript->Check(ST);
    if(!base->exprType || !subscript->exprType) return;
    /*check if the [] is used after an array*/
    if(!dynamic_cast<ArrayType*>(base->exprType))
    {
        ReportError::BracketsOnNonArray(base);
        /*check if the subscript is an int expression*/
        if(*(subscript->exprType)!=*Type::intType) 
            ReportError::SubscriptNotInteger(subscript);
        return;
    }
    /*check if the subscript is an int expression*/
    if(*(subscript->exprType)!=*Type::intType) 
        ReportError::SubscriptNotInteger(subscript);
    exprType = (dynamic_cast<ArrayType*>(base->exprType))->GetElemType();
}
FieldAccess::FieldAccess(Expr *b, Identifier *f) 
  : LValue(b? Join(b->GetLocation(), f->GetLocation()) : *f->GetLocation()) {
    Assert(f != NULL); // b can be be NULL (just means no explicit base)
    base = b; 
    if (base) base->SetParent(this); 
    (field=f)->SetParent(this);
}
void FieldAccess::Check(List< Hashtable<Decl*> *> *ST) {
    Decl *fieldDecl;
    VarDecl *fieldVar;
    bool flag = false;
    if(NULL==base)
    {
        for(int i = ST->NumElements()-1; i>=0; --i) {
            if((fieldDecl=ST->Nth(i)->Lookup(field->GetName())))
            {
                if((fieldVar=dynamic_cast<VarDecl *>(fieldDecl)))
                {
                    flag = true;
                    exprType = fieldVar->GetType();
                    break;
                }
                else break;
            }
        }
        if(false == flag) 
            ReportError::IdentifierNotDeclared(field, LookingForVariable);
    } 
    else
    {   
        /*check if the name of base could be of a class*/
        NamedType *baseName;
        Decl *decl;
        ClassDecl *classDecl;
        base->Check(ST);
        if(!base->exprType) return;
        if((baseName =  dynamic_cast<NamedType *>(base->exprType))==NULL){
            ReportError::FieldNotFoundInBase(field, base->exprType);
            return;
        }
        /*Now the base is something named like a function or a class or an imterface*/
        List< Hashtable<Decl*> *> *tmpSTList = new List< Hashtable<Decl*> *>;
        tmpSTList->Append(ST->Nth(0));
        decl = ST->Nth(0)->Lookup(baseName->GetName());
        if(NULL==(classDecl = dynamic_cast<ClassDecl*>(decl))) {
            ReportError::FieldNotFoundInBase(field, base->exprType);
            return;
        }
        /*Now the base is an object of class, search the class for the field*/
        /*get prepared for the variables in base class*/
        Hashtable<Decl*> *classST = new Hashtable<Decl*>; 
        /*check if the extends field has been defined, as a class*/
        Decl * result;
        ClassDecl *baseClass;
        if(classDecl->GetExtends()) {// the base type should be of above scope  
            result = ST->Nth(0)->Lookup(classDecl->GetExtends()->GetName());
            if(result && (baseClass = dynamic_cast<ClassDecl *>(result)))// if what is found in ST is not ClassDecl, Dynamic_cast returns NULL
            {   
                classDecl->ResolveInherit(baseClass, classST);
            }
        }
        /*check the fields in class*/
        CheckList(classST, classDecl->GetMembers(), false);
        VarDecl *fieldDecl = dynamic_cast<VarDecl *> (classST->Lookup(field->GetName()));
        if(!fieldDecl) {
            ReportError::FieldNotFoundInBase(field, base->exprType);
            return;
        }
        delete classST;
        /*finally check if the access is within the class scope*/
        Node* p = this;
        while((p = p->GetParent()) != NULL) {
            if(dynamic_cast<ClassDecl *>(p) != NULL) { 
                exprType = fieldDecl->GetType();
                return ;
            }
        }
        ReportError::InaccessibleField(field, base->exprType);
        return;
    }
}


Call::Call(yyltype loc, Expr *b, Identifier *f, List<Expr*> *a) : Expr(loc)  {
    Assert(f != NULL && a != NULL); // b can be be NULL (just means no explicit base)
    base = b;
    if (base) base->SetParent(this);
    (field=f)->SetParent(this);
    (actuals=a)->SetParentAll(this);
}
void Call::Check(List< Hashtable<Decl*> *> *ST) {
    Decl *fieldDecl;
    List<VarDecl*> *formals;
    bool flag = false;
    /*first check if the access is within the class scope*/
    for(int i = 0; i < actuals->NumElements(); ++i) {
        actuals->Nth(i)->Check(ST);
    }
    if(NULL==base)
    {
        for(int i = ST->NumElements()-1; i>=0; --i) {
            if((fieldDecl=ST->Nth(i)->Lookup(field->GetName())))
            {
                if((fieldFn=dynamic_cast<FnDecl *>(fieldDecl)))
                {
                    flag = true;
                    exprType = fieldFn->GetReturnType();
                    formals = fieldFn->GetFormals();
                    if(formals->NumElements()!=actuals->NumElements())
                        ReportError::NumArgsMismatch(field, formals->NumElements(), actuals->NumElements());
                    /*check if all the actuals match the formals in their types*/
                    else for(int k = 0; k < actuals->NumElements(); ++k)
                    {
                        actuals->Nth(k)->Check(ST);
                        if(!actuals->Nth(k)->exprType) continue;
                        if(*(actuals->Nth(k)->exprType)!=*(formals->Nth(k)->GetType()))    
                        {
                            if(!actuals->Nth(k)->exprType->CompatibleWith(formals->Nth(k)->GetType(), ST))
                            ReportError::ArgMismatch(actuals->Nth(k), k+1, actuals->Nth(k)->exprType, formals->Nth(k)->GetType());
                            continue;
                        }
                    }
                    break;
                }
                else break;
            }
        }
        if(false == flag) 
            ReportError::IdentifierNotDeclared(field, LookingForVariable);
    } 
    else
    {   
        base->Check(ST);
        if(!base->exprType) return;
        /*array type and length()*/
        //printf("%s\n", base->exprType->GetName());
        if(dynamic_cast<ArrayType *>(base->exprType)&&!strcmp(field->GetName(), "length"))
        {
            if(actuals->NumElements()!=0)
                ReportError::NumArgsMismatch(field, 0, actuals->NumElements());
            exprType = Type::intType;
            return;
        }
        /*check if the name of base could be of a class*/
        NamedType *baseName;
        Decl *decl;
        ClassDecl *classDecl;
        /*base is of some base type, and field cannot be within it*/
        if((baseName =  dynamic_cast<NamedType *>(base->exprType))==NULL){
            ReportError::FieldNotFoundInBase(field, base->exprType);
            return;
        }
        /*Now the base is something named like a function or a class or an imterface*/
        /*try to find the declaration in the global scope*/
        List< Hashtable<Decl*> *> *tmpSTList = new List< Hashtable<Decl*> *>;
        tmpSTList->Append(ST->Nth(0));
        decl = ST->Nth(0)->Lookup(baseName->GetName());
        if(NULL==(classDecl = dynamic_cast<ClassDecl*>(decl))) {
            /*if the class decl cannot be found, relevent error should have been reported
                when the base(an object of such class) was declared
            */
            //ReportError::FieldNotFoundInBase(field, base->exprType);
            return;
        }
        /*Now the base is an object of class, search the class for the field*/
        /*get prepared for the variables in base class*/
        Hashtable<Decl*> *classST = new Hashtable<Decl*>; 
        /*check the fields in class*/
        CheckList(classST, classDecl->GetMembers(), false);
        fieldFn = dynamic_cast<FnDecl *> (classST->Lookup(field->GetName()));
        if(!fieldFn) {
            ReportError::FieldNotFoundInBase(field, base->exprType);
            return;
        }
        formals = fieldFn->GetFormals();
        if(formals->NumElements()!=actuals->NumElements())
            ReportError::NumArgsMismatch(field, formals->NumElements(), actuals->NumElements());
        else for(int k = 0; k < actuals->NumElements(); ++k)
        {
            actuals->Nth(k)->Check(ST);
            if(!actuals->Nth(k)->exprType) continue;
            if(*(actuals->Nth(k)->exprType)!=*(formals->Nth(k)->GetType()))    
            {
                if(!actuals->Nth(k)->exprType->CompatibleWith(formals->Nth(k)->GetType(), ST))
                ReportError::ArgMismatch(actuals->Nth(k), k+1, actuals->Nth(k)->exprType, formals->Nth(k)->GetType());
                continue;
            }
        }
        delete classST;
        /*remember to set the type of the expression*/
        exprType = fieldFn->GetReturnType();
        return;
    }
}

 

NewExpr::NewExpr(yyltype loc, NamedType *c) : Expr(loc) { 
  Assert(c != NULL);
  (cType=c)->SetParent(this);
}
void NewExpr::Check(List< Hashtable<Decl*> *> *ST){
    Hashtable<Decl*> *globalST= ST->Nth(0);
    Decl *decl = globalST->Lookup(cType->GetName());
    if(!decl || !dynamic_cast<ClassDecl *>(decl)){
        ReportError::IdentifierNotDeclared(cType->GetIdentifier(), LookingForClass);
        return;
    }
    exprType = cType;
}

NewArrayExpr::NewArrayExpr(yyltype loc, Expr *sz, Type *et) : Expr(loc) {
    Assert(sz != NULL && et != NULL);
    (size=sz)->SetParent(this); 
    (elemType=et)->SetParent(this);
}
void NewArrayExpr::Check(List< Hashtable<Decl*> *> *ST) {//NewArray(1, int)
    size->Check(ST);
    if(!size->exprType) return;
    if(*(size->exprType)!=*Type::intType)
        ReportError::NewArraySizeNotInteger(size);
    exprType = new ArrayType(*GetLocation(), elemType);
    Type::CheckType(elemType, ST);
}
       
void IntConstant::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    //printf("IntConstant::Emit\n");
    varloc = cg->GenLoadConstant(value);
}

void DoubleConstant::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    printf("DoubleConstant::Emit\n");
}

void BoolConstant::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    //printf("BoolConstant::Emit\n");
    if(value)
        varloc = cg->GenLoadConstant(1);
    else
        varloc = cg->GenLoadConstant(0);
}

void StringConstant::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    varloc = cg->GenLoadConstant(value);
}

void NullConstant::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    varloc = cg->GenLoadConstant(0);
}

void CompoundExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    printf("CompoundExpr::Emit\n");
}

void ArithmeticExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST){
    if(left) left->Emit(cg, ST);
    right->Emit(cg, ST);
    if(left) varloc = cg->GenBinaryOp(op->GetName(), left->varloc, right->varloc);
    else 
    {
        Location *tmp = cg->GenLoadConstant(0);
        varloc = cg->GenBinaryOp("-", tmp, right->varloc);
    }
}

void RelationalExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    left->Emit(cg, ST);
    right->Emit(cg, ST);
    if(0==strcmp(op->GetName(), "<"))
    {
        varloc = cg->GenBinaryOp("<", left->varloc, right->varloc);
    }
    else if(0==strcmp(op->GetName(), ">"))
    {
        varloc = cg->GenBinaryOp("<", right->varloc, left->varloc);
    }
    else if(0==strcmp(op->GetName(), "<="))
    {
        Location *tmp1 = cg->GenBinaryOp("<", left->varloc, right->varloc);
        Location *tmp2 = cg->GenBinaryOp("==", left->varloc, right->varloc);
        varloc = cg->GenBinaryOp("||", tmp1, tmp2);
    }
    else if(0==strcmp(op->GetName(), ">="))
    {
        Location *tmp1 = cg->GenBinaryOp("<", right->varloc, left->varloc);
        Location *tmp2 = cg->GenBinaryOp("==", left->varloc, right->varloc);
        varloc = cg->GenBinaryOp("||", tmp1, tmp2);
    }
}

void EqualityExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    left->Emit(cg, ST);
    right->Emit(cg, ST);
    if(*(left->exprType)!=*Type::stringType)
    {
        if(0==strcmp(op->GetName(), "=="))
        {
            varloc = cg->GenBinaryOp("==", left->varloc, right->varloc);
        }
        else if(0==strcmp(op->GetName(), "!="))
        {
            Location *tmp = cg->GenBinaryOp("==", right->varloc, left->varloc);
            Location *zero = cg->GenLoadConstant(0);
            varloc = cg->GenBinaryOp("==", zero, tmp);
        }
    }
    else
    {
        if(0==strcmp(op->GetName(), "=="))
        {
            varloc = cg->GenBuiltInCall(StringEqual, left->varloc, right->varloc);
        }
        else if(0==strcmp(op->GetName(), "!="))
        {
            Location *tmp = cg->GenBuiltInCall(StringEqual, left->varloc, right->varloc);
            Location *zero = cg->GenLoadConstant(0);
            varloc = cg->GenBinaryOp("==", zero, tmp);  
        }  
    }
}

void LogicalExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) { 
    if(left) left->Emit(cg, ST);
    right->Emit(cg, ST);
    if(left) varloc = cg->GenBinaryOp(op->GetName(), left->varloc, right->varloc);
    else 
    {
        Location *zero = cg->GenLoadConstant(0);
        varloc = cg->GenBinaryOp("==", zero, right->varloc);
    }
}

void AssignExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST)
{//NotCompleted:what about string
    right->Emit(cg, ST);
    left->Emit(cg, ST);
    if(dynamic_cast<ArrayAccess*>(left) != NULL) {
        cg->GenStore(dynamic_cast<ArrayAccess*>(left)->memoryAddr, right->varloc);
    }
    else
    {
        cg->GenAssign(left->varloc, right->varloc);       
        varloc = left->varloc;
    }
}

void This::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    printf("This::Emit\n");
}

void ArrayAccess::Emit(CodeGenerator *cg, List< Hashtable<Decl*> *> *ST) {
    char *okLabel = cg->NewLabel();
    base->Emit(cg, ST);
    subscript->Emit(cg, ST);
    Location *zero = cg->GenLoadConstant(0);
    Location *elemSize = cg-> GenLoadConstant(4);

    //run time check if size is below 0
    Location *max = cg->GenLoad(base->varloc, 0);//fetch the array size
    Location *upEx = cg->GenBinaryOp("||", cg->GenBinaryOp("==", subscript->varloc, max), cg->GenBinaryOp("<", max, subscript->varloc));
    Location *isError = cg->GenBinaryOp("||", cg->GenBinaryOp("<", subscript->varloc, zero), upEx);

    cg->GenIfZ(isError, okLabel);
    cg->GenBuiltInCall(PrintString, cg->GenLoadConstant(err_arr_out_of_bounds), NULL);
    cg->GenBuiltInCall(Halt, NULL, NULL);

    cg->GenLabel(okLabel);
    //pass the run time check
    Location *offset = cg->GenBinaryOp("+", cg->GenBinaryOp("*", subscript->varloc, elemSize), elemSize);
    memoryAddr = cg->GenBinaryOp("+", base->varloc, offset);
    varloc = cg->GenLoad(memoryAddr);
}
void FieldAccess::Emit(CodeGenerator *cg, List< Hashtable<Decl*> *> *ST) {
    //printf("FieldAccess::Emit\n");
    if(NULL==base)
    {
        VarDecl * decl; 
        for(int i = ST->NumElements()-1; i>=0; --i) 
        {
            decl = dynamic_cast<VarDecl *>(ST->Nth(i)->Lookup(field->GetName()));
            if(decl) {
                varloc = decl->GetLoc();
                break;
            }
        }
        //if(!decl) printf("unexpected error in fieldaccess Emit\n" );
    }
}

void Call::Emit(CodeGenerator *cg, List< Hashtable<Decl*> *> *ST) {
    //NotCompleted
    if(base){
        base->Emit(cg, ST);
        if(dynamic_cast<ArrayType *>(base->exprType)&&!strcmp(field->GetName(), "length"))
        {
            varloc = cg->GenLoad(base->varloc, 0);
        }   
    }
    else {
            if(ClassDecl* cd = dynamic_cast<ClassDecl* >(fieldFn->GetParent())) {

            } 
            else {
                string tmp = "__";
                tmp += fieldFn->GetName();
                for(int i = actuals->NumElements() - 1; i >= 0; i--) {
                    actuals->Nth(i)->Emit(cg, ST);
                    cg->GenPushParam(actuals->Nth(i)->varloc);
                }
                if(!fieldFn->GetReturnType())
                {
                    varloc = cg->GenLoadConstant(0);
                    cg->GenLCall(tmp.c_str(), false);    
                }
                else
                {
                   varloc =  cg->GenLCall(tmp.c_str(), true);  
                }
                cg->GenPopParams(actuals->NumElements()*4);
            }

    }

}

void NewExpr::Emit(CodeGenerator *cg, List< Hashtable<Decl*> *> *ST) {
    //NotCompleted
    printf("NewExprAccess::Emit\n");
}

void NewArrayExpr::Emit(CodeGenerator *cg, List< Hashtable<Decl*> *> *ST) {
    //printf("NewExprAccess::Emit\n");
    char *okLabel = cg->NewLabel();
    size->Emit(cg, ST);
    //run time check if size is below 0
    Location *zero = cg->GenLoadConstant(0);
    Location *isError = cg->GenBinaryOp("<", size->varloc, zero);
    cg->GenIfZ(isError, okLabel);
    cg->GenBuiltInCall(PrintString, cg->GenLoadConstant(err_arr_bad_size), NULL);
    cg->GenBuiltInCall(Halt, NULL, NULL);

    cg->GenLabel(okLabel);
    Location *elemSize = cg->GenLoadConstant(4);
    Location *arraySize = cg->GenBinaryOp("*", size->varloc, elemSize);
    /*one more for the array size*/
    Location *wholeSize = cg->GenBinaryOp("+", arraySize, elemSize);
    varloc = cg->GenBuiltInCall(Alloc, wholeSize, NULL);
    cg->GenStore(varloc, size->varloc, 0);//store the size at the start of the array

}

void ReadIntegerExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    varloc = cg->GenBuiltInCall(ReadInteger, NULL, NULL);
}

void ReadLineExpr::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {
    varloc = cg->GenBuiltInCall(ReadLine, NULL, NULL);
}