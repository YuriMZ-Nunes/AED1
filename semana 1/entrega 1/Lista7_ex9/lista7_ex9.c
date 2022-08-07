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