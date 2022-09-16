#include <stdio.h>
#include <stdlib.h>

void menu(void *pBuffer);
void incluir(void *pBuffer);
//void apagar(void *pBuffer);
//void buscar(void *pBuffer);
void listar(void *pBuffer);

int main(){
	void *pBuffer = malloc(sizeof(int) + (10 * sizeof(char) + (2 * sizeof(int))));

	*(int *)pBuffer = 0;

	menu(pBuffer);
}

void menu(void *pBuffer){
	printf("1. Incluir\n");
	printf("2. Apagar\n");
	printf("3. Buscar\n");
	printf("4. Listar\n");

	switch(getchar()){
		case '1':
			incluir(pBuffer);
			getchar();
			break;
		/*case '2':
			getchar();
			apagar(pBuffer);
			break;
		case '3':
			getchar();
			buscar(pBuffer);
			break;*/
		case '4':
			listar(pBuffer);
			getchar();
			break;
		}
}

void incluir(void *pBuffer){
	*(int *)pBuffer+=1;

	pBuffer =  realloc(pBuffer, (*(int *)pBuffer) * (sizeof(int) + (10 * sizeof(char) + (2 * sizeof(int)))));

	printf("Digite um nome: \n");
	scanf("%s", (char *)pBuffer + (*(int *)pBuffer) * (sizeof(int)));
	printf("Digite a idade: \n");
	scanf("%d", (int *)(pBuffer + (*(int *)pBuffer) * (sizeof(int) + (10 * sizeof(char)))));
	printf("Digite o telefone: \n");
	scanf("%d", (int *)(pBuffer + (*(int *)pBuffer) * (sizeof(int) + (10 * sizeof(char)) + sizeof(int))) );
	
	getchar();

	menu(pBuffer);
}

void listar(void *pBuffer){
	
	for(int i = 0; i < *(int *)pBuffer; i++){
		printf("PESSOA %d\n", i + 1);
		printf("Nome: %s\n", (char *)(pBuffer + ((i + 1) * (sizeof(int)))));
		printf("Idade: %d\n", *(int *)(pBuffer + ((i + 1) * ((sizeof(int)) + (10 * sizeof(char))))));
		printf("Telefone: %d\n", *(int *)(pBuffer + ((i + 1) * ((sizeof(int)) + (10 * sizeof(char)) + sizeof(int)))));
	}

	menu(pBuffer);
}