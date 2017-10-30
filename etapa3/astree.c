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
			case AST_FUNDEC: fprintf(stderr, "AST_FUNDEC,");break;
			case AST_VTL: fprintf(stderr, "AST_VTL,");break;	

			case AST_LIT: fprintf(stderr, "AST_LIT,");break;
			case AST_LITLIST: fprintf(stderr, "AST_LITLIST,");break;
			case AST_VARTYPE: fprintf(stderr, "AST_VARTYPE,");break;			
			case AST_ARGSDEF: fprintf(stderr, "AST_ARGSDEF,");break;
			case AST_ASSIGN: fprintf(stderr, "AST_ASSIGN,");break;
			case AST_PRINTARGS: fprintf(stderr, "AST_PRINTARGS,");break;
			case AST_ARGS: fprintf(stderr, "AST_ARGS,");break;
			case AST_VTLIST: fprintf(stderr, "AST_VTLIST,");break;	

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

#endif