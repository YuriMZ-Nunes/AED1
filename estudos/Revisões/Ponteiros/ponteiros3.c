#include <stdio.h>

int main(){
    int a, b;

    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite mais um numero: ");
    scanf("%d", &b);

    if(&a > &b){
        printf("\n O endereço de 'a' é maior que o endereço de 'b'.\n");
        return;
    }

    printf("\n O endereço de 'b' é maior que o endereço de 'a'.\n");

}