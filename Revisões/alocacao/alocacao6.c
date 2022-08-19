#include <stdio.h>
#include <stdlib.h>

void adicionar(int *vet){
    int posicao, num;

    printf("%d\n", vet);
    printf("%d\n", *vet);



    printf("Em qual posição deseja adicionar: ");
    scanf("%d", &posicao);

    printf("Escreva o numero a ser adicionado: ");
    scanf("%d", &num);
    vet[posicao] = num;

    for(int i = 0; i < 5; i++){
        printf("%d", vet[i]);
    }

}

void menu(int *vet){
    int escolha;

    printf("%d\n", vet[0]);
    printf("%d\n", *vet);

    printf("1. Adicionar em determinada posição\n");
    printf("2. Consultar determinada posição\n");

    scanf("%d", &escolha);

    if(escolha == 1){
        adicionar(&vet);
    }else if(escolha==2){

    }else{
        menu(&vet);
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

    for(int i = 0; i < tam/sizeof(int); i++){
        vet[i] = 0;
    }

    printf("endereco do vetor: %d\n", &vet);
    menu(&vet);

}