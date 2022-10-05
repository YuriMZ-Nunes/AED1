#include <stdio.h>
#include <string.h>

int main(){
    char frase[50], inverso[50], palindromo1[50], palindromo2[50];
    int j, i;

    printf("Digite uma frase: ");
    gets(frase);

    j = strlen(frase);

    for(i = 0; i < strlen(frase); i++){
        inverso[i] = frase[j-1];
        j--;
    }
    inverso[i] = '\0';

    for(i = 0; i < strlen(frase); i++){
        palindromo1[i] = tolower(frase[i]);
        palindromo2[i] = tolower(inverso[i]);
    }
    palindromo1[i] = '\0';
    palindromo2[i] = '\0';
    
    for(i = 0; i < strlen(palindromo1); i++){
        if(palindromo1[i] == ' ' || palindromo1[i] == '-' || palindromo1[i] == ','){
            for(int k = i; k < strlen(palindromo1); k++){
                palindromo1[k] = palindromo1[k+1];
            }
            i--;
        }
        if(palindromo2[i] == ' ' || palindromo2[i] == '-' || palindromo2[i] == ','){
            for(int k = i; k < strlen(palindromo2); k++){
                palindromo2[k] = palindromo2[k+1];
            }
            i--;
        }
        
    }

    if(strcmp(palindromo1, palindromo2) == 0){
        printf("%s eh é palindromo", frase);
    }else{
        printf("%s nao eh um palindromo", frase);
    }

    
}