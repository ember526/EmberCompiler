/* File: ast_decl.h
 * ----------------
 * In our parse tree, Decl nodes are used to represent and
 * manage declarations. There are 4 subclasses of the base class,
 * specialized for declarations of variables, functions, classes,
 * and interfaces.
 *
 * pp3: You will need to extend the Decl classes to implement 
 * semantic processing including detection of declaration conflicts 
 * and managing scoping issues.
 */

#ifndef _H_ast_decl
#define _H_ast_decl

#include "ast.h"
#include "list.h"
#include "hashtable.h"
#include  "codegen.h"
class Type;
class NamedType;
class Identifier;
class Stmt;
class VarDecl;
class StmtBlock;
class InterfaceDecl;
class Decl : public Node 
{
  protected:
    Identifier *id;
  public:
    Location *varloc=NULL;
    Decl(Identifier *name);
    Identifier * GetIdentifier(){ return id;};
    const char *GetName() { return id->GetName(); }
    virtual void Check(List< Hashtable<Decl*> *> *ST);
    friend ostream& operator<<(ostream& out, Decl *d) { return out << d->id; }
    virtual void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST) {printf("Decl Emit\n");}
    Location *GetLoc() {return varloc;}
};

class VarDecl : public Decl 
{
  protected:
    Type *type;
    
  public:
    VarDecl(Identifier *name, Type *type);
    void Check(List< Hashtable<Decl*> *> *ST);
    Type *GetType() { return type; }
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

class ClassDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    NamedType *extends;
    List<NamedType*> *implements;
    Hashtable<Decl*> *classST;
  public:
    ClassDecl(Identifier *name, NamedType *extends, 
              List<NamedType*> *implements, List<Decl*> *members);
    void Check(List< Hashtable<Decl*> *> *ST);
    void ResolveImplements(InterfaceDecl *interface, NamedType *impItem);
    void ResolveInherit(ClassDecl *baseClass, Hashtable<Decl *>*classST);
    List<Decl*> *GetMembers(){return members;}
    NamedType *GetExtends(){return extends;}
    List<NamedType*> *GetImplements(){return implements;}
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

class InterfaceDecl : public Decl 
{
  protected:
    List<Decl*> *members;
    
  public:
    InterfaceDecl(Identifier *name, List<Decl*> *members);
    void Check(List< Hashtable<Decl*> *> *ST); 
    List<Decl*> *GetMembers(){return members;}
};

class FnDecl : public Decl 
{
  protected:
    Hashtable<Decl*> *fnST;
    List<VarDecl*> *formals;
    Type *returnType;
    Stmt *body;
    
  public:
    FnDecl(Identifier *name, Type *returnType, List<VarDecl*> *formals);
    void SetFunctionBody(Stmt *b);
    void Check(List< Hashtable<Decl*> *> *ST); 
    List<VarDecl*> *GetFormals(){return formals;}
    Type *GetReturnType()  {return returnType;}
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

#endif
