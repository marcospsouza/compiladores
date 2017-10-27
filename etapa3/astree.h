//operandos filhos do operador


#infndef ASTREE_HEADER
#define ASTREE_HEADER

#include "hash.h"
#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_MUL 3
#define AST_ASS 4
#define AST_LCMD 5


//"se botou $$, precisa de símbolo associado"

typedef struct ast_node{
	int type;
	HASH_NODE *symbol;
	struct ast_node* son[MAX_SONS];
}ABT;

//PROTOTYPES





AST* setCreate();
void astPrint(AST * node);



#endif