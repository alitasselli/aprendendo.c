/*
ao passar um numero fazer uma funcao para retornar os n 
primeiros numeros pares para a main e imprimir eles

retornar um array de inteiros= ponteiro do tipo int 
que vai apontar p um espaco da memoria

recebe o inteiro n
vai alocar um espaco p essa quantidade de numeros (n)
dentro dos n espacos vai ser 0 2 4 6 8 
retornar o endereco dos espaco que ja ta alocado com os 
numeros dentros e imprimi os numeros dentro da main
*/

#include <stdio.h>
#include <stdlib.h>

int *numEven(int n){

	int *array=malloc(sizeof(int)*n);

	for(int i=0;i<n;i++){
		
			array[i]=i*2;
	}

return array;

}


int main(int argc,char *argv[]){


	int quant= atoi(argv[1]);

	int *numbers=numEven(quant);

	for(int i=0;i<quant;i++){
		printf("%d\n",numbers[i]);
	}


}

