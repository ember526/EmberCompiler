/* File: ast_type.h
 * ----------------
 * In our parse tree, Type nodes are used to represent and
 * store type information. The base Type class is used
 * for built-in types, the NamedType for classes and interfaces,
 * and the ArrayType for arrays of other types.  
 *
 * pp3: You will need to extend the Type classes to implement
 * the type system and rules for type equivalency and compatibility.
 */
 
#ifndef _H_ast_type
#define _H_ast_type

#include "ast.h"
#include "list.h"
#include "hashtable.h"
#include "ast_decl.h"
#include <iostream>
using namespace std;


class Type : public Node 
{
  protected:
    char *typeName;

  public :
    static Type *intType, *doubleType, *boolType, *voidType,
                *nullType, *stringType, *errorType;

    Type(yyltype loc) : Node(loc) {}
    Type(const char *str);
    Type(Type &t){typeName = t.typeName;}
    static void CheckType(Type *type, List< Hashtable<Decl*> *> *ST);
    virtual void PrintToStream(ostream& out) { out << typeName; }
    friend ostream& operator<<(ostream& out, Type *t) { t->PrintToStream(out); return out; }
    virtual bool IsEquivalentTo(Type *other) { return this == other; }
    const   char *GetName(){return typeName;}
    bool operator ==(Type &rt){ if(!strcmp(typeName, rt.GetName())) return true; return false;}
    bool operator !=(Type &rt){ return ! (*this==rt);}
    bool CompatibleWith(Type *target, List< Hashtable<Decl*> *> *ST);

};

class NamedType : public Type 
{
  protected:
    Identifier *id;
    
  public:
    NamedType(Identifier *i);
    //NamedType(NamedType &nt){typeName = nt.typeName;};
    const char * GetName() {return id->GetName();}
    Identifier * GetIdentifier()  {return id;};
    void PrintToStream(ostream& out) { out << id; }
};

class ArrayType : public Type 
{
  protected:
    Type *elemType;

  public:
    ArrayType(yyltype loc, Type *elemType);
    //ArrayType(ArrayType &at);
    Type *GetElemType(){return elemType;}
    void PrintToStream(ostream& out) { out << elemType << "[]"; }
};

 
#endif
