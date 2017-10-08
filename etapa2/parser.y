/*parser.y

yacc parser.y

yacc -d parser.y
pra gerar ytab.h que tem defines é o nosso novo token.h


int : var ;
for 5878 ;
for 7 ;

*/

%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
int yylex();
void yyerror(char const *s);

%}


%union{ HASH_NODE* symbol; }

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


%%
program : decl

decl : dec decl
	|	
	;

dec : vardec
	| fundec
	;

vardec : KW_BYTE TK_IDENTIFIER
	;

fundec : KW_BYTE TK_IDENTIFIER '(' ')' cmd
	;

cmd : TK_IDENTIFIER '=' exp
	| block
	;

exp : 
	;

block : '{' lcmd '}'
	;

lcmd : cmd lcmd
	|
	;



%%

void yyerror (char const *s) {
	fprintf (stderr, "Line %d: %s\n",getLineNumber(), s);
	exit(3);
}

/*

paramlist : param resto
	|
	;


resto : ',' param resto
	|
	;

param : LIT_INTEGER
	;


cmd::::

etapa2 teste.ling

deu um erro no trab dele pq nao tinha "<>" no scanner.l
faltava + coisa no scanner
*/