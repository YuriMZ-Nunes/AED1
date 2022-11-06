#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct NODE *left, *right;
}NODE;

NODE* push(NODE *root, int num);
NODE* rotate(NODE *root, int numRotacao);
NODE* newNode(NODE *root, int num);


void list(NODE *root);

int main(){
	NODE *root = NULL;
	int num, numRotacao;

	while(1){
		printf("\n\t1. inserir\n\t2. girar algum nó\n\t3. listar ");
		switch(getchar()){
			case '1':
				printf("\nDigite um valor: ");
				scanf("%d", &num);
				root = push(root, num);
				getchar();
				break;
			case '2':
				printf("\nDigite um numero: ");
				scanf("%d", &numRotacao);
				root = rotate(root, numRotacao);
				getchar();
				break;
			case '3':
				list(root);
				getchar();
				break;
		}
	}
}

NODE* newNode(NODE *root, int num){
	NODE *new = malloc(sizeof(NODE));

	if(!new){
		printf("ERROR");
	}else{
		new->num = num;
		new->left = NULL;
		new->right = NULL;
		printf("\n\nINSERIDO\n\n");
	}

	return new;
}

NODE* push(NODE *root, int num){
	if(root == NULL)
		return newNode(root, num);
	else
		if(num < root->num)
			root->left = push(root->left, num);
		else if(num > root->num)
			root->right = push(root->right, num);
		else
			printf("\n\nERRO!!\n\n");

	return root;

}

void list(NODE *root){
	if(root){
		printf("%d ", root->num);
		list(root->left);
		list(root->right);
	}
}


NODE* rotate(NODE *root, int numRotacao){
	NODE *aux, *son;

	aux = root->right;
	son = aux->left;

	aux->left = root;
	root->right = son;

	return aux;
	
}


