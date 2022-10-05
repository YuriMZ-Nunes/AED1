#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int escolha;
	void *pBuffer = malloc(sizeof(char));
	//char *remove = malloc(sizeof(char));
	do{

		printf("1. Adicionar\n");
		printf("2. Remover\n");
		printf("3. Listar\n");
		printf("4. Sair\n");

		scanf("%d", &escolha);
		
		switch(escolha){
			case 1:
				printf("Digite um nome: ");
				scanf("%s",(char *)pBuffer + strlen(pBuffer));

				break;
			case 2:

				/*printf("Digite qual nome deseja remover: ");
				scanf("%s", remove);
				
				aux = &pBuffer;

				for(int i = 0; i < strlen(pBuffer); i++){
					if(*pBuffer==*remove){
						for(int j = 0; j < strlen(remove); j++){
							pBuffer++;
							remove++;
							if(*pBuffer!=*remove){
								exit;
							}
							printf("\n%d\n", j);
						}

						
					}
					*pBuffer++;
				}*/

				break;
			case 3:
				printf("%s", pBuffer);
				break;
		}
	}while(escolha != 4);

	
}