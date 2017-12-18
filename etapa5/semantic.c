#ifndef SEMANTIC_C
#define SEMANTIC_C

#include <stdlib.h>
#include <string.h>

#include "semantic.h"

int checkBool(AST* node);
int checkReal(AST* node);


void semanticCheckUndeclared(void){

	HASH_NODE *n;

	for(int i = 0; i < HASH_SIZE; i++){
		for(n = table[i]; n != NULL; n = n->next){
			if(n->tk_type == TK_IDENTIFIER){
				fprintf(stderr, "Semantic ERROR on line %d: identifier %s undeclared\n",n->node_line, n->value);
				exit(4);
			}
		}
	}
	//hashCheckUndeclared();

}

void checkVecInit(AST* node, int type){

	AST* arg_pointer = node;
	int count = 0;
	while(arg_pointer != NULL){
		if(type == AST_KWBYTE || type == AST_KWSHORT || type == AST_KWLONG){
			if(arg_pointer->son[0]->symbol->tk_type == LIT_REAL){
				fprintf(stderr, "Semantic ERROR on line %d: initializer must be integer\n", node->node_line);
				exit(4);
			}
		}
		else if (type == AST_KWDOUBLE || type == AST_KWFLOAT){
			if(arg_pointer->son[0]->symbol->tk_type == LIT_CHAR || arg_pointer->son[0]->symbol->tk_type == LIT_INTEGER){
				fprintf(stderr, "Semantic ERROR on line %d: initializer must be real\n", node->node_line);
				exit(4);
			}
		}
		arg_pointer = arg_pointer->son[1];
	}
}

void semanticSetTypes(AST* node){
	int i;
	if (!node) return;

	if(node->type == AST_VARDEC){
		if(node->symbol->tk_type != TK_IDENTIFIER){
			fprintf(stderr,"Semantic ERROR on line %d: identifier %s, already declared \n",  node->node_line,node->symbol->value);
			exit(4); 
		}
		else{
			node->symbol->tk_type = SYMBOL_VAR;
			if(node->son[0]->type == AST_KWBYTE){
				if(node->son[1]->symbol->tk_type != LIT_INTEGER && node->son[1]->symbol->tk_type != LIT_CHAR){
					fprintf(stderr, "Semantic ERROR on line %d: initializer must be integer\n", node->node_line);
					exit(4);
				}
				node->symbol->data_type = DATATYPE_BYTE;
			}
			if(node->son[0]->type == AST_KWSHORT){
				if(node->son[1]->symbol->tk_type != LIT_INTEGER && node->son[1]->symbol->tk_type != LIT_CHAR){
					fprintf(stderr, "Semantic ERROR on line %d: initializer must be integer\n", node->node_line);
					exit(4);
				}
				node->symbol->data_type = DATATYPE_SHORT;
			}
			if(node->son[0]->type == AST_KWLONG){
				if(node->son[1]->symbol->tk_type != LIT_INTEGER && node->son[1]->symbol->tk_type != LIT_CHAR){
					fprintf(stderr, "Semantic ERROR on line %d: initializer must be integer\n", node->node_line);
					exit(4);
				}
				node->symbol->data_type = DATATYPE_LONG;
			}
			if(node->son[0]->type == AST_KWFLOAT){
				if(node->son[1]->symbol->tk_type != LIT_REAL){
					fprintf(stderr, "Semantic ERROR on line %d: initializer must be real\n", node->node_line);
					exit(4);
				}
				node->symbol->data_type = DATATYPE_FLOAT;
			}
			if(node->son[0]->type == AST_KWDOUBLE) {
				if(node->son[1]->symbol->tk_type != LIT_REAL){
					fprintf(stderr, "Semantic ERROR on line %d: initializer must be real\n", node->node_line);
					exit(4);
				}
				node->symbol->data_type = DATATYPE_DOUBLE;
			}
		}
	}
	if(node->type == AST_VECDEC){
		if(node->symbol->tk_type != TK_IDENTIFIER){
			fprintf(stderr,"Semantic ERROR on line %d: identifier %s, already declared \n", node->node_line,node->symbol->value);
			exit(4); //deve vir depois, aqui cotinuar aserjaweirjaeijrieajriejrijeirj
		}
		else{
			if (!checkInt(node->son[1])){
				fprintf(stderr, "Semantic ERROR on line %d: vector index must be an integer\n", node->node_line);
				exit(4);
			}
			node->symbol->tk_type = SYMBOL_VEC;
			if(node->son[0]->type == AST_KWBYTE) {
				checkVecInit(node->son[2], AST_KWBYTE);
				node->symbol->data_type = DATATYPE_BYTE;
			}
			if(node->son[0]->type == AST_KWSHORT) {
				checkVecInit(node->son[2], AST_KWSHORT);
				node->symbol->data_type = DATATYPE_SHORT;
			}
			if(node->son[0]->type == AST_KWLONG) {
				checkVecInit(node->son[2], AST_KWLONG);
				node->symbol->data_type = DATATYPE_LONG;
			}
			if(node->son[0]->type == AST_KWFLOAT) {
				checkVecInit(node->son[2], AST_KWFLOAT);
				node->symbol->data_type = DATATYPE_FLOAT;
			}
			if(node->son[0]->type == AST_KWDOUBLE) {
				checkVecInit(node->son[2], AST_KWDOUBLE);
				node->symbol->data_type = DATATYPE_DOUBLE;
			}
		}
	}
	if (node->type == AST_FUNDEC){
		if(node->symbol->tk_type != TK_IDENTIFIER){
			fprintf(stderr, "Semantic ERROR on line %d: identifier %s already declared\n", node->node_line, node->symbol->value);
			exit(4);
		}
		else{
			node->symbol->tk_type = SYMBOL_FUN;
			newFunc(node->symbol);
			if(node->son[0]->type == AST_KWBYTE) node->symbol->data_type = DATATYPE_BYTE;
			if(node->son[0]->type == AST_KWSHORT) node->symbol->data_type = DATATYPE_SHORT;
			if(node->son[0]->type == AST_KWLONG) node->symbol->data_type = DATATYPE_LONG;
			if(node->son[0]->type == AST_KWFLOAT) node->symbol->data_type = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KWDOUBLE) node->symbol->data_type = DATATYPE_DOUBLE;
		}
	}
	if(node->type == AST_ARGSDEF){
		if(node->symbol->tk_type != TK_IDENTIFIER){
			fprintf(stderr, "Semantic ERROR on line %d: identifier %s already declared\n", node->node_line, node->symbol->value);
			exit(4);
		}
		else{
			node->symbol->tk_type = SYMBOL_VAR;
			functions_list.tail->n_parameters +=1;
			if(node->son[0]->type == AST_KWBYTE) node->symbol->data_type = DATATYPE_BYTE;
			if(node->son[0]->type == AST_KWSHORT) node->symbol->data_type = DATATYPE_SHORT;
			if(node->son[0]->type == AST_KWLONG) node->symbol->data_type = DATATYPE_LONG;
			if(node->son[0]->type == AST_KWFLOAT) node->symbol->data_type = DATATYPE_FLOAT;
			if(node->son[0]->type == AST_KWDOUBLE) node->symbol->data_type = DATATYPE_DOUBLE;
			functions_list.tail->p_types[functions_list.tail->n_parameters-1] = node->symbol->data_type;
		}
	}


	for (i=0; i<MAX_SONS; ++i){
		semanticSetTypes(node->son[i]);
	}


}

void semanticCheckUsage(AST* node){
	int i;
	if (!node) return;

	if(node->type == AST_ASSIGN){
		if(node->symbol->tk_type != SYMBOL_VAR){
			fprintf(stderr, "Semantic ERROR on line %d: identifier %s must be a variable\n", node->node_line, node->symbol->value);
			exit(4);
		}
	}

	if(node->type == AST_VASSIGN || node->type == AST_VACCESS){
		if(node->symbol->tk_type != SYMBOL_VEC){ 
			fprintf(stderr, "Semantic ERROR on line %d: identifier %s must be a vector\n", node->node_line, node->symbol->value);
			exit(4);
		}
		//se a leitura ou escrita estiver sendo feita realmente em um vetor, checa se o indice é válido
		else{
			//percorre a árvore e checa se resultado é int, ACESSO A VETOR SOMENTE COM INT (byte, short, long e literais char, int)
			if (!checkInt(node->son[0])){
				fprintf(stderr, "Semantic ERROR on line %d: vector index must be an integer\n", node->node_line);
				exit(4);
			}
		}
	}

	if(node->type == AST_FUNCALL){
		//fprintf(stderr, "eita, funssaum");
		if(node->symbol->tk_type != SYMBOL_FUN){
			fprintf(stderr, "Semantic ERROR on line %d: identifier %s must be a function\n", node->node_line, node->symbol->value);
			exit(4); //isso deveria ser uma flag global pra mostrar erro na main, e não uma parada de erro realmente
		}
		else{
			checkArgs(node->son[0], node->symbol->value);
		}
	}

	for (i=0; i<MAX_SONS; ++i){
		semanticCheckUsage(node->son[i]);
	}

}

//-
void semanticCheckOperands(AST* node){
	int i;
	if (!node) return;

	//check operands of arithmetical operators
	if (node->type == AST_ADD || node->type == AST_SUB || node->type == AST_MUL || node->type == AST_DIV){
		//check first operand
		//fprintf(stderr, "%d ", node->node_line);

		if(checkBool(node->son[0])){
			fprintf(stderr, "Semantic ERROR on line %d: left operand of arithmetical operation cannot be a logical operand (>, <, >=, <=, !=, ==, ||, &&, !)\n", node->node_line);
			exit(4);
		}

		//check second operand
		if(checkBool(node->son[1])){
			fprintf(stderr, "Semantic ERROR on line %d: right operand of arithmetical operation cannot be a logical operand (>, <, >=, <=, !=, ==, ||, &&, !)\n", node->node_line);
			exit(4);
		}
	}
	if(node->type == AST_ASSIGN){
		HASH_NODE* n = hash_search(node->symbol->value);
		if(checkBool(node->son[0])){
			fprintf(stderr, "Semantic ERROR on line %d: right operand cannot be logical in assignment (>, <, >=, <=, !=, ==, ||, &&, !)\n", node->node_line);
			exit(4);
		}
		if(checkInt(node->son[0])){	
			if(n->data_type != DATATYPE_BYTE && n->data_type != DATATYPE_SHORT && n->data_type != DATATYPE_LONG){
				fprintf(stderr, "Semantic ERROR on LINE %d: invalid assignment, expected real value.\n", node->node_line);
				exit(4);
			}
		}
		else if(checkReal(node->son[0])){
			if(n->data_type != DATATYPE_FLOAT && n->data_type != DATATYPE_DOUBLE){
				fprintf(stderr, "Semantic ERROR on LINE %d: invalid assignment, expected integer value.\n", node->node_line);
				exit(4);
			}
		}		
	}

	if(node->type == AST_VASSIGN){
		HASH_NODE* n = hash_search(node->symbol->value);
		if(checkBool(node->son[1])){	
			fprintf(stderr, "Semantic ERROR on line %d: right operand cannot be logical in vector assignment (>, <, >=, <=, !=, ==, ||, &&, !)\n", node->node_line);
			exit(4);
		}
		if(checkInt(node->son[1])){	
			if(n->data_type != DATATYPE_BYTE && n->data_type != DATATYPE_SHORT && n->data_type != DATATYPE_LONG){
				fprintf(stderr, "Semantic ERROR on LINE %d: invalid assignment, expected real value.\n", node->node_line);
				exit(4);
			}
		}
		else if(checkReal(node->son[1])){
			if(n->data_type != DATATYPE_FLOAT && n->data_type != DATATYPE_DOUBLE){
				fprintf(stderr, "Semantic ERROR on LINE %d: invalid assignment, expected integer value.\n", node->node_line);
				exit(4);
			}
		}
	}

	if(node->type == AST_KWRETURN){
		if(!checkReal(node->son[0])){	//check argtype checa se é numerico
			fprintf(stderr, "Semantic ERROR on line %d: invalid return type\n", node->node_line);
			exit(4);
		}
	}

	for (i=0; i<MAX_SONS; ++i){
		semanticCheckOperands(node->son[i]);
	}
}

int checkBool(AST* node){

	if(node->type == AST_GT || node->type == AST_LS || node->type == AST_GE || node->type == AST_LE || node->type == AST_NE
		|| node->type == AST_EQ || node->type == AST_OR || node->type == AST_AND || node->type == AST_NOT)
		return 1;

	if(node->type == AST_MUL || node->type == AST_DIV || node->type == AST_ADD || node->type == AST_SUB){
		//return (checkBool(node->son[0]) || checkBool(node->son[1]));
		return 0;
	}
	if(node->type == AST_EXP){
		return checkBool(node->son[0]);
	}

	if(node->type == AST_SYMBOL || node->type == AST_VACCESS || node->type == AST_FUNCALL)
		return 0;

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
	// TBM ACEITA CHAR
	if(node->type == AST_SYMBOL || node->type == AST_VACCESS || node->type == AST_FUNCALL){
		if(node->symbol->tk_type != LIT_INTEGER && node->symbol->tk_type != LIT_CHAR && node->symbol->data_type != DATATYPE_BYTE 
			&& node->symbol->data_type != DATATYPE_SHORT && node->symbol->data_type != DATATYPE_LONG)
			return 0;
		else return 1;
	}
}

void checkArg(AST* node, FUNC_INFO* f, char* func_name, int param){
	if(checkInt(node)){
		if(f->p_types[param] != DATATYPE_BYTE && f->p_types[param] != DATATYPE_SHORT && f->p_types[param] != DATATYPE_LONG){
			fprintf(stderr, "Semantic ERROR on LINE %d: wrong argument (%d) type passed to function \"%s\". Expected real value. \n", f->func->node_line, param, func_name);
			exit(4);
		}
	}	
	else if(checkReal(node)){
		if(f->p_types[param] != DATATYPE_DOUBLE && f->p_types[param] != DATATYPE_FLOAT){
			fprintf(stderr, "Semantic ERROR on LINE %d: wrong argument (%d) type passed to function \"%s\". Expected integer value. \n", f->func->node_line, param, func_name);
			exit(4);		
		}
	}
}

int checkArgs(AST* node, char* func_name){
	/*args: exp largs {$$ = astCreate(AST_ARGS, 0, $1, $2, 0, 0);}
	| {$$ = 0;}
	;

	largs: ',' exp largs {$$ = astCreate(AST_ARGS, 0, $2, $3, 0, 0);}
	| {$$ = 0;}
	;

	;*/

	FUNC_INFO *f = searchFunc(func_name);
	AST* arg_pointer = node;
	int count = 0;

	while(arg_pointer != NULL){
		if (arg_pointer->son[0] != NULL && count < f->n_parameters)
			checkArg(arg_pointer->son[0], f, func_name, count);
		count++;
		if(count > f->n_parameters){
			fprintf(stderr, "Semantic ERROR on LINE %d: too many arguments passed to function \"%s\". \n", f->func->node_line, func_name);
			exit(4);
		}
		arg_pointer = arg_pointer->son[1];
	}

	if(count < f->n_parameters){
		fprintf(stderr, "Semantic ERROR on LINE %d: arguments lacking on calling \"%s\" function call\n", f->func->node_line, func_name);
		exit(4);
	}
	return 1;
}

int checkReal(AST* node){
	//aceita qualquer argumento numérico
	if(node->symbol != NULL)
		if(node->symbol->tk_type == LIT_STRING)
			return 0;
	if(node->type == AST_NOT || node->type == AST_GT || node->type == AST_LS || node->type == AST_GE || node->type == AST_LE ||
	 	node->type == AST_EQ || node->type == AST_NE || node->type == AST_AND || node->type == AST_OR){
		return 0;
	}
	if(node->type == AST_SYMBOL || node->type == AST_VACCESS || node->type == AST_FUNCALL ||
		node->type == AST_MUL || node->type == AST_DIV || node->type == AST_ADD || node->type == AST_SUB)
		return 1;
	if(node->type == AST_EXP)
		return checkReal(node->son[0]);
}

void newFunc(HASH_NODE *func){
	FUNC_INFO* new_func = (FUNC_INFO*)calloc(1,sizeof(FUNC_INFO));
	new_func->func = func;
	new_func->n_parameters = 0;
	new_func->next = NULL;

	if(functions_list.head == NULL){
		functions_list.head = new_func;
		functions_list.tail = new_func;
	}
	else{
		functions_list.tail->next = new_func;
		functions_list.tail = new_func;
	}
}

FUNC_INFO* searchFunc(char* func_name){

	FUNC_INFO* pointer = functions_list.head;

	while(pointer != functions_list.tail){
		if(strcmp(func_name, pointer->func->value) == 0)
			break;
		pointer = pointer->next;
	}
	return pointer;
}



#endif
