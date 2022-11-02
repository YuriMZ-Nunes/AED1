#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int num;
	struct NO *left, *right;
	int height;
}NO;

NO* newNode(int x){
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

int bigger(int a, int b) {
	if(a > b){
		return a;
	}

	return b;
}

int nodeHeight(NO *node) {
	if(!node)
		return -1;

	return node->height;
}

int balance(NO *node){
	if(node)
		return(nodeHeight(node->left) - nodeHeight(node->right));
	
	return 0;
}

int main() {
	
}