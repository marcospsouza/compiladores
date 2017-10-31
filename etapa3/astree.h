//operandos filhos do operador


#ifndef ASTREE_HEADER
#define ASTREE_HEADER
#include <stdio.h>
#define MAX_SONS 4

#define AST_SYMBOL 1
#define AST_ADD 2
#define AST_SUB 3
#define AST_MUL 4
#define AST_DIV 5
#define AST_GT 6
#define AST_LS 7
#define AST_NOT 8
#define AST_LE 9
#define AST_GE 10
#define AST_EQ 11
#define AST_NE 12
#define AST_AND 13
#define AST_OR 14
#define AST_INT 15
#define AST_CHAR 16
#define AST_REAL 17
#define AST_KWBYTE 18
#define AST_KWSHORT 19
#define AST_KWLONG	20
#define AST_KWFLOAT 21
#define AST_KWDOUBLE 22
#define AST_KWIF 23
#define AST_KWTHEN 24
#define AST_KWELSE 25
#define AST_KWWHILE 26
#define AST_KWFOR 27
#define AST_KWREAD 28
#define AST_KWRETURN 29
#define AST_KWPRINT 30
#define AST_TKID 31
#define AST_EXP 32
#define AST_LCMD 33
#define AST_CMD 34
#define AST_BLOCK 35 
#define AST_DECL 36
#define AST_DEC 37
#define AST_VARDEC 38
#define AST_FUNDEC 39
#define AST_VTL 40
#define AST_LIT 41
#define AST_LITLIST 42
#define AST_VARTYPE 43
#define AST_ARGSDEF 44
#define AST_ASSIGN 45
#define AST_PRINTARGS 46
#define AST_ARGS 47
#define AST_VTLIST 48
#define AST_VT 49




//"se botou $$, precisa de símbolo associado"

typedef struct ast_node{
	int type;
	HASH_NODE *symbol;
	struct ast_node* son[MAX_SONS];
}AST;

//PROTOTYPES





AST* astCreate(int type, HASH_NODE *symbol, AST* son0, AST* son1, AST* son2,AST* son3);
void astPrint(AST * node, int level);

void printSource(AST *root);
void printnodeSource(AST *node, FILE *source_code);


#endif