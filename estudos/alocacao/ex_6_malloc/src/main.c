#include <stdio.h>
#include <stdlib.h>

void adicionar(int *vet){
    int posicao, num;

	int *ini = vet;

    for(int i = 0; i < 5; i++){
        printf("[ %d ]", *vet);
        vet++;
    }

	vet = ini;

    printf("\nEm qual posição deseja adicionar: ");
    scanf("%d", &posicao);

    printf("\nEscreva o numero a ser adicionado: ");
    scanf("%d", &num);
    vet[posicao] = num;
	 
	for(int i = 0; i < 5; i++){
        printf("[ %d ]", *vet);
        vet++;
    }
    
}

void menu(int *vet){
    int escolha;
    int *ini = vet;

    for(int i = 0; i < 5; i++){
        printf("[ %d ]", *vet);
        vet++;
    }

    vet = ini;

    printf("\n");

    printf("1. Adicionar em determinada posição\n");
    printf("2. Consultar determinada posição\n");

    scanf("%d", &escolha);

    if(escolha == 1){
        adicionar(vet);
    }else if(escolha==2){

    }else{
        menu(vet);
    }
}

int main(){
    int tam;

    printf("Digite o tamanho da memoria em bytes: ");
    scanf("%d", &tam);

    if(tam % sizeof(int) != 0){
        printf("Digite o tamanho correto (multiplo de 4): ");
        scanf("%d", &tam);
    }

    int *vet = malloc(sizeof(int) * tam);

    printf(" inicio: endereco do vetor: %d\n", vet);
    

    for(int i = 0; i < tam/sizeof(int); i++){
        vet[i] = i;
    }

    for(int i = 0; i < tam/sizeof(int); i++){
        printf("[ %d ]", vet[i]);
    }

    printf("\n");

    menu(vet);

}