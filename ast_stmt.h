/* File: ast_stmt.h
 * ----------------
 * The Stmt class and its subclasses are used to represent
 * statements in the parse tree.  For each statment in the
 * language (for, if, return, etc.) there is a corresponding
 * node class for that construct. 
 *
 * pp3: You will need to extend the Stmt classes to implement
 * semantic analysis for rules pertaining to statements.
 */


#ifndef _H_ast_stmt
#define _H_ast_stmt

#include "list.h"
#include "ast.h"
#include "hashtable.h"
#include "ast_decl.h"
#include  "codegen.h"
class Decl;
class VarDecl;
class Expr;
class Program : public Node
{
  protected:
     List<Decl*> *decls;
     Hashtable<Decl*> *globalST;
  public:
     Program(List<Decl*> *declList);
     void Check();
     void Emit();
};

class Stmt : public Node
{

  public:
     Stmt() : Node() {}
     Stmt(yyltype loc) : Node(loc) {}
     virtual void Check(List< Hashtable<Decl*> *> *ST){printf("stmt check\n");};
     virtual void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST){printf("Stmt::Emit\n");}
};

class StmtBlock : public Stmt 
{
  protected:
    Hashtable<Decl*> *blockST;
    List<VarDecl*> *decls;
    List<Stmt*> *stmts;
    
  public:
    StmtBlock(List<VarDecl*> *variableDeclarations, List<Stmt*> *statements);
    void Check(List< Hashtable<Decl*> *> *ST);
    friend void FnDecl::Check(List< Hashtable<Decl*> *> *ST);
    friend void FnDecl::Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

  
class ConditionalStmt : public Stmt
{
  protected:
    Expr *test;
    Stmt *body;
  
  public:
    ConditionalStmt(Expr *testExpr, Stmt *body);
    void Check(List< Hashtable<Decl*> *> *ST);
};

class LoopStmt : public ConditionalStmt 
{
  public:
  char *outlabel=NULL;
    LoopStmt(Expr *testExpr, Stmt *body)
            : ConditionalStmt(testExpr, body) {}
};

class ForStmt : public LoopStmt 
{
  protected:
    Expr *init, *step;
  public:
    ForStmt(Expr *init, Expr *test, Expr *step, Stmt *body);
    void Check(List< Hashtable<Decl*> *> *ST);
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

class WhileStmt : public LoopStmt
{
  public:
    WhileStmt(Expr *test, Stmt *body) : LoopStmt(test, body) {}
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

class IfStmt : public ConditionalStmt 
{
  protected:
    Stmt *elseBody;
  public:
    IfStmt(Expr *test, Stmt *thenBody, Stmt *elseBody);
    void Check(List< Hashtable<Decl*> *> *ST);
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

class BreakStmt : public Stmt 
{
  public:
    BreakStmt(yyltype loc) : Stmt(loc) {}
    void Check(List< Hashtable<Decl*> *> *ST);
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

class ReturnStmt : public Stmt  
{
  protected:
    Expr *expr;
  
  public:
    ReturnStmt(yyltype loc, Expr *expr);
    void Check(List< Hashtable<Decl*> *> *ST) ;
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};

class PrintStmt : public Stmt
{
  protected:
    List<Expr*> *args;
    
  public:
    PrintStmt(List<Expr*> *arguments);
    void Check(List< Hashtable<Decl*> *> *ST) ;
    void Emit(CodeGenerator* cg, List< Hashtable<Decl*> *> *ST);
};
void CheckList(Hashtable<Decl*> *currentST, List<Decl*> *declList, bool reportFlag=true);
void CheckList(Hashtable<Decl*> *currentST, List<VarDecl*> *declList);
void RemoveST(List< Hashtable<Decl*> *> *ST);
void print_ST(List< Hashtable<Decl*> *> *ST);
#endif
