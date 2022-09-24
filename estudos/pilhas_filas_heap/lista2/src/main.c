#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int cod;
	char nome[40];
	float preco;
}SProduto;

typedef struct{
	SProduto info;
	struct STipoFila *pNext;
}STipoFila;

typedef struct{
	STipoFila *pFirst;
	STipoFila *pLast;
}Sfila;


int main()
{
	
}