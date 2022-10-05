#include <stdio.h>

int main(){
    float num[10];

    for( int i = 0; i < 10; i++ ){
        printf("%d: ", i+1);
        scanf("%d", &num[i]);
    }

    for( int i = 0; i < 10; i++ ){
        printf(" Endereço do %dº valor: %d\n", i+1, &num[i]);
    }
}