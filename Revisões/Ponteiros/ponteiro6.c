#include <stdio.h>

int Soma(int *a, int *b){
    *a *= 2;
    *b *= 2;

    return *a + *b;
}

int main(){
    int a, b;

    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite outro numero: ");
    scanf("%d", &b);

    printf("%d + %d = %d", a, b, Soma(&a, &b));

}