#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *data, int n);

int main(){
	int n;

	srand(time(NULL));

	printf("\nDigite o tamanho do vetor: ");
	scanf("%d", &n);

	int data[n];

	for(int i=0; i<n; i++){
		data[i] = rand() % 100;
	}

	for(int i=0; i<n; i++)
		printf("[%d] ", data[i]);

	printf("\n");

	selectionSort(data, n);

	for(int i=0; i<n; i++)
		printf("[%d] ", data[i]);
}

void selectionSort(int data[], int n){
	int min, tmp, i, j;

	for(i=0; i<n; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(data[j] < data[min])
				min = j;
		}
		if(min != i){
			tmp = data[i];
			data[i] = data[min];
			data[min] = tmp;
		}
	}
	
}