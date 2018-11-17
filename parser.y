/* File: parser.y
 * --------------
 * Bison input file to generate the parser for the compiler.
 *
 * pp2: your job is to write a parser that will construct the parse tree
 *      and if no parse errors were found, print it.  The parser should 
 *      accept the language as described in specification, and as augmented 
 *      in the pp2 handout.
 */

%{

/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(const char *msg); // standard error-handling routine

%}

/* The section before the first %% is the Definitions section of the yacc
 * input file. Here is where you declare tokens and types, add precedence
 * and associativity options, and so on.
 */
 
/* yylval 
 * ------
 * Here we define the type of the yylval global variable that is used by
 * the scanner to store attibute information about the token just scanned
 * and thus communicate that information to the parser. 
 *
 * pp2: You will need to add new fields to this union as you add different 
 *      attributes to your non-terminal symbols.
 */
%union {
    int integerConstant;
    int nullConstant;
    bool boolConstant;
    char *stringConstant;
    double doubleConstant;
    char identifier[MaxIdentLen+1]; // +1 for terminating null
    Program *program;
    Decl *decl;
    VarDecl *varDecl;
    List<Decl*> *declList;
    List<VarDecl*> *varDeclList;
    Stmt *stmt;
    List<Stmt*> *stmtList;
    Expr *expr;
    List<Expr*> *exprList;
    Operator *op;
    Type *typ;
    NamedType *namedType;
    List<NamedType*> *namedTypeList;
    //CaseStmt *caseStmt;
    //List<CaseStmt*> *caseList;
    //DefaultStmt *defaultStmt;
    IntConstant *intConstant;
}


/* Tokens
 * ------
 * Here we tell yacc about all the token types that we are using.
 * Bison will assign unique numbers to these and export the #define
 * in the generated y.tab.h header file.
 */
%token   T_Void T_Bool T_Int T_Double T_String T_Class 
%token    T_Dims 
%token   T_And T_Or T_Extends T_This T_Interface T_Implements
%token   T_While T_For T_If T_Else T_Return T_Break
%token   T_New T_NewArray T_Print T_ReadInteger T_ReadLine
%token T_Default T_Switch T_Case
%token   <identifier> T_Identifier
%token   <stringConstant> T_StringConstant 
%token   <integerConstant> T_IntConstant
%token   <doubleConstant> T_DoubleConstant
%token   <boolConstant> T_BoolConstant
%token   <nullConstant> T_Null
%nonassoc LOWER_THAN_ELSE
%nonassoc T_Else
%right '=' //没注意，优先级设定对于规约/移进到底意味着什么
%left T_Or
%left T_And
%left T_Equal T_NotEqual
%left T_GreaterEqual  '>'  '<'  T_LessEqual
%left '+'  '-'
%left '/' '%' '*' 
%right '!' 
%left '.' '[' T_Increment T_Decrement
%right  ']'//双引号和单引号在这里不同

/* Non-terminal types
 * ------------------
 * In order for yacc to assign/access the correct field of $$, $1, we
 * must to declare which field is appropriate for the non-terminal.
 * As an example, this first type declaration establishes that the DeclList
 * non-terminal uses the field named "declList" in the yylval union. This
 * means that when we are setting $$ for a reduction for DeclList ore reading
 * $n which corresponds to a DeclList nonterminal we are accessing the field
 * of the union named "declList" which is of type List<Decl*>.
 * pp2: You'll need to add many of these of your own.
 */
%type <declList>    DeclList PrototypeList FieldList
%type <decl>        Decl  FunctionDecl ClassDecl InterfaceDecl Prototype Field
%type <varDecl>     VariableDecl Variable
%type <varDeclList> Formals FormalsTail VarDeclList
%type <stmt>        StmtBlock Stmt PrintStmt ';' ForStmt WhileStmt IfStmt BreakStmt ReturnStmt// SwitchStmt
%type <stmtList>    StmtList
%type <program>     Program
%type <expr>        Expr Constant LValue Call T_This
%type <exprList>    ExprList Actuals
%type <op>          '+' '*' '/' '-'  '%' '<' '>' '!' T_And T_Or T_LessEqual T_GreaterEqual T_Equal T_NotEqual T_Increment T_Decrement
%type <typ>         Type T_Void T_Bool T_Int T_Double T_String 
%type <namedTypeList>   Implement T_Implements IdentList 
%type <namedType>   Extend
//%type <caseList>    Cases
//%type <defaultStmt> DefaultStmt
//%type <caseStmt> CaseStmt
//%type <intConstant> Lable
%%
/* Rules
 * -----
 * All productions and actions should be placed between the start and stop
 * %% markers which delimit the Rules section.
	 
 */
Program   :    DeclList            {
                                      @1; 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/

                                      Program *program = new Program($1);
                                      $$ = program;
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                        program->Check();
                                      if (ReportError::NumErrors() == 0) 
                                        program->Emit();
                                    }
          ;

DeclList        :    DeclList Decl    { ($$=$1)->Append($2); }
                |    Decl             {
                                        ($$ = new List<Decl*>)->Append($1);
                                      } 
                ;
        
Decl            :     VariableDecl      {$$=$<decl>1;}
                |     FunctionDecl         { $$=$1;}
                |     ClassDecl            { $$=$1;}
                |     InterfaceDecl        { $$=$1;} 
                ;
VariableDecl    :   Variable ';'  {$$=$1;}
                ;
Variable        :   Type T_Identifier   {Identifier *ident = new Identifier(@2, $2); $$=new VarDecl(ident, $1);}
                ;
Type            : T_Int           {$$=Type::intType;}
                | T_Double        {$$=Type::doubleType;}
                | T_Bool          {$$=Type::boolType;}
                | T_String        {$$=Type::stringType;}
                | T_Identifier    {Identifier *ident = new Identifier(@1, $1); $$=new NamedType(ident);}
                | Type T_Dims     {$$=new ArrayType(Join(@1, @2), $1);}
                ;
FunctionDecl    :   Type T_Identifier '(' Formals ')' StmtBlock   {   
                                                                      Identifier *identifier = new Identifier(@2, $2);
                                                                      FnDecl *fun= new FnDecl(identifier, $1, $4);
                                                                      fun->SetFunctionBody($6);  
                                                                      $$=fun; 
                                                                  }
                |   T_Void T_Identifier '(' Formals ')' StmtBlock {
                                                                      Identifier *identifier = new Identifier(@2, $2);
                                                                      FnDecl *fun= new FnDecl(identifier, Type::voidType, $4);
                                                                      fun->SetFunctionBody($6);  
                                                                      $$=fun; 
                                                                  }
                ;
Formals         : Variable FormalsTail        {($$=$2)->InsertAt($1, 0);}
                |                             {$$ = new List<VarDecl*>;}
                ;
FormalsTail     : ',' Variable FormalsTail {($$=$3)->InsertAt($2, 0);} 
                | {$$ = new List<VarDecl*>;}
                ;
ClassDecl       : T_Class T_Identifier Extend Implement '{' FieldList '}' { 
                                                                          Identifier *ident = new Identifier(@2, $2);
                                                                          $$=new ClassDecl(ident, $3, $4, $6);
                                                                          }
                ;
Extend          : T_Extends T_Identifier  {   Identifier *ident = new Identifier(@2, $2); $$=new NamedType(ident);}
                |                         {   $$=NULL;}
                ;
Implement       : T_Implements IdentList  {   $$=$2;}
                |                         {   $$=new List<NamedType *>;}
                ;
IdentList       : T_Identifier                {   
                                                  Identifier *ident = new Identifier(@1, $1);
                                                  NamedType *name = new NamedType(ident);
                                                  ($$=new List<NamedType*>)->Append(name);
                                              }
                | IdentList ',' T_Identifier  {   
                                                  Identifier *ident = new Identifier(@3, $3); 
                                                  NamedType *name = new NamedType(ident);
                                                  ($$=$1)->Append(name);
                                              }
                ;
Field           : VariableDecl    { $$=$<decl>1;}
                | FunctionDecl     {$$=$1;}
                ;
FieldList       : FieldList Field {($$=$1)->Append($2);}
                | {$$=new List<Decl*>;}
                ;
InterfaceDecl   : T_Interface T_Identifier '{' PrototypeList '}' {Identifier *ident = new Identifier(@2, $2); $$=new InterfaceDecl(ident, $4);}
                | T_Interface T_Identifier '{'  '}' {
                                                      Identifier *ident = new Identifier(@2, $2);
                                                      List<Decl*> *emptyList = new List<Decl*>;
                                                      $$=new InterfaceDecl(ident, emptyList);}
                ;
PrototypeList   :    PrototypeList Prototype        { ($$=$1)->Append($2);}
                |    Prototype                      { ($$=new List<Decl*>)->Append($1);}
                ;
Prototype       : Type T_Identifier '(' Formals ')' ';'       {   
                                                                  Identifier *identifier = new Identifier(@5, $2);
                                                                  $$ = new FnDecl(identifier, $1, $4);   
                                                              }
                | T_Void T_Identifier '(' Formals ')' ';'     {   
                                                                  Identifier *identifier = new Identifier(@5, $2);
                                                                  $$ = new FnDecl(identifier, Type::voidType, $4);   
                                                              }
                ;
StmtBlock       :'{' VarDeclList StmtList '}'  {$$=new StmtBlock($2, $3);}
                |'{' VarDeclList '}'  {
                                      List<Stmt*> *stmtlist = new List<Stmt*>();
                                      $$=new StmtBlock($2, stmtlist);
                                      }
                |'{' StmtList '}'     {
                                      List<VarDecl*> *vardecllist = new List<VarDecl*>();
                                      $$=new StmtBlock(vardecllist, $2);
                                      }
                | '{' '}'             {
                                      List<VarDecl*> *vardecllist = new List<VarDecl*>();
                                      List<Stmt*> *stmtlist = new List<Stmt*>();
                                      $$=new StmtBlock(vardecllist, stmtlist);
                                      }
                ;
VarDeclList     : VarDeclList VariableDecl {($$=$1)->Append($2);}
                | VariableDecl {($$=new List<VarDecl*>)->Append($1);}
                ;
StmtList        : StmtList Stmt   {($$=$1)->Append($2);}
                | Stmt            {($$=new List<Stmt*>)->Append($1); }
                ;
Stmt            : Expr ';'     {  $$=$<stmt>1;}//!!!!!!!!!!!!!!!!!!!!!!
                | ';'          {  $$=$1;}
                | IfStmt | WhileStmt   | ForStmt| BreakStmt| ReturnStmt| PrintStmt | StmtBlock /*| SwitchStmt*/  {$$ = $1;}
                ;
IfStmt          : T_If '(' Expr ')' Stmt   %prec LOWER_THAN_ELSE          {$$ = new IfStmt($3, $5, NULL);}
                | T_If '(' Expr ')' Stmt T_Else Stmt                      {$$ = new IfStmt($3, $5, $7);}
                ;
                //| T_If '(' Expr ')' Stmt T_Else Stmt  {}
                //;//最大问题
    
WhileStmt       : T_While '(' Expr ')' Stmt { $$ = new WhileStmt($3, $5);}
                ;
ForStmt         : T_For '(' Expr ';' Expr ';' Expr ')' Stmt {$$ = new ForStmt($3, $5, $7, $9);}
                | T_For '('  ';' Expr ';' Expr ')' Stmt     {EmptyExpr *empty = new EmptyExpr(); $$ = new ForStmt(empty, $4, $6, $8);}
                | T_For '(' Expr ';' Expr ';'  ')' Stmt     {EmptyExpr *empty = new EmptyExpr(); $$ = new ForStmt($3, $5, empty, $8);}
                | T_For '(' ';' Expr ';' ')' Stmt           {EmptyExpr *empty = new EmptyExpr(); $$ = new ForStmt(empty, $4, empty, $7);}
                ;
ReturnStmt      : T_Return Expr ';' {$$= new ReturnStmt(Join(@1, @3), $2);}
                | T_Return ';'      {EmptyExpr *empty = new EmptyExpr(); $$= new ReturnStmt(Join(@1, @2), empty);}
                ;
BreakStmt       : T_Break ';'       {$$ = new BreakStmt(@1);}
                ;
PrintStmt       : T_Print '(' ExprList  ')' ';' { $$ = new PrintStmt($3);}
                ;
//SwitchStmt      : T_Switch '(' Expr ')' '{' Cases DefaultStmt '}' {$$=new SwitchStmt($3, $6, $7);}
//                ;      
//Cases           : Cases CaseStmt {($$=$1)->Append($2);}
//                | CaseStmt {($$=new List<CaseStmt*>)->Append($1);}
//                ;
//CaseStmt        : T_Case Lable ':' StmtList {   $$ = new CaseStmt($2, $4);  }
//                | T_Case Lable ':'          { List<Stmt*> *stmtlist = new List<Stmt*>();  $$ = new CaseStmt($2, stmtlist);  }
//                ;
//DefaultStmt     : T_Default ':' StmtList    {$$=new DefaultStmt($3);}
//                | T_Default ':'             {List<Stmt*> *stmtlist = new List<Stmt*>(); $$ = new DefaultStmt(stmtlist);}
//                ;
ExprList        : ExprList ',' Expr {($$=$1)->Append($3); }
                | Expr              {($$ = new List<Expr*>)->Append($1);}
                ;
Expr            : Constant                                {$$=$1;} 
                | LValue                                  {$$=$1;} 
                | T_This                                  {$$=new This(@1);} 
                | Call                                    {$$=$1;} 
                | '('  Expr  ')'                          {$$=$2;}     
                | LValue  '='  Expr                       {Operator *o = new Operator(@2, "=");   $$=new AssignExpr($1, o, $3);}
                | LValue T_Increment                      //{Operator *o = new Operator(@2, "++");   $$=new PostfixExpr($1, o);   }
                | LValue T_Decrement                      //{Operator *o = new Operator(@2, "--");   $$=new PostfixExpr($1, o);}
                | Expr '+' Expr                           {Operator *o = new Operator(@2, "+");   $$=new ArithmeticExpr($1, o, $3);} 
                | Expr '-' Expr                           {Operator *o = new Operator(@2, "-");   $$=new ArithmeticExpr($1, o, $3);} 
                | Expr '*' Expr                           {Operator *o = new Operator(@2, "*");   $$=new ArithmeticExpr($1, o, $3);} 
                | Expr '/' Expr                           {Operator *o = new Operator(@2, "/");   $$=new ArithmeticExpr($1, o, $3);} 
                | Expr '%' Expr                           {Operator *o = new Operator(@2, "%");   $$=new ArithmeticExpr($1, o, $3); }        
                |  '-'  Expr                              {Operator *o = new Operator(@2, "-");   $$=new ArithmeticExpr(o, $2);}   
                | Expr '<' Expr                           {Operator *o = new Operator(@2, "<");   $$=new RelationalExpr($1, o, $3);} 
                | Expr T_LessEqual Expr                   {Operator *o = new Operator(@2, "<=");  $$=new RelationalExpr($1, o, $3);} 
                | Expr '>' Expr                           {Operator *o = new Operator(@2, ">");  $$=new RelationalExpr($1, o, $3);} 
                | Expr T_GreaterEqual Expr                {Operator *o = new Operator(@2, ">=");  $$=new RelationalExpr($1, o, $3);} 
                | Expr T_Equal Expr                       {Operator *o = new Operator(@2, "==");  $$=new EqualityExpr($1, o, $3);} 
                | Expr T_NotEqual Expr                    {Operator *o = new Operator(@2, "!=");  $$=new EqualityExpr($1, o, $3);}                                                                                 
                | Expr T_And Expr                         {Operator *o = new Operator(@2, "&&");  $$=new LogicalExpr($1, o, $3);}
                | Expr T_Or Expr                          {Operator *o = new Operator(@2, "||");  $$=new LogicalExpr($1, o, $3);}        
                | '!'  Expr                               {Operator *o = new Operator(@2, "!");   $$=new LogicalExpr(o, $2);}
                | T_ReadInteger '(' ')'                   {$$=new ReadIntegerExpr(Join(@1, @3));}           
                | T_ReadLine '(' ')'                      {$$=new ReadLineExpr(Join(@1, @3));}     
                | T_New T_Identifier                      {
                                                              Identifier *ident = new Identifier(@2, $2);
                                                              NamedType *type = new NamedType(ident);
                                                              $$=new NewExpr(Join(@1, @2), type);
                                                          }
                | T_NewArray   '('  Expr ','  Type  ')'                                   {
                                                                                              $$=new NewArrayExpr(Join(@1, @6), $3, $5);
                                                                                          }
                ;
LValue          : T_Identifier                            { Identifier *ident = new Identifier(@1, $1); $$=new FieldAccess(NULL, ident);}        
                | Expr '.' T_Identifier                   { 
                                                              Identifier *ident = new Identifier(@3, $3);
                                                              $$=new FieldAccess($1, ident);
                                                          }
                | Expr '[' Expr ']'                       { $$=new ArrayAccess(Join(@1,@4), $1, $3);  }
                ;//为什么LValue对象创建只需要loc
Call            : T_Identifier  '(' Actuals ')'           {   Identifier *ident = new Identifier(@1, $1); $$=new Call(Join(@1,@4), NULL, ident, $3);   }
                | Expr '.' T_Identifier '(' Actuals ')'   {   Identifier *ident = new Identifier(@3, $3); $$=new Call(Join(@1,@6), $1, ident, $5);     }
                ;
Actuals         : ExprList                        {$$=$1;}
                |                                 {$$=new List<Expr*>;}
                ;
//Lable           : T_IntConstant                   {$$=new IntConstant(@1, $1);}
//                ;
Constant        : T_IntConstant                   {$$=new IntConstant(@1, $1);}
                | T_DoubleConstant                {$$=new DoubleConstant(@1, $1);}
                | T_BoolConstant                  {$$=new BoolConstant(@1, $1);}
                | T_StringConstant                {$$=new StringConstant(@1, $1);}          
                | T_Null                          {$$=new NullConstant(@1);}
                ; 

%%

/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */
void InitParser()
{
   PrintDebug("parser", "Initializing parser");
   yydebug = false;
}
