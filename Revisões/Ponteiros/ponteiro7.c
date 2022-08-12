#include <stdio.h>

void Soma(int *a, int *b){
    *a = *a + *b;
}

int main(){
    int a, b;

    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite outro numero: ");
    scanf("%d", &b);

    Soma(&a, &b);

    printf("Soma = %d", a);
}