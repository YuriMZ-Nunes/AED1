#include <stdio.h>

int main(){
    int vet[5], *pVet;

    pVet = &vet;

    for(int i = 0; i < 5; i++){
        printf("%d: ", i+1);
        scanf("%d", pVet);
        
        pVet++;
    }

    pVet = &vet;

    for(int i = 0; i < 5; i++){
        printf("%d: ", (*pVet)*2);
        pVet++;
    }

}