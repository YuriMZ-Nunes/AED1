#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct NO *left, *right;
	int height;
}NO;

int bigger(int a, int b);
int balanceFactor(NO *root);
int height(NO *root);

NO *newNode(int num);
NO *push(NO *root, int num);
NO *rotationLeft(NO *root);
NO *rotationRight(NO *root);
NO *rotationLeftRight(NO *root);
NO *rotationRightLeft(NO *root);
NO *balance(NO *root);
void printTree(NO *root, int level);

int main(){
	NO *root = NULL;
	
	int num;

	while(1){
		printf("\n1. Inserir\n2. Remover\n3. Listar\n");
		switch(getchar()){
			case '1':
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &num);
				root = push(root, num);
				getchar();
				break;
			case '3':
				printTree(root, 1);
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

NO *push(NO *root, int num){
	if(root == NULL){
		return newNode(num);
	}else{
		if(num < root->num)
			root->left = push(root->left, num);
		else if(num > root->num)
			root->right = push(root->right, num);
		else
			printf("\n INSERCAO NAO REALIZADA\n");
	}

	root->height = bigger(height(root->left), height(root->right)) + 1;
	root = balance(root);

	return root;

}	

int bigger(int a, int b){
	if(a > b)
		return a;
	else return b;
}

int height(NO *root){
	if(root == NULL)
		return -1;
	else return root->height;
}

int balanceFactor(NO *root){
	if(root)
		return (height(root->left) - height(root->right));
	else return 0;
}

NO *rotationLeft(NO *root){
	NO *aux, *son;

	aux = root->right;
	son = aux->left;

	aux->left = root;
	root->right = son;

	root->height = bigger(height(root->left), height(root->right)) + 1;
	aux->height = bigger(height(aux->left), height(aux->right)) + 1;

	return aux;
}

NO *rotationRight(NO *root){
	NO *aux, *son;

	aux = root->left;
	son = aux->right;

	aux->right = root;
	root->left = son;

	root->height = bigger(height(root->left), height(root->right)) + 1;
	aux->height = bigger(height(aux->left), height(aux->right)) + 1;

	return aux;
}

NO *rotationLeftRight(NO *root){
	root->left = rotationLeft(root->left);
	return rotationRight(root);
}

NO *rotationRightLeft(NO *root){
	root->right = rotationRight(root->right);
	return rotationLeft(root);
}

NO *balance(NO *root){
	int bf = balanceFactor(root);

	if(bf < -1 && balanceFactor(root->right) <= 0)
		root = rotationLeft(root);
	else if(bf > 1 && balanceFactor(root->left) >= 0)
		root = rotationRight(root);
	else if(bf > 1 && balanceFactor(root->left) < 0)
		root = rotationLeftRight(root);
	else if(bf < -1 && balanceFactor(root->right) > 0)
		root = rotationRightLeft(root);
	
	return root;
}

void printTree(NO *root, int level){
	if(root){
		printTree(root->right, level + 1);
		printf("\n\n");

		for(int i = 0; i < level; i++)
			printf("\t");
		
		printf("%d", root->num);
		printTree(root->left, level + 1);
	}
}


