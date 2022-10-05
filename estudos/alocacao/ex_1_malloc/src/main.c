#include <stdio.h>
#include <stdlib.h>

int *Valores (int *pBuffer){
    for (int i = 0; i < 4; i++)
        *(pBuffer+i) = i+6;

    printf("\nValores durante funcao\n");

    for (int i = 0; i < 4; i++)
        printf(" [%d] ", *(pBuffer+i));
    
    return (int*) realloc(pBuffer, 4*sizeof(int));
}

int main(){
    int *pBuffer = malloc(5*sizeof(int));

    pBuffer = Valores(pBuffer);

    printf("\nNovos valores\n");
    for (int i = 0; i < 4; i++)
        printf(" [%d] ", *(pBuffer+i));
        
}