/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 7 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include "genco.h"
/*#include "hash.h"*/
#include "astree.h"


void semanticSetTypes() ; /*recursiva*/
void semanticCheckUndeclared(void);
void semanticCheckUsage();
void semanticCheckOperands();





int yylex();
void yyerror(char const *s);

#line 29 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union{AST* ast; HASH_NODE* symbol;} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 50 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define KW_BYTE 256
#define KW_SHORT 257
#define KW_LONG 258
#define KW_FLOAT 259
#define KW_DOUBLE 260
#define KW_IF 261
#define KW_THEN 262
#define KW_ELSE 263
#define KW_WHILE 264
#define KW_FOR 265
#define KW_READ 266
#define KW_RETURN 267
#define KW_PRINT 268
#define OPERATOR_LE 270
#define OPERATOR_GE 271
#define OPERATOR_EQ 272
#define OPERATOR_NE 273
#define OPERATOR_AND 274
#define OPERATOR_OR 275
#define TK_IDENTIFIER 269
#define LIT_INTEGER 276
#define LIT_REAL 277
#define LIT_CHAR 278
#define LIT_STRING 279
#define TOKEN_ERROR 290
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    5,    5,    6,    6,    7,    7,    9,    9,    9,
   10,   10,    8,   17,   17,   18,   18,   12,   12,   12,
   11,   11,   11,   11,   11,    4,    3,    3,    3,    3,
    3,    3,    3,    3,    3,   14,   15,   15,   16,   16,
   13,   13,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    4,    2,    2,
};
static const YYINT yylen[] = {                            2,
    1,    2,    0,    1,    1,    6,    7,    1,    1,    1,
    2,    1,    8,    2,    0,    3,    0,    5,    4,    0,
    1,    1,    1,    1,    1,    3,    1,    2,    3,    5,
    8,    6,    2,    1,    0,    2,    3,    0,    1,    1,
    3,    6,    3,    1,    4,    4,    1,    1,    1,    1,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    1,    0,    4,    5,    0,   21,   22,
   23,   24,   25,    0,    2,    0,    0,    0,    0,    0,
    8,    9,   10,    0,    0,    0,    6,    0,    0,    0,
   12,    0,    7,    0,    0,   11,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   13,   34,   27,    0,   19,
    0,    0,    0,    0,   47,   50,   49,   48,    0,    0,
    0,    0,   28,    0,    0,    0,    0,    0,    0,   18,
    0,    0,   29,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   36,    0,    0,   26,    0,   64,    0,    0,    0,    0,
    0,   43,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   57,   58,    0,    0,   65,    0,   30,
   45,    0,   14,   46,   37,    0,    0,    0,    0,    0,
   16,   31,
};
static const YYINT yydgoto[] = {                          3,
   62,   67,   68,   47,    4,    5,    6,    7,   32,   33,
   14,   30,   48,   63,   91,   64,  101,  123,
};
static const YYINT yysindex[] = {                       -26,
  -46,  -76,    0,    0,  -26,    0,    0,  -76,    0,    0,
    0,    0,    0,  -10,    0,  -58, -231, -227, -227,    7,
    0,    0,    0,   -7,  -53, -182,    0,  -24,   32,   57,
    0,  -24,    0,  -76,  355,    0,  -44,   61,   64,   51,
  -38,  176,  -50,  355,  355,    0,    0,    0, -182,    0,
  -38,  -38, -151,  -18,    0,    0,    0,    0,  -38,  526,
    0,  526,    0,   76,  -38,  -38,   82,   68,   14,    0,
  336,  380,    0,  -38,  -38,  441,  -38,  -38,  -38,  -38,
  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  -38,  176,
    0,  526,  473,    0,  355,    0, -121,  355,  494,  520,
  102,    0,   67,   67,   67,   67,  -37,  -37,  -37,   67,
   67,  -21,  -21,    0,    0,   76,   83,    0,  355,    0,
    0,  -38,    0,    0,    0,  -38, -118,  520,  526,  355,
    0,    0,
};
static const YYINT yyrindex[] = {                       146,
    0,    0,    0,    0,  146,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  107,    0,    0,    0,    0,
    0,    0,    0,    0,  153,    0,  107,    0,    0,    0,
    0,    0,    0,  -23,  -40,    0,    0,    0,  107,    0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,   88,
   24,   15,    0,  163,    0,    0,    0,  -34,    0,    0,
    0,    0,    0,    0,  115,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  218,    0,    0,  -32,    0,    0,   17,    0,  -10,
    0,    0,   75,   92,  117,  131,  283,  397,  435,  188,
  374,   37,   62,    0,    0,  163,    0,    0,   17,    0,
    0,    0,    0,    0,    0,    0,   13,  -10,  245,   17,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
  761,   -6,  -19,    0,  154,    0,    0,    0,   10,  128,
   -4,  -17,    0,    0,   49,   77,    0,   38,
};
#define YYTABLESIZE 887
static const YYINT yytable[] = {                         49,
   44,   59,   18,   16,   88,   86,   66,   87,   35,   89,
   65,    8,   32,    2,   39,   46,   35,   35,   35,   50,
   88,   75,   84,   40,   85,   89,   35,   24,   25,   37,
   17,   70,   19,   44,   31,   35,   59,   20,   69,   28,
   66,   44,   44,   44,   44,   44,   26,   44,   21,   22,
   23,   27,   32,   32,   39,   39,   48,   35,   39,   44,
   44,   60,   44,   40,   40,   48,   48,   40,   48,   59,
   48,   32,   74,   39,   51,   35,   59,   59,  120,   59,
   59,   59,   40,   48,   35,   48,   29,   33,  118,   34,
   66,   52,   35,   44,   60,   59,   59,   35,   59,  127,
   51,   60,   60,   52,   60,   60,   60,   51,   88,   86,
  132,   87,   53,   89,   51,   51,   53,   73,   51,   90,
   60,   60,   94,   60,   52,   44,   95,   33,   33,   59,
   54,   52,   52,   51,   51,   52,   51,   32,   96,   39,
  119,   35,  124,  126,  130,    3,   33,   20,   40,   53,
   52,   52,   35,   52,   60,   15,   53,   53,   15,   36,
   53,   59,   38,   54,  125,  131,  116,   51,    0,    0,
   54,   54,    0,    0,   54,   53,   53,    0,   53,    9,
   10,   11,   12,   13,   52,    0,   60,   62,    0,   54,
   54,    0,   54,    0,    0,    0,    0,    0,    0,   51,
    0,    0,   38,   38,    0,    0,    0,    0,    0,   53,
    0,    0,   33,    0,    0,   59,   52,   41,    0,    0,
   62,   38,    0,   54,   29,    0,    0,   62,   62,    0,
   54,   62,   77,   78,   79,   80,    0,   55,   56,   57,
   58,   53,    1,    0,   42,    0,   62,   62,    0,   62,
    0,   21,   22,   23,    0,   54,    0,   41,   41,    0,
    0,    0,    0,   44,    0,    0,    0,    0,    0,   44,
   44,   44,   44,   44,   44,   44,   41,   39,    0,   35,
   62,   32,   55,   39,   42,   42,   40,   38,    0,    0,
    0,    0,   40,   48,   48,   48,   48,   48,   48,   59,
    0,    0,    0,   42,    0,   59,   59,   59,   59,   59,
   59,   59,   62,    0,    0,   55,    0,    0,    0,    0,
    0,    0,   55,   55,   60,    0,   55,    0,    0,    0,
   60,   60,   60,   60,   60,   60,   60,   51,    0,    0,
    0,   55,   41,   51,   51,   51,   51,   51,   51,   51,
   33,    0,    0,    0,   52,    0,   33,    0,    0,    0,
   52,   52,   52,   52,   52,   52,   52,    0,   83,   42,
    0,    0,    0,   61,    0,   55,   97,   88,   86,   53,
   87,    0,   89,    0,    0,   53,   53,   53,   53,   53,
   53,   53,    0,   54,   44,   84,   56,   85,    0,   54,
   54,   54,   54,   54,   54,   54,   61,   55,    0,    0,
    0,    0,   83,   61,   61,    0,    0,   61,    0,    0,
   98,   88,   86,    0,   87,   38,   89,    0,    0,   56,
    0,   38,   61,   61,   63,   61,   56,   56,    0,   84,
   56,   85,    0,    0,   54,    0,    0,    0,    0,    0,
   62,   55,   56,   57,   61,   56,   62,   62,   62,   62,
   62,   62,   62,    0,    0,    0,   61,   63,    0,    0,
    0,    0,    0,   83,   63,   63,    0,   45,   63,    0,
   41,  102,   88,   86,    0,   87,   41,   89,    0,   56,
    0,    0,    0,   63,    0,    0,    0,    0,   61,    0,
   84,    0,   85,    0,    0,   83,    0,   42,    0,    0,
    0,    0,    0,   42,   88,   86,    0,   87,    0,   89,
    0,   56,    0,    0,    0,    0,   83,   63,    0,    0,
    0,    0,   84,    0,   85,   88,   86,    0,   87,    0,
   89,    0,    0,    0,    0,   55,    0,    0,    0,    0,
    0,   55,   83,   84,    0,   85,   55,   55,   83,   63,
    0,   88,   86,  122,   87,  117,   89,   88,   86,    0,
   87,    0,   89,    0,    0,    0,    0,    0,    0,   84,
    0,   85,    0,    0,    0,   84,  121,   85,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   77,   78,   79,   80,   81,
   82,    0,    0,    0,    0,   38,    0,    0,   39,    0,
   40,   41,   42,   43,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   61,    0,    0,    0,
    0,    0,   61,   61,   61,   61,   61,   61,   61,   77,
   78,   79,   80,   81,   82,    0,    0,    0,    0,   56,
    0,    0,    0,    0,    0,   56,    0,    0,    0,    0,
   56,   56,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   63,    0,    0,
    0,    0,    0,   63,    0,    0,    0,    0,   63,   63,
   77,   78,   79,   80,   81,   82,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   77,   78,   79,   80,   81,   82,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   77,   78,   79,   80,   81,   82,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   77,
   78,   79,   80,   81,   82,   77,   78,   79,   80,   81,
   82,   60,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   71,   72,    0,    0,    0,    0,    0,    0,   76,
    0,    0,    0,    0,    0,   92,   93,    0,    0,    0,
    0,    0,    0,    0,   99,  100,    0,  103,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  128,    0,    0,    0,  129,
};
static const YYINT yycheck[] = {                         44,
    0,   40,   61,    8,   42,   43,   41,   45,   41,   47,
   61,   58,    0,   40,    0,   35,    0,   41,   59,   37,
   42,   40,   60,    0,   62,   47,   59,   18,   19,   34,
   41,   49,   91,   33,   59,   59,    0,  269,   45,   93,
   91,   41,   42,   43,   44,   45,   40,   47,  276,  277,
  278,   59,   40,   41,   40,   41,   33,   41,   44,   59,
   60,    0,   62,   40,   41,   42,   43,   44,   45,   33,
   47,   59,   91,   59,    0,   59,   40,   41,   98,   43,
   44,   45,   59,   60,  125,   62,  269,    0,   95,   58,
  125,    0,  125,   93,   33,   59,   60,   41,   62,  119,
   40,   40,   41,   40,   43,   44,   45,   33,   42,   43,
  130,   45,   62,   47,   40,   41,    0,  269,   44,   44,
   59,   60,   41,   62,   33,  125,   59,   40,   41,   93,
    0,   40,   41,   59,   60,   44,   62,  125,  125,  125,
  262,  125,   41,   61,  263,    0,   59,   41,  125,   33,
   59,   60,    0,   62,   93,   41,   40,   41,    5,   32,
   44,  125,    0,   33,  116,  128,   90,   93,   -1,   -1,
   40,   41,   -1,   -1,   44,   59,   60,   -1,   62,  256,
  257,  258,  259,  260,   93,   -1,  125,    0,   -1,   59,
   60,   -1,   62,   -1,   -1,   -1,   -1,   -1,   -1,  125,
   -1,   -1,   40,   41,   -1,   -1,   -1,   -1,   -1,   93,
   -1,   -1,  125,   -1,   -1,   40,  125,    0,   -1,   -1,
   33,   59,   -1,   93,  269,   -1,   -1,   40,   41,   -1,
  269,   44,  270,  271,  272,  273,   -1,  276,  277,  278,
  279,  125,  269,   -1,    0,   -1,   59,   60,   -1,   62,
   -1,  276,  277,  278,   -1,  125,   -1,   40,   41,   -1,
   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,   -1,  269,
  270,  271,  272,  273,  274,  275,   59,  263,   -1,  263,
   93,  269,    0,  269,   40,   41,  263,  125,   -1,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  263,
   -1,   -1,   -1,   59,   -1,  269,  270,  271,  272,  273,
  274,  275,  125,   -1,   -1,   33,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,  263,   -1,   44,   -1,   -1,   -1,
  269,  270,  271,  272,  273,  274,  275,  263,   -1,   -1,
   -1,   59,  125,  269,  270,  271,  272,  273,  274,  275,
  263,   -1,   -1,   -1,  263,   -1,  269,   -1,   -1,   -1,
  269,  270,  271,  272,  273,  274,  275,   -1,   33,  125,
   -1,   -1,   -1,    0,   -1,   93,   41,   42,   43,  263,
   45,   -1,   47,   -1,   -1,  269,  270,  271,  272,  273,
  274,  275,   -1,  263,   40,   60,    0,   62,   -1,  269,
  270,  271,  272,  273,  274,  275,   33,  125,   -1,   -1,
   -1,   -1,   33,   40,   41,   -1,   -1,   44,   -1,   -1,
   41,   42,   43,   -1,   45,  263,   47,   -1,   -1,   33,
   -1,  269,   59,   60,    0,   62,   40,   41,   -1,   60,
   44,   62,   -1,   -1,  269,   -1,   -1,   -1,   -1,   -1,
  263,  276,  277,  278,  279,   59,  269,  270,  271,  272,
  273,  274,  275,   -1,   -1,   -1,   93,   33,   -1,   -1,
   -1,   -1,   -1,   33,   40,   41,   -1,  123,   44,   -1,
  263,   41,   42,   43,   -1,   45,  269,   47,   -1,   93,
   -1,   -1,   -1,   59,   -1,   -1,   -1,   -1,  125,   -1,
   60,   -1,   62,   -1,   -1,   33,   -1,  263,   -1,   -1,
   -1,   -1,   -1,  269,   42,   43,   -1,   45,   -1,   47,
   -1,  125,   -1,   -1,   -1,   -1,   33,   93,   -1,   -1,
   -1,   -1,   60,   -1,   62,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,   -1,
   -1,  269,   33,   60,   -1,   62,  274,  275,   33,  125,
   -1,   42,   43,   44,   45,   93,   47,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   60,
   -1,   62,   -1,   -1,   -1,   60,   93,   62,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  270,  271,  272,  273,  274,
  275,   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,   -1,
   -1,   -1,  269,  270,  271,  272,  273,  274,  275,  270,
  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,  263,
   -1,   -1,   -1,   -1,   -1,  269,   -1,   -1,   -1,   -1,
  274,  275,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  263,   -1,   -1,
   -1,   -1,   -1,  269,   -1,   -1,   -1,   -1,  274,  275,
  270,  271,  272,  273,  274,  275,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  270,  271,  272,  273,  274,  275,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  270,
  271,  272,  273,  274,  275,  270,  271,  272,  273,  274,
  275,   41,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   51,   52,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   -1,   -1,   -1,   -1,   -1,   65,   66,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   74,   75,   -1,   77,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  122,   -1,   -1,   -1,  126,
};
#define YYFINAL 3
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 311
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,
0,"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'{'",0,"'}'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"KW_BYTE","KW_SHORT","KW_LONG","KW_FLOAT",
"KW_DOUBLE","KW_IF","KW_THEN","KW_ELSE","KW_WHILE","KW_FOR","KW_READ",
"KW_RETURN","KW_PRINT","TK_IDENTIFIER","OPERATOR_LE","OPERATOR_GE",
"OPERATOR_EQ","OPERATOR_NE","OPERATOR_AND","OPERATOR_OR","LIT_INTEGER",
"LIT_REAL","LIT_CHAR","LIT_STRING",0,0,0,0,0,0,0,0,0,0,"TOKEN_ERROR",0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"program : decl",
"decl : dec decl",
"decl :",
"dec : vardec",
"dec : fundec",
"vardec : TK_IDENTIFIER ':' vartype '=' lit ';'",
"vardec : TK_IDENTIFIER ':' vartype '[' lit ']' litlist",
"lit : LIT_INTEGER",
"lit : LIT_REAL",
"lit : LIT_CHAR",
"litlist : lit litlist",
"litlist : ';'",
"fundec : '(' vartype ')' TK_IDENTIFIER '(' argsdef ')' cmd",
"args : exp largs",
"args :",
"largs : ',' exp largs",
"largs :",
"argsdef : TK_IDENTIFIER ':' vartype ',' argsdef",
"argsdef : TK_IDENTIFIER ':' vartype argsdef",
"argsdef :",
"vartype : KW_BYTE",
"vartype : KW_SHORT",
"vartype : KW_LONG",
"vartype : KW_FLOAT",
"vartype : KW_DOUBLE",
"block : '(' lcmd ')'",
"cmd : atrib",
"cmd : KW_PRINT printargs",
"cmd : KW_READ '>' TK_IDENTIFIER",
"cmd : KW_WHILE '(' exp ')' cmd",
"cmd : KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd",
"cmd : KW_IF '(' exp ')' KW_THEN cmd",
"cmd : KW_RETURN exp",
"cmd : block",
"cmd :",
"printargs : argprint tailprint",
"tailprint : ',' argprint tailprint",
"tailprint :",
"argprint : exp",
"argprint : LIT_STRING",
"atrib : TK_IDENTIFIER '=' exp",
"atrib : TK_IDENTIFIER '[' exp ']' '=' exp",
"exp : '(' exp ')'",
"exp : TK_IDENTIFIER",
"exp : TK_IDENTIFIER '[' exp ']'",
"exp : TK_IDENTIFIER '(' args ')'",
"exp : LIT_INTEGER",
"exp : LIT_STRING",
"exp : LIT_CHAR",
"exp : LIT_REAL",
"exp : exp OPERATOR_LE exp",
"exp : exp OPERATOR_GE exp",
"exp : exp OPERATOR_EQ exp",
"exp : exp OPERATOR_NE exp",
"exp : exp OPERATOR_AND exp",
"exp : exp OPERATOR_OR exp",
"exp : exp '*' exp",
"exp : exp '/' exp",
"exp : exp '+' exp",
"exp : exp '-' exp",
"exp : exp '>' exp",
"exp : exp '<' exp",
"exp : exp '!' exp",
"block : '{' lcmd '}'",
"lcmd : cmd ';' lcmd",
"lcmd : cmd",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 216 "parser.y"
int getLineNumber();


void yyerror (char const *s) {
	fprintf (stderr, "Line %d: %s\n",getLineNumber(), s);
	exit(3);
}
#line 504 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 91 "parser.y"
	{ /*astPrint($1,0);*/
					printSource(yystack.l_mark[0].ast);
					semanticSetTypes(yystack.l_mark[0].ast);
					semanticCheckUndeclared();
					semanticCheckUsage(yystack.l_mark[0].ast);
					semanticCheckOperands(yystack.l_mark[0].ast);
					tacPrintBack(tacGenerator(yystack.l_mark[0].ast));
				}
break;
case 2:
#line 102 "parser.y"
	{ yyval.ast = astCreate(AST_DECL, 0, yystack.l_mark[-1].ast, yystack.l_mark[0].ast, 0, 0);}
break;
case 3:
#line 103 "parser.y"
	{ yyval.ast = 0; }
break;
case 4:
#line 106 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 5:
#line 107 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 6:
#line 110 "parser.y"
	{ yyval.ast = astCreate(AST_VARDEC, yystack.l_mark[-5].symbol, yystack.l_mark[-3].ast, yystack.l_mark[-1].ast, 0, 0); }
break;
case 7:
#line 111 "parser.y"
	{yyval.ast = astCreate(AST_VECDEC, yystack.l_mark[-6].symbol, yystack.l_mark[-4].ast, yystack.l_mark[-2].ast, yystack.l_mark[0].ast, 0); }
break;
case 8:
#line 114 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 9:
#line 115 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 10:
#line 116 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL, yystack.l_mark[0].symbol, 0, 0, 0, 0); }
break;
case 11:
#line 119 "parser.y"
	{ yyval.ast = astCreate(AST_LITLIST, 0, yystack.l_mark[-1].ast, yystack.l_mark[0].ast, 0, 0); }
break;
case 12:
#line 120 "parser.y"
	{yyval.ast = 0;}
break;
case 13:
#line 125 "parser.y"
	{ yyval.ast = astCreate(AST_FUNDEC,yystack.l_mark[-4].symbol,yystack.l_mark[-6].ast,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast); }
break;
case 14:
#line 128 "parser.y"
	{yyval.ast = astCreate(AST_ARGS, 0, yystack.l_mark[-1].ast, yystack.l_mark[0].ast, 0, 0);}
break;
case 15:
#line 129 "parser.y"
	{yyval.ast = 0;}
break;
case 16:
#line 132 "parser.y"
	{yyval.ast = astCreate(AST_ARGS, 0, yystack.l_mark[-1].ast, yystack.l_mark[0].ast, 0, 0);}
break;
case 17:
#line 133 "parser.y"
	{yyval.ast = 0;}
break;
case 18:
#line 137 "parser.y"
	{ yyval.ast = astCreate(AST_ARGSDEF,yystack.l_mark[-4].symbol,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 19:
#line 138 "parser.y"
	{ yyval.ast = astCreate(AST_ARGSDEF,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0); }
break;
case 20:
#line 139 "parser.y"
	{ yyval.ast = 0; }
break;
case 21:
#line 143 "parser.y"
	{ yyval.ast = astCreate(AST_KWBYTE,0,0,0,0,0); }
break;
case 22:
#line 144 "parser.y"
	{ yyval.ast = astCreate(AST_KWSHORT,0,0,0,0,0); }
break;
case 23:
#line 145 "parser.y"
	{ yyval.ast = astCreate(AST_KWLONG,0,0,0,0,0); }
break;
case 24:
#line 146 "parser.y"
	{ yyval.ast = astCreate(AST_KWFLOAT, 0,0,0,0,0); }
break;
case 25:
#line 147 "parser.y"
	{ yyval.ast = astCreate(AST_KWDOUBLE,0,0,0,0,0); }
break;
case 26:
#line 152 "parser.y"
	{ yyval.ast = astCreate(AST_BLOCK,0,yystack.l_mark[-1].ast,0,0,0); }
break;
case 27:
#line 156 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 28:
#line 157 "parser.y"
	{yyval.ast = astCreate(AST_KWPRINT, 0, yystack.l_mark[0].ast, 0, 0, 0);}
break;
case 29:
#line 158 "parser.y"
	{yyval.ast = astCreate(AST_KWREAD, yystack.l_mark[0].symbol, 0, 0, 0, 0);}
break;
case 30:
#line 159 "parser.y"
	{yyval.ast = astCreate(AST_KWWHILE, 0, yystack.l_mark[-2].ast, yystack.l_mark[0].ast, 0, 0);}
break;
case 31:
#line 160 "parser.y"
	{yyval.ast = astCreate(AST_KWIF, 0, yystack.l_mark[-5].ast, yystack.l_mark[-2].ast, yystack.l_mark[0].ast, 0);}
break;
case 32:
#line 161 "parser.y"
	{yyval.ast = astCreate(AST_KWIF, 0, yystack.l_mark[-3].ast, yystack.l_mark[0].ast, 0, 0);}
break;
case 33:
#line 162 "parser.y"
	{yyval.ast = astCreate(AST_KWRETURN, 0, yystack.l_mark[0].ast, 0, 0, 0);}
break;
case 34:
#line 163 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast;}
break;
case 35:
#line 164 "parser.y"
	{yyval.ast = 0;}
break;
case 36:
#line 167 "parser.y"
	{ yyval.ast = astCreate(AST_PRINTARGS,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0); }
break;
case 37:
#line 170 "parser.y"
	{ yyval.ast = astCreate(AST_PRINTARGS,0,yystack.l_mark[-1].ast,yystack.l_mark[0].ast,0,0); }
break;
case 38:
#line 171 "parser.y"
	{ yyval.ast = 0; }
break;
case 39:
#line 174 "parser.y"
	{ yyval.ast = yystack.l_mark[0].ast; }
break;
case 40:
#line 175 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
case 41:
#line 179 "parser.y"
	{ yyval.ast = astCreate(AST_ASSIGN, yystack.l_mark[-2].symbol, yystack.l_mark[0].ast, 0, 0, 0); }
break;
case 42:
#line 180 "parser.y"
	{ yyval.ast = astCreate(AST_VASSIGN, yystack.l_mark[-5].symbol, yystack.l_mark[-3].ast, yystack.l_mark[0].ast, 0, 0); }
break;
case 43:
#line 182 "parser.y"
	{ yyval.ast = astCreate(AST_EXP,0,yystack.l_mark[-1].ast,0,0,0); }
break;
case 44:
#line 183 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
case 45:
#line 184 "parser.y"
	{ yyval.ast = astCreate(AST_VACCESS,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0); }
break;
case 46:
#line 185 "parser.y"
	{ yyval.ast = astCreate(AST_FUNCALL,yystack.l_mark[-3].symbol,yystack.l_mark[-1].ast,0,0,0); }
break;
case 47:
#line 186 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
case 48:
#line 187 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
case 49:
#line 188 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
case 50:
#line 189 "parser.y"
	{ yyval.ast = astCreate(AST_SYMBOL,yystack.l_mark[0].symbol,0,0,0,0); }
break;
case 51:
#line 190 "parser.y"
	{ yyval.ast = astCreate(AST_LE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 52:
#line 191 "parser.y"
	{ yyval.ast = astCreate(AST_GE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 53:
#line 192 "parser.y"
	{ yyval.ast = astCreate(AST_EQ,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 54:
#line 193 "parser.y"
	{ yyval.ast = astCreate(AST_NE,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 55:
#line 194 "parser.y"
	{ yyval.ast = astCreate(AST_AND,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 56:
#line 195 "parser.y"
	{ yyval.ast = astCreate(AST_OR,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 57:
#line 196 "parser.y"
	{ yyval.ast = astCreate(AST_MUL,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 58:
#line 197 "parser.y"
	{ yyval.ast = astCreate(AST_DIV,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 59:
#line 198 "parser.y"
	{ yyval.ast = astCreate(AST_ADD,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 60:
#line 199 "parser.y"
	{ yyval.ast = astCreate(AST_SUB,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 61:
#line 200 "parser.y"
	{ yyval.ast = astCreate(AST_GT,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 62:
#line 201 "parser.y"
	{ yyval.ast = astCreate(AST_LS,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 63:
#line 202 "parser.y"
	{ yyval.ast = astCreate(AST_NOT, 0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0); }
break;
case 64:
#line 207 "parser.y"
	{ yyval.ast = astCreate(AST_BLOCK,0,yystack.l_mark[-1].ast,0,0,0); }
break;
case 65:
#line 210 "parser.y"
	{yyval.ast = astCreate(AST_LCMD,0,yystack.l_mark[-2].ast,yystack.l_mark[0].ast,0,0);}
break;
case 66:
#line 211 "parser.y"
	{yyval.ast = yystack.l_mark[0].ast;}
break;
#line 977 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
