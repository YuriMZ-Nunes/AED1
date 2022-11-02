#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct NO *left, *right;
	int height;
}NO;

NO* newNode(int x){ //função de criação de um novo nó
	NO *new = malloc(sizeof(NO));

	if(!new){
		printf("ERROR");
	}else{
		new -> num = x;
		new -> right = NULL;
		new -> left = NULL;
		new -> height = 0;
	}

	return new;
}

int bigger(int a, int b) { //recebe a altura e retorna a maior
	if(a > b){
		return a;
	}

	return b;
}

int nodeHeight(NO *node) {  //retorna a altura do nó. caso seja nulo retorna -1
	if(!node)
		return -1;

	return node->height;
}

int balance(NO *node){ //calcula o fator de balanceamento do nó
	if(node)
		return(nodeHeight(node->left) - nodeHeight(node->right));
	
	return 0;
}

NO* leftRotation(NO *root){ //rotação para a esquerda
	NO *newRoot, *children;

	newRoot = root->right; 
	children = newRoot->left;

	newRoot->left = root;
	root->right = children;

	root->height = bigger(nodeHeight(root->left), nodeHeight(root->right)) + 1;
	newRoot->height = bigger(nodeHeight(newRoot->left), nodeHeight(newRoot->right)) + 1;

	return newRoot;
}

NO* rightRotation(NO *root){ //rotação para direita
	NO *newRoot, *children;

	newRoot = root->left;
	children = newRoot->right;

	newRoot->right = root;
	root->left = children;

	root->height = bigger(nodeHeight(root->left), nodeHeight(root->right)) + 1;
	newRoot->height = bigger(nodeHeight(newRoot->left), nodeHeight(newRoot->right)) + 1;

	return newRoot;

}

NO* rightLeftRotation(NO *root){ //rotação esquerda direita
	root->right = rightRotation(root->right);
	return leftRotation(root);
}

NO* leftRightRotation(NO *root){ //rotação direita esquerda
	root->left = leftRotation(root->left);
	return rightRotation(root);
}

int main() {
	
}