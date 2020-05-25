//numeros = {5,12,3,-9,52,-38,-5,3,0,5};

/*dois lacos for

-receber uma sequencia de 10 inteiros e dar a subsequencia 
com a maior soma
se tiver duas iguais retornar com a maior media */
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char*argv[]){

	int tamanho=argc-1;
	int *numeros=malloc(sizeof(int)*tamanho); //alocar espaco

	for(int k=0;k<tamanho;k++){ //converter em int
		numeros[k]=atoi(argv[k+1]);
	}
	int maior = numeros[0];
	//printf("%d\n",maior );




}
