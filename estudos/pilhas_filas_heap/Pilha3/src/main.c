#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Reset(Pilha *pilha);

typedef struct{
	int ra;
	char nome[50];
}Aluno;

typedef struct{
	Aluno *alunos;
	Aluno *topo;
	Aluno *base;
	int limite;
}Pilha;

int main()
{

}

void Reset(Pilha *pilha){
	pilha -> alunos = NULL;
	pilha -> topo = NULL;
	pilha -> base = NULL;
	pilha -> limite = 0;
}