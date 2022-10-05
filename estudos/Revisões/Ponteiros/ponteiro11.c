#include <stdio.h>

int main(){
    int vet[5], *pVet;

    pVet = &vet;

    for( int i = 0; i < 5; i++ ){
        printf("%d: ", i+1);
        scanf("%d", pVet);

        pVet++;
    }

    pVet = &vet;

    for( int i = 0; i < 5; i++ ){
        if( (*pVet)%2 == 0){
            printf("%d %d\n", pVet, *pVet);    
        }
        
        pVet++;
    }
}