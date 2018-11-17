/* File: ast_type.cc
 * -----------------
 * Implementation of type node classes.
 */

#include <string.h>
#include "ast_type.h"
#include "errors.h"

 
/* Class constants
 * ---------------
 * These are public constants for the built-in base types (int, double, etc.)
 * They can be accessed with the syntax Type::intType. This allows you to
 * directly access them and share the built-in types where needed rather that
 * creates lots of copies.
 */

Type *Type::intType    = new Type("int");
Type *Type::doubleType = new Type("double");
Type *Type::voidType   = new Type("void");
Type *Type::boolType   = new Type("bool");
Type *Type::nullType   = new Type("null");
Type *Type::stringType = new Type("string");
Type *Type::errorType  = new Type("error"); 

Type::Type(const char *n) {
    Assert(n);
    typeName = strdup(n);
}

void Type::CheckType(Type *type, List< Hashtable<Decl*> *> *ST) {
	bool flag = false;
    Decl *result;
    /*try if the type is of named type or array type, which are of different class,
      this was devided when the type was constructed in previous stages
    */
    NamedType *nT = dynamic_cast<NamedType *>(type);
    ArrayType *aT = dynamic_cast<ArrayType *>(type);
    if (nT)
    {
        for(int i = ST->NumElements()-1; i>=0; --i) 
        {   
            result = ST->Nth(i)->Lookup(nT->GetName());
            if(result && (dynamic_cast<ClassDecl *>(result)||dynamic_cast<InterfaceDecl *>(result)))// if what is found in ST is not ClassDecl, Dynamic_cast returns NULL
                {   flag = true; break; }
        }
        if(false == flag) 
            ReportError::IdentifierNotDeclared(nT->GetIdentifier(), LookingForType);
    }
    else if(aT)
    {
    	CheckType(aT->GetElemType(), ST);
    }
    else{ //the only possibility left is base type, which can be guaranteed since it was produced by early stages
        ;
    }
}
bool Type::CompatibleWith(Type *target, List< Hashtable<Decl*> *> *ST) {
	/*if the target is namedType and origin is null*/
	if(dynamic_cast<NamedType *>(target)&&(*(this)==*Type::nullType))
    {
        return true;
    }
    else
    {
    	NamedType 	*tar = dynamic_cast<NamedType *>(target),
    				*ori = dynamic_cast<NamedType *>(this);
    	if(tar && ori)
    	{
    		const char *oriName = this->GetName();
    		ClassDecl *classDecl;
    		if((classDecl = dynamic_cast<ClassDecl *>( ST->Nth(0)->Lookup(oriName))))
    		{
    			List<NamedType*> *impList = classDecl->GetImplements();
    			NamedType *imp;
    			for(int i = 0; i < impList->NumElements(); ++i)
    			{
    				imp = impList->Nth(i);
    				if(*imp==*tar)
    					return true;
    			}
    			if(classDecl->GetExtends())
    			{
    				if(*(classDecl->GetExtends())==*tar)
    					return true;
    				return CompatibleWith(classDecl->GetExtends(), ST);
    			}
    		}

    	}
    }
    return false;
}
	
NamedType::NamedType(Identifier *i) : Type(*i->GetLocation()) {
    Assert(i != NULL);
    (id=i)->SetParent(this);
    typeName = const_cast<char *>(i->GetName());
} 


ArrayType::ArrayType(yyltype loc, Type *et) : Type(loc) {
    Assert(et != NULL);
    (elemType=et)->SetParent(this);
    char *name = (char *)malloc(sizeof(et->GetName())+2);
    strcpy(name, et->GetName());
    strcat(name,"[]");
    typeName = name;
}


