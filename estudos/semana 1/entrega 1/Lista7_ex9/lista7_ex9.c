/*

Faça umam função que receba a altura e o raio de um cilindro circular e retorne o volume ˜
do cilindro. O volume de um cilindro circular e calculado por meio da seguinte fórmula: 

vol = 3.141592 * ( raio * raio ) * altura

*/

#include <stdio.h>

float Volume( float altura, float raio ){
    float vol;

    vol = 3.141592 * ( raio * raio ) * altura;

    return vol;
}

int main(){
    float altura, raio;
    printf( "Digite a altura: " );
    scanf( "%f", &altura );

    printf( "Digite o raio: " );
    scanf( "%f", &raio );

    printf( "Volume: %0.2f\n", Volume(altura, raio) );
    
}