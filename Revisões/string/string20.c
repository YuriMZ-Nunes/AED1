#include <stdio.h>
#include <string.h>

int main(){

    //[quantas palavras terão][tamanho de cada palavra]
    char tabelaCarros[5][15];
    float consumo[5];
    char maisEconomico[15];


    printf("Digite as marcas do carro: \n");
    for(int i = 0; i < 5; i++){
        printf("Modelo %d: ", i+1);
        scanf("%s", tabelaCarros[i]);
        printf("Km/L do %s: ", tabelaCarros[i]);
        scanf("%f", &consumo[i]);

        if(i == 0){
            strcpy(maisEconomico, tabelaCarros[i]);
        }else{
           if(consumo[i] > consumo[i-1]){
                strcpy(maisEconomico, tabelaCarros[i]);
            } 
        }
    }

    for(int i = 0; i < 5; i++){
        printf("O(A) %s gastara %0.2f litros para percorrer 1000 KM\n", tabelaCarros[i], 1000/consumo[i]);
    }

    printf("O modelo mais economico eh o(a) %s",maisEconomico);
} 
