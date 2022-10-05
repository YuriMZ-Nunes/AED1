#include <stdio.h>

int main(){
    int i = 1, *pi;
    float f = 2.5, *pf;
    char c = 'm', *pc;

    pi = &i;
    pf = &f;
    pc = &c;

    printf("Antes da modificação: %d, %0.2f, %c\n", *pi, *pf, *pc);

    *pi = *pi * 5;
    *pf = *pf * 2.5;
    *pc= 'd';

    printf("Depois da modificação: %d, %0.2f, %c\n", *pi, *pf, *pc);

}