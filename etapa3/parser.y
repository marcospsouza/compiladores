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











%union{ //houve mudanças
	AST* ast;
	HASH_NODE* symbol;
	//;;;;BOBAGEM BOBAGEM , , ; ; ;  ; WEFRAWEIRJAWERR24K234234 2323OKRPWEFDSF;S;ER23423/E2;3RWEKFSR
}











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


%token TK_IDENTIFIER 280

%token LIT_INTEGER 281
%token LIT_REAL 282
%token LIT_CHAR 285
%token LIT_STRING 286


%token TOKEN_ERROR 290

%left OPERATOR_AND OPERATOR_OR '!'
%left '<' '>' OPERATOR_LE OPERATOR_GE OPERATOR_EQ OPERATOR_NE
%left '+' '-'
%left '*' '/'

%%
program : decl



//mudanças
%type<ast> exp
%type<ast> lcmd
%type<ast> cmd
%type<ast> bloco


decl : dec decl
	|
	;

dec : vardec
	| fundec
	;

vardec : TK_IDENTIFIER ':' vartypeandlist
	;


vartypeandlist: KW_BYTE '=' lit ';'
	| KW_SHORT '=' lit ';'
	| KW_LONG '=' lit ';'
	| KW_FLOAT '=' lit ';'
	| KW_DOUBLE '=' lit ';'
	| KW_BYTE '[' LIT_INTEGER ']' litlist
	| KW_SHORT '[' LIT_INTEGER ']' litlist
	| KW_LONG '[' LIT_INTEGER ']' litlist
	| KW_FLOAT '[' LIT_INTEGER ']' litlist
	| KW_DOUBLE '[' LIT_INTEGER ']' litlist
	;

lit: LIT_INTEGER
	| LIT_REAL
	| LIT_CHAR
	;

litlist: lit litlist
	| ';'
	;

fundec : '(' vartype ')' TK_IDENTIFIER '(' argsdef ')' cmd
	;

args: exp ',' args
	| exp
	;

argsdef: TK_IDENTIFIER ':' vartype ',' argsdef
	| TK_IDENTIFIER ':' vartype argsdef
	|
	;


vartype: KW_BYTE
	| KW_SHORT
	| KW_LONG
	| KW_FLOAT
	| KW_DOUBLE
	;
//mudanças
//"orientação: criem um nodo e representem que tem parenteseseesesesess"
fundec : KW_INT TK_ID '(' ')' cmd {astPrint($5,0);}

cmd : TK_ID '=' exp  {$$ = astCreate(AST_ASS,$1,$3,0,0);}
	| block        
	|
	;
lcmd : cmd lcmd {setPrint($1,0);}   {$$ = astCreate(AST_LCMD,0,$1,$2,0,0);}
	|                             {$$ = 0;} 
	;

block: '(' lcmd')'  {$$ = $2;}
	;

	//"vai criar e imprimir lista de comandos"
//fimdessasmudançasaqui


cmd : atrib     
	| KW_PRINT printargs
	| KW_READ '>' TK_IDENTIFIER
	| KW_WHILE '(' exp ')' cmd
	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd
	| KW_IF '(' exp ')' KW_THEN cmd
	| KW_RETURN '(' exp ')'
	| block
	|
	;

printargs: LIT_STRING ',' printargs
	| exp ',' printargs
	| LIT_STRING
	| exp

atrib : TK_IDENTIFIER '=' exp
	| TK_IDENTIFIER '[' exp ']' '=' exp

exp : '(' exp ')'
    | TK_IDENTIFIER
    | TK_IDENTIFIER '[' exp ']'
    | TK_IDENTIFIER '(' args ')'
    | LIT_INTEGER
    | LIT_CHAR
    | LIT_REAL
	| exp OPERATOR_LE exp
	| exp OPERATOR_GE exp
	| exp OPERATOR_EQ exp
	| exp OPERATOR_NE exp
	| exp OPERATOR_AND exp
	| exp OPERATOR_OR exp
	| exp '*' exp
	| exp '/' exp
	| exp '+' exp
	| exp '-' exp
	| exp '>' exp
	| exp '<' exp
	| exp '!' exp
	;


//mudanças
//" $ = dólar " HAHAHAHAHHAHAHHAHAHA
/*  
exp : TK_LITINT
	|TK_ID              {$$ = setCreate(AST_SYMBOL,$1,0,0,0,0);}
 	| '('exp')'			{$$ = $2;} //"tinha parenteses aqui no original"
	|exp '*'exp			{$$ = setCreate(AST_ADD,0,$1,$3,0,0);}
	|exp '+' exp		{$$ = setCreate(AST_MUL,0,$1,$3,0,0);}
	;

*/




block : '{' lcmd '}'
	;

lcmd : cmd ';' lcmd
	| cmd
	;


%%
int getLineNumber();


void yyerror (char const *s) {
	fprintf (stderr, "Line %d: %s\n",getLineNumber(), s);
	exit(3);
}
