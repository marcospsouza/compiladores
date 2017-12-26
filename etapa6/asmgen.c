#include "asmgen.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int searchStr(char* string){

	for(int i = 0; i < 100; i++)
		if(strcmp(string, strings_list[i]) == 0)
			return i;
	
}

void asmGenerator(char *filename, TAC* code){
	TAC *tac;
	FILE *fout;
	int count = 0;

	if(!(fout = fopen(filename, "w"))){
		fprintf(stderr,"Couldn't open ASM output file.\n");
		exit(5);
	}

	for(int i = 0; i < HASH_SIZE; i++){
		for(HASH_NODE *n = table[i]; n; n = n->next){

			if(n->tk_type == SYMBOL_TEMPORARY_VAR)
				fprintf(fout,".comm %s, 4, 4\n",n->value);

			if(n->tk_type == LIT_STRING){
				fprintf(fout,"\nstring%d_label:\n"
				"\t.string %s\n\n", count, n->value);

				strcpy(strings_list[count], n->value);
				count++;
			}

		}
	}
	//fprintf(fout, ".data\n");

	for (tac=code; tac != NULL; tac=tac->next){
		fprintf(fout, "\n");
		switch(tac->type){

  			case TAC_BEGINFUN:fprintf(fout, "##BEGFUN\n"
  							 				".text\n"
											".globl	%s\n"
											".type	%s, @function\n"
											"%s:\n"
											"\tpushq	%rbp\n"
											"\tmovq	%rsp, %rbp\n", tac->res->value, tac->res->value, tac->res->value);
    			break;

  			case TAC_ENDFUN: 
    			fprintf(fout,"\n"
                			 "\t\n"
                 			 "\t\n"
                 			 "\t\n");
    			break;

			case TAC_PRINTARG: fprintf(fout, "## PRINT\n"
											"\tmovl $string%d_label, %%edi\n"
											"\tcall printf\n", searchStr(tac->res->value));
				break;

			case TAC_VARDEC: fprintf(fout, "##VARDEC\n"
											"\t.globl	%s\n"
											"\t.align 4\n"
											"\t.type	%s, @object\n"
											"\t.size	%s, 4\n"
											"a:\n"
											"\t.long	%s", tac->res->value, tac->res->value, tac->res->value, tac->op1->value);
				break;

  			case TAC_ADD: fprintf(fout,"##TAC ADD\n");break;
  			case TAC_ASSIGN: fprintf(fout,"##TAC_ASSIGN");break;
		}
	}

	fclose(fout);
}
