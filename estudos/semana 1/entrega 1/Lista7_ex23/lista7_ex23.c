/*

Escreva uma função que gera um triãngulo lateral de altura ( 2*n-1 ) e n largura. Por exem- ˆ
plo, a saída para n = 4 seria:

*
**
***
****
***
**
*

*/

#include<stdio.h>

void Triangulo( int n ){
    for( int i = 0; i<n; i++ ){
        for( int j = 0; j<=i; j++ ){
            printf( "*" );
        }
        printf( "\n" );
    }

    for( int i = n - 1; i>0; i-- ){
        for( int j = 0; j<i; j++ ){
            printf( "*" );
        }
        printf( "\n" );
    }
}

int main(){

    int n;

    printf( "Digite a largura: " );
    scanf( "%d", &n );

    Triangulo( n );

}