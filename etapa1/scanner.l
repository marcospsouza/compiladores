%{
	int lineCount = 0;
%}

%%

	\n		{lineCount++;}
	int		{return KW_INT;}
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

	[_A-Za-z][_A-Za-z0-9]*	{return TK_IDENTIFIER;}

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