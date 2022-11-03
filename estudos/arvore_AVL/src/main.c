#include <stdio.h>
#include <stdlib.h>

typedef struct no{
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
	int height;
	if(!node)
		return -1;

	height = node->height;
	return height;
}

int balanceFactor(NO *node){ //calcula o fator de balanceamento do nó
	int bf;
	if(node)
		bf = (nodeHeight(node->left) - nodeHeight(node->right));
		return bf;
	
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

NO* push(NO *root, int num){
	if(!root)
		return newNode(num);
	else{
		if(num < root->num)
			root->left = push(root->left, num);
		else if(num > root->num)
			root->right = push(root->right, num);
		else
			printf("\n Insercao nao realizada\n");
	}

	root->height = bigger(nodeHeight(root->left), nodeHeight(root->right));

	root = balance(root);

	return root;
			
}

NO* balance(NO *root){
	int bf = balanceFactor(root);

	//rotacao a esquerda
	if(bf < -1 && balanceFactor(root->right) <= 0)
		root = leftRotation(root);

	//rotacao a esquerda
	else if(bf < -1 && balanceFactor(root->left) <= 0)
		root = rightRotation(root);

	//rotacao dupla a esquerda
	else if(bf < -1 && balanceFactor(root->left) < 0)
		root = leftRightRotation(root);
	
	//rotacao dupla a direita
	else if(bf < -1 && balanceFactor(root->right) < 0)
		root = rightleftRotation(root);

}

NO* pop(NO *root, int key){ //remover nó
	if(!root){	//verifica se existe algum nó
		printf("Valor nao encontrado\n");
		return NULL;
	}else{
		if(root->num == key){ //verifica se a raiz é igual ao numero a ser removido
			if(root->left == NULL && root->right == NULL){ //verifica se a raiz não tem folhas
				free(root);
				printf("Elemento folha removido\n");
				return NULL;
			}else{
				if(root->left != NULL && root->right != NULL){ //verifica se tem mais elementos dos 2 lados
					NO *aux = root->left;
					while(aux->right != NULL)
						aux = aux->right;
					root->num = aux->num;
					aux->num = key;
					printf("elemento trocado\n");
					root->left = pop(root->left, key);
					return root;
				}else{
					NO *aux;
					if(root->left != NULL)
						aux = root->left;
					else
						aux = root->right;
					free(root);
					printf("Elemento com 1 filho removido: ");
					return aux;
				}
			}
		}else{ //percorre a arvore
			if(key < root->num)
				root->left = pop(root->left, key);
			else
				root->right = pop(root->right, key);
		}

		root->height = bigger(nodeHeight(root->right), nodeHeight(root->left));

		root = balance(root);

		return root;
	}
}

void printNode(NO *root, int level){
	if(root){
		printNode(root->right, level + 1);
		printf("\n\n");

		for(int i = 0; i < level; i++)
			printf("\t");
		printf("%d", root->num);
		printNode(root->left, level + 1);
	}
}

int main() {
	NO *root = NULL;
	int num;

	while(1){
		printf("\n\n1. Inserir\n2. Remover\n 3. Listar");
		switch(getchar()){
			case '1':
				printf("\nDigite o valor a ser inserido: ");
				scanf("%d", &num);
				root = push(root, num);
				getchar();
				break;
			case '2':
				printf("\nDigite o valor a ser removido: ");
				scanf("%d", &num);
				root = pop(root, num);
				getchar();
				break;
			case '3':
				printNode(root, 1);
				getchar();
				break;
			default:
				printf("Digite uma opcao valida!");
		}
	}


	return 0;
}