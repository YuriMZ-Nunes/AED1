#include <stdio.h>

int main(){
    float mat[3][3];

    for( int i = 0; i < 3; i++){
        for( int j = 0; j < 3; j++){
            printf("Linha %d coluna %d: ", i+1, j+1);
            scanf("%d", &mat[i][j]);
        }
    }

    for( int i = 0; i < 3; i++){
        for( int j = 0; j < 3; j++){
            printf("endereço da linha %d coluna %d: %d\n", i+1, j+1, &mat[i][j]);
        }
    }
}