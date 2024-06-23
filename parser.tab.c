
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void yyerror(const char* s);

    int identf = 0;
    

        struct ast{
            char* token;
            int id;
            int num;
            int type;
            struct ast** offspring; 
        };
    
    
    void init(struct ast** root){
        *root = malloc(sizeof(struct ast));
        (*root)->token = malloc(sizeof(strdup("root"))+1);
        strcpy((*root)->token,"root");
        (*root)->id = 0;
        (*root)->num = 0;
        (*root)->type = 0;
        (*root)->offspring = (struct ast**)malloc(10*sizeof(struct ast*));
        
    }
    void add(struct ast* parent, struct ast* child){
        parent->offspring[parent->num] = malloc(sizeof(*child));
        parent->offspring[parent->num] = child;
        parent->num = parent->num+1;
    }
    struct ast* createNode(char* token,int type){
        
        identf++;
        struct ast* node = malloc(sizeof(struct ast));
        node->token = malloc(sizeof(strdup(token))+1);
        strcpy(node->token,token);
        
        node->id = identf;
        node->num = 0;
        node->type = type;
        node->offspring = (struct ast**)malloc(10*sizeof(struct ast*));
        
        return node;
    }
    void printAST(struct ast* root){
        
        int n = root->num;
        printf("(%s, %d) -> (",root->token,root->id);
        int i=0;
        while(i<n){
            printf("%s, %d; ",root->offspring[i]->token,root->offspring[i]->id);
            i++;
        }
        printf(") \n" );
        i=0;
        while(i<n){
            printAST(root->offspring[i]);
            i++;
        }
    }
    struct ast* root;
    
    
    
    



/* Line 189 of yacc.c  */
#line 145 "parser.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_ID = 258,
     T_DEC = 259,
     T_HEX = 260,
     T_DOU = 261,
     T_PLUS = 262,
     T_MINUS = 263,
     T_STAR = 264,
     T_SLASH = 265,
     T_PERCENT = 266,
     T_LESS = 267,
     T_LESSEQ = 268,
     T_GREATER = 269,
     T_GREATEREQ = 270,
     T_ASSIGN = 271,
     T_EQ = 272,
     T_NEQ = 273,
     T_AND = 274,
     T_OR = 275,
     T_NOT = 276,
     T_SEMICOLON = 277,
     T_COMMA = 278,
     T_LPAREN = 279,
     T_RPAREN = 280,
     T_LET = 281,
     T_IN = 282,
     T_END = 283,
     T_SKIP = 284,
     T_IF = 285,
     T_THEN = 286,
     T_ELSE = 287,
     T_FI = 288,
     T_WHILE = 289,
     T_DO = 290,
     T_READ = 291,
     T_WRITE = 292,
     T_INT = 293,
     T_DOUBLE = 294,
     T_BOOL = 295,
     T_STRING = 296,
     T_INTCONST = 297,
     T_DOUBLECONST = 298,
     T_BOOLCONST = 299,
     T_STRCONST = 300,
     T_FUNCTION = 301,
     T_PARAMETER = 302,
     T_FUNCTIONEND = 303,
     T_RETURN = 304,
     T_MODULO = 305
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 74 "parser.y"

    double d_num;
    int i_num;
    float f_num;
    char* id;
    struct ast* tree;



/* Line 214 of yacc.c  */
#line 241 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 253 "parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   413

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  55
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    11,    16,    19,    23,    25,    28,
      31,    32,    37,    45,    51,    55,    59,    71,    79,    82,
      83,    85,    90,    98,   104,   108,   112,   124,   132,   134,
     136,   140,   144,   148,   152,   156,   160,   164,   168,   172,
     176,   180,   184,   188,   191,   195,   197,   199,   203,   205,
     207,   209,   211,   213,   215,   217
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    26,    54,    27,    56,    28,
      -1,    26,    27,    56,    28,    -1,    64,    55,    -1,    54,
      64,    55,    -1,     3,    -1,    55,     3,    -1,    56,    57,
      -1,    -1,     3,    16,    62,    22,    -1,    30,    62,    31,
      60,    32,    60,    33,    -1,    34,    62,    35,    60,    28,
      -1,    36,     3,    22,    -1,    37,    62,    22,    -1,    64,
      46,     3,    47,    54,    27,    61,    49,    62,    22,    48,
      -1,    46,     3,    47,    54,    27,    61,    48,    -1,    58,
      59,    -1,    -1,    29,    -1,     3,    16,    62,    22,    -1,
      30,    62,    31,    60,    32,    60,    33,    -1,    34,    62,
      35,    60,    28,    -1,    36,     3,    22,    -1,    37,    62,
      22,    -1,    64,    46,     3,    47,    54,    27,    61,    49,
      62,    22,    48,    -1,    46,     3,    47,    54,    27,    61,
      48,    -1,    58,    -1,    56,    -1,    62,    16,    62,    -1,
      62,    20,    62,    -1,    62,    19,    62,    -1,    62,    18,
      62,    -1,    62,    17,    62,    -1,    62,    14,    62,    -1,
      62,    13,    62,    -1,    62,    15,    62,    -1,    62,    12,
      62,    -1,    62,     7,    62,    -1,    62,     8,    62,    -1,
      62,     9,    62,    -1,    62,    10,    62,    -1,    21,    62,
      -1,    24,    62,    25,    -1,    63,    -1,     3,    -1,     3,
      47,    55,    -1,     4,    -1,     6,    -1,    44,    -1,    45,
      -1,    38,    -1,    39,    -1,    40,    -1,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   152,   152,   155,   167,   183,   192,   204,   208,   213,
     222,   230,   244,   245,   246,   247,   248,   249,   253,   253,
     255,   256,   257,   258,   259,   260,   261,   262,   265,   266,
     269,   270,   271,   272,   273,   274,   275,   276,   277,   279,
     293,   294,   295,   296,   298,   299,   302,   305,   308,   313,
     318,   319,   320,   321,   322,   323
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ID", "T_DEC", "T_HEX", "T_DOU",
  "T_PLUS", "T_MINUS", "T_STAR", "T_SLASH", "T_PERCENT", "T_LESS",
  "T_LESSEQ", "T_GREATER", "T_GREATEREQ", "T_ASSIGN", "T_EQ", "T_NEQ",
  "T_AND", "T_OR", "T_NOT", "T_SEMICOLON", "T_COMMA", "T_LPAREN",
  "T_RPAREN", "T_LET", "T_IN", "T_END", "T_SKIP", "T_IF", "T_THEN",
  "T_ELSE", "T_FI", "T_WHILE", "T_DO", "T_READ", "T_WRITE", "T_INT",
  "T_DOUBLE", "T_BOOL", "T_STRING", "T_INTCONST", "T_DOUBLECONST",
  "T_BOOLCONST", "T_STRCONST", "T_FUNCTION", "T_PARAMETER",
  "T_FUNCTIONEND", "T_RETURN", "T_MODULO", "$accept", "S", "program",
  "declarations", "ident_decl", "stat", "command", "stat1", "command1",
  "command_sequence1", "command_sequence", "expression", "constant",
  "type", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    61,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    63,    63,
      63,    63,    64,    64,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     5,     4,     2,     3,     1,     2,     2,
       0,     4,     7,     5,     3,     3,    11,     7,     2,     0,
       1,     4,     7,     5,     3,     3,    11,     7,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,    10,    52,    53,    54,    55,     0,
       0,     1,     0,    10,     0,     7,     5,     0,     4,     0,
       0,     0,     0,     0,     9,     0,     0,     6,     8,     0,
      46,    48,    49,     0,     0,    50,    51,     0,    45,     0,
       0,     0,     0,     0,     3,     0,     0,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    19,    14,    15,     0,     0,    11,    47,
      44,    39,    40,    41,    42,    38,    36,    35,    37,    30,
      34,    33,    32,    31,    28,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,    18,     0,    19,    13,
      10,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,    10,     0,    19,    19,    24,    25,     0,     0,
      12,    17,     0,    21,     0,     0,     0,     0,     0,    19,
      23,    10,     0,     0,     0,     0,    10,     0,    22,    27,
       0,    16,     0,     0,     0,    26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     9,    16,   110,    24,    84,    96,    85,
     111,    37,    38,    10
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -108
static const yytype_int16 yypact[] =
{
      -4,   -20,     8,  -108,  -108,  -108,  -108,  -108,  -108,    17,
       3,  -108,    57,  -108,     3,  -108,    25,    31,  -108,     6,
       6,    46,     6,    49,  -108,    13,    97,    25,  -108,     6,
      14,  -108,  -108,     6,     6,  -108,  -108,   196,  -108,   158,
      44,   250,    20,    60,  -108,   266,     3,  -108,   236,     6,
       6,     6,     6,     6,     6,     6,     6,     6,     6,     6,
       6,     6,  -108,  -108,  -108,  -108,   160,    21,  -108,    25,
    -108,    16,    16,  -108,  -108,   346,   346,   346,   346,   359,
     398,   398,   386,   373,   110,    38,    43,    42,   160,    56,
    -108,     6,     6,    74,     6,    83,  -108,    53,  -108,  -108,
    -108,    80,     6,   216,   172,    66,   282,    55,    86,    71,
     123,    58,  -108,   298,  -108,  -108,  -108,  -108,   160,    61,
    -108,  -108,    62,  -108,    73,    81,   156,   160,     6,  -108,
    -108,  -108,   324,   314,    79,    67,  -108,    68,  -108,  -108,
      65,  -108,     6,   330,    82,  -108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -108,  -108,  -108,   -65,     0,    41,  -108,  -108,  -108,   -50,
    -107,   -18,  -108,    -9
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int16 yytable[] =
{
      14,    87,    39,    25,    41,   122,    15,     4,    11,    30,
      31,    45,    32,    86,    27,    47,    48,    25,     5,     6,
       7,     8,     1,   101,   135,    51,    52,    33,    28,   140,
      34,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    13,    12,    69,    29,   109,    40,
      35,    36,    42,   126,    26,     5,     6,     7,     8,    43,
      17,    46,   132,    67,   124,   125,    64,    66,    88,   100,
      98,    99,   102,   103,   104,    97,   106,   105,    14,   134,
       5,     6,     7,     8,   113,    18,   107,    19,   116,   119,
       0,    20,    14,    21,    22,     5,     6,     7,     8,   108,
      17,    25,   118,    23,   120,   129,   121,   112,   127,   130,
     133,   128,   138,    89,   142,   139,   141,    14,     5,     6,
       7,     8,     0,    14,   143,    44,    17,    19,     0,     0,
     145,    20,     0,    21,    22,     5,     6,     7,     8,    90,
      91,     0,     0,    23,    92,     0,    93,    94,     5,     6,
       7,     8,     0,    19,     0,     0,    95,    20,     0,    21,
      22,     5,     6,     7,     8,    49,    50,    51,    52,    23,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    49,
      50,    51,    52,   131,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    63,     5,     6,     7,     8,     5,     6,
       7,     8,     0,    49,    50,    51,    52,   115,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
       0,     0,     0,    49,    50,    51,    52,    62,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,     0,     0,
       0,     0,     0,    49,    50,    51,    52,   114,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    49,    50,    51,
      52,    70,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     0,    65,    49,    50,    51,    52,     0,    53,    54,
      55,    56,    57,    58,    59,    60,    61,     0,    68,    49,
      50,    51,    52,     0,    53,    54,    55,    56,    57,    58,
      59,    60,    61,     0,   117,    49,    50,    51,    52,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     0,
     123,    49,    50,    51,    52,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,     0,   137,    49,    50,    51,
      52,     0,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   136,   144,    49,    50,    51,    52,     0,    -1,    -1,
      -1,    -1,     5,     6,     7,     8,    49,    50,    51,    52,
       0,    53,    54,    55,    56,    -1,    58,    59,    60,    61,
      49,    50,    51,    52,     0,    53,    54,    55,    56,     0,
      58,    59,    60,    49,    50,    51,    52,     0,    53,    54,
      55,    56,     0,    58,    59,    49,    50,    51,    52,     0,
      53,    54,    55,    56
};

static const yytype_int16 yycheck[] =
{
       9,    66,    20,    12,    22,   112,     3,    27,     0,     3,
       4,    29,     6,    63,    14,    33,    34,    26,    38,    39,
      40,    41,    26,    88,   131,     9,    10,    21,     3,   136,
      24,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    27,     4,    46,    16,    98,     3,
      44,    45,     3,   118,    13,    38,    39,    40,    41,    46,
       3,    47,   127,     3,   114,   115,    22,    47,    47,    27,
      32,    28,    16,    91,    92,    84,    94,     3,    87,   129,
      38,    39,    40,    41,   102,    28,     3,    30,    22,     3,
      -1,    34,   101,    36,    37,    38,    39,    40,    41,    46,
       3,   110,    47,    46,    33,    32,    48,    27,    47,    28,
     128,    49,    33,     3,    49,    48,    48,   126,    38,    39,
      40,    41,    -1,   132,   142,    28,     3,    30,    -1,    -1,
      48,    34,    -1,    36,    37,    38,    39,    40,    41,    29,
      30,    -1,    -1,    46,    34,    -1,    36,    37,    38,    39,
      40,    41,    -1,    30,    -1,    -1,    46,    34,    -1,    36,
      37,    38,    39,    40,    41,     7,     8,     9,    10,    46,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     7,
       8,     9,    10,    27,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    35,    38,    39,    40,    41,    38,    39,
      40,    41,    -1,     7,     8,     9,    10,    35,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,     7,     8,     9,    10,    31,    12,    13,
      14,    15,    16,    17,    18,    19,    20,     7,     8,     9,
      10,    25,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    -1,    22,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,     7,     8,     9,    10,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    -1,
      22,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    -1,    22,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    27,    22,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    38,    39,    40,    41,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
       7,     8,     9,    10,    -1,    12,    13,    14,    15,    -1,
      17,    18,    19,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    -1,    17,    18,     7,     8,     9,    10,    -1,
      12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    52,    53,    27,    38,    39,    40,    41,    54,
      64,     0,    56,    27,    64,     3,    55,     3,    28,    30,
      34,    36,    37,    46,    57,    64,    56,    55,     3,    16,
       3,     4,     6,    21,    24,    44,    45,    62,    63,    62,
       3,    62,     3,    46,    28,    62,    47,    62,    62,     7,
       8,     9,    10,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    31,    35,    22,    22,    47,     3,    22,    55,
      25,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    58,    60,    60,    54,    47,     3,
      29,    30,    34,    36,    37,    46,    59,    64,    32,    28,
      27,    54,    16,    62,    62,     3,    62,     3,    46,    60,
      56,    61,    27,    62,    31,    35,    22,    22,    47,     3,
      33,    48,    61,    22,    60,    60,    54,    47,    49,    32,
      28,    27,    54,    62,    60,    61,    27,    22,    33,    48,
      61,    48,    49,    62,    22,    48
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 3:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {
        struct ast* tLet =  createNode("LET",0);
        struct ast* tIn =  createNode("IN",0);
        struct ast* tEnd =  createNode("END",0);
        struct ast* st = (yyvsp[(4) - (5)].tree);

        add(root,tLet);
        add(root,(yyvsp[(2) - (5)].tree));
        add(root,tIn);
        add(root,st);
        add(root,tEnd);
;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {
        
        struct ast* tLet =  createNode("LET",0);
        struct ast* tIn =  createNode("IN",0);
        struct ast* tEnd =  createNode("END",0);
        struct ast* st = (yyvsp[(3) - (4)].tree);


        add(root,tLet);
        add(root,tIn);
        add(root,st);
        add(root,tEnd);
    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {
    
    struct ast* declaration = createNode("declar",0);

    add(declaration,(yyvsp[(1) - (2)].tree));
    add(declaration,(yyvsp[(2) - (2)].tree));

    (yyval.tree) = declaration;
;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {

    struct ast* declaration = createNode("declaration",0);

    add(declaration,(yyvsp[(1) - (3)].tree));
    add(declaration,(yyvsp[(2) - (3)].tree));
    add(declaration,(yyvsp[(3) - (3)].tree));

    (yyval.tree) = declaration;

;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {
    
    (yyval.tree)  = createNode((yyvsp[(1) - (1)].id),0);
;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {
    struct ast* stat = createNode("stat",0);
    
    struct ast* command = (yyvsp[(2) - (2)].tree);
    

    add(stat,(yyvsp[(1) - (2)].tree));
    add(stat,command);
    (yyval.tree) = stat;
;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {
    struct ast* lambda = createNode("lambda",0);
    (yyval.tree) = lambda;
;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {
        printf(" %s ",(yyvsp[(1) - (4)].id));
        struct ast* id = createNode((yyvsp[(1) - (4)].id),0);
        struct ast* assign = createNode("=",0);
        struct ast* exp = (yyvsp[(3) - (4)].tree);
        struct ast* sc = createNode(";",0);
        struct ast* command = createNode("command",0);
        add(command,id);
        add(command,assign);
        add(command,exp);
        add(command,sc);
    
        (yyval.tree) = command;
     ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 244 "parser.y"
    {(yyval.tree)=createNode("prazno",0);;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {(yyval.tree)=createNode("prazno",0);;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 246 "parser.y"
    {(yyval.tree)=createNode("prazno",0);;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {(yyval.tree)=createNode("prazno",0);;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 248 "parser.y"
    {(yyval.tree)=createNode("prazno",0);;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    {(yyval.tree)=createNode("prazno",0);;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 270 "parser.y"
    { if( !((yyvsp[(1) - (3)].tree)->type==3 && (yyvsp[(3) - (3)].tree)->type==3) ){printf("01");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    {if( !((yyvsp[(1) - (3)].tree)->type==3 && (yyvsp[(3) - (3)].tree)->type==3) ){printf("02");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 272 "parser.y"
    {if((yyvsp[(1) - (3)].tree)->type!=(yyvsp[(3) - (3)].tree)->type){printf("03");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {if((yyvsp[(1) - (3)].tree)->type!=(yyvsp[(3) - (3)].tree)->type){printf("04");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 274 "parser.y"
    {if(  !(((yyvsp[(1) - (3)].tree)->type==1 || (yyvsp[(1) - (3)].tree)->type==2) && ((yyvsp[(3) - (3)].tree)->type==1 || (yyvsp[(3) - (3)].tree)->type==2)) ){printf("05");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 275 "parser.y"
    {if(  !(((yyvsp[(1) - (3)].tree)->type==1 || (yyvsp[(1) - (3)].tree)->type==2) && ((yyvsp[(3) - (3)].tree)->type==1 || (yyvsp[(3) - (3)].tree)->type==2)) ){printf("06");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {if(  !(((yyvsp[(1) - (3)].tree)->type==1 || (yyvsp[(1) - (3)].tree)->type==2) && ((yyvsp[(3) - (3)].tree)->type==1 || (yyvsp[(3) - (3)].tree)->type==2)) ){printf("07");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 277 "parser.y"
    {if(  !(((yyvsp[(1) - (3)].tree)->type==1 || (yyvsp[(1) - (3)].tree)->type==2) && ((yyvsp[(3) - (3)].tree)->type==1 || (yyvsp[(3) - (3)].tree)->type==2)) ){printf("08");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 279 "parser.y"
    {
        struct ast* p = createNode("+",0);
        
        if((yyvsp[(1) - (3)].tree)->type!=(yyvsp[(3) - (3)].tree)->type){
            printf("Can not add two different types /n0");exit(1);
            }
        
        struct ast* expF = createNode("exp",0);
        add(expF,((yyvsp[(1) - (3)].tree)));
        add(expF,p);
        add(expF,((yyvsp[(3) - (3)].tree)));

        (yyval.tree) = expF;
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 293 "parser.y"
    {if((yyvsp[(1) - (3)].tree)->type != (yyvsp[(3) - (3)].tree)->type){printf("010");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
    {if((yyvsp[(1) - (3)].tree)->type != (yyvsp[(3) - (3)].tree)->type){printf("011");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    {if((yyvsp[(1) - (3)].tree)->type != (yyvsp[(3) - (3)].tree)->type){printf("012");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 296 "parser.y"
    {if((yyvsp[(2) - (2)].tree)->type != 3){printf("013");exit(1);} (yyval.tree)=createNode("prazno",0);;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {(yyval.tree)=createNode("prazno",0);;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    {
        (yyval.tree) = (yyvsp[(1) - (1)].tree)
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 302 "parser.y"
    {
        (yyval.tree) = createNode((yyvsp[(1) - (1)].id),0);
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {(yyval.tree) = createNode((yyvsp[(1) - (3)].id),0);;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 308 "parser.y"
    {
    char num[32];
    sprintf(num,"%d",(yyvsp[(1) - (1)].i_num));
    (yyval.tree) = createNode(num,1);
;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    {
        char num[32];
        sprintf(num,"%f",(yyvsp[(1) - (1)].d_num));
        (yyval.tree) = createNode(num,2);
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 318 "parser.y"
    {(yyval.tree) = createNode((yyvsp[(1) - (1)].id),3);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    {(yyval.tree) = createNode((yyvsp[(1) - (1)].id),4);;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 320 "parser.y"
    {(yyval.tree) = createNode("INT",0);;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 321 "parser.y"
    {(yyval.tree) = createNode("DOUBLE",0);;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 322 "parser.y"
    {(yyval.tree) = createNode("BOOL",0);;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    {(yyval.tree) = createNode("STRING",0);;}
    break;



/* Line 1455 of yacc.c  */
#line 1984 "parser.tab.c"
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
		      yytoken, &yylval);
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 326 "parser.y"


void yyerror(const char* s) { // poklapa se sa definicijom f-je u bisonu
    printf("%s",s);
    printf("0");
}

int main(){
    init(&root);
    int res = yyparse();
    if(res == 0)
        printf("1\n");
    printAST(root);
    
    
    return 0;
}

//stablo formata (token, id) -> (token,id; token,id)
