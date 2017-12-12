//Feito por Marcos Praisler de Souza (242239) e João Batista Henz (242251)

#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "astree.h" 
#include "y.tab.h" 

extern FILE *yyin;


void initMe();
int yyparse();

int main(int argc, char **argv){

	if(argc < 2){
		printf("Argumentos faltando, informe o nome do arquivo\nChamar ./etapa1 file_name output_file\n");
		exit(1);
	}
	else if((yyin = fopen(argv[1], "r")) != NULL){
		if(source_code = fopen(argv[2],"w+")){
		
			initMe();
			yyparse();


			fclose(source_code);
			printf("Nenhum erro de sintaxe\n");
			exit(0);
		}
		else
			fprintf(stderr, "Erro ao criar o arquivo de saída.\n");		
	}
	else{
		exit(2);
	}
}