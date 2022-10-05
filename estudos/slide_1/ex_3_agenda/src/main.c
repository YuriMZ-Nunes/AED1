#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qtdPessoas = 0;
int size = (int)(sizeof(char) * 10) + (2 * sizeof(int));

void menu(void *pBuffer);
void add(void *pBuffer);
void remover(void *pBuffer);
void list(void *pBuffer);

int main()
{
	void *pBuffer = malloc(size);

	menu(pBuffer);
}

void menu(void *pBuffer){
	int escolha;

	printf("1. Adicionar\n");
	printf("2. Remover\n");
	printf("3. Listar\n");
	printf("4. Sair\n");

	scanf("%d", &escolha);

	switch(escolha){
		case 1:
			add(pBuffer);
			break;
		case 2:
			remover(pBuffer);
			break;
		case 3:
			list(pBuffer);
			break;
		case 4:
			free(pBuffer);
			exit;
	}
}

void add(void *pBuffer){

	pBuffer = realloc(pBuffer, size*(qtdPessoas + 1));
	
	if ( !pBuffer ){
		printf("\nNão foi possivel realocar!\n");
		exit(1);
	}

	printf("\nNome: ");
	scanf("%s", (char *)(pBuffer + size * qtdPessoas));
	getchar();
	printf("\nIdade: ");
	scanf("%d", ((int *)(pBuffer + (sizeof(char)*10) + size * qtdPessoas)) );
	getchar();
	printf("\nTelefone: ");
	scanf("%d", ((int *)(pBuffer + (sizeof(char)*10) + (sizeof(int)) + size * qtdPessoas)));
	getchar();

	qtdPessoas++;
	menu(pBuffer);

}

void remover(void *pBuffer){
	char nome[10];
	printf("Nome para remover: ");
	scanf("%s", nome);
	getchar();
	int nEncontrado = 1;

	for(int i = 0; i < qtdPessoas; i++){
		if(strcmp(nome, (char *)pBuffer + size * i) == 0){
			for(int r = i; r < qtdPessoas; r++){
				strcpy((char *)(pBuffer + size * r), (char *)(pBuffer + size * (r + 1)));
				*(int *)(pBuffer + (size * r) + (sizeof(char) * 10)) = *(int *)(pBuffer + (size * (r + 1)) + (sizeof(char) * 10) );
				*(int *)(pBuffer + (size * r) + (sizeof(char) * 10) + sizeof(int)) = *(int *)(pBuffer + (size * (r + 1)) + (sizeof(char) * 10)  + sizeof(int));
			}
			qtdPessoas--;
			nEncontrado--;
			pBuffer = realloc(pBuffer, qtdPessoas * size);
			printf("\nRemovido!\n");
			break;
		}
	}

	if ( nEncontrado==1 )
		printf("\nNão encontrado!\n");
	menu(pBuffer);

}

void list(void *pBuffer){

	for(int i = 0; i < qtdPessoas; i++){
		printf("\nPessoa numero %d\n\n", i+1);
		printf("Nome: %s\n", (char *)(pBuffer + (size * i)));
		printf("Idade: %d\n", *(int *)(pBuffer + (sizeof(char)*10) + (size * i)));
		printf("Telefone: %d\n\n", *(int *)(pBuffer + (sizeof(char)*10) + (sizeof(int)) + (size * i)));

	}

	menu(pBuffer);
}