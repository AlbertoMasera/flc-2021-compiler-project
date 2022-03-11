/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_VAL = 258,
     REAL_VAL = 259,
     BOOLEAN_VAL = 260,
     STRING_VAL = 261,
     ID = 262,
     PRINT = 263,
     BLOCK = 264,
     RETURN = 265,
     IF = 266,
     ELSE = 267,
     ELIF = 268,
     WHILE = 269,
     INT = 270,
     REAL = 271,
     BOOLEAN = 272,
     STRING = 273,
     LN = 274,
     LOG = 275,
     LOG10 = 276,
     SQRT = 277,
     GT = 278,
     LT = 279,
     GE = 280,
     LE = 281,
     EQ = 282,
     NE = 283,
     TAN = 284,
     COS = 285,
     SIN = 286,
     UMINUS = 287
   };
#endif
/* Tokens.  */
#define INT_VAL 258
#define REAL_VAL 259
#define BOOLEAN_VAL 260
#define STRING_VAL 261
#define ID 262
#define PRINT 263
#define BLOCK 264
#define RETURN 265
#define IF 266
#define ELSE 267
#define ELIF 268
#define WHILE 269
#define INT 270
#define REAL 271
#define BOOLEAN 272
#define STRING 273
#define LN 274
#define LOG 275
#define LOG10 276
#define SQRT 277
#define GT 278
#define LT 279
#define GE 280
#define LE 281
#define EQ 282
#define NE 283
#define TAN 284
#define COS 285
#define SIN 286
#define UMINUS 287




/* Copy the first part of user declarations.  */
#line 1 "calc-yacc.y"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define ERROR_BUFFER_SIZE 100
#define OUTPUT_FILE "output.txt"
#define EPSILON 0.00001


/* BASIC TYPES */
typedef enum {
      FALSE,
      TRUE
} Boolean;


/* OPERATORS */
typedef enum {
      SUM_OP,
      DIF_OP,
      MOL_OP,
      DIV_OP,
      EXP_OP,
      FAC_OP,
      NEG_OP,
      LN_OP,
      LOG_OP,
      LOG10_OP,
      SQRT_OP,
      SIN_OP,
      COS_OP,
      TAN_OP,
      CON_OP,
      CON_SPACE_OP,
      EQ_OP,
      NE_OP,
      GT_OP,
      LT_OP,
      GE_OP,
      LE_OP
} Operation;


/* TYPES */
typedef enum {
      VOID_TYPE,
      INT_TYPE,
      REAL_TYPE,
      STRING_TYPE,
      BOOLEAN_TYPE
} Type;

typedef union {
      int int_value;
      double real_value;
      char *string_value;
      Boolean boolean_value;
} TypeData;


/* SYMBOL TABLES */
typedef struct {
      char* name;
      Type type;
      TypeData data;
} SymbolTableEntry;

typedef struct symbol_table_node {
      SymbolTableEntry *entry;
      struct symbol_table_node *next;
} SymbolTableNode;

typedef struct {
      SymbolTableNode *head;
      SymbolTableNode *tail;
} SymbolTable;


/* SCOPING */
typedef struct scope {
      SymbolTable *symbol_table;
      struct scope *outer;
} Scope;

typedef struct {
      Scope *current;
} Program;


/* STATEMENTS */
typedef struct {
      Type type;
      TypeData data;
} StatementResult;


/* EXPRESSIONS */
typedef struct {
      Type type;
      TypeData data;
} ExprResult;


/* HELPER FUNCTIONS */
int yylex();
void yyerror(const char *s);
void parse(FILE *fileInput);
void check_types_eq(Type type1, Type type2);
char *type_to_string(Type type);


/* PROGRAM FUNCTIONS */
Program *get_program();


/* SCOPE FUNCTIONS */
void destroy_scope();
void new_scope();


/* SYMBOL TABLE FUNCTIONS */
SymbolTable *init_symbol_table();
SymbolTable *get_symbol_table(int scope_index);
void insert(char *name, Type type, TypeData data);
void update(char *name, Type type, TypeData data);
SymbolTableEntry *search(char *name, int current_only);
SymbolTableEntry *lookup(char *name);
void delete(char *name);
void print_symbol_table(SymbolTable *symbol_table);


/* GENERIC FUNCTIONS */
void initial_assignment(char *variable_name, Type variable_type, StatementResult *statement_result);
void existing_assignment(char *variable_name, StatementResult *statement_result);


/* STATEMENT FUNCTIONS */
StatementResult *build_statement_result(Type type, TypeData data);
StatementResult *build_statement_result_from(ExprResult *expr_result);
StatementResult *build_void_statement_result();


/* EXPRESSION FUNCTIONS */
ExprResult *build_expr_result(Type type, TypeData data);
ExprResult *operation(ExprResult *left, ExprResult *right, Operation operation);
ExprResult *sum_op(ExprResult *left, ExprResult *right);
ExprResult *dif_op(ExprResult *left, ExprResult *right);
ExprResult *mol_op(ExprResult *left, ExprResult *right);
ExprResult *div_op(ExprResult *left, ExprResult *right);
ExprResult *exp_op(ExprResult *left, ExprResult *right);
ExprResult *log_op(ExprResult *left, ExprResult *right);
ExprResult *con_op(ExprResult *left, ExprResult *right);
ExprResult *con_space_op(ExprResult *left, ExprResult *right);
ExprResult *eq_op(ExprResult *left, ExprResult *right);
ExprResult *ne_op(ExprResult *left, ExprResult *right);
ExprResult *gt_op(ExprResult *left, ExprResult *right);
ExprResult *lt_op(ExprResult *left, ExprResult *right);
ExprResult *ge_op(ExprResult *left, ExprResult *right);
ExprResult *le_op(ExprResult *left, ExprResult *right);
ExprResult *single_operation(ExprResult *left, Operation operation);
ExprResult *neg_op(ExprResult *left);
ExprResult *fac_op(ExprResult *left);
ExprResult *ln_op(ExprResult *left);
ExprResult *log10_op(ExprResult *left);
ExprResult *sqrt_op(ExprResult *left);
ExprResult *sin_op(ExprResult *left);
ExprResult *cos_op(ExprResult *left);
ExprResult *tan_op(ExprResult *left);
void print_expr_result(ExprResult *expr_result);


/* GLOBAL VARIABLES */
Program *MAIN = NULL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 179 "calc-yacc.y"
{
        int int_value;
        double real_value;
        Boolean boolean_value;
        char *string_value;
        char *lexeme;
        Type type;
        StatementResult *statement_result;
        ExprResult *expr_result;
       }
/* Line 193 of yacc.c.  */
#line 349 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 362 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  52
/* YYNRULES -- Number of states.  */
#define YYNSTATES  130

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,     2,     2,     2,     2,     2,
      44,    45,    31,    30,    48,    29,    38,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    42,    41,
       2,    43,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    33,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    46,    39,    47,     2,     2,     2,     2,
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
      25,    26,    27,    28,    35,    36,    37,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     6,    10,    13,    15,    21,    25,
      30,    31,    32,    39,    48,    56,    65,    70,    71,    73,
      78,    82,    84,    86,    88,    90,    94,    98,   102,   106,
     110,   114,   117,   120,   124,   128,   135,   140,   145,   150,
     155,   160,   165,   169,   173,   177,   181,   185,   189,   191,
     193,   195,   197
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    -1,    -1,    52,    41,    51,    -1,
      52,    41,    -1,    58,    -1,     7,    42,    57,    43,    52,
      -1,     7,    43,    52,    -1,     8,    44,    58,    45,    -1,
      -1,    -1,     9,    46,    53,    56,    54,    47,    -1,    11,
      44,    58,    45,    46,    51,    47,    55,    -1,    14,    44,
      58,    45,    46,    51,    47,    -1,    13,    44,    58,    45,
      46,    51,    47,    55,    -1,    12,    46,    51,    47,    -1,
      -1,    51,    -1,    51,    10,    58,    41,    -1,    10,    58,
      41,    -1,    15,    -1,    16,    -1,    18,    -1,    17,    -1,
      44,    58,    45,    -1,    58,    30,    58,    -1,    58,    29,
      58,    -1,    58,    31,    58,    -1,    58,    32,    58,    -1,
      58,    33,    58,    -1,    58,    34,    -1,    29,    58,    -1,
      58,    38,    58,    -1,    58,    39,    58,    -1,    20,    44,
      58,    48,    58,    45,    -1,    19,    44,    58,    45,    -1,
      21,    44,    58,    45,    -1,    22,    44,    58,    45,    -1,
      37,    44,    58,    45,    -1,    36,    44,    58,    45,    -1,
      35,    44,    58,    45,    -1,    58,    23,    58,    -1,    58,
      24,    58,    -1,    58,    25,    58,    -1,    58,    26,    58,
      -1,    58,    27,    58,    -1,    58,    28,    58,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,     7,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   215,   215,   216,   219,   220,   223,   224,   225,   226,
     227,   227,   227,   228,   229,   232,   233,   234,   237,   238,
     239,   242,   243,   244,   245,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_VAL", "REAL_VAL", "BOOLEAN_VAL",
  "STRING_VAL", "ID", "PRINT", "BLOCK", "RETURN", "IF", "ELSE", "ELIF",
  "WHILE", "INT", "REAL", "BOOLEAN", "STRING", "LN", "LOG", "LOG10",
  "SQRT", "GT", "LT", "GE", "LE", "EQ", "NE", "'-'", "'+'", "'*'", "'/'",
  "'^'", "'!'", "TAN", "COS", "SIN", "'.'", "'|'", "UMINUS", "';'", "':'",
  "'='", "'('", "')'", "'{'", "'}'", "','", "$accept", "program",
  "statements", "statement", "@1", "@2", "else", "stmt_block", "type",
  "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,    45,
      43,    42,    47,    94,    33,   284,   285,   286,    46,   124,
     287,    59,    58,    61,    40,    41,   123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      53,    54,    52,    52,    52,    55,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     2,     1,     5,     3,     4,
       0,     0,     6,     8,     7,     8,     4,     0,     1,     4,
       3,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     6,     4,     4,     4,     4,
       4,     4,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    48,    49,    50,    51,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       2,     0,     6,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,    52,    32,     0,     0,     0,     0,     1,
       5,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,    21,    22,    24,    23,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     4,    42,    43,    44,    45,    46,    47,
      27,    26,    28,    29,    30,    33,    34,     0,     9,     0,
      18,    11,     0,     0,    36,     0,    37,    38,    41,    40,
      39,     7,     0,     0,     0,     0,     0,     0,    20,     0,
      12,     0,     0,    35,    19,    17,    14,     0,     0,    13,
       0,     0,     0,     0,    16,     0,     0,     0,    17,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    20,    21,    62,   104,   119,    91,    59,    22
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -42
static const yytype_int16 yypact[] =
{
      89,   -42,   -42,   -42,   -42,   -33,   -41,   -34,    -6,    -3,
      -2,    -1,    12,    21,   109,    22,    25,    27,   109,    57,
     -42,    31,   471,   -10,    89,   109,   -42,   109,   109,   109,
     109,   109,   109,   -42,   -42,   109,   109,   109,   157,   -42,
      89,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   -42,   109,   109,   -42,   -42,   -42,   -42,    30,
     -42,   180,    41,   203,   226,   249,   131,   272,   295,   318,
     341,   364,   -42,   -42,   482,   482,   482,   482,   482,   482,
     103,   103,    20,    20,   -19,   -42,   -42,    89,   -42,   109,
      64,   -42,    33,    34,   -42,   109,   -42,   -42,   -42,   -42,
     -42,   -42,   433,   109,    36,    89,    89,   387,   -42,   452,
     -42,    37,    39,   -42,   -42,    13,   -42,    44,    43,   -42,
      89,   109,    52,   410,   -42,    45,    89,    54,    13,   -42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -42,   -42,   -38,   -23,   -42,   -42,   -26,   -42,   -42,   -14
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    60,    73,    25,    38,    55,    56,    57,    58,    23,
      24,    61,    26,    63,    64,    65,    66,    67,    68,    53,
      54,    69,    70,    71,    90,   117,   118,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    27,    85,
      86,    28,    29,    30,     1,     2,     3,     4,     5,     6,
       7,    89,     8,    51,    52,     9,    31,    39,    53,    54,
      10,    11,    12,    13,   101,    32,    35,   111,   112,    36,
      14,    37,    40,    87,   103,   102,    15,    16,    17,   105,
     106,   107,   122,   110,   115,    18,   116,   121,   127,   109,
     120,   126,     1,     2,     3,     4,     5,     6,     7,   124,
       8,   128,   129,     9,     0,     0,     0,   123,    10,    11,
      12,    13,     1,     2,     3,     4,    33,     0,    14,     0,
       0,     0,     0,     0,    15,    16,    17,     0,    10,    11,
      12,    13,     0,    18,    49,    50,    51,    52,    14,     0,
       0,    53,    54,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,    18,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,    72,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,    53,    54,
       0,     0,     0,     0,     0,    88,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,    54,     0,     0,     0,     0,     0,    92,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,    54,     0,     0,     0,     0,
       0,    93,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,    53,    54,     0,
       0,     0,     0,     0,    94,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,    54,     0,     0,     0,     0,     0,    96,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    53,    54,     0,     0,     0,     0,     0,
      97,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,     0,    53,    54,     0,     0,
       0,     0,     0,    98,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
      54,     0,     0,     0,     0,     0,    99,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,     0,    53,    54,     0,     0,     0,     0,     0,   100,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,    53,    54,     0,     0,     0,
       0,     0,   113,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,    53,    54,
       0,     0,     0,     0,     0,   125,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,    54,     0,   108,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,    54,     0,   114,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
      54,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,    54
};

static const yytype_int16 yycheck[] =
{
      14,    24,    40,    44,    18,    15,    16,    17,    18,    42,
      43,    25,    46,    27,    28,    29,    30,    31,    32,    38,
      39,    35,    36,    37,    62,    12,    13,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    44,    53,
      54,    44,    44,    44,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    33,    34,    14,    44,     0,    38,    39,
      19,    20,    21,    22,    87,    44,    44,   105,   106,    44,
      29,    44,    41,    43,    10,    89,    35,    36,    37,    46,
      46,    95,   120,    47,    47,    44,    47,    44,   126,   103,
      46,    46,     3,     4,     5,     6,     7,     8,     9,    47,
      11,    47,   128,    14,    -1,    -1,    -1,   121,    19,    20,
      21,    22,     3,     4,     5,     6,     7,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    -1,    19,    20,
      21,    22,    -1,    44,    31,    32,    33,    34,    29,    -1,
      -1,    38,    39,    -1,    35,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    -1,    -1,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    -1,
      -1,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    39,    -1,    41,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39,    -1,    41,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      39,    29,    30,    31,    32,    33,    34,    -1,    -1,    -1,
      38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    11,    14,
      19,    20,    21,    22,    29,    35,    36,    37,    44,    50,
      51,    52,    58,    42,    43,    44,    46,    44,    44,    44,
      44,    44,    44,     7,    58,    44,    44,    44,    58,     0,
      41,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    38,    39,    15,    16,    17,    18,    57,
      52,    58,    53,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    45,    51,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    43,    45,    10,
      51,    56,    45,    45,    45,    48,    45,    45,    45,    45,
      45,    52,    58,    10,    54,    46,    46,    58,    41,    58,
      47,    51,    51,    45,    41,    47,    47,    12,    13,    55,
      46,    44,    51,    58,    47,    45,    46,    51,    47,    55
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 215 "calc-yacc.y"
    { exit(0); }
    break;

  case 3:
#line 216 "calc-yacc.y"
    { exit(0); }
    break;

  case 6:
#line 223 "calc-yacc.y"
    { (yyval.statement_result) = build_statement_result_from((yyvsp[(1) - (1)].expr_result)); }
    break;

  case 7:
#line 224 "calc-yacc.y"
    { initial_assignment((yyvsp[(1) - (5)].lexeme), (yyvsp[(3) - (5)].type), (yyvsp[(5) - (5)].statement_result)); (yyval.statement_result) = build_void_statement_result(); }
    break;

  case 8:
#line 225 "calc-yacc.y"
    { existing_assignment((yyvsp[(1) - (3)].lexeme), (yyvsp[(3) - (3)].statement_result)); (yyval.statement_result) = build_void_statement_result(); }
    break;

  case 9:
#line 226 "calc-yacc.y"
    { print_expr_result((yyvsp[(3) - (4)].expr_result)); (yyval.statement_result) = build_void_statement_result(); }
    break;

  case 10:
#line 227 "calc-yacc.y"
    { new_scope(); }
    break;

  case 11:
#line 227 "calc-yacc.y"
    { destroy_scope(); }
    break;

  case 12:
#line 227 "calc-yacc.y"
    { (yyval.statement_result) = (yyvsp[(4) - (6)].statement_result); }
    break;

  case 13:
#line 228 "calc-yacc.y"
    { (yyval.statement_result) = build_void_statement_result(); }
    break;

  case 14:
#line 229 "calc-yacc.y"
    { (yyval.statement_result) = build_void_statement_result(); }
    break;

  case 18:
#line 237 "calc-yacc.y"
    { (yyval.statement_result) = build_void_statement_result(); }
    break;

  case 19:
#line 238 "calc-yacc.y"
    { (yyval.statement_result) = build_statement_result_from((yyvsp[(3) - (4)].expr_result)); }
    break;

  case 20:
#line 239 "calc-yacc.y"
    { (yyval.statement_result) = build_statement_result_from((yyvsp[(2) - (3)].expr_result)); }
    break;

  case 21:
#line 242 "calc-yacc.y"
    { (yyval.type) = INT_TYPE; }
    break;

  case 22:
#line 243 "calc-yacc.y"
    { (yyval.type) = REAL_TYPE; }
    break;

  case 23:
#line 244 "calc-yacc.y"
    { (yyval.type) = STRING_TYPE; }
    break;

  case 24:
#line 245 "calc-yacc.y"
    { (yyval.type) = BOOLEAN_TYPE; }
    break;

  case 25:
#line 248 "calc-yacc.y"
    { (yyval.expr_result) = (yyvsp[(2) - (3)].expr_result); }
    break;

  case 26:
#line 249 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), SUM_OP); }
    break;

  case 27:
#line 250 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), DIF_OP); }
    break;

  case 28:
#line 251 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), MOL_OP); }
    break;

  case 29:
#line 252 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), DIV_OP); }
    break;

  case 30:
#line 253 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), EXP_OP); }
    break;

  case 31:
#line 254 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(1) - (2)].expr_result), FAC_OP); }
    break;

  case 32:
#line 255 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(2) - (2)].expr_result),  NEG_OP); }
    break;

  case 33:
#line 256 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), CON_OP); }
    break;

  case 34:
#line 257 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), CON_SPACE_OP); }
    break;

  case 35:
#line 258 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(3) - (6)].expr_result), (yyvsp[(5) - (6)].expr_result), LOG_OP); }
    break;

  case 36:
#line 259 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(3) - (4)].expr_result), LN_OP); }
    break;

  case 37:
#line 260 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(3) - (4)].expr_result), LOG10_OP); }
    break;

  case 38:
#line 261 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(3) - (4)].expr_result), SQRT_OP); }
    break;

  case 39:
#line 262 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(3) - (4)].expr_result), SIN_OP); }
    break;

  case 40:
#line 263 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(3) - (4)].expr_result), COS_OP); }
    break;

  case 41:
#line 264 "calc-yacc.y"
    { (yyval.expr_result) = single_operation((yyvsp[(3) - (4)].expr_result), TAN_OP); }
    break;

  case 42:
#line 265 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), GT_OP); }
    break;

  case 43:
#line 266 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), LT_OP); }
    break;

  case 44:
#line 267 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), GE_OP); }
    break;

  case 45:
#line 268 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), LE_OP); }
    break;

  case 46:
#line 269 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), EQ_OP); }
    break;

  case 47:
#line 270 "calc-yacc.y"
    { (yyval.expr_result) = operation((yyvsp[(1) - (3)].expr_result), (yyvsp[(3) - (3)].expr_result), NE_OP); }
    break;

  case 48:
#line 271 "calc-yacc.y"
    { TypeData data; data.int_value = (yyvsp[(1) - (1)].int_value); (yyval.expr_result) = build_expr_result(INT_TYPE, data); }
    break;

  case 49:
#line 272 "calc-yacc.y"
    { TypeData data; data.real_value = (yyvsp[(1) - (1)].real_value); (yyval.expr_result) = build_expr_result(REAL_TYPE, data); }
    break;

  case 50:
#line 273 "calc-yacc.y"
    { TypeData data; data.boolean_value = (yyvsp[(1) - (1)].boolean_value) == 0 ? FALSE : TRUE; (yyval.expr_result) = build_expr_result(BOOLEAN_TYPE, data); }
    break;

  case 51:
#line 274 "calc-yacc.y"
    { TypeData data; data.string_value = (yyvsp[(1) - (1)].string_value); (yyval.expr_result) = build_expr_result(STRING_TYPE, data); }
    break;

  case 52:
#line 275 "calc-yacc.y"
    { SymbolTableEntry *entry = lookup((yyvsp[(1) - (1)].lexeme)); (yyval.expr_result) = build_expr_result(entry->type, entry->data); }
    break;


/* Line 1267 of yacc.c.  */
#line 1963 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 278 "calc-yacc.y"


#include "lex.yy.c"

/**
      Checks if two types are equal, otherwise throws an error.
*/
void check_types_eq(Type type1, Type type2) {
      if (type1 != type2) {
            char message[ERROR_BUFFER_SIZE];
            sprintf(message, "incompatible types\nrequired: %s\nfound: %s", type_to_string(type1), type_to_string(type2));
            yyerror(message);
      }
}

/**
      Converts a type to its string representation.
*/
char *type_to_string(Type type) {
      switch (type) {
            case VOID_TYPE: return "void";
            case INT_TYPE: return "int";
            case REAL_TYPE: return "real";
            case STRING_TYPE: return "string";
            case BOOLEAN_TYPE: return "Boolean";
            default: return "unknown";
      }
}

/**
      Gets the program which is currently running.

      In this case we have one single MAIN program which has linked to it the
      current scope in execution.      
*/
Program *get_program() {
      if (MAIN == NULL) MAIN = malloc(sizeof(Program));

      return MAIN;
}

/**
      Destroys the current scope, together with all the symbol table entries.

      If there exist an outer scope we will set that as the new current scope for
      the program.      
*/
void destroy_scope() {
      Program *program = get_program();
      Scope *current_scope = program->current;

      if (current_scope != NULL) {
            SymbolTable *symbol_table = current_scope->symbol_table;
            SymbolTableNode *current_node = symbol_table->head;

            while (current_node != NULL) {
                  SymbolTableNode *next = current_node->next;
                  free(current_node->entry);
                  free(current_node);
                  current_node = next;
            }

            program->current = current_scope->outer;
            free(current_scope);
      }
}

/**
      Creates a new scope from the current scope.

      If there exist a current scope it will link that scope as the outer scope
      of the newly created scope.
*/
void new_scope() {
      Program *program = get_program();

      Scope *scope = malloc(sizeof(Scope));
      scope->symbol_table = init_symbol_table();

      if (program->current == NULL) {
            // We do not have any active scope, create the main scope.
            scope->outer = NULL;
            program->current = scope;
      } else {
            // We already have one scope, we need to update this scope as the current.
            scope->outer = program->current;
            program->current = scope;
      }
}

/**
      Initialized the symbol table in memory.      
*/
SymbolTable *init_symbol_table() {
      SymbolTable *symbol_table = malloc(sizeof(SymbolTable));
      return symbol_table;
}

/**
      Gets the symbol table at a given scope index, where the index 0 corresponds
      to the current scope and the other index + 1 will correspond to the outer scopes.
*/
SymbolTable *get_symbol_table(int scope_index) {
      if (MAIN == NULL) new_scope();

      int index = 0;
      Program *program = get_program();
      Scope *current_scope = program->current;
      while (current_scope != NULL && index < scope_index) {
            current_scope = current_scope->outer;
            index++;
      }

      return current_scope == NULL ? NULL : current_scope->symbol_table;
}

/**
      Inserts an entry into the symbol table.      
*/
void insert(char *name, Type type, TypeData data) {
      SymbolTable *symbol_table = get_symbol_table(0);

      SymbolTableEntry *entry = malloc(sizeof(SymbolTableEntry));
      entry->name = name;
      entry->type = type;
      entry->data = data;

      SymbolTableNode *node = malloc(sizeof(SymbolTableNode));
      node->entry = entry;

      if (search(name, 1) != NULL) {
            char message[ERROR_BUFFER_SIZE];
            sprintf(message, "variable %s is already declared in this scope", name);
            yyerror(message);
      }
      
      if (symbol_table->head == NULL) {
            // The symbol table is empty, initialize it.
            symbol_table->head = node;
            symbol_table->tail = node;
      } else {
            // The symbol table is non empty, append the value to it. 
            symbol_table->tail->next = node;
            symbol_table->tail = node;
      }
}

/**
      Updates an entry into the symbol table.

      This update can be done only if the new type and old type are the same.      
*/
void update(char *name, Type type, TypeData data) {
      SymbolTableEntry *found_entry = search(name, 0);

      if (found_entry == NULL) {
            char message[ERROR_BUFFER_SIZE];
            sprintf(message, "the variable %s is not in this scope", name);
            yyerror(message);
      }

      check_types_eq(found_entry->type, type);

      found_entry->data = data;
}

/**
      Searches for a symbol table entry by name.

      If current only is set to 1 this means that we will search only in the
      symbol table for the current scope, otherwise it will check in the outer scopes.      
*/
SymbolTableEntry *search(char *name, int current_only) {
      int scope_index = 0;
      SymbolTable *symbol_table = NULL;

      do {
            symbol_table = get_symbol_table(scope_index);

            if (symbol_table != NULL) {
                  SymbolTableNode *current = symbol_table->head;

                  while (current != NULL) {
                        if (strcmp(current->entry->name, name) == 0) 
                              return current->entry;

                        current = current->next;
                  }

                  if (current_only == 1) {
                        return NULL;
                  }

                  scope_index++;
            }
      } while (symbol_table != NULL);

      return NULL;
}

/**
      Looks up for a symbol table entry by name.      
*/
SymbolTableEntry *lookup(char *name) {
      SymbolTableEntry *found_entry = search(name, 0);

      if (found_entry == NULL) {
            char message[ERROR_BUFFER_SIZE];
            sprintf(message, "the variable %s is not in this scope", name);
            yyerror(message);
      }

      return found_entry;
}

/**
      Deletes an entry in the symbol table by name.      
*/
void delete(char *name) {
      SymbolTable *symbol_table = get_symbol_table(0);

      if (strcmp(symbol_table->head->entry->name, name) == 0) {
            // If we want to delete the head of the list we need to replace it.
            SymbolTableNode *head = symbol_table->head;
            symbol_table->head = head->next;
            free(head);
      } else {
            SymbolTableNode *prev = NULL;
            SymbolTableNode *current = symbol_table->head;

            // We search for the value which we want to delete and we keep his previous element.
            while (current != NULL && strcmp(current->entry->name, name) != 0) {
                  prev = current;
                  current = current->next;
            }

            if (current != NULL) {
                  // If we delete the last element we update the tail.
                  if (current->next == NULL) 
                        symbol_table->tail = prev;

                  prev->next = current->next;
                  free(current);
            }
      }
}

void print_symbol_table(SymbolTable *symbol_table) {
      SymbolTableNode *current = symbol_table->head;

      while (current != NULL) {
            printf("Variable: %s\n", current->entry->name);
            current = current->next;
      }
}

void initial_assignment(char *variable_name, Type variable_type, StatementResult *statement_result) {
      check_types_eq(variable_type, statement_result->type);
      insert(variable_name, variable_type, statement_result->data);
}

void existing_assignment(char *variable_name, StatementResult *statement_result) {
      update(variable_name, statement_result->type, statement_result->data);
}

StatementResult *build_statement_result(Type type, TypeData data) {
      StatementResult *statement_result = malloc(sizeof(StatementResult));
      statement_result->type = type;
      statement_result->data = data;

      return statement_result;
}

StatementResult *build_statement_result_from(ExprResult *expr_result) {
      return build_statement_result(expr_result->type, expr_result->data);
}

StatementResult *build_void_statement_result() {
      TypeData data;
      return build_statement_result(VOID_TYPE, data);
}

ExprResult *build_expr_result(Type type, TypeData data) {
      ExprResult *expr_result = malloc(sizeof(ExprResult));
      expr_result->type = type;
      expr_result->data = data;
      
      return expr_result;
}

ExprResult *operation(ExprResult *left, ExprResult *right, Operation operation) {
      switch (operation) {
            case SUM_OP: 
                  return sum_op(left, right);
            case DIF_OP: 
                  return dif_op(left, right);
            case MOL_OP: 
                  return mol_op(left, right);
            case DIV_OP: 
                  return div_op(left, right);
            case EXP_OP: 
                  return exp_op(left, right);
            case LOG_OP: 
                  return log_op(left, right);
            case CON_OP: 
                  return con_op(left, right);
            case CON_SPACE_OP: 
                  return con_space_op(left, right);
            case EQ_OP: 
                  return eq_op(left, right);   
            case NE_OP: 
                  return ne_op(left, right); 
            case GT_OP: 
                  return gt_op(left, right);  
            case LT_OP: 
                  return lt_op(left, right);   
            case GE_OP: 
                  return ge_op(left, right);   
            case LE_OP: 
                  return le_op(left, right); 
            default:
                  return left;
      }
}

ExprResult *single_operation(ExprResult *left, Operation operation) {
      switch (operation) {
            case NEG_OP: 
                  return neg_op(left);
            case FAC_OP: 
                  return fac_op(left);
            case LN_OP: 
                  return ln_op(left);
            case LOG10_OP: 
                  return log10_op(left);
            case SQRT_OP: 
                  return sqrt_op(left);
            case SIN_OP: 
                  return sin_op(left);
            case COS_OP: 
                  return cos_op(left);
            case TAN_OP: 
                  return tan_op(left);
            default:
                  return left;
      }
}

ExprResult *sum_op(ExprResult *left, ExprResult *right) {
      ExprResult *sum_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            sum_op->type = INT_TYPE;
            sum_op->data.int_value = left->data.int_value + right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            sum_op->type = REAL_TYPE;
            sum_op->data.real_value = left->data.int_value + right->data.real_value;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            sum_op->type = REAL_TYPE;
            sum_op->data.real_value = left->data.real_value + right->data.int_value;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            sum_op->type = REAL_TYPE;
            sum_op->data.real_value = left->data.real_value + right->data.real_value;
      } else {
            yyerror("invalid type/s for expression +");
      }

      return sum_op;
}

ExprResult *dif_op(ExprResult *left, ExprResult *right) {
      ExprResult *dif_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            dif_op->type = INT_TYPE;
            dif_op->data.int_value = left->data.int_value - right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            dif_op->type = REAL_TYPE;
            dif_op->data.real_value = left->data.int_value - right->data.real_value;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            dif_op->type = REAL_TYPE;
            dif_op->data.real_value = left->data.real_value - right->data.int_value;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            dif_op->type = REAL_TYPE;
            dif_op->data.real_value = left->data.real_value - right->data.real_value;
      } else {
            yyerror("invalid type/s for expression -");
      }

      return dif_op;
}

ExprResult *mol_op(ExprResult *left, ExprResult *right) {
      ExprResult *mol_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            mol_op->type = INT_TYPE;
            mol_op->data.int_value = left->data.int_value * right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            mol_op->type = REAL_TYPE;
            mol_op->data.real_value = left->data.int_value * right->data.real_value;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            mol_op->type = REAL_TYPE;
            mol_op->data.real_value = left->data.real_value * right->data.int_value;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            mol_op->type = REAL_TYPE;
            mol_op->data.real_value = left->data.real_value * right->data.real_value;
      } else {
            yyerror("invalid type/s for expression *");
      }

      return mol_op;
}

ExprResult *div_op(ExprResult *left, ExprResult *right) {
      ExprResult *div_op = malloc(sizeof(ExprResult));

      if ((right->type == INT_TYPE && right->data.int_value == 0) || (right->type == REAL_TYPE && right->data.real_value == 0)){
            yyerror("cannot divide by 0");
      } else if (left->type == INT_TYPE && right->type == INT_TYPE) {
            div_op->type = INT_TYPE;
            div_op->data.int_value = left->data.int_value / right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            div_op->type = REAL_TYPE;
            div_op->data.real_value = left->data.int_value / right->data.real_value;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            div_op->type = REAL_TYPE;
            div_op->data.real_value = left->data.real_value / right->data.int_value;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            div_op->type = REAL_TYPE;
            div_op->data.real_value = left->data.real_value / right->data.real_value;
      } else {
            yyerror("invalid type/s for expression /");
      }

      return div_op;
}

ExprResult *exp_op(ExprResult *left, ExprResult *right) {
      ExprResult *exp_op = malloc(sizeof(ExprResult));

      if (((left->type == INT_TYPE && left->data.int_value == 0) || (left->type == REAL_TYPE && left->data.real_value == 0)) 
            && ((right->type == INT_TYPE && right->data.int_value < 0) || (right->type == REAL_TYPE && right->data.real_value < 0))){
            yyerror("result equal to infinity");
      } else if (left->type == INT_TYPE && right->type == INT_TYPE) {
            exp_op->type = INT_TYPE;
            exp_op->data.int_value = pow(left->data.int_value, right->data.int_value);
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            exp_op->type = REAL_TYPE;
            exp_op->data.real_value = pow(left->data.int_value, right->data.real_value);
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            exp_op->type = REAL_TYPE;
            exp_op->data.real_value = pow(left->data.real_value, right->data.int_value);
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            exp_op->type = REAL_TYPE;
            exp_op->data.real_value = pow(left->data.real_value, right->data.real_value);
      } else {
            yyerror("invalid type/s for expression ^");
      }

      return exp_op;
}

ExprResult *log_op(ExprResult *left, ExprResult *right) {
      ExprResult *log_op = malloc(sizeof(ExprResult));

      if (((left->type == INT_TYPE && left->data.int_value <= 0 ) || (left->type == REAL_TYPE && left->data.real_value <= 0 )) 
            || ((right->type == INT_TYPE && (right->data.int_value <= 0 || right->data.int_value == 1)) || (right->type == REAL_TYPE && (right->data.real_value <= 0 || right->data.int_value == 1)))){
            yyerror("invalid input for expression log");
      } else if (left->type == INT_TYPE && right->type == INT_TYPE) {
            log_op->type = REAL_TYPE;
            log_op->data.real_value = log(left->data.int_value) / log(right->data.int_value);
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            log_op->type = REAL_TYPE;
            log_op->data.real_value = log(left->data.int_value) / log(right->data.real_value);
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            log_op->type = REAL_TYPE;
            log_op->data.real_value = log(left->data.real_value) / log(right->data.int_value);
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            log_op->type = REAL_TYPE;
            log_op->data.real_value = log(left->data.real_value) / log(right->data.real_value);
      } else {
            yyerror("invalid type/s for expression log");
      }

      return log_op;
}

ExprResult *eq_op(ExprResult *left, ExprResult *right) {
      ExprResult *eq_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            eq_op->type = BOOLEAN_TYPE;
            eq_op->data.boolean_value = left->data.int_value == right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            eq_op->type = BOOLEAN_TYPE;
            eq_op->data.boolean_value = fabs(left->data.int_value - right->data.real_value) < EPSILON;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            eq_op->type = BOOLEAN_TYPE;
            eq_op->data.boolean_value = fabs(left->data.real_value - right->data.int_value) < EPSILON;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            eq_op->type = BOOLEAN_TYPE;
            eq_op->data.boolean_value = fabs(left->data.real_value - right->data.real_value) < EPSILON;
      } else {
            yyerror("invalid type/s for expression ==");
      }

      return eq_op;
}

ExprResult *ne_op(ExprResult *left, ExprResult *right) {
      ExprResult *ne_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            ne_op->type = BOOLEAN_TYPE;
            ne_op->data.boolean_value = left->data.int_value != right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            ne_op->type = BOOLEAN_TYPE;
            ne_op->data.boolean_value = !(fabs(left->data.int_value - right->data.real_value) < EPSILON);
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            ne_op->type = BOOLEAN_TYPE;
            ne_op->data.boolean_value = !(fabs(left->data.real_value - right->data.int_value) < EPSILON);
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            ne_op->type = BOOLEAN_TYPE;
            ne_op->data.boolean_value = !(fabs(left->data.real_value - right->data.real_value) < EPSILON);
      } else {
            yyerror("invalid type/s for expression !=");
      }

      return ne_op;
}

ExprResult *gt_op(ExprResult *left, ExprResult *right) {
      ExprResult *gt_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            gt_op->type = BOOLEAN_TYPE;
            gt_op->data.boolean_value = left->data.int_value > right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            gt_op->type = BOOLEAN_TYPE;
            gt_op->data.boolean_value = left->data.int_value > right->data.real_value;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            gt_op->type = BOOLEAN_TYPE;
            gt_op->data.boolean_value = left->data.real_value > right->data.int_value;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            gt_op->type = BOOLEAN_TYPE;
            gt_op->data.boolean_value = left->data.real_value > right->data.real_value;
      } else {
            yyerror("invalid type/s for expression >");
      }

      return gt_op;
}

ExprResult *lt_op(ExprResult *left, ExprResult *right) {
      ExprResult *lt_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            lt_op->type = BOOLEAN_TYPE;
            lt_op->data.boolean_value = left->data.int_value < right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            lt_op->type = BOOLEAN_TYPE;
            lt_op->data.boolean_value = left->data.int_value < right->data.real_value;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            lt_op->type = BOOLEAN_TYPE;
            lt_op->data.boolean_value = left->data.real_value < right->data.int_value;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            lt_op->type = BOOLEAN_TYPE;
            lt_op->data.boolean_value = left->data.real_value < right->data.real_value;
      } else {
            yyerror("invalid type/s for expression <");
      }

      return lt_op;
}

ExprResult *ge_op(ExprResult *left, ExprResult *right) {
      ExprResult *ge_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            ge_op->type = BOOLEAN_TYPE;
            ge_op->data.boolean_value = left->data.int_value >= right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            ge_op->type = BOOLEAN_TYPE;
            ge_op->data.boolean_value = left->data.int_value > right->data.real_value || fabs(left->data.int_value - right->data.real_value) < EPSILON;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            ge_op->type = BOOLEAN_TYPE;
            ge_op->data.boolean_value = left->data.real_value > right->data.int_value || fabs(left->data.real_value - right->data.int_value) < EPSILON;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            ge_op->type = BOOLEAN_TYPE;
            ge_op->data.boolean_value = left->data.real_value > right->data.real_value || fabs(left->data.real_value - right->data.real_value) < EPSILON;
      } else {
            yyerror("invalid type/s for expression >=");
      }

      return ge_op;
}

ExprResult *le_op(ExprResult *left, ExprResult *right) {
      ExprResult *le_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE && right->type == INT_TYPE) {
            le_op->type = BOOLEAN_TYPE;
            le_op->data.boolean_value = left->data.int_value <= right->data.int_value;
      } else if (left->type == INT_TYPE && right->type == REAL_TYPE) {
            le_op->type = BOOLEAN_TYPE;
            le_op->data.boolean_value = left->data.int_value < right->data.real_value || fabs(left->data.int_value - right->data.real_value) < EPSILON;
      } else if (left->type == REAL_TYPE && right->type == INT_TYPE) {
            le_op->type = BOOLEAN_TYPE;
            le_op->data.boolean_value = left->data.real_value < right->data.int_value || fabs(left->data.real_value - right->data.int_value) < EPSILON;
      } else if (left->type == REAL_TYPE && right->type == REAL_TYPE) {
            le_op->type = BOOLEAN_TYPE;
            le_op->data.boolean_value = left->data.real_value < right->data.real_value || fabs(left->data.real_value - right->data.real_value) < EPSILON;
      } else {
            yyerror("invalid type/s for expression <=");
      }

      return le_op;
}

ExprResult *con_op(ExprResult *left, ExprResult *right) {
      ExprResult *con_op = malloc(sizeof(ExprResult));

      if (left->type == STRING_TYPE && right->type == STRING_TYPE) {
            con_op->type = STRING_TYPE;
            char *new_str;
            new_str = malloc(strlen(left->data.string_value) + strlen(right->data.string_value));
            new_str[0] = '\0';
            strcat(new_str, left->data.string_value);
      
            strcat(new_str, right->data.string_value);
            con_op->data.string_value = new_str;
      } else {
            yyerror("invalid type/s for expression .");
      } 

      return con_op;
}

ExprResult *con_space_op(ExprResult *left, ExprResult *right) {
      ExprResult *con_op = malloc(sizeof(ExprResult));

      if (left->type == STRING_TYPE && right->type == STRING_TYPE) {
            con_op->type = STRING_TYPE;
            char *new_str;
            new_str = malloc(strlen(left->data.string_value) + 1 + strlen(right->data.string_value));
            new_str[0] = '\0';
            strcat(new_str, left->data.string_value);
            strcat(new_str, " ");
            strcat(new_str, right->data.string_value);
            con_op->data.string_value = new_str;
      } else {
            yyerror("invalid type/s for expression |");
      } 

      return con_op;
}

ExprResult *neg_op(ExprResult *left) {
      ExprResult *neg_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE) {
            neg_op->type = INT_TYPE;
            neg_op->data.int_value = -(left->data.int_value);
      } else if (left->type == REAL_TYPE) {
            neg_op->type = REAL_TYPE;
            neg_op->data.real_value = -(left->data.int_value);
      } else {
            yyerror("invalid type/s for expression -");
      }

      return neg_op;
}

ExprResult *fac_op(ExprResult *left) {
      ExprResult *fac_op = malloc(sizeof(ExprResult));
      
      if (left->type == INT_TYPE) {
            fac_op->type = INT_TYPE;
            int n = left->data.int_value;
            if (n < 0) yyerror("invalid type/s for expression !");

            int fact = 1;  
            for (int i = 1; i <= n; ++i) fact *= i;

            fac_op->data.int_value = fact;
      } else {
            yyerror("invalid type/s for expression !");
      }

      return fac_op;
}

ExprResult *ln_op(ExprResult *left) {
      ExprResult *ln_op = malloc(sizeof(ExprResult));

      if ((left->type == INT_TYPE && left->data.int_value <= 0) || (left->type == REAL_TYPE && left->data.real_value <= 0)){
            yyerror("cannot evaluate ln of negative numbers or 0");
      } else if (left->type == INT_TYPE) {
            ln_op->type = REAL_TYPE;
            ln_op->data.real_value = log(left->data.int_value);
      } else if (left->type == REAL_TYPE) {
            ln_op->type = REAL_TYPE;
            ln_op->data.real_value = log(left->data.int_value);
      } else {
            yyerror("invalid type/s for expression ln");
      }

      return ln_op;
}

ExprResult *log10_op(ExprResult *left) {
      ExprResult *log10_op = malloc(sizeof(ExprResult));

      if ((left->type == INT_TYPE && left->data.int_value <= 0) || (left->type == REAL_TYPE && left->data.real_value <= 0)){
            yyerror("cannot evaluate log of negative numbers or 0");
      } else if (left->type == INT_TYPE) {
            log10_op->type = REAL_TYPE;
            log10_op->data.real_value= log10(left->data.int_value);
      } else if (left->type == REAL_TYPE) {
            log10_op->type = REAL_TYPE;
            log10_op->data.real_value = log10(left->data.real_value);
      } else {
            yyerror("invalid type/s for expression log10");
      }

      return log10_op;
}

ExprResult *sqrt_op(ExprResult *left) {
      ExprResult *sqrt_op = malloc(sizeof(ExprResult));

      if ((left->type == INT_TYPE && left->data.int_value < 0) || (left->type == REAL_TYPE && left->data.real_value < 0)){
            yyerror("cannot evaluate sqrt of negative numbers");
      } else if (left->type == INT_TYPE) {
            sqrt_op->type = REAL_TYPE;
            sqrt_op->data.real_value= sqrt(left->data.int_value);
      } else if (left->type == REAL_TYPE) {
            sqrt_op->type = REAL_TYPE;
            sqrt_op->data.real_value = sqrt(left->data.real_value);
      } else {
            yyerror("invalid type/s for expression sqrt");
      }

      return sqrt_op;
}

ExprResult *sin_op(ExprResult *left) {
      ExprResult *sin_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE) {
            sin_op->type = REAL_TYPE;
            sin_op->data.real_value= sin(left->data.int_value);
      } else if (left->type == REAL_TYPE) {
            sin_op->type = REAL_TYPE;
            sin_op->data.real_value = sin(left->data.real_value);
      } else {
            yyerror("invalid type/s for expression sin");
      }

      return sin_op;
}

ExprResult *cos_op(ExprResult *left) {
      ExprResult *cos_op = malloc(sizeof(ExprResult));

      if (left->type == INT_TYPE) {
            cos_op->type = REAL_TYPE;
            cos_op->data.real_value= cos(left->data.int_value);
      } else if (left->type == REAL_TYPE) {
            cos_op->type = REAL_TYPE;
            cos_op->data.real_value = cos(left->data.real_value);
      } else {
            yyerror("invalid type/s for expression cos");
      }

      return cos_op;
}

ExprResult *tan_op(ExprResult *left) {
      ExprResult *tan_op = malloc(sizeof(ExprResult));

      if (left->type == REAL_TYPE && fabs((int)(left->data.real_value / (acos(-1.0) / 2))-(left->data.real_value / (acos(-1.0) / 2) ))< EPSILON){
            yyerror("result equal to infinity");
      } else if (left->type == INT_TYPE) {
            tan_op->type = REAL_TYPE;
            tan_op->data.real_value= tan(left->data.int_value);
      } else if (left->type == REAL_TYPE) {
            tan_op->type = REAL_TYPE;
            tan_op->data.real_value = tan(left->data.real_value);
      } else {
            yyerror("invalid type/s for expression tan");
      }

      return tan_op;
}

void print_expr_result(ExprResult *expr_result) {
	FILE *fp = fopen(OUTPUT_FILE, "a");

	switch (expr_result->type) {
	    case INT_TYPE:
		  fprintf(fp, "int: %i\n", expr_result->data.int_value);
		  break;
	    case REAL_TYPE:
		  fprintf(fp, "real: %f\n", expr_result->data.real_value);
		  break;
	    case STRING_TYPE:
		  fprintf(fp, "string: %s\n", expr_result->data.string_value);
		  break;
	    case BOOLEAN_TYPE:
		  fprintf(fp, "boolean: %s\n", expr_result->data.boolean_value == TRUE ? "true" : "false");
		  break;
	    default:
		  fprintf(fp, "unknown type\n");   
		  break;   
      }

      fclose(fp);
}

void yyerror(const char *s) {
    fprintf(stderr, "Error at %d: %s\n", yylineno, s);
    exit(0);
}

void parse(FILE *fileInput) {
      yyin = fileInput;

      while(feof(yyin) == 0) {
            yyparse();
      }
}

int main(int argc, char* argv[]) {
	FILE *fp = fopen(OUTPUT_FILE, "w");
	fclose (fp);

	FILE* fileInput;
	if((fileInput = fopen(argv[1], "r")) == NULL) {
	      printf("Error while reading the file, try again.\n");
	      exit(0);
	}

      // It is important here to initialize the global scope before
      // starting the parsing.
      new_scope();
	parse(fileInput);
} 
