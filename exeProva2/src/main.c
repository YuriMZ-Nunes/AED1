#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(void *expressao, char *primeiro);
char *pop(void *expressao,  char *primeiro);
void comparar(void *expressao, char *primeiro);

int main(){
	
	char caracter;
	void *expressao = malloc(sizeof(int) + sizeof(char));
	char *primeiro;

	primeiro = expressao + sizeof(int);
	

	*(int *)expressao = 0;
	push(expressao, primeiro);

	comparar(expressao, primeiro);

}


void push(void *expressao, char *primeiro){
	char caracter;
	char *ultimo;
	while (1){
		printf("\nDigite uma letra e de enter: ");
		caracter = getchar();
		getchar();
		if(caracter == 'x'){
			return;
		}

		*(int *)expressao += 1;

		expressao = realloc(expressao, sizeof(int) + (sizeof(char) * *(int *)expressao));
		*(char *)(expressao + ( sizeof(int) + (sizeof(char) * (*(int *)expressao - 1)))) = caracter;
		
		
	}

	return;
}

void comparar(void *expressao, char *primeiro){
	
	char *removido;
	void *par = malloc(sizeof(int));
	*(int *)par = 0;

	removido = pop(expressao, primeiro);

	while(removido != NULL){
		if(*(char *)removido == '(' || *(char *)removido == ')'){
			*(int *)par+=1;
			par = realloc(par, sizeof(int) + (sizeof(char) * *(int *)par));
			(char *)(par + sizeof(int) + (sizeof(char) * (*(int *)par - 1)));
			printf("%s", (char *)(par + sizeof(int) + (sizeof(char) * (*(int *)par - 1))));
			removido = pop(expressao, primeiro);
		}else{
			removido = pop(expressao, primeiro);
		}

	}

	
}

char *pop(void *expressao, char *primeiro){

	char *ultimo;
	char *removido;

	ultimo = expressao + ( sizeof(int) + (sizeof(char) * (*(int *)expressao - 1)));

	while(*ultimo != *primeiro){

		removido = ultimo;

		*(int *)expressao-=1;
		expressao = realloc(expressao, sizeof(int) + (sizeof(char) * *(int *)expressao));

		
		return(removido);
	}
	if(*ultimo == *primeiro){
		removido = ultimo;

		*(int *)expressao--;
		expressao = realloc(expressao, sizeof(int) + (sizeof(char) * *(int *)expressao));

		return(removido);
	}
	

}