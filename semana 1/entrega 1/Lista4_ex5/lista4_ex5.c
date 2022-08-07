/*

Leia um vetor de 10 posições. Contar e escrever quantos valores pares ele possui.

*/

#include <stdio.h>

int main(){
    int num[10];
    int pares = 0;

    for( int i=0; i<10; i++ ){
        printf( "%d: ", i+1);
        scanf( "%d", &num[i] );
        if( num[i]%2 == 0 ){
            pares+=1;
        }
    }

    printf( "A quantidade de pares é: %d\n", pares );


}