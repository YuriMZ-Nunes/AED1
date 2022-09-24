if((void **)pFirst == NULL){ //verifica se é o primeiro cadastro
		*(void **)pFirst = infos; //atualiza o ponteiro para o primeiro
		*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2))) = 0;
		*(int *)(infos + ((sizeof(char) * 10) + (sizeof(int) * 2) + sizeof(int))) = 0;
		
	}