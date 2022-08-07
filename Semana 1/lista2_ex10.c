#include <stdio.h>

float pesoIdeal(float altura, char sexo){
    float peso;
    if(sexo == 'm'){
        peso = (72.7 * altura) - 58;
        return peso;
    }
    else{
        peso = (62.1 * altura) - 44.7;
        return peso;
    }
}

int main(){
    float altura;
    char sexo;

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    getchar();

    printf("Digite se sexo(m/f): ");
    scanf("%c", &sexo);
    

    printf("Seu peso ideal é: %.2f", pesoIdeal(altura, sexo));

}