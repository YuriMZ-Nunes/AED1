#include <stdio.h>

int Maior(int *a, int *b){
    int aux;
    if( *a > *b){
        return;
    }

    aux = *a;
    *a = *b;
    *b = aux;
}

int main(){
    int a, b;

    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite outro numero: ");
    scanf("%d", &b);

    Maior(&a, &b);

    printf("maior valor: %d, menor valor: %d\n", a, b);
}