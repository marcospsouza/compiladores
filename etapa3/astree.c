#ifndef ASTREE_C
#define ASTREE_C

#include "hash.h"
#include "astree.h"
#include <stdio.h>
#include <stdlib.h>


// "PAU NO CU DA IDE DO ARDUÍNO" - Johann
//"3 maneiras de modelar esta lisat de comandos"
/*
lcmd ->lcmd ->lcmd ->lcmd ->lcmd ->lcmd ->
  v      v      v      v      v      v 
 ass    ass    ass    ass    ass    ass

 "possibilidade sem a criaçao de lista de comandos"

"assim é mais elegante e ortogonal *aponta pro quadro autisticamente*"

DEFAULT {$$ = $1;} 

"em alguns pontos da gramática vocês não precisam escrever nada"

FM, & {$$ = 0;}
PASSAR {$$ = $N;}
PRINCIPAL {$$ = astCreate(...);}

MISC	>debug {print}
		>opcional {$1->sum[3]=$2;}

*/



//pronta
AST* astCreate(int type, HASH_NODE *symbol, AST* son0, AST* son1, AST* son2,AST* son3){
	AST* newnode;
	newnode =  (AST*)calloc(1,sizeof(AST));
	newnode->type = type;
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
			case AST_SYMBOL:
				fprintf(stderr, "SYMBOL,");
				break;
			case AST_ADD:
				fprintf(stderr, "AST_ADD,");
				break;
			case AST_MUL:
				fprintf(stderr, "AST_MUL,");
				break;
			default:			
				fprintf(stderr, "UNKNOWN\n");
				break;

		}
		if(node->symbol)
			fprintf(stderr, "%s\n",node->symbol->value);
		else
			fprintf(stderr, "0\n");



		for(i=0; i < MAX_SONS; i++)
			astPrint(node->son[i], level+1);
	

	}
}

#endif