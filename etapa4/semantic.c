#include <stdlib.h>
#include "semantic.h"


void semanticSetTypes(AST* node){
	int i;
	if (!node) return;
	//process this node
	if(node->type == AST_VARDEC){
		if(node->symbol->tk_type != SYMBOL_ID){
			fprintf(stderr,"semantic error: identifier %s, already declared \n",node->symbol->value);
			exit(4); //deve vir depois, aqui cotinuar aserjaweirjaeijrieajriejrijeirj
		}
		else{
			node->symbol->tk_type = SYMBOL_VAR;
			if(node->son[0]->type == AST_KWBYTE) node->type = DATATYPE_BYTE;
			if(node->son[0]->type == AST_KWSHORT) node->type = DATATYPE_SHORT;
			if(node->son[0]->type == AST_KWLONG) node->type = DATATYPE_LONG;
			if(node->son[0]->type == AST_KWFLOAT) node->type = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KWDOUBLE) node->type = DATATYPE_DOUBLE;
		}
	}
	if(node->type == AST_VECDEC){
		if(node->symbol->tk_type != SYMBOL_ID){
			fprintf(stderr,"semantic error: identifier %s, already declared \n",node->symbol->value);
			exit(4); //deve vir depois, aqui cotinuar aserjaweirjaeijrieajriejrijeirj
		}
		else{
			node->symbol->tk_type = SYMBOL_VEC;
			if(node->son[0]->type == AST_KWBYTE) node->type = DATATYPE_BYTE;
			if(node->son[0]->type == AST_KWSHORT) node->type = DATATYPE_SHORT;
			if(node->son[0]->type == AST_KWLONG) node->type = DATATYPE_LONG;
			if(node->son[0]->type == AST_KWFLOAT) node->type = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KWDOUBLE) node->type = DATATYPE_DOUBLE;
		}
	}
	if (node->type == AST_FUNDEC){
		if(node->symbol->tk_type != SYMBOL_ID){
			fprintf(stderr, "Semantic ERROR: identifier %s already declared\n", node->symbol->value);
			exit(4);
		}
		else{
			node->symbol->tk_type = SYMBOL_FUN;
			if(node->son[0]->type == AST_KWBYTE) node->type = DATATYPE_BYTE;
			if(node->son[0]->type == AST_KWSHORT) node->type = DATATYPE_SHORT;
			if(node->son[0]->type == AST_KWLONG) node->type = DATATYPE_LONG;
			if(node->son[0]->type == AST_KWFLOAT) node->type = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KWDOUBLE) node->type = DATATYPE_DOUBLE;
		}
	}
	if(node->type == AST_ARGSDEF){
		if(node->symbol->tk_type != SYMBOL_ID){
			fprintf(stderr, "Semantic ERROR: identifier %s already declared\n", node->symbol->value);
			exit(4);
		}
		else{
			node->symbol->tk_type = SYMBOL_VAR;
			if(node->son[0]->type == AST_KWBYTE) node->type = DATATYPE_BYTE;
			if(node->son[0]->type == AST_KWSHORT) node->type = DATATYPE_SHORT;
			if(node->son[0]->type == AST_KWLONG) node->type = DATATYPE_LONG;
			if(node->son[0]->type == AST_KWFLOAT) node->type = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KWDOUBLE) node->type = DATATYPE_DOUBLE;
		}
	}


	for (i=0; i<MAX_SONS; ++i){
		semanticSetTypes(node->son[i]);
	}


}


void semanticCheckUndeclared(void){

	//hashCheckUndeclared();

}

void semanticCheckUsage(AST* node){
	int i;
	if (!node) return;
	//process this node

	if(node->type == AST_ASSIGN){
		if(node->symbol->tk_type != SYMBOL_VAR){
			fprintf(stderr, "Semantic ERROR: identifier %s must be a variable\n", node->symbol->value);
			exit(4);
		}
	}

	if(node->type == AST_VASSIGN || node->type == AST_VACCESS){
		if(node->symbol->tk_type != SYMBOL_VEC){ //nao tem isso aqui no nosso
			fprintf(stderr, "Semantic ERROR: identifier %s must be a vector\n", node->symbol->value);
			exit(4);
		}
	}

//tem que fazer umas correção autista de numero de linha
	//check if functions calls are calling functions
	if(node->type == AST_FUNCALL){
		if(node->symbol->tk_type != SYMBOL_FUN){ //tem que informar numero da linha que? agora o get lliine number daria sempre eof
			fprintf(stderr, "Semantic ERROR: identifier %s must be a function\n", node->symbol->value);
			exit(4); //isso deveria ser uma flag global pra mostrar erro na main, e não uma parada de erro realmente
		}
	}

	for (i=0; i<MAX_SONS; ++i){
		semanticCheckUsage(node->son[i]);
	}

}
void semanticCheckOperands(AST* node){
	int i;
	if (!node) return;
	//process this node

	//check operands of arithmetical operators
	if (node->type == AST_ADD || node->type == AST_SUB || node->type == AST_MUL || node->type == AST_DIV){
		//check first operand
		if(node->son[0]->type == AST_GT || node->son[0]->type == AST_LS || node->son[0]->type == AST_GE || node->son[0]->type == AST_LE
			|| node->son[0]->type == AST_NE || node->son[0]->type == AST_EQ || node->son[0]->type == AST_OR || node->son[0]->type == AST_AND
			|| node->son[0]->type == AST_NOT){

			fprintf(stderr, "Semantic ERROR: left operand of cannot be a logical operand (>, <, >=, <=, !=, ==, ||, &&, !)\n");
			exit(4);


		}
		//check seconds operand
		if(node->son[1]->type == AST_GT || node->son[1]->type == AST_LS || node->son[1]->type == AST_GE || node->son[1]->type == AST_LE
			|| node->son[1]->type == AST_NE || node->son[1]->type == AST_EQ || node->son[1]->type == AST_OR || node->son[1]->type == AST_AND
			|| node->son[1]->type == AST_NOT){

			fprintf(stderr, "Semantic ERROR: right operand of cannot be a logical operand (>, <, >=, <=, !=, ==, ||, &&, !)\n");
			exit(4);


		}
	}
	//check operands of logical operators
	if (node->type == AST_ADD ||node->type == AST_MUL){
		//check first operand
		if(node->son[0]->type == AST_GREATER){

			fprintf(stderr, "Semantic ERROR: left operand of cannot be >\n");
			exit(4);


		}
		//check seconds operand
		if(node->son[1]->type == AST_GREATER){

			fprintf(stderr, "Semantic ERROR: right operand of cannot be >\n");
			exit(4);


		}
	}
	//check assigment (real to real, int to int)
	if (node->type == AST_ADD ||node->type == AST_MUL){
		//check first operand
		if(node->son[0]->type == AST_GREATER){

			fprintf(stderr, "Semantic ERROR: left operand of cannot be >\n");
			exit(4);


		}
		//check seconds operand
		if(node->son[1]->type == AST_GREATER){

			fprintf(stderr, "Semantic ERROR: right operand of cannot be >\n");
			exit(4);


		}
	}



	for (i=0; i<MAX_SONS; ++i){
		semanticSetTypes(node->son[i]);
	}
}










