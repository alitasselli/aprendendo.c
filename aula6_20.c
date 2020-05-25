/*
recebendo um array de inteiros ordenados do menor 
para o maior elemento, sendo possível ter elementos repetidos. 
> ./a.out 1 2 2 3 3 3
0
> ./a.out 1 2 2 2 2 3 3
1
*/

#include <stdio.h>
#include <stdlib.h>

int *aloc_coloc(char **array,int n){

	int tamanho = n;
	int *numeros = malloc(sizeof(int)*tamanho);

	for(int i = 0;i < tamanho;i++){
		numeros[i] = atoi(array[i+1]);
	}
	return numeros;
}

int determinar(int *array,int tamanho){
	
	int comparacao = tamanho/2;
	
	int iguais = 0;
	int *numeros = array;
	
	for(int i = 0;i < tamanho;i++){
		for(int j = i;j < tamanho;j++){
			
			if(numeros[i] == numeros[j]){
				iguais++;
			}

			if(iguais > comparacao){
				
				return 1;
			}
		}

		iguais = 0; }

	return 0;
}

int main(int argc,char *argv[]){
	
	int tamanho = argc-1;
	
	int *numeros = aloc_coloc(argv,tamanho);
	int resposta = determinar(numeros,tamanho);
	
	printf("%d\n",resposta);
}