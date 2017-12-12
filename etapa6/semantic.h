



#ifndef semantic_h
#define semantic_h

#include <stdio.h>
#include "hash.h"
#include "astree.h"
#include "y.tab.h"



void semanticSetTypes(AST* node) ; //recursiva
void semanticCheckUndeclared(void);
void semanticCheckUsage(AST* node);
void semanticCheckOperands(AST* node);

int checkInt(AST* node);
int checkReal(AST* node);
int checkArgs(AST* node, char* func_name);
typedef struct func_info{
	HASH_NODE *func;
	int n_parameters;
	int p_types[20];                                                                       
	struct func_info* next;

}FUNC_INFO;

//lista encadeada usada para armazenar informações das declarações (nome, numero de parametros, etc)
typedef struct func_list{
	FUNC_INFO* head;
	FUNC_INFO* tail;

}FUNC_LIST;

FUNC_LIST functions_list;

void newFunc(HASH_NODE *func);
FUNC_INFO* searchFunc(char *func_name);

#endif /* semantic_h*/