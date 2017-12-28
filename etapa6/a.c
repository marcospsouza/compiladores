#include <stdio.h>

/*
  gera assembly gcc -S -c a.c

  roda assembly gcc a.s -o
  
*/
/*
int a[20];
int b = 3;

int func(){
	return 3;
}
int main(){
	b = func();
	printf("ola amigos");
}*/
int a = 10;
int b = 15;
int i;

int f(){
	return a + b;
}

int main(){
	i = f();
}