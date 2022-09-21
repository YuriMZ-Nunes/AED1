#include <stdio.h>
#include <stdlib.h>

int *push(int *pBuffer);
int *pop(int *pBuffer);
int *list(int *pBuffer);


int main(){
	int *pBuffer = malloc(sizeof(int));
	//quantidade de itens armazenados na primeira posição
	*pBuffer = 0;

	while(1){
		printf("\n1. Adicionar\n2. Remover\n3. Listar\n4. Sair\n");

		switch(getchar()){
			case '1':
				pBuffer = push(pBuffer);
				getchar();
				break;
			case '2':
				pBuffer = pop(pBuffer);
				getchar();
				break;
			case '3':
				list(pBuffer);
				getchar();
				break;
			case '4':
				free(pBuffer);
				exit(0);
		}
	}
}

int *push(int *pBuffer){
	*pBuffer += 1;
	pBuffer = realloc(pBuffer, ((*pBuffer) * sizeof(int)) + sizeof(int));
	printf("\nDigite um valor: ");
	scanf("%d", pBuffer + *pBuffer);

	return(pBuffer);
}

int *list(int *pBuffer){
	for(int i = 0; i < *pBuffer; i++){
		printf("[ %d ] ", *(pBuffer + (i + 1)));
	}
	return 0;
}

int *pop(int *pBuffer){
	*pBuffer -= 1;
	pBuffer = realloc(pBuffer, ((*pBuffer) * sizeof(int)) + sizeof(int));
	
	return(pBuffer);
}