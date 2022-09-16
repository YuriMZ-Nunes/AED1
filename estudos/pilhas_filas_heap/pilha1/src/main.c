#include <stdio.h>
#include <stdlib.h>

int empty(int *pBuffer);
void menu(int *pBuffer);
void push(int *pBuffer);
void list(int *pBuffer);



int main()
{
	int *pBuffer = malloc(sizeof(int));
	//quantidade de itens dentro da pilha
	*pBuffer = 0;
	menu(pBuffer);
}

void menu(int *pBuffer){
	printf("\n1. PUSH");
	printf("\n2. POP");
	printf("\n3. LIST");
	printf("\n4. EXIT");

	printf("\nDigite uma das opcoes: ");

	switch(getchar()){
		case '1':
			getchar();
			push(pBuffer);
			break;
		case '3':
			getchar();
			list(pBuffer);
			break;
		
	}
}

void push(int *pBuffer){
	*pBuffer += 1;
	pBuffer = realloc(pBuffer, (2 * sizeof(int) + ((*pBuffer) * sizeof(int))));
	printf("\nDigite um numero inteiro: ");
	scanf("%d", pBuffer + (2 + (*pBuffer)));
	*(pBuffer + 1) = (int)(pBuffer + ((2 + (*pBuffer))));
	
	getchar();
	menu(pBuffer);
}

void list(int *pBuffer){
	for(int i = 0; i < *pBuffer; i++){
		printf("[ %d ] ", *(pBuffer + 2 + (i + 1)));
	}
}