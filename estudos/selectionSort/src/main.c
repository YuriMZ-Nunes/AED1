#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectSort(int data[], int n);

int main() {
	int n;

	srand(time(NULL));

	printf("\n\tDigite o tamanho do vetor: ");
	scanf("%d", &n);

	int data[n];

	for(int i = 0; i < n; i++)
		data[i] = rand() % 100;
	
	printf("\n\tAntes da ordenação:");

	for(int i = 0; i < n; i++)
		printf("[%d] ", data[i]);

	selectSort(data, n);

	printf("\n\tDepois da ordenação:");

	for(int i = 0; i < n; i++)
		printf("[%d] ", data[i]);

}

void selectSort(int data[], int n){
	int min, tmp;
	data[0] = 1;
	for(int i = 0; i < n-1; i++){
		min = i;
		for(int j = i+1; j < n; j++){
			if(data[j] < data[min]){
				min = j;
			}
		}
		if(i != min){
			tmp = data[i];
			data[i] = data[min];
			data[min] = tmp;
		}
		
	}
}