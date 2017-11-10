



#ifndef semantic_h
#define semantic_h

#include <stdio.h>
#include "./hash.h"
#include "./astree.h"


void semanticSetTypes(AST* node) ; //recursiva
void semanticCheckUndeclared(void);v
void semanticCheckUsage(AST* node);
void semanticCheckOperands(AST* node);

#endif /* semantic_h*/