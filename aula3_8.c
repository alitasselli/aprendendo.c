#include <stdio.h>
#include <stdlib.h>
//segundo maior numero de um array

int *aloc_coloc(char **array,int n){
	int tamanho=n;

	int *numeros=malloc(sizeof(int)*tamanho);

	for(int i=0;i<tamanho;i++){
		numeros[i]=atoi(array[i+1]);
	}
	return numeros;
}

int segundo(int*array,int n){

	int maior=0;
	int segmaior=0;

	for(int i=0;i<n;i++){
		if(array[i]>maior){
			maior=array[i];
		}
	}

	for(int i=0;i<n;i++){
		if(array[i]!= maior){
			segmaior=array[i];
		}
	}
	return segmaior;
}

int main(int argc,char*argv[]){

	int tamanho=argc-1;
	int *numeros=aloc_coloc(argv,tamanho);

	int segmaior=segundo(numeros,tamanho);

	printf("%d\n",segmaior);
}


