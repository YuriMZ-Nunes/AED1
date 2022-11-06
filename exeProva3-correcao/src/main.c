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
	int num;

	while(1){
		printf("\n\t1. Inserir\n\t2. Giro a esquerda\n\t3. Giro a direita \n\t4. Listar\n\t5. Buscar\n\t6. Remover\n\t7. Sair\n\tEscolha: ");
		switch(getchar()){
			case '1':
				printf("\nDigite um valor: ");
				scanf("%d", &num);
				root = push(root, num);
				getchar();
				break;
			case '2':
				printf("\nDigite um numero: ");
				scanf("%d", &num);
				printf("\n\t--ROTACAO A ESQUERDA FEITA--\n");
				root = searchValue(root, num, 0);
				getchar();
				break;
			case '3':
				printf("\nDigite um numero: ");
				scanf("%d", &num);
				printf("\n\t--ROTACAO A DIREITA FEITA--\n");
				root = searchValue(root, num, 1);
				getchar();
				break;
			case '4':
				printf("\n\t--ARVORE COMPLETA--\n");
				list(root, 1);
				printf("\n");
				getchar();
				break;
			case '5':
				printf("\nDigite um numero: ");
				scanf("%d", &num);
				searchValue(root, num, 2);
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
	NODE *new = malloc(sizeof(NODE)); //aloca espaço para um novo nó

	if(!new){
		printf("ERROR");
	}else{
		new->num = num; //atribui o valor do novo nó
		new->left = NULL; //atribui nulo para o nó da esquerda
		new->right = NULL; //atribui nulo para o nó da direita
		printf("\n\t--NUMERO INSERIDO--\n");
	}
	return new;
}
NODE* push(NODE *root, int num){
	if(root == NULL)
		return newNode(num); //retorna a criação de um novo nó
	else
		if(num < root->num)
			root->left = push(root->left, num); //percorre para esquerda caso o numero seja menor que o nó anterior
		else if(num > root->num)
			root->right = push(root->right, num); //percorre para direita caso o numero seja maior que o nó anterior
		else
			printf("\n\nERRO!!\n\n");
	return root;
}

void list(NODE *root, int level){
	if(root){
		list(root->right, level  + 1); //percorre até o nó mais a direita
		printf("\n\n");

		for(int i = 0; i < level; i++) //adiciona espaços para formar o desenho da arvore
			printf("\t");
		
		printf("%d", root->num); 
		list(root->left, level + 1); //percorre até o nó mais a esquerda
	}
}

NODE* searchValue(NODE *root, int num, int rotateOption){
	if(root){
		if(num > root->num)
			root->right = searchValue(root->right, num, rotateOption); //percorre para direita enquanto o numero procurado é maior q o numero do nó
		else if(num < root->num)
			root->left = searchValue(root->left, num, rotateOption); //percorre para esquerda enquanto o numero procurado é menor q o numero do nó
		else if(num == root->num){ //verifica se encontrou
			if(rotateOption == 0)
				root = rotateLeft(root); //opção 0: rotação a esquerda no nó procurado
			else if(rotateOption == 1)
				root = rotateRight(root); //opção 1: rotação a direita no nó procurado
			else if(rotateOption == 2)
				printf("\n\t--NUMERO %d ENCONTRADO--\n", root->num); //opção 3: apenas buscar o nó
			else{
				root = pop(root); //opção 4: apagar o nó procurado
				printf("\n\t--NUMERO %d REMOVIDO--\n", num);
			}
		}
	}
	return root;
}

NODE* rotateLeft(NODE *root){ //rotação a esquerda
	NODE *aux, *son;
	
	aux = root->right;
	son = aux->left;

	aux->left = root;
	root->right = son;

	return aux;
}

NODE* rotateRight(NODE *root){ //rotação a direita
	NODE *aux, *son;

	aux = root->left;
	son = aux->right;

	aux->right = root;
	root->left = son;

	return aux;		
}

void exitProgram(NODE *root){ //libera todos os nós da memória
	if(root){
		exitProgram(root->left);
		exitProgram(root->right);
		free(root);
	}
}

NODE* pop(NODE *root){ //remove o nó escolhido e suas folhas
	if(root){
		pop(root->left);
		pop(root->right);
		free(root);
	}

	return NULL;
}



