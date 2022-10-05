#include <stdio.h>

int main(){
    int a = 3, b = 7, *p1, *p2;

    p1 = &b;
    p2 = &a;

    if(p1 > p2) {
        printf("p1 é maior");
    }else if(p1 < p2){
        printf("p2 é maior");
    }else{
        printf("são iguais");
    }
}