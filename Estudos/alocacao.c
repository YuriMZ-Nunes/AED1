#include <stdio.h>
#include <stdlib.h>

int main(){

    int *p;

    p = (int *) malloc(4);

    *p = 12;

    printf("%d", p);
    
}