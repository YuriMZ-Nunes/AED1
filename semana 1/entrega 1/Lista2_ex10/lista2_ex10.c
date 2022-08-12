/*
Faça um programa que receba a altura e o sexo de uma pessoa e calcule e mostre seu peso ideal, utilizando as seguintes formulas (onde h corresponde a altura):

- Homens: ( 72.7 * h ) - 58
- Mulheres: ( 62.1 * h ) - 44.7

*/

#include <stdio.h>

float PesoIdeal( float altura, char sexo ){
    float peso;
    if( sexo == 'm' ){
        peso = ( 72.7 * altura ) - 58;
        return peso;
    }else{
        peso = ( 62.1 * altura ) - 44.7;
        return peso;
    }
}

int main(){
    float altura;
    char sexo;

    printf( "Digite sua altura: " );
    scanf( "%f", &altura );

    getchar();

    printf( "Digite se sexo(m/f): " );
    scanf( "%c", &sexo );
    
    
    printf( "Seu peso ideal é: %0.2f", PesoIdeal(altura, sexo) );

    return 0;

}