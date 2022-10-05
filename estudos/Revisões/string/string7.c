#include <stdio.h>

int main(){
    char str1[10], str2[10];
    int i = 0;
    int equals;
    

    printf("Digite a primeira palavra: ");
    gets(str1);
    printf("%s\n", str1);
    printf("Digite a segunda palavra: ");
    gets(str2);
    printf("%s\n", str2);

    while(str1[i] != '\0'){
        if(str1[i] == str2[i]){
            equals = 1;
        }else{
            equals = 0;
            printf("%s e %s são diferentes", str1, str2);
            break;
        }
        i++;
    }

    if(equals == 1){
        printf("são iguais.");
    }

    
}