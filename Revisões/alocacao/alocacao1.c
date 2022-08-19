#include <stdio.h>
#include <stdlib.h>

int main(){
    int *array = malloc(sizeof(int) * 5);

    for(int i = 0; i < 5; i++){
        scanf("%d", &array[i]);
    }
    
    for(int i = 0; i < 5; i++){
        printf("%d | ", array[i]);
    }

    free(array);
}