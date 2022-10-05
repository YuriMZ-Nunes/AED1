#include <stdio.h>

int Ordem(int *a, int *b, int *c){
    int aux;

    if(*a == *b && *b == *c){
        return 1;
    }else{
        if(*a > *b && *a > *c){
            if(*b > *c)
                return 0;
            else{
                aux = *b;
                *b = *c;
                *c = aux;
            }
        }else if(*b > *a && *b > *c){
            if(*a > *c){
                aux = *b;
                *b = *a;
                *a = aux;
            }else{
                aux = *b;
                *b = *a;
                *a = aux;
                aux = *b;
                *b = *c;
                *c = aux;
            }
        }else if(*c > *a && *c > *b){
            if(*a > *b){
                aux = *c;
                *c = *b;
                *b = aux;
                aux = *b;
                *b = *a;
                *a = aux;
            }
            else{
                aux = *c;
                *c = *a;
                *a = aux;
            }
        }
        return 0;
    }
}

int main(){
    int a, b, c, ret;

    printf("Digite um numero: ");
    scanf("%d", &a);
    printf("Digite mais um numero: ");
    scanf("%d", &b);
    printf("Digite mais um numero: ");
    scanf("%d", &c);

    ret = Ordem(&a, &b, &c);

    printf("maior: %d, meio: %d, menor: %d, retorno: %d", a, b, c, ret);
}