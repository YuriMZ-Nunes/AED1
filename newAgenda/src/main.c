#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *push(void **pFirst, void **pAtual, void **pAnt);
void *pop(void **pFirst);
void *search(void **pFirst, void **pAtual);
void *list(void **pFirst, void **pAtual);
void *exitProgram(void **pFirst, void **pAtual, void **pAnt);


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
                pop(pFirst);
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
			if(strcmp((char *)infos, (char *)(*pAtual)) < 0){
				if((int *)*pAtual == (int *)*pFirst){ //verifica se será adicionado no topo da lista
					*pFirst = infos;
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(int *)pAtual; //atualiza o next
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0;

					*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0;
					*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = infos;

				}
			}else{
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0; //atualiza o next
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = *(int *)pAtual;

					*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) = infos;
					*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0;

				}
		}else{
			while(*(int *)(pAtual) != 0){
				if(strcmp((char *)infos, (char *)(*pAtual)) < 0){
					if((int *)*pAtual == (int *)*pFirst){ //verifica se será adicionado no topo da lista
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(int *)pAtual;
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0;

						*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = infos;

						*pFirst = infos;
						break;
					}else{ //add no meio
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(int *)pAtual;
						*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = (int)*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int)));
					
						*(int *)pAnt = (int)*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int)));
						*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = infos;
					
						*(void **)(*pAnt + ((sizeof(char) * 10) + (sizeof(int) * 2))) = infos;
						break;
					}

				}

				if(*(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) == 0){
					
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0;
					*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = *(int *)pAtual;

					*(void **)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2))) = infos;
					
					break;
				}

				*(int *)pAtual = *(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2)));
			}	
		}
	}
	return (0);
}

void *pop(void **pFirst){

	void *delete;
	void **infos = (void **)pFirst;

	if(pFirst){
		delete = *(void **)(infos);
		if(*(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2))) == 0){
			free(delete);
			return (0);
		}

		*(int *)pFirst = *(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2)));
		free(delete);
	}

	return(0);
}

void *search(void **pFirst, void **pAtual){

	char *nameSearch = malloc(sizeof(char) * 10);

	printf("\nBuscar nome: ");
	scanf("%s", nameSearch);

	*pAtual = *pFirst;

	while(*(int *)(pAtual) != 0){

		if(strcmp((char *)*pAtual, (char *)nameSearch) == 0){
			printf("\nNome encontrado!");
			printf("\nNome: %s", (char *)*pAtual);
			printf("\nIdade: %d", *(int *)(*pAtual + (sizeof(char) * 10)));
			printf("\nTelefone: %d", *(int *)(*pAtual + (sizeof(char) * 10) + sizeof(int)));
			free(nameSearch);
			return(0);
		}

		*(int *)pAtual = *(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2)));
	}

	printf("\nNenhum nome encontrado!");
	free(nameSearch);
	return(0);
}


void *list(void **pFirst, void **pAtual){

	*pAtual = *pFirst; //atual começa pelo primeiro

	while(*(int *)(pAtual) != 0){

		printf("\n----------------");
		printf("\nNome: %s", (char *)*pAtual);
		printf("\nIdade: %d", *(int *)(*pAtual + (sizeof(char) * 10)));
		printf("\nTelefone: %d", *(int *)(*pAtual + (sizeof(char) * 10) + sizeof(int)));

		*(int *)pAtual = *(int *)(*pAtual + ((sizeof(char) * 10) + (sizeof(int) * 2)));
	}

	return(0);
}

void *exitProgram(void **pFirst, void **pAtual, void **pAnt){

	void *delete;
	void **infos = (void **)pFirst;

	if(pFirst){
		while(1){
			delete = *(void **)(infos);
			if(*(int *)(*pFirst + ((sizeof(char) * 10) + (sizeof(int) * 2))) == 0){
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