#include <stdio.h>

void exclm(int qtd){
    for(int i=0; i<qtd; i++){
        for(int j=0; j<=i; j++){
            printf("!");
        }
        printf("\n");
    }
}

int main(){
    int qtd;

    printf("Digite a quantidade de '!': ");
    scanf("%d", &qtd);

    exclm(qtd);


}