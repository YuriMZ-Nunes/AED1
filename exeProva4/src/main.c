#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int nums[], int n);

int main(){
	int n;

	srand(time(NULL));

	printf("\nDigite o tamanho do vetor desejado: ");
	scanf("%d", &n);

	int nums[n];

	for(int i = 0; i < n; i++)
		nums[i] = rand() % 100;

	printf("\n\tANTES DA ORDENACAO\n\n");

	for(int i = 0; i < n; i++)
		printf("[%d] ", nums[i]);

	selectionSort(nums, n);

	printf("\n\tDEPOIS DA ORDENACAO\n\n");

	for(int i = 0; i < n; i++)
		printf("[%d] ", nums[i]);

	
}

void selectionSort(int nums[], int n){
	int min, aux;

	for(int i = 0; i < n - 1; i++){
		min = i;
		for(int j = i + 1; j < n; j++){
			if((nums[min]%2 != 0) && (nums[j]%2 == 0))
				min = j;
		}
		if(i != min){
			aux = nums[i];
			nums[i] = nums[min];
			nums[min] = aux;
		}
	}
}