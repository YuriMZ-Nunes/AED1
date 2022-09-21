#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *push(void **pBuffer, void **pFirst);
void *pop(void **pBuffer, void **pFirst);
void *search(void **pBuffer, void **pFirst);
void *list(void **pBuffer, void **pFirst);
void *exitProgram(void **pBuffer, void **pFirst);

int main(){
    void **pBuffer = NULL; // Buffer de pessoas
    void **pFirst = malloc(sizeof(int) + sizeof(void)); // Ponteiro para a primeira posição do buffer e quantidade de itens
   
    *(int *)pFirst = 0; //primeira posição do pFirst = quantidade de itens armazenados
    *(pFirst + (sizeof(int))) = pBuffer; 

    while(1){
        printf("\n1. ADD\n2. DELETE\n3. BUSCAR\n4. LISTAR\n5. SAIR\n");
        switch(getchar()){
            case '1':
                pBuffer = push(pBuffer, pFirst);
                getchar();
                break;
            case '2':
                pBuffer = pop(pBuffer, pFirst);
                getchar();
                break;
            case '3':
                search(pBuffer, pFirst);
                getchar();
                break;
            case '4':
                list(pBuffer, pFirst);
                getchar();
                break;
            case '5':
                exitProgram(pBuffer, pFirst);
                break;
        }
    }
}

void *push(void **pBuffer, void **pFirst){

    int *nCount = malloc(sizeof(int));
    nCount = (int *)pFirst; //variavel para usar o numero de cadastros
    *(int *)pFirst += 1; 

    int *i = malloc(sizeof(int));
    int *j = malloc(sizeof(int));

    void **pNextNew = malloc(sizeof(char)); //criando espaço para o ponteiro para o proximo do novo nó
    void **pPreviousNew = malloc(sizeof(char)); //criando espaço para o ponteiro para o anterior do novo nó
    void **pNext = malloc(sizeof(char)); //criando espaço para o ponteiro para o proximo para atualizar o nó anterior
    void **pPrevious = malloc(sizeof(char)); //criando espaço para o ponteiro para o anterior para atualizar o proximo nó

    *pNextNew = NULL;
    *pPreviousNew = NULL;
    *pNext = NULL;
    *pPrevious = NULL;
    
    void *infos = malloc((sizeof(char) * 10) + (sizeof(int) * 2) + (sizeof(char) * 2)); //alocando espaço para as informações

    pNextNew = (infos + ((sizeof(char) * 10) + (sizeof(int) * 2))); //aponta para a posição que será armazenado o ponteiro para o proximo
    pPreviousNew = (infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char))); //aponta para a posição que será armazenado o ponteiro para o anterior

    printf("\nNome: ");
    scanf("%s", (char *)infos);
    printf("\nIdade: ");
    scanf("%d", (int *)(infos + (sizeof(char) * 10)));
    printf("\nTelefone: ");
    scanf("%d", (int *)(infos + (sizeof(char) * 10) + sizeof(int)));

    if(pBuffer == NULL){ //verificando se o buffer de cadastros está vazio
        pBuffer = realloc(pBuffer, sizeof(int) * (*nCount)); //realocando espaço para armazenar os ponteiros de cada cadastro
        *pBuffer = infos; //aponta para as informações
        *(pFirst + sizeof(int)) = pBuffer;//atualiza o ponteiro para a primeira posição do buffer
        pNextNew = NULL; //next NULL
        pPreviousNew = NULL; //previous NULL

    }else{
        pBuffer = realloc(pBuffer, sizeof(int) * (*nCount)); //aloca mais um espaço para um endereço de memoria para as infos

        for(*i = 0; *i < (*nCount - 1); *i+=1){

            pNext = (*(pBuffer + (*i - 1)) + (sizeof(char) * 10) + (sizeof(int) * 2));
            pPrevious = (*(pBuffer + (*i + 1)) + (sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char));

            if(strcmp((char *)infos, (char *)(*(pBuffer + *i))) < 0){//compara os nomes para ver em que posição ele deve ficar
                for(*j = (*nCount - 1); *j > *i; *j-=1){
                    *(pBuffer  + (*j)) = *(pBuffer  + (*j - 1));//move os ponteiros para as infos para abrir espaço
                }
                *(pBuffer + *i) = infos;//armazena o endereço das informações na posição correta
                
                if(*i == 0){//verifica se é o primeiro item da lista
                    *(pFirst + sizeof(int)) = pBuffer;
                    pNextNew = *(pBuffer + (*i) + 1);//armazena o next
                    pPreviousNew = NULL; //previous NULL pois é a primeira posição do buffer

                    pPrevious = *(pBuffer + (*i));//atualiza o previous do proximo
                }else{//verifica se ficará no meio da lista
                    pNextNew = *(pBuffer + (*i) + 1); //armazena o next
                    pPreviousNew = *(pBuffer + (*i) - 1); //armazena o previous
                    
                    pNext = *(pBuffer + (*i));//atualiza o next do anterior
                    pPrevious = *(pBuffer + (*i));//atualiza o previous do proximo
                }
                *i = 0;
                break;
            }  
        }
        if(*i == *nCount - 1){ //verifica se é o ultimo item da lista
            *(pBuffer + *i) = infos;
            pNextNew = NULL; //armazena o next
            pPreviousNew = *(pBuffer + (*i) - 1); //armazena o previous

            pNext = *(pBuffer + (*i));//atualiza o next do anterior
        }
    }

    return(pBuffer);
}

void *pop(void **pBuffer, void **pFirst){

    int *nCount = malloc(sizeof(int));
    nCount = (int *)pFirst; //variavel para usar o numero de cadastros

    void *infos; //variavel para armazenar o endereço das infos 
    infos = *pBuffer;

    void **pPreviousNew = malloc(sizeof(char)); //criando espaço para o ponteiro para o anterior do nó
    *pPreviousNew = NULL;
    pPreviousNew = (infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(char)));

    int *i = malloc(sizeof(int));

    for(*i = 0; *i < (*nCount - 1); *i+=1){
        *(pBuffer  + (*i)) = *(pBuffer  + (*i + 1));//move uma posição para a esquerda todos os dados
    }
    *i = 0;

    
    pPreviousNew = NULL; //atualiza o previous da primeira posição para NULL

    *(int *)pFirst -= 1; //diminui a quantidade
    *(pFirst + sizeof(int)) = pBuffer;
    free(infos);
    pBuffer = realloc(pBuffer, sizeof(int) * (*nCount));


    printf("\nCADASTRO REMOVIDO!!\n");
    return(pBuffer);
}

void *search(void **pBuffer, void **pFirst){

    int *nCount = malloc(sizeof(int));
    nCount = (int *)pFirst; //variavel para usar o numero de cadastros

    char *nameSearch = malloc(sizeof(char) * 10);
    int *find = malloc(sizeof(int));//variavel para verificar se foi encontrado um nome 
    *find = 0;

    void *infos;

    int *i = malloc(sizeof(int));

    printf("\nDigite um nome para busca: ");
    scanf("%s", nameSearch);

    for(*i = 0; *i < *nCount; *i+=1){
        infos = *(pBuffer + *i);
        if(strcmp((char *)infos, (char *)nameSearch) == 0){
            printf("\nENCONTRADO!!\n");
            printf("\nNome: %s", (char *)infos);
            printf("\nIdade: %d", *(int *)(infos + (sizeof(char) * 10)));
            printf("\nTelefone: %d\n", *(int *)(infos + (sizeof(char) * 10) + sizeof(int)));
            *find = 1;
        }
    }
    if(*find == 0){
        printf("\nNAO ENCONTRADO!!\n");
    }

    return 0;

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
        infos = *(pBuffer + *i); 
        printf("\nNome: %s", (char *)infos);
        printf("\nIdade: %d", *(int *)(infos + (sizeof(char) * 10)));
        printf("\nTelefone: %d", *(int *)(infos + (sizeof(char) * 10) + sizeof(int)));
    }

    return 0;
}

void *exitProgram(void **pBuffer, void **pFirst){

    int *nCount = malloc(sizeof(int));
    nCount = (int *)pFirst; //variavel para usar o numero de cadastros

    int *i = malloc(sizeof(int));

    void *infos;

    for(*i = 0; *i < *nCount; *i+=1){
        infos = *(pBuffer + *i);
        free(infos);
    }

    free(pFirst);
    free(pBuffer);
    
    exit(0);
}



