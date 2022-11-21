#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int data[], int left, int right);

int main(){
	int n;

	srand(time(NULL));

	printf("--%d--", 9/2);

	printf("\nDigite o tamanho do vetor: ");
	scanf("%d", &n);

	int data[n];

	for(int i=0; i<n; i++)
		data[i] = rand() % 100;
	
	for(int i=0; i<n; i++)
		printf("[%d] ", data[i]);
	
	printf("\n");

	quickSort(data, 0, n-1);

	for(int i=0; i<n; i++)
		printf("[%d] ", data[i]);

}

void quickSort(int data[], int left, int right){
	int i, j, pivo, aux;

	i = left;
	j = right;
	pivo = data[(left + right)/2];

	while(i <= j){
		while(data[i] < pivo && i < right)
			i++;
		while(data[j] > pivo && j > left)
			j--;
		if(i <= j){
			aux = data[i];
			data[i] = data[j];
			data[j] = aux;
			i++;
			j--;
		}
	}

	if(j > left)
		quickSort(data, left, j);
	if(i < right)
		quickSort(data, i, right);
}
