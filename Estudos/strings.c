#include <stdio.h>
#include <stdlib.h>


int main(){
    char letra;

    printf("Digite: ");
    getc(letra);
    
    letra -= 32;
    printf("\n%s", letra);
}