#include <stdio.h>
#include <stdlib.h>

int main(){
	int *pBuffer = malloc(sizeof(int));
	*pBuffer = 0;

	while(1){
		printf("\n1. Adicionar\n2. Remover\n3. Listar\n4. Sair\n");

		switch(getchar()){
			case '1':
				pBuffer = push(pBuffer);
				getchar();
				break;
			case '3':
				list(pBuffer);
				getchar();
				break;
		}
	}
}

int *push(int *pBuffer){
	*pBuffer += 1;
	pBuffer = realloc(pBuffer, sizeof(int) + ((*pBuffer) * sizeof(int)));
	printf("\nDigite um valor: ");
	scanf("%d", pBuffer + 1 +(*pBuffer));

	return(pBuffer);
}

void list(int *pBuffer){
	for(int i = 0; i < *pBuffer, i++){
		printf("[ %d ] ", pBuffer + 1 + (i + 1));
	}
}