#include<stdio.h>

void triangulo(int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i = n - 1; i>0; i--){
        for(int j = 0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){

    int n;

    printf("Digite a largura: ");
    scanf("%d", &n);

    triangulo(n);

}