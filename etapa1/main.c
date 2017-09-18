#include <stdio.h>
#include <stdlib.h>

#include "tokens.h"

extern FILE *yyin;

int main(int argc, char **argv){

	initMe();
	while(1)
		yylex();
}