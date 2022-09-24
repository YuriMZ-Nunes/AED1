#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[10];
}Aluno;

typedef struct{
	Aluno *alunos;
	Aluno *topo;
	Aluno *base;
	int limite;
}Pilha;

void Reset(Pilha *pilha);
void push(Pilha *pilha, Aluno *item);
void pop(Pilha *pilha, Aluno *aluno);

int main(){
	Aluno *item = (Aluno *)malloc(sizeof(Aluno));

	Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));

	pilha -> alunos = NULL;
	pilha -> topo = NULL;
	pilha -> base = NULL;
	pilha -> limite = 0;

	while (1){
		switch(getchar()){
			case '1':
				printf("\nDigite um nome: ");
				scanf("%s", item -> nome);
				push(pilha, item);
				getchar();
				break;
			case '2':
				Aluno aluno;
				pop(pilha, &aluno);
				getchar();
				break;
		}
		
	}
	

	
}



void push(Pilha *pilha, Aluno *item){
	Aluno *alunos;

	pilha -> limite++;

	alunos = (Aluno *)malloc(sizeof(Aluno));

	pilha -> alunos = alunos;
	pilha -> alunos[pilha -> limite -1] = *item;
	pilha -> topo = &pilha -> alunos[pilha -> limite - 1];
	pilha -> base = pilha -> alunos;

}

void pop(Pilha *pilha, Aluno *aluno){

	aluno = pilha -> topo;
}
