#include <stdio.h>


//função recebe o endereço das variaveis vazias
void frac(float num, int* inteiro, float* frac){

  *inteiro = (int)num;
  *frac = num - *inteiro;
    
}

int main(){
    float num = 2.50;
    //cria 2 variaveis vazias para receber conteudo na função
    float numFrac;
    int inteiro;

    //manda os endereços das variaveis vazias para a função
    frac(num, &inteiro, &numFrac);

    printf("%0.2f, %d, %0.2f", num, inteiro, numFrac);
}