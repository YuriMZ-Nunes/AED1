#include <stdio.h>

int main(){
    int A = 34, *B, **C, ***D;

    D = &C;
    C = &B;
    B = &A;

    printf("%d %d %d %d", A, *B*2, **C*3, ***D*4);

}