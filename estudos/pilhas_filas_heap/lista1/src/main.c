#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *push(char *pFirstPosition, char *pBuffer, int *index){

	*index += 1;
	pBuffer = realloc(pBuffer, sizeof(char) * (*index));

	char *novo = malloc((sizeof(char) * 10 + (sizeof(char) * 2)));

	printf("Digite um nome: ");

	
	scanf("%s", novo);
	*(novo + sizeof(char) * 10) = NULL; //atualiza o next
	*(novo + (sizeof(char) * 10) + sizeof(char)) = NULL; //atualiza o anterior
	*(pBuffer + (*index)) = novo;
	

	getchar();
	return(pBuffer);
}

int main()
{
	char *pFirstPosition = NULL; //aponta para a primeira pessoa
	char *pBuffer = NULL;
	int *index = malloc(sizeof(int));
	*index = 0;

	while(1){
		printf("\n1. add\n2. exclude\n3. list\n");

		switch(getchar()){
			case '1':
				pBuffer = push(pBuffer, pFirstPosition, index);
				getchar();
				break;
		}
	}
}