/*

Crie uma função que receba como parãmetro um valor inteiro e gere como saída n linhas
com pontos de exclamção, conforme o exemplo abaixo (para n = 5):
!
!!
!!!
!!!!
!!!!!


*/

#include <stdio.h>

void Exclm( int qtd ){
    for( int i=0; i<qtd; i++ ){
        for( int j=0; j<=i; j++ ){
            printf( "!" );
        }
        printf( "\n" );
    }
}

int main(){
    int qtd;

    printf( "Digite a quantidade de '!': " );
    scanf( "%d", &qtd );

    Exclm( qtd );


}