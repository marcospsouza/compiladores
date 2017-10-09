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

vardec : TK_IDENTIFIER ':' vartypeandlist '=' lit ';'
	| TK_IDENTIFIER ':' vartypeandlist ';'
	;

litlist: lit
	| lit litlist
	|
	;

vartypeandlist: KW_BYTE
	| KW_SHORT
	| KW_LONG
	| KW_FLOAT
	| KW_DOUBLE
	| KW_SHORT '[' LIT_INTEGER ']' litlist
	| KW_LONG '[' LIT_INTEGER ']' litlist
	;

lit: LIT_INTEGER
	| LIT_REAL
	| LIT_CHAR
	| LIT_STRING
	;


fundec : '(' vartype ')' TK_IDENTIFIER '(' argsdef ')' cmd
	;

args: exp arglist
	| 
	;

arglist: ',' exp arglist
	|
	;

argsdef: TK_IDENTIFIER ':' vartype argsdeflist
	| 
	;

argsdeflist: ',' argsdef argsdeflist
	|
	;

vartype: KW_BYTE
	| KW_SHORT
	| KW_LONG
	| KW_FLOAT
	| KW_DOUBLE

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
	| LIT_STRING ',' printargs
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
    | exp op exp
	;

op: OPERATOR_LE
    | OPERATOR_GE
    | OPERATOR_EQ
    | OPERATOR_NE
    | OPERATOR_AND
    | OPERATOR_OR
    | '*'
    | '/'
    | '+'
    | '-'
    | '>'
    | '<'
    | '!' 
	;  

block : '{' lcmd '}'
	;

lcmd : lcmd cmd ';'
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