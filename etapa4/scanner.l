%{
	 
	//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)

	#include "hash.h"
	#include "astree.h" //problemas idiotas sendo resolvidos - C flat é uma piada de mau gosto
	#include "y.tab.h"

	int running = 1;
	int lineCount = 1;
%}

%x COMMENT

%%

\n		{lineCount++;}
byte	{return KW_BYTE;}
short	{return KW_SHORT;}
long	{return KW_LONG;}
float	{return KW_FLOAT;}
double	{return KW_DOUBLE;}
if		{return KW_IF;}
then	{return KW_THEN;}
else	{return KW_ELSE;}
while	{return KW_WHILE;}
for		{return KW_FOR;}
read	{return KW_READ;}
return	{return KW_RETURN;}
print	{return KW_PRINT;}


(<=)	{return OPERATOR_LE;}
(>=)	{return OPERATOR_GE;}
(==)	{return OPERATOR_EQ;}
(!=)	{return OPERATOR_NE;}
(&&)	{return OPERATOR_AND;}
(\|\|)	{return OPERATOR_OR;}


[a-zA-Z_]([a-zA-Z_0-9 ]*[a-zA-Z_0-9])?	{yylval.symbol = hash_insert(yytext,TK_IDENTIFIER);return TK_IDENTIFIER;}

[,;:\(\)\[\]{}\+\-\*/<>=!&\$#] {return yytext[0];}

[0-9]*			{yylval.symbol = hash_insert(yytext,LIT_INTEGER);return LIT_INTEGER;}
[0-9]*\.[0-9]*	{yylval.symbol = hash_insert(yytext,LIT_REAL);return LIT_REAL;}
\'.\'			{yylval.symbol = hash_insert(yytext,LIT_CHAR);return LIT_CHAR;}
\"[^\"\n]*\" 	{yylval.symbol = hash_insert(yytext,LIT_STRING);return LIT_STRING;}

"//".*

"/*"			{BEGIN COMMENT;}

<COMMENT>"*/" 	{BEGIN 0;}
<COMMENT>\n 	{lineCount++;}
<COMMENT>.


<<EOF>>		{running = 0; return 0;}
[ \t\r]+


.		{return TOKEN_ERROR;}

%%

int getLineNumber(){
	return lineCount;
}

int isRunning(){
	return running;
}

void initMe(){
	hash_create();
}

int yywrap(){
	return 1;
}
