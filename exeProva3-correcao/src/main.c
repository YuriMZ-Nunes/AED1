#include <stdio.h>
#include <stdlib.h>

typedef struct NODE{
	int num;
	struct NODE *left, *right;
}NODE;

NODE* push(NODE *root, int num);
NODE* searchValue(NODE *root, int numRotacao, int rotateOption);
NODE* rotateLeft(NODE *root);
NODE* rotateRight(NODE *root);
NODE* newNode(int num);
NODE* pop(NODE *root);
void exitProgram(NODE *root);


void list(NODE *root, int level);

int main(){
	NODE *root = NULL;
	int num, numRotacao;

	while(1){
		printf("\n\n\t1. Inserir\n\t2. Giro a esquerda\n\t3. Giro a direita \n\t4. Listar\n\t5. Buscar\n\t6. Sair\n\tEscolha: ");
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
				root = searchValue(root, numRotacao, 0);
				getchar();
				break;
			case '3':
				printf("\nDigite um numero: ");
				scanf("%d", &numRotacao);
				root = searchValue(root, numRotacao, 1);
				getchar();
				break;
			case '4':
				list(root, 1);
				getchar();
				break;
			case '5':
				printf("\nDigite um numero: ");
				scanf("%d", &numRotacao);
				searchValue(root, numRotacao, 2);
				getchar();
				break;
			case '6':
				printf("\nDigite um numero para remover: ");
				scanf("%d", &num);
				searchValue(root, num, 3);
				getchar();
				break;
			case '7':
				exitProgram(root);
				exit(1);
				break;
			default:
				printf("\nDigite um numero valido!");
				getchar();
				break;
		}
	}
}

NODE* newNode(int num){
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
		return newNode(num);
	else
		if(num < root->num)
			root->left = push(root->left, num);
		else if(num > root->num)
			root->right = push(root->right, num);
		else
			printf("\n\nERRO!!\n\n");
	return root;
}

void list(NODE *root, int level){
	if(root){
		list(root->right, level  + 1);
		printf("\n\n");

		for(int i = 0; i < level; i++)
			printf("\t");
		
		printf("%d", root->num);
		list(root->left, level + 1);
	}
}

NODE* searchValue(NODE *root, int numRotacao, int rotateOption){
	if(root){
		if(numRotacao > root->num)
			root->right = searchValue(root->right, numRotacao, rotateOption);
		else if(numRotacao < root->num)
			root->left = searchValue(root->left, numRotacao, rotateOption);
		else if(numRotacao == root->num){
			if(rotateOption == 0)
				root = rotateLeft(root);
			else if(rotateOption == 1)
				root = rotateRight(root);
			else if(rotateOption == 2)
				printf("\n o numero %d esta cadastrado!", root->num);
			else
				root = pop(root);
		}
	}
	return root;
}

NODE* rotateLeft(NODE *root){
	NODE *aux, *son;
	
	aux = root->right;
	son = aux->left;

	aux->left = root;
	root->right = son;

	return aux;
}

NODE* rotateRight(NODE *root){
	NODE *aux, *son;

	aux = root->left;
	son = aux->right;

	aux->right = root;
	root->left = son;

	return aux;		
}

void exitProgram(NODE *root){
	if(root){
		exitProgram(root->left);
		exitProgram(root->right);
		free(root);
	}
}

NODE* pop(NODE *root){
	if(root){
		pop(root->left);
		pop(root->right);
		free(root);
	}

	return NULL;
}



