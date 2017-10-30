/*

	//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

int yylex();
void yyerror(char const *s);

%}


%union{AST* ast; HASH_NODE* symbol;}


%token KW_BYTE 256
%token KW_SHORT 257
%token KW_LONG 258
%token KW_FLOAT 259
%token KW_DOUBLE 260
%token KW_IF 261
%token KW_THEN 262
%token KW_ELSE 263
%token KW_WHILE 264
%token KW_FOR 265
%token KW_READ 266
%token KW_RETURN 267
%token KW_PRINT 268


%token OPERATOR_LE 270
%token OPERATOR_GE 271
%token OPERATOR_EQ 272
%token OPERATOR_NE 273
%token OPERATOR_AND 274
%token OPERATOR_OR 275


%token <symbol> TK_IDENTIFIER
%token <symbol> LIT_INTEGER
%token <symbol> LIT_REAL
%token <symbol> LIT_CHAR
%token <symbol> LIT_STRING

%token TOKEN_ERROR 290

%type <ast> exp
%type <ast> lcmd
%type <ast> cmd
%type <ast> block
%type <ast> decl
%type <ast> dec
%type <ast> vardec
%type <ast> fundec
%type <ast> vartypeandlist
%type <ast> lit
%type <ast> litlist
%type <ast> vartype
%type <ast> argsdef
%type <ast> atrib
%type <ast> printargs
%type <ast> args



%left OPERATOR_AND OPERATOR_OR '!'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'


%%
program : decl { astPrint($1,0);} 



decl : dec decl { $$ = astCreate(AST_DECL, NULL, $1, $2, 0, 0); }
	|	{ $$ = 0; }
	;

dec : vardec { $$ = $1; }
	| fundec { $$ = $1; } 
	;

vardec : TK_IDENTIFIER ':' vartypeandlist  { $$ = astCreate(AST_VARDEC, $1, $3, 0, 0, 0); }
	;


vartypeandlist: KW_BYTE '=' lit ';' { $$ = astCreate(AST_VTLIST, NULL, $3, 0, 0, 0); }
	| KW_SHORT '=' lit ';' { $$ = astCreate(AST_VTLIST, NULL, $3, 0, 0, 0); }
	| KW_LONG '=' lit ';' { $$ = astCreate(AST_VTLIST, NULL, $3, 0, 0, 0); }
	| KW_FLOAT '=' lit ';' { $$ = astCreate(AST_VTLIST, NULL, $3, 0, 0, 0); }
	| KW_DOUBLE '=' lit ';' { $$ = astCreate(AST_VTLIST, NULL, $3, 0, 0, 0); }
	| KW_BYTE '[' lit ']' litlist { $$ = astCreate(AST_VTLIST, NULL, $3, $5, 0, 0); }
	| KW_SHORT '[' lit ']' litlist { $$ = astCreate(AST_VTLIST, NULL, $3, $5, 0, 0); }
	| KW_LONG '[' lit ']' litlist { $$ = astCreate(AST_VTLIST, NULL, $3, $5, 0, 0); }
	| KW_FLOAT '[' lit ']' litlist { $$ = astCreate(AST_VTLIST, NULL, $3, $5, 0, 0); }
	| KW_DOUBLE '[' lit ']' litlist { $$ = astCreate(AST_VTLIST, NULL, $3, $5, 0, 0); }
	;

lit: LIT_INTEGER { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_REAL { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	| LIT_CHAR { $$ = astCreate(AST_SYMBOL, $1, 0, 0, 0, 0); }
	;

litlist: lit litlist { $$ = astCreate(AST_LITLIST, 0, $1, $2, 0, 0); }
	| ';' {$$ = 0;}
	;

fundec : '(' vartype ')' TK_IDENTIFIER '(' argsdef ')' cmd { $$ = astCreate(AST_FUNDEC,$4,$2,0,$6,$8); }
	;

args: exp ',' args { $$ = astCreate(AST_ARGS,NULL,$1,$3,0,0); }
	| exp { $$ = astCreate(AST_ARGS,NULL,$1,0,0,0); }
	;

argsdef: TK_IDENTIFIER ':' vartype ',' argsdef { $$ = astCreate(AST_ARGSDEF,$1,$3,$5,0,0); }  
	| TK_IDENTIFIER ':' vartype argsdef { $$ = astCreate(AST_ARGSDEF,$1,$3,$4,0,0); }  
	|	{ $$ = 0; }
	;


vartype: KW_BYTE  { $$ = astCreate(AST_KWBYTE,0,0,0,0,0); }
	| KW_SHORT { $$ = astCreate(AST_KWSHORT,0,0,0,0,0); }
	| KW_LONG { $$ = astCreate(AST_KWLONG,0,0,0,0,0); }
	| KW_FLOAT { $$ = astCreate(AST_KWFLOAT, 0,0,0,0,0); }
	| KW_DOUBLE { $$ = astCreate(AST_KWDOUBLE,0,0,0,0,0); }
	;



block: '(' lcmd')'  { $$ = astCreate(AST_BLOCK,0,$2,0,0,0); }
	;


cmd : atrib { $$ = $1; }     
	| KW_PRINT printargs {$$ = astCreate(AST_KWPRINT, NULL, $2, 0, 0, 0);}
	| KW_READ '>' TK_IDENTIFIER {$$ = astCreate(AST_KWREAD, $3, 0, 0, 0, 0);}
	| KW_WHILE '(' exp ')' cmd {$$ = astCreate(AST_KWWHILE, NULL, $3, $5, 0, 0);}
	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd {$$ = astCreate(AST_KWIF, NULL, $3, $6, $8, 0);}
	| KW_IF '(' exp ')' KW_THEN cmd {$$ = astCreate(AST_KWIF, NULL, $3, $6, 0, 0);}
	| KW_RETURN exp {$$ = astCreate(AST_KWRETURN, NULL, $2, 0, 0, 0);}
	| block { $$ = $1; }
	| {$$ = 0;}
	;

printargs: LIT_STRING ',' printargs {$$ = astCreate(AST_PRINTARGS, $1, $3, 0, 0, 0);}
	| exp ',' printargs {$$ = astCreate(AST_PRINTARGS, NULL, $1, $3, 0, 0);}
	| LIT_STRING { $$ = astCreate(AST_SYMBOL,$1,0,0,0,0); }
	| exp {$$ = $1;}

atrib : TK_IDENTIFIER '=' exp { $$ = astCreate(AST_ASSIGN, $1, $3, 0, 0, 0); }
	| TK_IDENTIFIER '[' exp ']' '=' exp { $$ = astCreate(AST_ASSIGN, $1, $3, $6, 0, 0); }

exp : '(' exp ')' { $$ = astCreate(AST_EXP,NULL,$2,0,0,0); }
    | TK_IDENTIFIER { $$ = astCreate(AST_TKID,$1,0,0,0,0); }
    | TK_IDENTIFIER '[' exp ']' { $$ = astCreate(AST_TKID,$1,$3,0,0,0); }
    | TK_IDENTIFIER '(' args ')' { $$ = astCreate(AST_TKID,$1,$3,0,0,0); }
    | LIT_INTEGER { $$ = astCreate(AST_INT,$1,0,0,0,0); }
    | LIT_CHAR { $$ = astCreate(AST_CHAR,$1,0,0,0,0); }
    | LIT_REAL { $$ = astCreate(AST_REAL,$1,0,0,0,0); }
	| exp OPERATOR_LE exp { $$ = astCreate(AST_LE,NULL,$1,$3,0,0); }
	| exp OPERATOR_GE exp { $$ = astCreate(AST_GE,NULL,$1,$3,0,0); }
	| exp OPERATOR_EQ exp { $$ = astCreate(AST_EQ,NULL,$1,$3,0,0); }
	| exp OPERATOR_NE exp { $$ = astCreate(AST_NE,NULL,$1,$3,0,0); }
	| exp OPERATOR_AND exp { $$ = astCreate(AST_AND,NULL,$1,$3,0,0); }
	| exp OPERATOR_OR exp { $$ = astCreate(AST_OR,NULL,$1,$3,0,0); }
	| exp '*' exp { $$ = astCreate(AST_MUL,NULL,$1,$3,0,0); }
	| exp '/' exp { $$ = astCreate(AST_DIV,NULL,$1,$3,0,0); }
	| exp '+' exp { $$ = astCreate(AST_ADD,NULL,$1,$3,0,0); }
	| exp '-' exp { $$ = astCreate(AST_SUB,NULL,$1,$3,0,0); }
	| exp '>' exp { $$ = astCreate(AST_GT,NULL,$1,$3,0,0); }
	| exp '<' exp { $$ = astCreate(AST_LS,NULL,$1,$3,0,0); }
	| exp '!' exp { $$ = astCreate(AST_NOT, NULL,$1,$3,0,0); }
	;



block : '{' lcmd '}' { $$ = astCreate(AST_BLOCK,NULL,$2,0,0,0); }
	;

lcmd : cmd ';' lcmd {astPrint($1,0);}   {$$ = astCreate(AST_LCMD,0,$1,$3,0,0);}
	| cmd {$$ = astCreate(AST_LCMD,0,$1,0,0,0);}
	;


%%
int getLineNumber();


void yyerror (char const *s) {
	fprintf (stderr, "Line %d: %s\n",getLineNumber(), s);
	exit(3);
}
