#include <stdio.h>
#include <stdlib.h>

int main(){
    int N;
    printf("Tamanho do vetor: ");
    scanf("%d", &N);

    int *vet = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        printf("%d: ", i+1);
        scanf("%d", &vet[i]);
    }

    for(int i = 0; i < N; i++){
        printf(" %d |", vet[i]);
    }

    free(vet);
}