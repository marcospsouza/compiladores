#include "astree.h"
#include <stdio.h>
#include <stdlib.h>


// "PAU NO CU DA IDE DO ARDUÍNO" - Johann
//"3 maneiras de modelar esta lisat de comandos"
/*
lcmd ->lcmd ->lcmd ->lcmd ->lcmd ->lcmd ->
  v      v      v      v      v      v 
 ass    ass    ass    ass    ass    ass

 "possibilidade sem a criançao de lista de comandos"

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
AST* setCreate(int type, HASH_NODE *symbol, AST* son0, AST* son1, AST* son2,AST* son3){
	AST* newnode;
	newnode =  (AST*)calloc(i,sizeof(AST));
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
		for(i=0;i<level;i++)
			fprintf();

//tem que fazer um switch aqui, 3 na verdade, potencialmente...

//stuff


	for(i=0;i<level;i++)
			//stuff;
	

	}
//stuff
}