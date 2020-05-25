/*24. Escreva um programa em C que chama uma 
função capaz de receber um inteiro positvo
 e construir a sequencia de fibonacci associada.
Imprima a sequencia construída através de 
comandos printf dentro da main e 
não dentro da função que calcula o fibonacci.*/

#include <stdio.h>
#include <stdlib.h>

int *fibonacci(int n){

	int f1=1,f2=1,f=0;
	int *array = malloc(sizeof(int)*n);
	
	for(int i=0;i<n;i++){
		f=f1+f2;
		array[i]=f;
		f1=f2;
		f2=f;
	}
	
	return array;
}

int main(int argc, char* argv[]){

	int numero=atoi(argv[1]);

	int *sequencia=fibonacci(numero);

	for(int i=0;i<numero;i++){
		printf("%d\n",sequencia[i]);

	}
}


