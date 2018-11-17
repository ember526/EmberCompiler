/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 11 "parser.y" /* yacc.c:339  */


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


#line 82 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_Void = 258,
    T_Bool = 259,
    T_Int = 260,
    T_Double = 261,
    T_String = 262,
    T_Class = 263,
    T_Dims = 264,
    T_And = 265,
    T_Or = 266,
    T_Extends = 267,
    T_This = 268,
    T_Interface = 269,
    T_Implements = 270,
    T_While = 271,
    T_For = 272,
    T_If = 273,
    T_Else = 274,
    T_Return = 275,
    T_Break = 276,
    T_New = 277,
    T_NewArray = 278,
    T_Print = 279,
    T_ReadInteger = 280,
    T_ReadLine = 281,
    T_Default = 282,
    T_Switch = 283,
    T_Case = 284,
    T_Identifier = 285,
    T_StringConstant = 286,
    T_IntConstant = 287,
    T_DoubleConstant = 288,
    T_BoolConstant = 289,
    T_Null = 290,
    LOWER_THAN_ELSE = 291,
    T_Equal = 292,
    T_NotEqual = 293,
    T_GreaterEqual = 294,
    T_LessEqual = 295,
    T_Increment = 296,
    T_Decrement = 297
  };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Double 261
#define T_String 262
#define T_Class 263
#define T_Dims 264
#define T_And 265
#define T_Or 266
#define T_Extends 267
#define T_This 268
#define T_Interface 269
#define T_Implements 270
#define T_While 271
#define T_For 272
#define T_If 273
#define T_Else 274
#define T_Return 275
#define T_Break 276
#define T_New 277
#define T_NewArray 278
#define T_Print 279
#define T_ReadInteger 280
#define T_ReadLine 281
#define T_Default 282
#define T_Switch 283
#define T_Case 284
#define T_Identifier 285
#define T_StringConstant 286
#define T_IntConstant 287
#define T_DoubleConstant 288
#define T_BoolConstant 289
#define T_Null 290
#define LOWER_THAN_ELSE 291
#define T_Equal 292
#define T_NotEqual 293
#define T_GreaterEqual 294
#define T_LessEqual 295
#define T_Increment 296
#define T_Decrement 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 41 "parser.y" /* yacc.c:355  */

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

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 263 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   815

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  215

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,     2,     2,    47,     2,     2,
      56,    57,    48,    44,    58,    45,    50,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
      42,    37,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    38,    39,    40,    43,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   150,   151,   156,   157,   158,   159,   161,
     163,   165,   166,   167,   168,   169,   170,   172,   178,   185,
     186,   188,   189,   191,   196,   197,   199,   200,   202,   207,
     213,   214,   216,   217,   219,   220,   225,   226,   228,   232,
     237,   238,   242,   246,   252,   253,   255,   256,   258,   259,
     260,   260,   260,   260,   260,   260,   260,   262,   263,   268,
     270,   271,   272,   273,   275,   276,   278,   280,   293,   294,
     296,   297,   298,   299,   300,   301,   302,   303,   304,   305,
     306,   307,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,   321,   326,   330,   331,   335,
     337,   338,   340,   341,   345,   346,   347,   348,   349
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_Dims", "T_And", "T_Or", "T_Extends", "T_This",
  "T_Interface", "T_Implements", "T_While", "T_For", "T_If", "T_Else",
  "T_Return", "T_Break", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Default", "T_Switch", "T_Case", "T_Identifier",
  "T_StringConstant", "T_IntConstant", "T_DoubleConstant",
  "T_BoolConstant", "T_Null", "LOWER_THAN_ELSE", "'='", "T_Equal",
  "T_NotEqual", "T_GreaterEqual", "'>'", "'<'", "T_LessEqual", "'+'",
  "'-'", "'/'", "'%'", "'*'", "'!'", "'.'", "'['", "T_Increment",
  "T_Decrement", "']'", "';'", "'('", "')'", "','", "'{'", "'}'",
  "$accept", "Program", "DeclList", "Decl", "VariableDecl", "Variable",
  "Type", "FunctionDecl", "Formals", "FormalsTail", "ClassDecl", "Extend",
  "Implement", "IdentList", "Field", "FieldList", "InterfaceDecl",
  "PrototypeList", "Prototype", "StmtBlock", "VarDeclList", "StmtList",
  "Stmt", "IfStmt", "WhileStmt", "ForStmt", "ReturnStmt", "BreakStmt",
  "PrintStmt", "ExprList", "Expr", "LValue", "Call", "Actuals", "Constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,    61,   292,   293,
     294,    62,    60,   295,    43,    45,    47,    37,    42,    33,
      46,    91,   296,   297,    93,    59,    40,    41,    44,   123,
     125
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -16

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     290,   -28,   -72,   -72,   -72,   -72,   -21,   -18,   -72,    19,
     290,   -72,   -72,   -27,    16,   -72,   -72,   -72,   -17,    32,
      -7,   -72,   -72,   -72,   -72,    33,   773,    64,    89,     1,
     773,    60,    18,    65,   -72,    95,    68,   103,   -72,    45,
      17,   -72,    71,   773,   -72,   -72,    84,   -72,    61,   -72,
      97,   105,   -72,   -72,    84,    60,   134,   -72,   132,    30,
     773,   773,   -72,   -72,   -72,   107,   114,   116,   629,   118,
     144,   120,   121,   122,   124,     2,   -72,   -72,   -72,   -72,
     -72,   685,   685,   -72,   685,   -72,   -72,   -72,   191,   256,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   432,    50,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   125,   127,   685,   657,
     685,   129,   -72,   453,   -72,   -72,   685,   685,   130,   135,
     685,    98,    62,   327,   -72,   -72,   301,   -72,   -72,   685,
     685,   685,   685,   685,   685,   685,   685,   685,   685,   685,
     685,   685,   151,   685,   -72,   685,   -72,   -72,   136,   146,
     348,   685,   474,   369,   -72,   217,    58,   711,   -72,   -72,
     141,   143,   -72,   -72,   743,   725,   764,   764,    35,    35,
      35,    35,    98,    98,    62,    62,    62,   147,   537,   711,
     -72,   -72,    75,   495,   685,    75,   773,   155,   685,   -72,
     685,   -72,   -72,   573,   516,   183,    -6,   -72,   711,   161,
      75,   390,   601,    75,   -72,   -72,   -72,    75,    75,   411,
     -72,   -72,   -72,    75,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    13,    11,    12,    14,     0,     0,    15,     0,
       2,     4,     5,     0,     0,     6,     7,     8,     0,    25,
       0,     1,     3,     9,    16,    10,    20,     0,    27,     0,
      20,    22,     0,     0,    24,     0,     0,     0,    35,     0,
       0,    37,     0,     0,    19,    10,     0,    28,    26,    33,
       0,     0,    34,    36,     0,    22,     0,    18,     0,     0,
      20,    20,    17,    21,    72,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,   107,   104,   105,   106,
     108,     0,     0,    49,     0,    43,    45,    56,     0,     0,
      47,    50,    51,    52,    54,    53,    55,     0,    71,    73,
      70,    29,    23,    30,    31,    32,     0,     0,     0,     0,
       0,    97,    65,     0,    66,    95,     0,     0,     0,     0,
     103,    83,    92,     0,    41,    44,     0,    42,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    76,    77,     0,     0,
       0,     0,     0,     0,    64,     0,     0,    69,    93,    94,
     102,     0,    74,    40,    90,    91,    88,    89,    87,    86,
      84,    85,    78,    79,    81,    82,    80,    98,     0,    75,
      39,    38,     0,     0,     0,     0,     0,     0,     0,   100,
     103,    99,    59,     0,     0,    57,     0,    67,    68,     0,
       0,     0,     0,     0,    96,   101,    63,     0,     0,     0,
      58,    61,    62,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   -72,   209,   -43,   145,     0,   170,    -4,   165,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   190,   -16,
     -72,   149,   -71,   -72,   -72,   -72,   -72,   -72,   -72,   115,
     -67,   -72,   -72,    41,   -72
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    32,    15,    33,    44,
      16,    28,    36,    48,   105,    59,    17,    40,    41,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,   160,
      97,    98,    99,   161,   100
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,   113,    18,    24,    37,     2,     3,     4,     5,    19,
      14,   -15,    20,    86,   121,   122,   103,   123,   128,    21,
      37,     2,     3,     4,     5,    24,    42,    24,    23,    39,
      57,     8,   -15,     1,     2,     3,     4,     5,    62,    26,
      39,   150,   152,   153,    27,   125,    25,     8,    45,   155,
     157,   204,    29,   157,    24,   128,   106,   107,   120,    14,
       8,    38,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,    51,   178,    52,   179,   137,
     138,   139,   140,   141,   183,   142,   143,   145,    64,    30,
     102,    65,    66,    67,    34,    68,    69,    70,    71,    72,
      73,    74,   146,   147,    35,   111,    76,    77,    78,    79,
      80,   192,   142,   143,   195,   187,   188,   194,    43,    58,
      81,   198,    46,   157,    82,    47,   201,    49,    54,   206,
      83,    84,   210,    50,    56,   209,   211,   212,     2,     3,
       4,     5,   214,    56,   139,   140,   141,    64,   142,   143,
      65,    66,    67,    60,    68,    69,    70,    71,    72,    73,
      74,    61,   101,   108,    75,    76,    77,    78,    79,    80,
     109,    31,   110,   114,   115,    31,   116,   117,   118,    81,
     119,   177,   148,    82,   149,   120,   196,   158,    55,    83,
      84,   180,   159,    56,    85,     2,     3,     4,     5,   188,
     189,   181,   203,   190,    64,    31,    31,    65,    66,    67,
     197,    68,    69,    70,    71,    72,    73,    74,   205,    22,
      63,    75,    76,    77,    78,    79,    80,   129,   130,   104,
      53,   199,   156,     0,     0,     0,    81,   126,     0,     0,
      82,     0,     0,     0,     0,     0,    83,    84,     0,     0,
      56,   124,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,   142,   143,    64,
       0,     0,    65,    66,    67,   186,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,   111,    76,    77,    78,
      79,    80,     0,     1,     2,     3,     4,     5,     6,     0,
       0,    81,     0,     0,     7,    82,     0,     0,     0,     0,
       0,    83,    84,     0,    64,    56,   127,    65,    66,    67,
       8,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,   111,    76,    77,    78,    79,    80,   129,   130,     0,
       0,     0,     0,     0,     0,     0,    81,     0,     0,     0,
      82,     0,     0,     0,     0,     0,    83,    84,   129,   130,
      56,   163,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,   142,   143,   129,
     130,     0,     0,     0,   162,     0,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,     0,   142,   143,
     129,   130,     0,     0,     0,   182,     0,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,     0,   142,
     143,   129,   130,     0,     0,     0,   185,     0,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,     0,
     142,   143,   129,   130,     0,     0,     0,   207,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,   142,   143,   129,   130,     0,     0,     0,   213,     0,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,     0,   142,   143,   129,   130,     0,   144,     0,     0,
       0,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,   142,   143,   129,   130,     0,   154,     0,
       0,     0,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,   142,   143,   129,   130,     0,   184,
       0,     0,     0,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,   142,   143,   129,   130,     0,
     193,     0,     0,     0,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,     0,   142,   143,     0,     0,
       0,   202,     0,     0,     0,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,    64,   142,   143,     0,
       0,   191,     0,     0,     0,    70,    71,     0,    73,    74,
       0,     0,     0,   111,    76,    77,    78,    79,    80,     0,
       0,     0,     0,     0,    64,     0,     0,     0,    81,     0,
       0,     0,    82,    70,    71,     0,    73,    74,     0,    84,
     200,   111,    76,    77,    78,    79,    80,     0,     0,     0,
       0,     0,    64,     0,     0,     0,    81,     0,     0,     0,
      82,    70,    71,     0,    73,    74,     0,    84,   208,   111,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
      64,     0,     0,     0,    81,     0,     0,     0,    82,    70,
      71,     0,    73,    74,   112,    84,     0,   111,    76,    77,
      78,    79,    80,     0,     0,     0,     0,     0,    64,     0,
       0,     0,    81,     0,     0,     0,    82,    70,    71,     0,
      73,    74,   151,    84,     0,   111,    76,    77,    78,    79,
      80,   129,   130,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,     0,    82,   129,     0,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
       0,   142,   143,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,     0,   142,   143,     2,     3,     4,
       5,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,     0,   142,   143,     0,     0,     0,     0,     0,
       0,     0,     0,     8,   133,   134,   135,   136,   137,   138,
     139,   140,   141,     0,   142,   143
};

static const yytype_int16 yycheck[] =
{
       0,    68,    30,     9,     3,     4,     5,     6,     7,    30,
      10,     9,    30,    56,    81,    82,    59,    84,    89,     0,
       3,     4,     5,     6,     7,     9,    30,     9,    55,    29,
      46,    30,    30,     3,     4,     5,     6,     7,    54,    56,
      40,   108,   109,   110,    12,    88,    30,    30,    30,   116,
     117,    57,    59,   120,     9,   126,    60,    61,    56,    59,
      30,    60,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,    30,   143,    60,   145,    44,
      45,    46,    47,    48,   151,    50,    51,    37,    13,    56,
      60,    16,    17,    18,    30,    20,    21,    22,    23,    24,
      25,    26,    52,    53,    15,    30,    31,    32,    33,    34,
      35,   182,    50,    51,   185,    57,    58,   184,    58,    58,
      45,   188,    57,   190,    49,    30,   193,    59,    57,   200,
      55,    56,   203,    30,    59,   202,   207,   208,     4,     5,
       6,     7,   213,    59,    46,    47,    48,    13,    50,    51,
      16,    17,    18,    56,    20,    21,    22,    23,    24,    25,
      26,    56,    30,    56,    30,    31,    32,    33,    34,    35,
      56,    26,    56,    55,    30,    30,    56,    56,    56,    45,
      56,    30,    57,    49,    57,    56,   186,    57,    43,    55,
      56,    55,    57,    59,    60,     4,     5,     6,     7,    58,
      57,    55,    19,    56,    13,    60,    61,    16,    17,    18,
      55,    20,    21,    22,    23,    24,    25,    26,    57,    10,
      55,    30,    31,    32,    33,    34,    35,    10,    11,    59,
      40,   190,   117,    -1,    -1,    -1,    45,    88,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    56,    -1,    -1,
      59,    60,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    13,
      -1,    -1,    16,    17,    18,    58,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    -1,     3,     4,     5,     6,     7,     8,    -1,
      -1,    45,    -1,    -1,    14,    49,    -1,    -1,    -1,    -1,
      -1,    55,    56,    -1,    13,    59,    60,    16,    17,    18,
      30,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    55,    56,    10,    11,
      59,    60,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    -1,    50,    51,    10,
      11,    -1,    -1,    -1,    57,    -1,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    -1,    50,    51,
      10,    11,    -1,    -1,    -1,    57,    -1,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    -1,    50,
      51,    10,    11,    -1,    -1,    -1,    57,    -1,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    -1,
      50,    51,    10,    11,    -1,    -1,    -1,    57,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    10,    11,    -1,    -1,    -1,    57,    -1,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    -1,    50,    51,    10,    11,    -1,    55,    -1,    -1,
      -1,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    10,    11,    -1,    55,    -1,
      -1,    -1,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51,    10,    11,    -1,    55,
      -1,    -1,    -1,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,    10,    11,    -1,
      55,    -1,    -1,    -1,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    -1,    50,    51,    -1,    -1,
      -1,    55,    -1,    -1,    -1,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    13,    50,    51,    -1,
      -1,    54,    -1,    -1,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    49,    22,    23,    -1,    25,    26,    -1,    56,
      57,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      -1,    -1,    13,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      49,    22,    23,    -1,    25,    26,    -1,    56,    57,    30,
      31,    32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,
      13,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    22,
      23,    -1,    25,    26,    55,    56,    -1,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    22,    23,    -1,
      25,    26,    55,    56,    -1,    30,    31,    32,    33,    34,
      35,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    49,    10,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      -1,    50,    51,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    -1,    50,    51,     4,     5,     6,
       7,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    -1,    50,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    -1,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    14,    30,    62,
      63,    64,    65,    66,    67,    68,    71,    77,    30,    30,
      30,     0,    64,    55,     9,    30,    56,    12,    72,    59,
      56,    66,    67,    69,    30,    15,    73,     3,    60,    67,
      78,    79,    69,    58,    70,    30,    57,    30,    74,    59,
      30,    30,    60,    79,    57,    66,    59,    80,    58,    76,
      56,    56,    80,    70,    13,    16,    17,    18,    20,    21,
      22,    23,    24,    25,    26,    30,    31,    32,    33,    34,
      35,    45,    49,    55,    56,    60,    65,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    91,    92,    93,
      95,    30,    60,    65,    68,    75,    69,    69,    56,    56,
      56,    30,    55,    91,    55,    30,    56,    56,    56,    56,
      56,    91,    91,    91,    60,    65,    82,    60,    83,    10,
      11,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    50,    51,    55,    37,    52,    53,    57,    57,
      91,    55,    91,    91,    55,    91,    90,    91,    57,    57,
      90,    94,    57,    60,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    30,    91,    91,
      55,    55,    57,    91,    55,    57,    58,    57,    58,    57,
      56,    54,    83,    55,    91,    83,    67,    55,    91,    94,
      57,    91,    55,    19,    57,    57,    83,    57,    57,    91,
      83,    83,    83,    57,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    63,    63,    64,    64,    64,    64,    65,
      66,    67,    67,    67,    67,    67,    67,    68,    68,    69,
      69,    70,    70,    71,    72,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    83,    83,    83,    83,    83,    83,    84,    84,    85,
      86,    86,    86,    86,    87,    87,    88,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     2,     6,     6,     2,
       0,     3,     0,     7,     2,     0,     2,     0,     1,     3,
       1,     1,     2,     0,     5,     4,     2,     1,     6,     6,
       4,     3,     3,     2,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     7,     5,
       9,     8,     8,     7,     3,     2,     2,     5,     3,     1,
       1,     1,     1,     1,     3,     3,     2,     2,     3,     3,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     2,     6,     1,     3,     4,
       4,     6,     1,     0,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 134 "parser.y" /* yacc.c:1646  */
    {
                                      (yylsp[0]); 
                                      /* pp2: The @1 is needed to convince 
                                       * yacc to set up yylloc. You can remove 
                                       * it once you have other uses of @n*/

                                      Program *program = new Program((yyvsp[0].declList));
                                      (yyval.program) = program;
                                      // if no errors, advance to next phase
                                      if (ReportError::NumErrors() == 0) 
                                        program->Check();
                                      if (ReportError::NumErrors() == 0) 
                                        program->Emit();
                                    }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 150 "parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl)); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 151 "parser.y" /* yacc.c:1646  */
    {
                                        ((yyval.declList) = new List<Decl*>)->Append((yyvsp[0].decl));
                                      }
#line 1735 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 156 "parser.y" /* yacc.c:1646  */
    {(yyval.decl)=(yyvsp[0].decl);}
#line 1741 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 157 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].decl);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 158 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].decl);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 159 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].decl);}
#line 1759 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.varDecl)=(yyvsp[-1].varDecl);}
#line 1765 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 163 "parser.y" /* yacc.c:1646  */
    {Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier)); (yyval.varDecl)=new VarDecl(ident, (yyvsp[-1].typ));}
#line 1771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.typ)=Type::intType;}
#line 1777 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.typ)=Type::doubleType;}
#line 1783 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.typ)=Type::boolType;}
#line 1789 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.typ)=Type::stringType;}
#line 1795 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 169 "parser.y" /* yacc.c:1646  */
    {Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier)); (yyval.typ)=new NamedType(ident);}
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 170 "parser.y" /* yacc.c:1646  */
    {(yyval.typ)=new ArrayType(Join((yylsp[-1]), (yylsp[0])), (yyvsp[-1].typ));}
#line 1807 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 172 "parser.y" /* yacc.c:1646  */
    {   
                                                                      Identifier *identifier = new Identifier((yylsp[-4]), (yyvsp[-4].identifier));
                                                                      FnDecl *fun= new FnDecl(identifier, (yyvsp[-5].typ), (yyvsp[-2].varDeclList));
                                                                      fun->SetFunctionBody((yyvsp[0].stmt));  
                                                                      (yyval.decl)=fun; 
                                                                  }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 178 "parser.y" /* yacc.c:1646  */
    {
                                                                      Identifier *identifier = new Identifier((yylsp[-4]), (yyvsp[-4].identifier));
                                                                      FnDecl *fun= new FnDecl(identifier, Type::voidType, (yyvsp[-2].varDeclList));
                                                                      fun->SetFunctionBody((yyvsp[0].stmt));  
                                                                      (yyval.decl)=fun; 
                                                                  }
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 185 "parser.y" /* yacc.c:1646  */
    {((yyval.varDeclList)=(yyvsp[0].varDeclList))->InsertAt((yyvsp[-1].varDecl), 0);}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 186 "parser.y" /* yacc.c:1646  */
    {(yyval.varDeclList) = new List<VarDecl*>;}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 188 "parser.y" /* yacc.c:1646  */
    {((yyval.varDeclList)=(yyvsp[0].varDeclList))->InsertAt((yyvsp[-1].varDecl), 0);}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 189 "parser.y" /* yacc.c:1646  */
    {(yyval.varDeclList) = new List<VarDecl*>;}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 191 "parser.y" /* yacc.c:1646  */
    { 
                                                                          Identifier *ident = new Identifier((yylsp[-5]), (yyvsp[-5].identifier));
                                                                          (yyval.decl)=new ClassDecl(ident, (yyvsp[-4].namedType), (yyvsp[-3].namedTypeList), (yyvsp[-1].declList));
                                                                          }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 196 "parser.y" /* yacc.c:1646  */
    {   Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier)); (yyval.namedType)=new NamedType(ident);}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 197 "parser.y" /* yacc.c:1646  */
    {   (yyval.namedType)=NULL;}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 199 "parser.y" /* yacc.c:1646  */
    {   (yyval.namedTypeList)=(yyvsp[0].namedTypeList);}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 200 "parser.y" /* yacc.c:1646  */
    {   (yyval.namedTypeList)=new List<NamedType *>;}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 202 "parser.y" /* yacc.c:1646  */
    {   
                                                  Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier));
                                                  NamedType *name = new NamedType(ident);
                                                  ((yyval.namedTypeList)=new List<NamedType*>)->Append(name);
                                              }
#line 1896 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 207 "parser.y" /* yacc.c:1646  */
    {   
                                                  Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier)); 
                                                  NamedType *name = new NamedType(ident);
                                                  ((yyval.namedTypeList)=(yyvsp[-2].namedTypeList))->Append(name);
                                              }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 213 "parser.y" /* yacc.c:1646  */
    { (yyval.decl)=(yyvsp[0].decl);}
#line 1912 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.decl)=(yyvsp[0].decl);}
#line 1918 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 216 "parser.y" /* yacc.c:1646  */
    {((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl));}
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.declList)=new List<Decl*>;}
#line 1930 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 219 "parser.y" /* yacc.c:1646  */
    {Identifier *ident = new Identifier((yylsp[-3]), (yyvsp[-3].identifier)); (yyval.decl)=new InterfaceDecl(ident, (yyvsp[-1].declList));}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 220 "parser.y" /* yacc.c:1646  */
    {
                                                      Identifier *ident = new Identifier((yylsp[-2]), (yyvsp[-2].identifier));
                                                      List<Decl*> *emptyList = new List<Decl*>;
                                                      (yyval.decl)=new InterfaceDecl(ident, emptyList);}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 225 "parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=(yyvsp[-1].declList))->Append((yyvsp[0].decl));}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 226 "parser.y" /* yacc.c:1646  */
    { ((yyval.declList)=new List<Decl*>)->Append((yyvsp[0].decl));}
#line 1957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 228 "parser.y" /* yacc.c:1646  */
    {   
                                                                  Identifier *identifier = new Identifier((yylsp[-1]), (yyvsp[-4].identifier));
                                                                  (yyval.decl) = new FnDecl(identifier, (yyvsp[-5].typ), (yyvsp[-2].varDeclList));   
                                                              }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 232 "parser.y" /* yacc.c:1646  */
    {   
                                                                  Identifier *identifier = new Identifier((yylsp[-1]), (yyvsp[-4].identifier));
                                                                  (yyval.decl) = new FnDecl(identifier, Type::voidType, (yyvsp[-2].varDeclList));   
                                                              }
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt)=new StmtBlock((yyvsp[-2].varDeclList), (yyvsp[-1].stmtList));}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "parser.y" /* yacc.c:1646  */
    {
                                      List<Stmt*> *stmtlist = new List<Stmt*>();
                                      (yyval.stmt)=new StmtBlock((yyvsp[-1].varDeclList), stmtlist);
                                      }
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 242 "parser.y" /* yacc.c:1646  */
    {
                                      List<VarDecl*> *vardecllist = new List<VarDecl*>();
                                      (yyval.stmt)=new StmtBlock(vardecllist, (yyvsp[-1].stmtList));
                                      }
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 246 "parser.y" /* yacc.c:1646  */
    {
                                      List<VarDecl*> *vardecllist = new List<VarDecl*>();
                                      List<Stmt*> *stmtlist = new List<Stmt*>();
                                      (yyval.stmt)=new StmtBlock(vardecllist, stmtlist);
                                      }
#line 2009 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 252 "parser.y" /* yacc.c:1646  */
    {((yyval.varDeclList)=(yyvsp[-1].varDeclList))->Append((yyvsp[0].varDecl));}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 253 "parser.y" /* yacc.c:1646  */
    {((yyval.varDeclList)=new List<VarDecl*>)->Append((yyvsp[0].varDecl));}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 255 "parser.y" /* yacc.c:1646  */
    {((yyval.stmtList)=(yyvsp[-1].stmtList))->Append((yyvsp[0].stmt));}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 256 "parser.y" /* yacc.c:1646  */
    {((yyval.stmtList)=new List<Stmt*>)->Append((yyvsp[0].stmt)); }
#line 2033 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 258 "parser.y" /* yacc.c:1646  */
    {  (yyval.stmt)=(yyvsp[-1].stmt);}
#line 2039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 259 "parser.y" /* yacc.c:1646  */
    {  (yyval.stmt)=(yyvsp[0].stmt);}
#line 2045 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 260 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = (yyvsp[0].stmt);}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new IfStmt((yyvsp[-2].expr), (yyvsp[0].stmt), NULL);}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new IfStmt((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt));}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 268 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new WhileStmt((yyvsp[-2].expr), (yyvsp[0].stmt));}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 270 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new ForStmt((yyvsp[-6].expr), (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 271 "parser.y" /* yacc.c:1646  */
    {EmptyExpr *empty = new EmptyExpr(); (yyval.stmt) = new ForStmt(empty, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].stmt));}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 272 "parser.y" /* yacc.c:1646  */
    {EmptyExpr *empty = new EmptyExpr(); (yyval.stmt) = new ForStmt((yyvsp[-5].expr), (yyvsp[-3].expr), empty, (yyvsp[0].stmt));}
#line 2087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 273 "parser.y" /* yacc.c:1646  */
    {EmptyExpr *empty = new EmptyExpr(); (yyval.stmt) = new ForStmt(empty, (yyvsp[-3].expr), empty, (yyvsp[0].stmt));}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 275 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt)= new ReturnStmt(Join((yylsp[-2]), (yylsp[0])), (yyvsp[-1].expr));}
#line 2099 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 276 "parser.y" /* yacc.c:1646  */
    {EmptyExpr *empty = new EmptyExpr(); (yyval.stmt)= new ReturnStmt(Join((yylsp[-1]), (yylsp[0])), empty);}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 278 "parser.y" /* yacc.c:1646  */
    {(yyval.stmt) = new BreakStmt((yylsp[-1]));}
#line 2111 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 280 "parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new PrintStmt((yyvsp[-2].exprList));}
#line 2117 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 293 "parser.y" /* yacc.c:1646  */
    {((yyval.exprList)=(yyvsp[-2].exprList))->Append((yyvsp[0].expr)); }
#line 2123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 294 "parser.y" /* yacc.c:1646  */
    {((yyval.exprList) = new List<Expr*>)->Append((yyvsp[0].expr));}
#line 2129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 296 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[0].expr);}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 297 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[0].expr);}
#line 2141 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 298 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new This((yylsp[0]));}
#line 2147 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 299 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[0].expr);}
#line 2153 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 300 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=(yyvsp[-1].expr);}
#line 2159 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 301 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "=");   (yyval.expr)=new AssignExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 304 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "+");   (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2171 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 305 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "-");   (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2177 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 306 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "*");   (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 307 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "/");   (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 308 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "%");   (yyval.expr)=new ArithmeticExpr((yyvsp[-2].expr), o, (yyvsp[0].expr)); }
#line 2195 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 309 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[0]), "-");   (yyval.expr)=new ArithmeticExpr(o, (yyvsp[0].expr));}
#line 2201 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 310 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "<");   (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 311 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "<=");  (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 312 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), ">");  (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2219 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 313 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), ">=");  (yyval.expr)=new RelationalExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2225 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 314 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "==");  (yyval.expr)=new EqualityExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2231 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 315 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "!=");  (yyval.expr)=new EqualityExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 316 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "&&");  (yyval.expr)=new LogicalExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 317 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[-1]), "||");  (yyval.expr)=new LogicalExpr((yyvsp[-2].expr), o, (yyvsp[0].expr));}
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 318 "parser.y" /* yacc.c:1646  */
    {Operator *o = new Operator((yylsp[0]), "!");   (yyval.expr)=new LogicalExpr(o, (yyvsp[0].expr));}
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 319 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new ReadIntegerExpr(Join((yylsp[-2]), (yylsp[0])));}
#line 2261 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 320 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new ReadLineExpr(Join((yylsp[-2]), (yylsp[0])));}
#line 2267 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 321 "parser.y" /* yacc.c:1646  */
    {
                                                              Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier));
                                                              NamedType *type = new NamedType(ident);
                                                              (yyval.expr)=new NewExpr(Join((yylsp[-1]), (yylsp[0])), type);
                                                          }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 326 "parser.y" /* yacc.c:1646  */
    {
                                                                                              (yyval.expr)=new NewArrayExpr(Join((yylsp[-5]), (yylsp[0])), (yyvsp[-3].expr), (yyvsp[-1].typ));
                                                                                          }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 330 "parser.y" /* yacc.c:1646  */
    { Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier)); (yyval.expr)=new FieldAccess(NULL, ident);}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 331 "parser.y" /* yacc.c:1646  */
    { 
                                                              Identifier *ident = new Identifier((yylsp[0]), (yyvsp[0].identifier));
                                                              (yyval.expr)=new FieldAccess((yyvsp[-2].expr), ident);
                                                          }
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 335 "parser.y" /* yacc.c:1646  */
    { (yyval.expr)=new ArrayAccess(Join((yylsp[-3]),(yylsp[0])), (yyvsp[-3].expr), (yyvsp[-1].expr));  }
#line 2306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 337 "parser.y" /* yacc.c:1646  */
    {   Identifier *ident = new Identifier((yylsp[-3]), (yyvsp[-3].identifier)); (yyval.expr)=new Call(Join((yylsp[-3]),(yylsp[0])), NULL, ident, (yyvsp[-1].exprList));   }
#line 2312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 338 "parser.y" /* yacc.c:1646  */
    {   Identifier *ident = new Identifier((yylsp[-3]), (yyvsp[-3].identifier)); (yyval.expr)=new Call(Join((yylsp[-5]),(yylsp[0])), (yyvsp[-5].expr), ident, (yyvsp[-1].exprList));     }
#line 2318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 340 "parser.y" /* yacc.c:1646  */
    {(yyval.exprList)=(yyvsp[0].exprList);}
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 341 "parser.y" /* yacc.c:1646  */
    {(yyval.exprList)=new List<Expr*>;}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 345 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new IntConstant((yylsp[0]), (yyvsp[0].integerConstant));}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 346 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new DoubleConstant((yylsp[0]), (yyvsp[0].doubleConstant));}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 347 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new BoolConstant((yylsp[0]), (yyvsp[0].boolConstant));}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 348 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new StringConstant((yylsp[0]), (yyvsp[0].stringConstant));}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 349 "parser.y" /* yacc.c:1646  */
    {(yyval.expr)=new NullConstant((yylsp[0]));}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2364 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 352 "parser.y" /* yacc.c:1906  */


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
