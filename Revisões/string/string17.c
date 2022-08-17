#include <stdio.h>
#include <string.h>

int main(){
    char frase[30];

    printf("Digite uma frase: ");
    gets(frase);

    for(int i = 0; i < strlen(frase); i++){
        if(frase[i] == ' '){
            for(int j = i; j < strlen(frase); j++){
                frase[j] = frase[j+1];
            }
        }
    }

    printf(frase);

}