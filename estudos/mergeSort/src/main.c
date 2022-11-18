#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void mergeSort(int data[], int begin, int end);
void merge(int data[], int begin, int mid, int end);

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

	mergeSort(data, 0, n - 1);

	printf("\n\tDepois da ordenação:");

	for(int i = 0; i < n; i++)
		printf("[%d] ", data[i]);

}

void mergeSort(int data[], int begin, int end){
	int mid;
	if(begin < end){
		mid = floor((begin + end) / 2);
		mergeSort(data, begin, mid); //O(N)
		mergeSort(data, mid+1, end); //O(N)
		merge(data, begin, mid,end);
	}
}

void merge(int data[], int begin, int mid, int end){
	int *temp, p1, p2, size, i, j, k;
	int end1 = 0, end2 = 0;
	size = end - begin + 1;
	p1 = begin;
	p2 = mid + 1;
	temp = (int *)malloc(size * sizeof(int));
	if(temp != NULL){
		for(i = 0; i < size; i++){ // O(N)
			if(!end1 && !end2){
				if(data[p1] < data[p2])
					temp[i] = data[p1++];
				else
					temp[i] = data[p2++];
				if(p1 > mid)
					end1 = 1;
				if(p2 > end)
					end2 = 1;
			}else{
				if(!end1)
					temp[i] = data[p1++];
				else
					temp[i] = data[p2++];
			}
		}
		for(j = 0, k = begin; j < size; j++, k++) //O(N)
			data[k] = temp[j];
	}
	free(temp);
}
