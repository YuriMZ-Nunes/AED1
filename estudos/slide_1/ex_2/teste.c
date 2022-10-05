#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	void *pBuffer = malloc(sizeof(char));
	char str[5];

    printf("Digite um nome:");
	scanf("%s", str);
    
    pBuffer = realloc(pBuffer, 10);
				
	strcat(pBuffer, str);

	printf("%s\n", (char *)pBuffer);

    printf("Digite um nome:");
	scanf("%s", str);
    
    pBuffer = realloc(pBuffer, 10);
				
	strcat(pBuffer, str);

	printf("%s\n", (char *)pBuffer);
}