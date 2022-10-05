#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int qtd = 0;

void menu(void *pBuffer);
void add(void *pBuffer);
void removeName(void *pBuffer);
void list(void *pBuffer);


int main()
{
	void *pBuffer = malloc(sizeof(char));

	menu(pBuffer);

}

void add(void *pBuffer){

	printf("\nDigite um nome: ");
	if(qtd==0){
		scanf("%s",(char *)pBuffer);
		getchar();
		qtd++;
	}else{
		scanf("%s",(char *)pBuffer + strlen(pBuffer));
		getchar();
		qtd++;
	}
	
	menu(pBuffer);
	
}

void removeName(void *pBuffer){
	char nameRemove[20];
	char *posIni = pBuffer;
	printf("Digite qual nome deseja remover: ");
	scanf("%s", nameRemove);
	char *localName = strstr((char *)pBuffer, nameRemove);

	int bufferSize = (int) strlen((char *)pBuffer);
	int nameRemoveSize = (int) strlen(nameRemove);

	if(!localName){
		printf("\nNome nao encontrado");
		removeName(pBuffer);
	}else{
		for(int i = 0; i < bufferSize; i++){
			if(pBuffer==localName){
				for(int j = 0; j < nameRemoveSize; j++){
					while(*(char *)pBuffer != '\0'){
						*(char *)pBuffer = *(char *)(pBuffer + 1);
						pBuffer+=1;
					}
					pBuffer = localName;
				}
			}	
		pBuffer++;
		}
	}
	pBuffer = posIni;

	pBuffer = (void *) realloc(pBuffer, (int) strlen((char *)pBuffer));
	menu(pBuffer);
}

void list(void *pBuffer){
	printf("\n%s", (char *)pBuffer);
	menu(pBuffer);
}

void menu(void *pBuffer){
	int escolha;
	printf("\n1. Adicionar\n");
	printf("2. Remover\n");
	printf("3. Listar\n");
	printf("4. Sair\n");

	scanf("%d", &escolha);

	switch(escolha){
		case 1:
			add(pBuffer);
			break;
		case 2:
			removeName(pBuffer);
			break;
		case 3:
			list(pBuffer);
			break;
	}
}
