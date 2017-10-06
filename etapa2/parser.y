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
int yylex();
int yyerror(char *msg);

%}


%token KW_INT 		  256
%token KW_BYTE       256
// falta varios tokens que ele colocou




%%
program : cmdl

cmdl : cmd ';' cmdl
	|	
	;
cmd : KW_INT ';' TK_ID
	| KW_FOR '{' TK_ID '=' TK_LITINT  '<' TK_LITINT '}'
	| KW_INT ';' TK_ID '{' paramlist'}'
	; 
	

paramlist : param resto
	|
	;


resto : ',' param resto
	|
	;

param : TK_LITINT
	;


%%



int yyerrror(char *msg){
	fprint(stderr,"Eita, erro1!!@\n");
	exit(3);
}

/*
cmd::::

etapa2 teste.ling

deu um erro no trab dele pq nao tinha "<>" no scanner.l
faltava + coisa no scanner
*/