%{
#include <stdio.h>
#include <stdlib.h>
#include "hash.c"
#include "tokens.h"

;int running = 1;
int lineCount = 0;


int getLineNumber(){
	return lineCount;
}

int isRunning(){
	return running;
}


void yyerror (char const *s) {
	fprintf (stderr, "Line %d: %s\n",getLineNumber(), s);
	//exit(3);
}
%}

%x COMMENT

%%

\n		{lineCount++;}
int		{fprintf(stderr, "found int kw\n");return KW_INT;}
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

[a-zA-Z_][a-zA-Z_0-9 \t]*[a-zA-Z_0-9]	{return TK_IDENTIFIER;}

(<=)	{return OPERATOR_LE;}
(>=)	{return OPERATOR_GE;}
(==)	{return OPERATOR_EQ;}
(!=)	{return OPERATOR_NE;}
(&&)	{return OPERATOR_AND;}
(\|\|)	{return OPERATOR_OR;}

[0-9]*	{return LIT_INTEGER;}
[0-9]*\.[0-9]*		{return LIT_REAL;}
\'.\'	{return LIT_CHAR;}
\"[^\"\n]*\"	{return LIT_STRING;}

"//".*

[,;:\(\)\[\]{}\+\-\*/<>=!&\$#] {return yytext[0];}
.		{return TOKEN_ERROR;}



%%

int yywrap(){
	return 1;
}

int main(){
	while(1)
		yylex();
}