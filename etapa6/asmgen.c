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

	fprintf(fout, ".data\n");
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



	for (tac=code; tac != NULL; tac=tac->next){
		
		switch(tac->type){
			case TAC_LABEL: fprintf(fout, "\n.%s:\n", tac->res->value); break;
			case TAC_FUNCALL: fprintf(fout, "\n##FUNCALL\n"
											"\tmovl $0, %%eax\n"
											"\tcall %s\n", tac->res->value);
				break;
  			case TAC_BEGINFUN:fprintf(fout, "\n##BEGFUN\n"
  							 				".text\n"
											".globl	%s\n"
											".type	%s, @function\n\n"
											"%s:\n"
											"\tpushq	%%rbp\n"
											"\tmovq	%%rsp, %%rbp\n", tac->res->value, tac->res->value, tac->res->value);
    			break;

  			case TAC_ENDFUN: 
    			fprintf(fout,  "\n\tpopq	%%rbp\n"
								"\tret\n");
    			break;

    		case TAC_RETURN:
    			if(tac->res->tk_type == LIT_INTEGER)
    				fprintf(fout, "movl $%s, %%eax\n", tac->res->value);
    			else
    				fprintf(fout, "movl %s(%%rip), %%eax\n", tac->res->value);
    			break;

			case TAC_PRINTARG: fprintf(fout, "\n## PRINT\n"
											"\tmovl $string%d_label, %%edi\n"
											"\tcall printf\n", searchStr(tac->res->value));
				break;

			case TAC_VARDEC: fprintf(fout, "\n##VARDEC\n"
											"\t.globl	%s\n"
											"\t.align 4\n"
											"\t.type	%s, @object\n"
											"\t.size	%s, 4\n"
											"%s:\n"
											"\t.long	%s", tac->res->value, tac->res->value, tac->res->value, tac->res->value, tac->op1->value);
				break;

			case TAC_VECDEC: fprintf(fout, "##VECDEC\n"
											".comm	%s,%d,32\n", tac->res->value, atoi(tac->op1->value) * 4);
				break;
  			
  			case TAC_JMP: fprintf(fout, "\n\tjmp .%s\n", tac->res->value); break;
			case TAC_JZ: fprintf(fout, " .%s\n", tac->res->value);break;

			case TAC_GT: fprintf(fout, "\n##GREATER\n");
						if (tac->op1->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
						if (tac->op2->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
						fprintf(fout, "\tcmpl %%eax, %%edx\n");
						fprintf(fout, "\tjle");
				break;

			case TAC_LS: fprintf(fout, "\n##LESS\n");
						if (tac->op1->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
						if (tac->op2->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
						fprintf(fout, "\tcmpl %%eax, %%edx\n");
						fprintf(fout, "\tjge");
				break;

			case TAC_GE: fprintf(fout, "\n##GREATER OR EQUAL\n");
						if (tac->op1->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
						if (tac->op2->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
						fprintf(fout, "\tcmpl %%eax, %%edx\n");
						fprintf(fout, "\tjl");
				break;

			case TAC_LE: fprintf(fout, "\n##LESS OR EQUAL\n");
						if (tac->op1->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
						if (tac->op2->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
						fprintf(fout, "\tcmpl %%eax, %%edx\n");
						fprintf(fout, "\tjg");
				break;

			case TAC_EQ: fprintf(fout, "\n##EQUAL\n");
						if (tac->op1->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
						if (tac->op2->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
						fprintf(fout, "\tcmpl %%eax, %%edx\n");
						fprintf(fout, "\tjne");
				break;


			case TAC_NE: fprintf(fout, "\n##NOT EQUAL\n");
						if (tac->op1->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
						if (tac->op2->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
						else
							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
						fprintf(fout, "\tcmpl %%eax, %%edx\n");
						fprintf(fout, "\tjne");
				break;


  			case TAC_ADD: fprintf(fout,"\n##ADD\n");
  						if (tac->op1->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
  						if (tac->op2->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
  						fprintf(fout, "\taddl %%edx, %%eax\n");
  						fprintf(fout, "\tmovl %%eax, %s(%%rip)\n", tac->res->value);
  				break;

  			case TAC_SUB: fprintf(fout,"\n##SUB\n");
  						if (tac->op1->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
  						if (tac->op2->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
  						fprintf(fout, "\tsubl %%edx, %%eax\n");
  						fprintf(fout, "\tmovl %%eax, %s(%%rip)\n", tac->res->value);
  				break;

  			case TAC_MUL: fprintf(fout,"\n##MUL\n");
  						if (tac->op1->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%edx\n", tac->op1->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%edx\n", tac->op1->value);
  						if (tac->op2->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op2->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op2->value);
  						fprintf(fout, "\timull %%edx, %%eax\n");
  						fprintf(fout, "\tmovl %%eax, %s(%%rip)\n", tac->res->value);
  				break;

  			case TAC_DIV: fprintf(fout,"\n##DIV\n");
  						if (tac->op1->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%eax\n", tac->op1->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op1->value);
  						if (tac->op2->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %%ecx\n", tac->op2->value);
  						else 
  							fprintf(fout, "\tmovl %s(%%rip), %%ecx\n", tac->op2->value);

  						fprintf(fout, "cltd\n"
  								"idivl %%ecx\n"
  								"movl %%eax, %s(%%rip)\n", tac->res->value);
  				break;


  			case TAC_ASSIGN: fprintf(fout,"\n##ASSIGN\n");
  						if (tac->prev->type == TAC_FUNCALL)
							fprintf(fout, "\tmovl %%eax, %s(%%rip)\n", tac->res->value);
  						else if (tac->op1->tk_type == LIT_INTEGER)
  							fprintf(fout, "\tmovl $%s, %s(%%rip)\n", tac->op1->value, tac->res->value);
  						else{
  							fprintf(fout, "\tmovl %s(%%rip), %%eax\n", tac->op1->value);
  							fprintf(fout, "\tmovl %%eax, %s(%%rip)\n", tac->res->value);
						}
				break;

			case TAC_VASSIGN: fprintf(fout, "\n##VEC ASSIGN\n");
  						if (tac->prev->type == TAC_FUNCALL)
							fprintf(fout, "\tmovl %%eax, %s+%d(%%rip)\n", tac->res->value, atoi(tac->op1->value) * 4);
						else if(tac->prev->type == TAC_VACCESS){
							fprintf(fout, "\tmovl %s+%d(%%rip), %%eax\n"
											"\tmovl %%eax, %s+%d(%%rip)\n", tac->prev->op1->value, atoi(tac->prev->op2->value) * 4,
											tac->res->value, atoi(tac->op1->value) * 4);
						}
						else if (tac->op2->tk_type == LIT_INTEGER)
							fprintf(fout, "\tmovl $%s, %s+%d(%%rip)\n", tac->op2->value, tac->res->value, atoi(tac->op1->value) * 4);
						else{ //var
							fprintf(fout, "\tmovl %s(%%rip), %%eax\n"
											"\tmovl %%eax, %s+%d(%%rip)\n", tac->op2->value, tac->res->value, atoi(tac->op1->value) * 4);
						}
						
				break;

			case TAC_VACCESS: fprintf(fout, "\n##VEC READ\n");
						fprintf(fout,"\tmovl	%s+%d(%%rip), %%eax\n"
									"\tmovl	%%eax, %s(%%rip)\n", tac->op1->value, atoi(tac->op2->value) * 4, tac->res->value);
				break;

		}
	}

	fclose(fout);
}
