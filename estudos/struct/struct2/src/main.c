#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char rua[20];
	char bairro[20];
	int numero;
}endereco;

typedef struct{
	char nome[15];
	int idade;
	endereco end;
}dados;

int main(){
	system("cls");

	dados pessoa;

	printf("Nome: ");
	scanf("%s", pessoa.nome);
	printf("\nIdade: ");
	scanf("%d", &pessoa.idade);
	printf("\nRua: ");
	scanf("%s", pessoa.end.rua);
	printf("\nBairro: ");
	scanf("%s", pessoa.end.bairro);
	printf("\nNumero: ");
	scanf("%d", &pessoa.end.numero);

	printf("\n PESSOA CADASTRADA \n");

	printf("\nNome: %s", pessoa.nome);
	printf("\nIdade: %d", pessoa.idade);
	printf("\nRua: %s", pessoa.end.rua);
	printf("\nBairro: %s", pessoa.end.bairro);
	printf("\nNumero: %d", pessoa.end.numero);
	
	return(0);
}