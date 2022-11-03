#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct NO *left, *right;
	int height;
}NO;

NO *newNode(int num);
NO *push(NO **root, int num);

int main(){
	NO **root = malloc(sizeof(NO));
	*root = NULL;
	int num;

	while(1){
		printf("\n1. Inserir\n2. Remover\n 3. Listar\n");
		switch(getchar()){
			case '1':
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &num);
				*root = push(root, num);
				getchar();
				break;
		}
	}

}

NO *newNode(int num){
	NO *new = malloc(sizeof(NO));

	if(!new){
		printf("\n\nERROR\n\n");
		return NULL;
	}else{
		new->num = num;
		new->left = NULL;
		new->right = NULL;
		new->height = 0;
		printf("\n\nINSERIDO\n\n");
		return new;
	}
}

NO *push(NO **root, int num){
	if(*root == NULL){
		return newNode(num);
	}else{
		if(num < (*root)->num)
			(*root)->left = push((*root)->left, num);
	}

}
