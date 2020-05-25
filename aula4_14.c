/*14. Escreva uma função que calcule a média de números inteiros
 positivos, similar a apresentada em sala de aula, mas que não passe o número total de 
 números como parâmetro.*/

#include <stdio.h>
#include <stdlib.h>

int *alocar_colocar(char **array,int n){
	int tam=n;

	int*numeros=malloc(sizeof(int)*tam);

	for(int i=0;i<tam;i++){
		numeros[i]=atoi(array[i+1]);
		//printf("NUMEROS %d\n",numeros[i] );
	}
	return numeros;
}

int media_int(int *array,int n){
	int tam=n;
	int soma=0;

	for(int i=0;i<tam;i++){
		soma+=array[i];
		//printf("SOMA %d\n",soma );
	}
	int media=soma/tam;
	

	return media;
}

int main(int argc,char*argv[]){

	int tam=argc-1;

	//printf("TAM %d\n",tam );

	int *numeros=alocar_colocar(argv,tam);

	int media=media_int(numeros,tam);

	printf("%d\n",media);
	
	











}
