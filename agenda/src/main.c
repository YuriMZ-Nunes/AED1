#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *push(void **pBuffer, void **pFirst);
void *list(void **pBuffer, void **pFirst);

int main(){
    void **pBuffer = NULL; // Buffer de pessoas
    void **pFirst = malloc(sizeof(int) + sizeof(void)); // Ponteiro para a primeira posição do buffer e quantidade de itens
   
    *(int *)pFirst = 0; //primeira posição do pFirst = quantidade de itens armazenados
    *(pFirst + (sizeof(int))) = pBuffer; 

    while(1){
        printf("\n1. ADD\n");
        switch(getchar()){
            case '1':
                pBuffer = push(pBuffer, pFirst);
                getchar();
                break;
            case '2':
                list(pBuffer, pFirst);
                getchar();
                break;
        }
    }
}

void *push(void **pBuffer, void **pFirst){

    int *nCount = malloc(sizeof(int));
    nCount = (int *)pFirst; //variavel para usar o numero de cadastros
    *(int *)pFirst += 1; 

    int *i = malloc(sizeof(int));
    *i = 0;
    int *j = malloc(sizeof(int));
    *j = 0;

    //char **pNext = malloc(sizeof(char)); //criando espaço para o ponteiro para o proximo
    //char **pPrevios = malloc(sizeof(char)); //criando espaço para o ponteiro para o anterior
    
    void *infos = malloc((sizeof(char) * 10) + (sizeof(int) * 2) + (sizeof(char) * 2)); //alocando espaço para as informações
    //**pNext = *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2)));
    //**pPrevios = *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char)));

    printf("\nNome: ");
    scanf("%s", (char *)infos);
    printf("\nIdade: ");
    scanf("%d", (int *)(infos + (sizeof(char) * 10)));
    printf("\nTelefone: ");
    scanf("%d", (int *)(infos + (sizeof(char) * 10) + sizeof(int)));

    if(pBuffer == NULL){ //verificando se o buffer de cadastros está vazio
        pBuffer = realloc(pBuffer, sizeof(int) * (*nCount)); //realocando espaço para armazenar os ponteiros de cada cadastro
        *(pBuffer) = infos; //aponta para as informações
        *(pFirst + sizeof(int)) = pBuffer;//atualiza o ponteiro para a primeira posição do buffer
        *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = NULL; //next NULL
        *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char))) = NULL; //previous NULL

    }else{
        pBuffer = realloc(pBuffer, sizeof(int) * (*nCount)); //aloca mais um espaço para um endereço de memoria para as infos

        for(*i = 0; *i < (*nCount - 1); *i+=1){
            if(strcmp((char *)infos, (char *)(*(pBuffer + *i))) < 0){//compara os nomes para ver em que posição ele deve ficar
                for(*j = *i; *j < (*nCount); *j+=1){
                    *(pBuffer  + (*j + 1)) = *(pBuffer  + (*j));//move os ponteiros para as infos para abrir espaço
                }
                *(pBuffer + *i) = infos;//armazena o endereço das informações na posição correta
                
                if(*i == 0){
                    *(pFirst + sizeof(int)) = pBuffer;
                    *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(pBuffer + (*i) + 1); //armazena o next
                    *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char))) = NULL; //previous NULL pois é a primeira posição do buffer

                    *(char *)(*(pBuffer + (*i + 1)) + (sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char)) = *(pBuffer + (*i));//atualiza o previous do proximo
                }else{
                    *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = *(pBuffer + (*i) + 1); //armazena o next
                    *(char *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char))) = *(pBuffer + (*i) - 1); //armazena o previous
                    
                    *(char *)(*(pBuffer + (*i - 1)) + (sizeof(char) * 10) + (sizeof(int) * 2)) = *(pBuffer + (*i));//atualiza o next do anterior
                    *(char *)(*(pBuffer + (*i + 1)) + (sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char)) = *(pBuffer + (*i));//atualiza o previous do proximo
                }
                *i = 0;
                break;
            }  
        }
        if(*i == *nCount - 1){
            *(pBuffer + *i) = infos;
        }
    }

    return(pBuffer);
}

void *list(void **pBuffer, void **pFirst){
    int *nCount = malloc(sizeof(int));
    nCount = (int *)pFirst; //variavel para usar o numero de cadastros

    void *infos;

    int *i = malloc(sizeof(int));
    *i = 0;
    int *j = malloc(sizeof(int));
    *j = 0;

    for(*i = 0; *i < *nCount; *i+=1){
        printf("\n%d", *i);
        infos = *(pBuffer + *i); 
        printf("\nNome: %s", (char *)infos);
        printf("\nIdade: %d", *(int *)(infos + (sizeof(char) * 10)));
        printf("\nTelefone: %d", *(int *)(infos + (sizeof(char) * 10) + sizeof(int)));
    }
}



