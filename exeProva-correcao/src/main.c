#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencher(int *pBuffer, int tam);

int main(){

	int tam;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);

	int *pBuffer = malloc(sizeof(int) * tam);

	preencher(pBuffer, tam);

	free(pBuffer); //Liberando a memória ao fechar

}

void preencher(int *pBuffer, int tam){
	
	int *posIni = pBuffer;
	int busca, naoEncontrado = 1;
	int j;

	for(int i = 0; i < tam; i++){
		*pBuffer = rand();
		pBuffer++;
	}

	pBuffer = posIni;

	for(int i = 0; i < tam; i++){
		printf("\n[%d] ", *pBuffer);
		pBuffer++;
	}

	printf("\nDigite um numero para a busca: ");
	scanf("%d", &busca);

	pBuffer = posIni;

	for(int i = 0; i < tam; i++){
		if(busca == *pBuffer){
			for(int j = i; j < tam - 1; j++){	// tam - 1 para evitar o acesso fora do buffer
				*pBuffer = *(pBuffer+1);
				pBuffer++;
			}
			tam--;
			naoEncontrado--;
			break;
		}
		pBuffer++;
	}

	pBuffer = posIni;

	if(naoEncontrado == 1){
		for(int i = 0; i < tam; i++){
			for(j = i; j < tam; j++){
				if(*(pBuffer + i) + *(pBuffer + j) == busca){
					for(int k = i; k < tam - 1; k++){	// tam - 1 para evitar o acesso fora do buffer
						*(pBuffer + k) = *(pBuffer + k + 1);
					}
					tam--;
					for(int k = j - 1; k < tam - 1; k++){	// correção do erro de remoção do numero: j - 1 para remover a posição correta. 
						*(pBuffer + k) = *(pBuffer + k + 1);
					}
					tam--;
					printf("\nsoma encontrada e numeros removidos!\n");
					break;
				}	
			}
		}
	}

	pBuffer = posIni;
	pBuffer = realloc(pBuffer, sizeof(int) * tam);

	for(int i = 0; i < tam; i++){
		printf("\n[%d] ", *pBuffer);
		pBuffer++;
	}
}