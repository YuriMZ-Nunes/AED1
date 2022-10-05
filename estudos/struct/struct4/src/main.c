/*
	Crie uma estrutura representando os alunos de um determinado curso. A estrutura deve
	conter a matricula do aluno, nome, nota da primeira prova, nota da segunda prova e nota
	da terceira prova.

	(a) Permita ao usuario entrar com os dados de 5 alunos. 
	(b) Encontre o aluno com maior nota da primeira prova.
	(c) Encontre o aluno com maior media geral. 
	(d) Encontre o aluno com menor media geral. 
	(e) Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para
		aprovacao. 	

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char nome[20];
	float notaP1, notaP2, notaP3;
}aluno;

int main(){
	
	system("cls");

	aluno alunos[5];
	float maior = 0;
	float media, maiorMedia = 0, menorMedia = 10;
	int alunoMaior, alunoMenor;

	for(int i = 0; i < 5; i++){
		printf("\n");
		printf("\nNome: ");
		scanf("%s", alunos[i].nome);
		printf("\nNota 1: ");
		scanf("%d", alunos[i].notaP1);
		printf("\nNota 2: ");
		scanf("%d", alunos[i].notaP2);
		printf("\nNota 3: ");
		scanf("%d", alunos[i].notaP3);

		if(alunos[i].notaP1 > maior)
			maior = alunos[i].notaP1;
		
		media = (alunos[i].notaP1 + alunos[i].notaP2 + alunos[i].notaP3)/3;

		if(media > maiorMedia){
			maiorMedia = media;
			alunoMaior = i;
		}

		media = (alunos[i].notaP1 + alunos[i].notaP2 + alunos[i].notaP3)/3;
		
		if(media < menorMedia){
			menorMedia = media;
			alunoMenor = i;
		}

	}

	for(int i = 0; i < 5; i++){
		printf("\n");
		printf("\nNome: ");
		printf("\nNota 1: ");
		printf("\nNota 2: ");
		printf("\nNota 3: ");
		scanf("%d", alunos[i].notaP3);
	}

	

	
}