#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *push(char *aluno, void **pilha);
char *pop(char *aluno, void **pilha);

int main()
{	
	void **pilha = malloc(3 + sizeof(int)); //qtd de dados na pilha | primeiro item | ultimo item
	char *aluno = NULL;
	*(int *)pilha = 0;

	while(1){
		printf("\n1. add\n2. remover\n3. listar\n");
		switch(getchar()){
			case '1':
				aluno = push(aluno, pilha);
				getchar();
				break;
			case '2':
				printf("%s", (char *)(pop(aluno, pilha)));
				//pop(aluno, pilha);
				getchar();
				break;
		}
	}
}

void *push(char *aluno, void **pilha){
	
	*(int *)pilha += 1;
	char *nome = malloc(sizeof(char) * 10);
	
	printf("\nNome: ");

	if(*(int *)pilha == 1){ //verifica se aluno esta vazio
		scanf("%s", nome); 
		aluno = malloc(strlen(nome) + 1);
		strcpy(aluno, nome); //adiciona o nome na pilha
		*(pilha + 1) = aluno; //armazena o primeiro item da pilha
		*(pilha + 2) = aluno; //armazena o ultimo item da pilha
		*(pilha + 3) = strlen(nome);
		printf("Primeiro nome adicionado!");
	}else{
		*nome = '-'; //adiciona um separador
		scanf("%s", nome + sizeof(char));  
		aluno = realloc(aluno, (strlen(aluno) + strlen(nome) + 1)); //realoca mais um espaço para um nome
		*(pilha + 2) = aluno + strlen(aluno); //armazena o ultimo item da pilha
		strcpy(aluno + strlen(aluno), nome);//adiciona o nome na pilha
		// o endereço do primeiro item ja esta armazenado
		printf("Nome adicionado!");
	}

	return(aluno);
}

char *pop(char *aluno, void **pilha){
	
	char *removed = malloc(sizeof(char) * 10); //aloca um espaço para capturar o nome a ser retirado

	if(!aluno){ //verifica se a pilha de alunos esta vazia
		printf("Nenhum dado para remover.");
		return(aluno);
	}else{
		strcpy(removed, *(pilha + 2) + 1); //copia o ultimo nome para a removed
		aluno = realloc(aluno, strlen(aluno) - strlen(removed) - 1); //remoção do nome da pilha. -1 para remover o separador
		

		return(removed); //retorna o nome removido
	}
}

void *list(char *aluno, void **pilha){

}
