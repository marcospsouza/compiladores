#ifndef ASTREE_C
#define ASTREE_C

#include "hash.h"
#include "astree.h"
#include <stdio.h>
#include <stdlib.h>


AST* astCreate(int type, HASH_NODE *symbol, AST* son0, AST* son1, AST* son2,AST* son3){
	AST* newnode;
	newnode =  (AST*)calloc(1,sizeof(AST));
	newnode->type = type;
	newnode->node_line = getLineNumber();
	newnode->symbol = symbol;
	newnode->son[0]= son0;
	newnode->son[1]= son1;
	newnode->son[2]= son2;
	newnode->son[3]= son3;
	return newnode;
}

//não copiada 100%
void astPrint(AST * node,int level){
	int i;

	if(node){
		for(i=0; i < level; i++)
			fprintf(stderr, " ");

		fprintf(stderr, "AST( ");
		switch(node->type){
			case AST_SYMBOL: fprintf(stderr, "SYMBOL,");break;
			case AST_ADD: fprintf(stderr, "AST_ADD,");break;
			case AST_SUB: fprintf(stderr, "AST_SUB,");break;			
			case AST_MUL: fprintf(stderr, "AST_MUL,");break;
			case AST_DIV: fprintf(stderr, "AST_DIV,");break;
			case AST_GT: fprintf(stderr, "AST_GT,");break;
			case AST_LS: fprintf(stderr, "AST_LS,");break;
			case AST_NOT: fprintf(stderr, "AST_NOT,");break;

			case AST_LE: fprintf(stderr, "AST_LE,");break;
			case AST_GE: fprintf(stderr, "AST_GE,");break;
			case AST_EQ: fprintf(stderr, "AST_EQ,");break;			
			case AST_NE: fprintf(stderr, "AST_NE,");break;
			case AST_OR: fprintf(stderr, "AST_OR, ");break;
			case AST_AND: fprintf(stderr, "AST_AND,");break;
			case AST_INT: fprintf(stderr, "AST_INT,");break;
			case AST_CHAR: fprintf(stderr, "AST_CHAR,");break;
			case AST_REAL: fprintf(stderr, "AST_REAL,");break;				

			case AST_KWBYTE: fprintf(stderr, "AST_KWBYTE,");break;
			case AST_KWSHORT: fprintf(stderr, "AST_KWSHORT,");break;
			case AST_KWLONG: fprintf(stderr, "AST_KWLONG,");break;			
			case AST_KWFLOAT: fprintf(stderr, "AST_KWFLOAT,");break;
			case AST_KWDOUBLE: fprintf(stderr, "AST_KWDOUBLE,");break;
			case AST_KWIF: fprintf(stderr, "AST_KWIF,");break;
			case AST_KWTHEN: fprintf(stderr, "AST_KWTHEN,");break;
			case AST_KWELSE: fprintf(stderr, "AST_KWELSE,");break;	

			case AST_KWWHILE: fprintf(stderr, "AST_KWWHILE,");break;
			case AST_KWFOR: fprintf(stderr, "AST_KWFOR,");break;
			case AST_KWREAD: fprintf(stderr, "AST_KWREAD,");break;			
			case AST_KWRETURN: fprintf(stderr, "AST_KWRETURN,");break;
			case AST_KWPRINT: fprintf(stderr, "AST_KWPRINT,");break;
			case AST_TKID: fprintf(stderr, "AST_TKID,");break;
			case AST_EXP: fprintf(stderr, "AST_EXP,");break;
			case AST_LCMD: fprintf(stderr, "AST_LCMD,");break;	

			case AST_CMD: fprintf(stderr, "AST_CMD,");break;
			case AST_BLOCK: fprintf(stderr, "AST_BLOCK,");break;			
			case AST_DECL: fprintf(stderr, "AST_DECL,");break;
			case AST_DEC: fprintf(stderr, "AST_DEC,");break;
			case AST_VARDEC: fprintf(stderr, "AST_VARDEC,");break;
			case AST_VECDEC: fprintf(stderr, "AST_VECDEC,");break;
			case AST_FUNDEC: fprintf(stderr, "AST_FUNDEC,");break;
			case AST_FUNCALL: fprintf(stderr, "AST_FUNCALL,");break;
			case AST_VASSIGN: fprintf(stderr, "AST_VASSIGN,");break;
			case AST_VACCESS: fprintf(stderr, "AST_VACCESS,");break;
			case AST_VTL: fprintf(stderr, "AST_VTL,");break;	

			case AST_LIT: fprintf(stderr, "AST_LIT,");break;
			case AST_LITLIST: fprintf(stderr, "AST_LITLIST,");break;
			case AST_VARTYPE: fprintf(stderr, "AST_VARTYPE,");break;			
			case AST_ARGSDEF: fprintf(stderr, "AST_ARGSDEF,");break;
			case AST_ASSIGN: fprintf(stderr, "AST_ASSIGN,");break;
			case AST_PRINTARGS: fprintf(stderr, "AST_PRINTARGS,");break;
			case AST_ARGS: fprintf(stderr, "AST_ARGS,");break;

			default: fprintf(stderr, "UNKNOWN\n");break;

		}
		if(node->symbol)
			fprintf(stderr, "%s\n",node->symbol->value);
		else
			fprintf(stderr, "0\n");



		for(i=0; i < MAX_SONS; i++)
			astPrint(node->son[i], level+1);
	

	}
}
void printSource(AST *root){
	
	printnodeSource(root, source_code);


}

void printnodeSource(AST *node, FILE *source_code){
	if(node){
		switch(node->type){

			case AST_DECL: 
				printnodeSource(node->son[0], source_code);
				printnodeSource(node->son[1], source_code);
				break;

			case AST_VARDEC: 
				fprintf(source_code, "%s: ", node->symbol->value);
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, " = ");
				printnodeSource(node->son[1], source_code);
				fprintf(source_code, ";\n");
				break;

			case AST_VECDEC:
				fprintf(source_code, "%s: ", node->symbol->value);
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, "[");
				printnodeSource(node->son[1], source_code);
				fprintf(source_code, "]");
				if(node->son[2]!=0){
					fprintf(source_code, " ");
					printnodeSource(node->son[2], source_code);
				}
				fprintf(source_code, ";\n");
				break;
			case AST_LITLIST:
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, " ");
				printnodeSource(node->son[1], source_code);
				break;

			case AST_SYMBOL: 
				fprintf(source_code, "%s", node->symbol->value);
				if(node->son[0] != 0){
					fprintf(source_code, " ");
					printnodeSource(node->son[0], source_code);
				}
				break;

			case AST_FUNCALL:
				fprintf(source_code, "%s(", node->symbol->value);
            	printnodeSource(node->son[0], source_code);
            	fprintf(source_code, ")");
				break;
			case AST_VASSIGN:				
				fprintf(source_code, "%s", node->symbol->value);
				fprintf(source_code, "[");
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, "] =");
				printnodeSource(node->son[1], source_code);
				break;

			case AST_VACCESS:
				fprintf(source_code, "%s",node->symbol->value );
				fprintf(source_code, "[");
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, "]");
				break;

			case AST_FUNDEC: 
				fprintf(source_code, "(");
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, ") ");
				fprintf(source_code, "%s(", node->symbol->value);
				printnodeSource(node->son[2], source_code);
				fprintf(source_code, ")");
				printnodeSource(node->son[3], source_code);
				fprintf(source_code, "\n");
				break;


			case AST_ARGSDEF: 
				fprintf(source_code, "%s:", node->symbol->value);
				printnodeSource(node->son[0], source_code);
				if(node->son[1] != 0){
					fprintf(source_code, ", ");
					printnodeSource(node->son[1], source_code);
				}
				break;

			case AST_ARGS: 
				fprintf(source_code, "%s ", node->son[0]->symbol->value);
				printnodeSource(node->son[0]->son[0], source_code);
				if(node->son[1] != 0){
					fprintf(source_code, ", ");
					printnodeSource(node->son[1], source_code);
				}
				break;

			case AST_BLOCK:
				fprintf(source_code, "{\n");
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, "\n}");
				break;
			case AST_LCMD: 
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, ";\n");
				printnodeSource(node->son[1], source_code);
				break;

			case AST_ASSIGN: 
				fprintf(source_code, "%s=", node->symbol->value);
				printnodeSource(node->son[0], source_code);
				break;
			case AST_KWBYTE: 
				fprintf(source_code, "byte"); 
				break;
			case AST_KWSHORT: 
				fprintf(source_code, "short"); 
				break;
			case AST_KWLONG: 
				fprintf(source_code, "long"); 
				break;
			case AST_KWFLOAT: 
				fprintf(source_code, "float"); 
				break;
			case AST_KWDOUBLE: 
				fprintf(source_code, "double"); 
				break;
			case AST_KWREAD: 
				fprintf(source_code, "read > ");
				fprintf(source_code, "%s", node->symbol->value);
				break;
			case AST_KWRETURN: 
				fprintf(source_code, "return ");
				printnodeSource(node->son[0], source_code);
				break;
			case AST_KWPRINT: 
				fprintf(source_code, "print ");
				printnodeSource(node->son[0], source_code);
				break;

			case AST_PRINTARGS: 
				printnodeSource(node->son[0], source_code);
				if(node->son[1] != 0){
					fprintf(source_code, ", ");
					printnodeSource(node->son[1], source_code);
				}
				break;
			case AST_KWIF: 
				fprintf(source_code, "if (");
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, ") then\n\t");
				printnodeSource(node->son[1], source_code);
				fprintf(source_code, "\n");
				if(node->son[2] != 0){
					fprintf(source_code, "else\n\t");
					printnodeSource(node->son[2], source_code);
				}
				break;

	      	case AST_EXP: fprintf(source_code, "( ");
	            printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " )");
	            break;

	        /*case AST_KWFOR: 
				fprintf(stderr, "for (");
				printnodeSource(node->son[0], source_code);
				fprintf(stderr, ")\n\t");
				printnodeSource(node->son[1], source_code);
				break;*/

			case AST_KWWHILE: 
				fprintf(source_code, "while (");
				printnodeSource(node->son[0], source_code);
				fprintf(source_code, ")\n\t");
				printnodeSource(node->son[1], source_code);
				break;
	      	case AST_ADD: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " + ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_SUB: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " - ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_MUL: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " * ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_DIV: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " / ");
	            printnodeSource(node->son[1], source_code);
	            break;	      	
	        case AST_LE: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " <= ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_GE: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " >= ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_EQ: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " == ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_NE: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " != ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_AND: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " && ");
	            printnodeSource(node->son[1], source_code);
	            break;
			case AST_OR: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " || ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_LS: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " < ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_GT: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " > ");
	            printnodeSource(node->son[1], source_code);
	            break;
	      	case AST_NOT: printnodeSource(node->son[0], source_code);
	            fprintf(source_code, " ! ");
	            printnodeSource(node->son[1], source_code);
	            break;

			default: fputs("UNKNOWN", source_code); break;
		}
	}
}

#endif
