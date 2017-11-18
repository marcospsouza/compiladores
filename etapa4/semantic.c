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
		//se a leitura ou escrita estiver sendo feita realmente em um vetor, checa se o indice é válido
		else{
			//percorre a árvore e checa se resultado é int, ACESSO A VETOR SOMENTE COM INT (byte, short, long e literais char, int)
			if (!checkInt(node->son[0])){
				fprintf(stderr, "Semantic ERROR: vector index must be an integer\n", node->symbol->value);
			}
		}
	}

	//tem que fazer umas correção autista de numero de linha
	if(node->type == AST_FUNCALL){
		if(node->symbol->tk_type != SYMBOL_FUN){ //tem que informar numero da linha que? agora o get lliine number daria sempre eof
			fprintf(stderr, "Semantic ERROR: identifier %s must be a function\n", node->symbol->value);
			exit(4); //isso deveria ser uma flag global pra mostrar erro na main, e não uma parada de erro realmente
		}
		//checar argumentos da funçao AINDA NUM FIZ ISSO
		else{
			if(!checkArgs(node->son[0]))
				fprintf(stderr, "A");
		}
	}

	for (i=0; i<MAX_SONS; ++i){
		semanticCheckUsage(node->son[i]);
	}

}

//essa funçao n faz sentido, entendi nada
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

			fprintf(stderr, "Semantic ERROR: left operand of arithmetical operation cannot be a logical operand (>, <, >=, <=, !=, ==, ||, &&, !)\n");
			exit(4);
		}
		//check second operand
		if(node->son[1]->type == AST_GT || node->son[1]->type == AST_LS || node->son[1]->type == AST_GE || node->son[1]->type == AST_LE
			|| node->son[1]->type == AST_NE || node->son[1]->type == AST_EQ || node->son[1]->type == AST_OR || node->son[1]->type == AST_AND
			|| node->son[1]->type == AST_NOT){

			fprintf(stderr, "Semantic ERROR: right operand of arithmetical operation cannot be a logical operand (>, <, >=, <=, !=, ==, ||, &&, !)\n");
			exit(4);
		}
	}
	//check operands of logical operators
	if (node->type == AST_ADD || node->type == AST_MUL){
		//check first operand
		if(node->son[0]->type == AST_GREATER){
			fprintf(stderr, "Semantic ERROR: left operand of cannot be >\n");
			exit(4);
		}
		//check second operand
		if(node->son[1]->type == AST_GREATER){
			fprintf(stderr, "Semantic ERROR: right operand of cannot be >\n");
			exit(4);		
		}
	}
	//check assigment (real to real, int to int)
	if (node->type == AST_ADD || node->type == AST_MUL){
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

int checkInt(AST* node){  
	//operaçoes booleanas nunca resultarão em INT
	if(node->type == AST_NOT || node->type == AST_GT || node->type == AST_LS || node->type == AST_GE || node->type == AST_LE ||
	 	node->type == AST_EQ || node->type == AST_NE || node->type == AST_AND || node->type == AST_OR){
		return 0;
	}
	// operaçoes artitmeticas podem ser INT ou FLOAT, checar nodos filhos
	if(node->type == AST_MUL || node->type == AST_DIV || node->type == AST_ADD || node->type == AST_SUB){
		return (checkInt(node->son[0]) && checkInt(node->son[1]));
	}
	// '(' exp ')'
	if(node->type == AST_EXP){
		return checkInt(node->son[0]);
	}
	// N SEI SE TEM Q ACEITAR CHAR AQUI
	if(node->type == AST_SYMBOL || node->type == AST_VACCESS || node->type == AST_FUNCALL){
		if(node->symbol->tk_type != SYMBOL_LIT_INT && node->symbol->tk_type != DATATYPE_BYTE && node->symbol->tk_type != DATATYPE_SHORT
			&& node->symbol->tk_type != DATATYPE_LONG)
			return 0;
		else return 1;
	}
}
// PUTA MAO DO CARALHO ESTA BOSTA
int checkArgs(AST* node){
	/*args: exp ',' args { $$ = astCreate(AST_ARGS,0,$1,$3,0,0); }
	| exp { $$ = astCreate(AST_ARGS,0,$1,0,0,0); }
	;*/

	return 1;

}







