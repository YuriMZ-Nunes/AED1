#include <stdio.h>
#include <stdlib.h>

int main(){
    char string[20];
    int stringSize = 0;


    printf("Digite uma palavra: ");
    gets(string);

    printf("%s\n", string);

    while (string[stringSize] != '\0')
        stringSize++;
    
    printf("A palavra %s tem %d letras", string, stringSize);
    
}