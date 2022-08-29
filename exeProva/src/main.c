#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void preencher(int *pBuffer, int tam);

int main(){

	int tam;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tam);

	int *pbuffer = malloc(sizeof(int) * tam);

	preencher(pbuffer, tam);

}

void preencher(int *pBuffer, int tam){
	
	int *posIni = pBuffer;
	int busca, naoEncontrado = 1;
	int soma1, soma2, j;

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
			for(int j = i; j < tam; j++){
				*pBuffer = *(pBuffer+1);
				pBuffer++;
			}
			tam--;
			naoEncontrado--;
		}
		pBuffer++;
	}

	pBuffer = posIni;

	if(naoEncontrado == 1){
		for(int i = 0; i < tam; i++){
			soma1 = *pBuffer + i;
			for(j = i; j < tam; j++){
				if(*(pBuffer + i) + *(pBuffer + j) == busca){
					for(int k = i; k < tam; k++){
						*(pBuffer + k) = *(pBuffer + k + 1);
					}
					tam--;
					for(int k = j; k < tam; k++){
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