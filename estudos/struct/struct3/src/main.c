/*
	Construa uma estrutura aluno com nome, numero de matrıcula e curso. Leia do usuario
	a informacao de 5 alunos, armazene em vetor dessa estrutura e imprima os dados na
	tela.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	int numMatr;
	char curso[15];
}aluno;

int main(){
	system("cls");

	aluno alunos[5];

	for(int i = 0; i < 5; i++){
		printf("\nNome: ");
		scanf("%s", alunos[i].nome);
		printf("\nNumero da matricula: ");
		scanf("%d", &alunos[i].numMatr);
		printf("\nCurso: ");
		scanf("%s", alunos[i].curso);
	}

	for(int i = 0; i < 5; i++){
		printf("\nALUNO %d", i + 1);
		printf("\nNome: %s", alunos[i].nome);
		printf("\nNum mat: %d", alunos[i].numMatr);
		printf("\nCurso: %s", alunos[i].curso);
	}
}