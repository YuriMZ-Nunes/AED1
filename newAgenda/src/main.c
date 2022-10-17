#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *push(void **pFirst, void **pAtual, void **pAnt);
void *pop(void **pFirst);
void *search(void **pFirst, void **pAtual);
void *list(void **pFirst, void **pAtual);
void *exitProgram(void **pFirst, void **pAtual, void **pAnt);
//teste

int main()
{
	void **pFirst = malloc(sizeof(int)); //aponta para a primeira pessoa 
	void **pAtual = malloc(sizeof(int)); //ponteiro para o nó atual para percorrer
	void **pAnt = malloc(sizeof(int)); //ponteiro para o nó anteior para atualizar o ponteiro para o prox

	*pFirst = NULL; //aponta para nulo pois não existe nenhum cadastro

	while(1){
        printf("\n1. ADD\n2. DELETE\n3. BUSCAR\n4. LISTAR\n5. SAIR\n");
        switch(getchar()){
            case '1':
                push(pFirst, pAtual, pAnt);
                getchar();
                break;
            case '2':
				if(*pFirst != NULL){
                	pop(pFirst);
				}else{
					printf("Nenhum valor para excluir");
				}
                getchar();
                break;
            case '3':
                search(pFirst, pAtual);
                getchar();
                break;
            case '4':
                list(pFirst, pAtual);
                getchar();
                break;
            case '5':
                exitProgram(pFirst, pAtual, pAnt);
                break;
        }
    }
}

void *push(void **pFirst, void **pAtual, void **pAnt){

	void *infos = malloc((sizeof(char) * 10) + (sizeof(int) * 2) + (sizeof(int) * 2));	//criação do nó da pessoa

	*pAtual = *pFirst; //atual começa pelo primeiro

	printf("\nNome: ");
    scanf("%s", (char *)infos);
    printf("\nIdade: ");
    scanf("%d", (int *)(infos + (sizeof(char) * 10)));									//cadastro dos dados da pessoa
    printf("\nTelefone: ");
    scanf("%d", (int *)(infos + (sizeof(char) * 10) + sizeof(int)));

	if(*pFirst == NULL){ //verifica se é o primeiro cadastro
		*pFirst = infos; //atualiza o ponteiro para o primeiro
		*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0;
		*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0;
		
	}else{
		if(*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) == 0){ //verifica se só existe um cadastro
			if(strcmp((char *)infos, (char *)(*pAtual)) < 0){	//compara os nomes
				if((int *)*pAtual == (int *)*pFirst){ //verifica se será adicionado no topo da lista
					*pFirst = infos;	//atualiza o ponteiro para o primeiro
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(int *)pAtual; //atualiza o next
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0; //atualiza o prev

					*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0;	//atualiza o next da pessoa atual
					*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = infos; //atualiza o prev da pessoa atual

				}
			}else{ //será adicionado no fim
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0; //atualiza o next
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = *(int *)pAtual; //atualiza o prev

					*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) = infos; //atualiza o next da pessoa atual
					*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0; //atualiza o prev da pessoa atual

				}
		}else{
			while(*(int *)(pAtual) != 0){
				if(strcmp((char *)infos, (char *)(*pAtual)) < 0){
					if((int *)*pAtual == (int *)*pFirst){ //verifica se será adicionado no topo da lista
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(int *)pAtual; //atualiza o next
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0;//atualiza o prev

						*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = infos; //atualiza o prev da pessoa atual

						*pFirst = infos; //atualiza o ponteiro para o primeiro
						break;
					}else{ //add no meio
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(int *)pAtual; //atualiza o next
						*(int *)pAnt = (int)*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))); // recebe o endereço do anterior
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = *(int *)pAnt; // atualiza o prev com o endereço do anterior
						
						*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = infos; //atualiza o prev da pessoa atual
					
						*(void **)(*pAnt + ((sizeof(char) * 10) + (sizeof(int) * 2))) = infos; //atualiza o next da pessoa anteior
						break;
					}

				}

				if(*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) == 0){ //verifica se será adicionado no final
					
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0; //atualiza o next
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = *(int *)pAtual; //atualiza o pre

					*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) = infos; //atualiza o next da pessoa atual
					
					break;
				}

				*(int *)pAtual = *(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))); //incrementa o atual passando para a proxima pessoa
			}	
		}
	}
	return (0);
}

void *pop(void **pFirst){

	void *delete; //ponteiro para receber o endereço dos dados

	if(pFirst){
		delete = *(void **)(pFirst); //recebe o endereço dos dados
		if(*(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2))) == 0){ //verifica se há apenas um cadastro para não incrementar
			free(delete); //libera da memora os dados 
			
			printf("\nREMOVIDO COM SUCESSO!");
			*pFirst = NULL;
			return (0);
		}

		*(int *)pFirst = *(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2))); //atualiza o primeiro
		*(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0; //atualiza o prev 

		free(delete); //libera da memora os dados

		printf("\nREMOVIDO COM SUCESSO!");
	}

	return(0);
}

void *search(void **pFirst, void **pAtual){

	char *nameSearch = malloc(sizeof(char) * 10); //ponteiro para um nome para busca

	printf("\nBuscar nome: ");
	scanf("%s", nameSearch);

	*pAtual = *pFirst;

	while(*(int *)(pAtual) != 0){ //percorre

		if(strcmp((char *)*pAtual, (char *)nameSearch) == 0){ //faz a busca e impreme caso encontre
			printf("\nNome encontrado!");
			printf("\nNome: %s", (char *)*pAtual);
			printf("\nIdade: %d", *(int *)(*pAtual + (sizeof(char) * 10)));
			printf("\nTelefone: %d", *(int *)(*pAtual + (sizeof(char) * 10) + sizeof(int)));
			free(nameSearch);
			return(0);
		}

		*(int *)pAtual = *(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))); //incrementa
	}

	printf("\nNenhum nome encontrado!");
	free(nameSearch);
	return(0);
}


void *list(void **pFirst, void **pAtual){

	*pAtual = *pFirst; //atual começa pelo primeiro

	while(*(int *)(pAtual) != 0){ //percorre e lista 

		printf("\n----------------");
		printf("\nNome: %s", (char *)*pAtual);
		printf("\nIdade: %d", *(int *)(*pAtual + (sizeof(char) * 10)));
		printf("\nTelefone: %d", *(int *)(*pAtual + (sizeof(char) * 10) + sizeof(int)));

		*(int *)pAtual = *(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2)));
	}

	return(0);
}

void *exitProgram(void **pFirst, void **pAtual, void **pAnt){

	void *delete; //ponteiro para o endereço dos dados

	if(pFirst){
		while(1){
			delete = *(void **)(pFirst);
			if(*(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2))) == 0){ //verifica se só tem um cadastro para não incrementar
				free(delete);
				
				free(pFirst);
				free(pAnt);
				free(pAtual);

				exit(0);
			}

			*(int *)pFirst = *(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2)));
			free(delete);
		}
	}
	return(0);
}