



#include "semantic.h"


void semanticSetTypes(AST* node){

	if (!node) return;
	//process this node
	if(node->type == AST_VARDEC){
		if(node->symbol->type != SYMBOL_ID){
			fprintf(stderr,"semantic error: identifier %s, already declared \n",node->symbol->text);
			exit(4); //deve vir depois, aqui cotinuar aserjaweirjaeijrieajriejrijeirj
		}
		else{
			node->symbol->type = SYMBOL_VAR;
			if(node->son[0]->type == AST_TYPECHAR) node->symbol->datatype = DATATYPE_CHAR;
			if(node->son[0]->type == AST_TYPEINT) node->symbol->datatype = DATATYPE_INT;
		}
	}
	if (node->type == AST_FUNDEC){
		if(node->symbol->type != SYMBOL_ID){
			fprintf(stderr, "Semantic ERROR: identifier %s already declared\n", node->symbol->text);
		exit(4);
		}
		else{
			node->symbol->type = SYMBOL_FUN;
			if(node->son[0]->type == AST_TYPECHAR) node->symbol->datatype = DATATYPE_CHAR;
			if(node->son[0]->type == AST_TYPEINT) node->symbol->datatype = DATATYPE_INT;
		}
	}


	for (i=0; i<MAX_SONS; ++i){
		semanticSetTypes(node->son[i]);
	}


}


void semanticCheckUndeclared(void){

	hashCheckUndeclared();

}

void semanticCheckUsage(AST* node){
	if (!node) return;
	//process this node

	//check left-hand side for scalar 
	if(node->type == AST_ASS){
		if(node->symbol->type != SYMBOL_VAR){
			fprintf(stderr, "Semantic ERROR: identifier %s must be scalar\n", node->symbol->text);
			exit(4);
		}
	}

	//check right-hand side for scalar 
	if(node->type == AST_SYMBOL){
		if(node->symbol->type != SYMBOL_VAR && node->symbol->type != SYMBOL_LIT_INT){ //nao tem isso aqui no nosso
			fprintf(stderr, "Semantic ERROR: identifier %s must be scalar\n", node->symbol->text);
			exit(4);
		}
	}

//tem que fazer umas correção autista de numero de linha
	//check if functions calls are calling functions
	if(node->type == AST_FUNCALL){
		if(node->symbol->type != SYMBOL_FUN){ //tem que informar numero da linha que? agora o get lliine number daria sempre eof
			fprintf(stderr, "Semantic ERROR: identifier %s must be scalar\n", node->symbol->text);
			exit(4); //isso deveria ser uma flag global pra mostrar erro na main, e não uma parada de erro realmente
		}
	}



	for (i=0; i<MAX_SONS; ++i){
		semanticCheckUsage(node->son[i]);
	}

}
void semanticCheckOperands(AST* node){
	if (!node) return;
	//process this node

	//check operands of arithmetical operators
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










