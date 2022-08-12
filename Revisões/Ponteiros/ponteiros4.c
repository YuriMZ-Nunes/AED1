#include <stdio.h>

int Troca(int *a, int *b){
    int aux;

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

    Troca(&a, &b);

    printf("%d, %d\n", a, b);

}