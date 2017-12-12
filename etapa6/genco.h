#ifndef GENCO_HEADER
#define GENCO_HEADER

#include "hash.h"
#include "astree.h"


#define TAC_SYMBOL 1
#define TAC_ADD 2
#define TAC_SUB 3
#define TAC_MUL 4
#define TAC_DIV 5
#define TAC_GT 6
#define TAC_LS 7
#define TAC_GE 8
#define TAC_LE 9
#define TAC_EQ 10
#define TAC_NE 11
#define TAC_NOT 12
#define TAC_AND 13
#define TAC_OR 14
#define TAC_ASSIGN 15
#define TAC_VASSIGN 16
#define TAC_VACCESS 17
#define TAC_PRINT 18
#define TAC_PRINTARG 19
#define TAC_READ 20
#define TAC_RETURN 21
#define TAC_FUNCALL 22
#define TAC_ARG 23

#define TAC_JZ 30
#define TAC_LABEL 31
#define TAC_JMP 32
#define TAC_BEGINFUN 33
#define TAC_ENDFUN 34


//argumetno 0 da função f, argumento 1 da funçao f,. ... gera uuns temp safado


/*
não quer:
  TAC_SYMBOL - ??????
  declarações -

*/


typedef struct struct_tac{

  int type;
  HASH_NODE* res;
  HASH_NODE* op1;
  HASH_NODE* op2;
  struct struct_tac* prev;
  struct struct_tac* next;



}TAC;

TAC* tacCreate(int type, HASH_NODE* res,HASH_NODE* op1,HASH_NODE* op2);
TAC* tacGenerator(AST* node);
TAC* tacJoin(TAC* l1, TAC* l2);
void tacPrintBack(TAC* last);
TAC* makeWhile(TAC* code0, TAC* code1);
TAC* makeIfThen(TAC* code0,TAC* code1);
TAC* makeFun(HASH_NODE* f, TAC* c);

TAC* tacReverse(TAC*last);
void tacPrintForward(TAC* last);

#endif
