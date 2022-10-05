#include <stdio.h>

int Preencher(int *vet, int *num){

    int *aux = vet;

    for(int i = 0; i < 5; i++){
        *vet = *num;
        vet++;
    }

    vet = aux;

    for(int i = 0; i < 5; i++){
        printf("\n%d", *vet);
        vet++;
    }

}

int main(){
    int vet[5] = {16,2,3,4,5}, num;

    printf("digite um numero: ");
    scanf("%d", &num);

    Preencher(&vet, &num);

}