etapa1: lex.yy.o hash.o
	gcc lex.yy.o hash.o -o etapa1

lex.yy.o: lex.yy.c
	gcc lex.yy.c -c

hash.o: hash.c
	gcc hash.c -c


lex.yy.c: scanner.l
	lex scanner.l

clean:
	rm etapa1 lex.yy.c *.o