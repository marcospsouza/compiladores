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

int i = 0;

int main(){
	while(i < 5){
		printf("while");
		i = i + 1;
	}
}