#include <stdio.h>
#include <stdlib.h>


#include "y.tab.h"

extern FILE *yyin;

int main(int argc, char **argv){

	if(argc < 2){
		printf("Argumentos faltando, informe o nome do arquivo\nChamar ./etapa1 file_name\n");
	}
	else if((yyin = fopen(argv[1], "r")) != NULL){
		initMe();
		yyparse();
		/*while(isRunning()){
			int t = yylex();
			switch(t){
				case KW_SHORT:    
					printf("SHORT\n");
					break;
				case KW_LONG:
					printf("LONG\n");
					break;
				case KW_FLOAT:
					printf("FLOAT\n");
					break;
				case KW_DOUBLE:
					printf("DOUBLE\n");
					break;
				case KW_IF:
					printf("IF\n");   
					break;
				case KW_THEN:
					printf("THEN\n");
					break;
				case KW_ELSE:    
					printf("ELSE\n");
					break;
				case KW_WHILE:    
					printf("WHILE\n");
					break;
				case KW_FOR:    
					printf("FOR\n");
					break;
				case KW_READ:       
					printf("READ\n");
					break;
				case KW_RETURN:    
					printf("RETURN\n");
					break;
				case KW_PRINT:
					printf("PRINT\n");
					break;
				case OPERATOR_LE:   
					printf("LE\n");
					break;
				case OPERATOR_GE:
					printf("GE\n");
					break;
				case OPERATOR_EQ:   
					printf("EQ\n");
					break;
				case OPERATOR_NE:   
					printf("NE\n");
					break;
				case OPERATOR_AND: 
					printf("AND\n");
					break;
				case OPERATOR_OR:
					printf("OR\n");
					break;				
				case TK_IDENTIFIER: 
					printf("IDENTIFIER\n");
					break;
				case LIT_INTEGER:
					printf("LIT_INTEGER\n");
					break;
				case LIT_REAL:
					printf("LIT_REAL\n"); 
					break;
				case LIT_CHAR:
					printf("LIT_CHAR\n");
					break;				
				case LIT_STRING:
					printf("LIT_STRING\n");
					break;				
				case TOKEN_ERROR:
					printf("ERROR\n");
					break;
				case 0:
					printf("EOF\n");
					break;
				default:
					printf("%c\n",t);


			}
		}*/
	}
}