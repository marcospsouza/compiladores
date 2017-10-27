//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)

#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "astree.h" //erro idiota nível 2
#include "y.tab.h" //todo; check if this is necessary

extern FILE *yyin;


void initMe();
int yyparse();

int main(int argc, char **argv){

	if(argc < 2){
		printf("Argumentos faltando, informe o nome do arquivo\nChamar ./etapa1 file_name\n");
	}
	else if((yyin = fopen(argv[1], "r")) != NULL){
		initMe();
		yyparse();

		printf("Nenhum erro de sintaxe\n");
		exit(0);
	}
}