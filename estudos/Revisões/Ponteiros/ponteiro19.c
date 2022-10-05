#include <stdio.h>

void contador(int N, int *vet, int *maior, int *qtd){

    int *ini = vet;
    
    *maior = *vet;
    *qtd = 0;

    for(int i = 0; i < N; i++){
        if(*maior >= *vet){
            *maior = *vet;
        }
        vet++;
    }

    vet = ini;

    for(int i = 0; i < N; i++){
        if(*maior == *vet)
            *qtd+=1;
        vet++;
    }

    
}

int main(){
    int N;
    int maior, qtd;
    printf("DIgite o tamanho do vetor: ");
    scanf("%d", &N);

    int vet[N];

    for(int i = 0; i < N; i++){
        printf("%d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    contador(N, &vet, &maior, &qtd);

    printf("Maior: %d\nQuantidade: %d", maior, qtd);

}