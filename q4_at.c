#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/*
* 4. Por exemplo: os divisores de 84 são {1, 2, 3, 4, 6, 7, 12, 14, 21, 28, 42, 84} 
* e apenas 4 podem ser decompostos em dois os mais primos distintos e sem repetição, 
* são eles: 6 = 2 x 3, 14 = 2 x 7, 21 = 3 x 7 e 42 = 2 x 3 x 7
* > ./q4 84
* 4
*/

//DECLARACAO DAS FUNCOES
int *returnDivisores(int num, int *divisores);
int returnPrimo(int x);

int main (int argc, char **argv){

	int num = atoi(argv[1]);

	int *divisores = calloc(num, sizeof(int));
	
	divisores = returnDivisores(num, divisores);
	
	//quantidade de divisores
	int cont1 = 0; 
	for (int i = 0; i < num; i++) {
		if (divisores[i] != 0) {
			cont1++;
		}
	}

	int *decompostos = calloc(num,sizeof(int));
	int cont2 = 0; //quantidades de numeros dentro do array decompositores
	int iguais = 0; //quantidade de numeros iguais no array de decompositores
	int resultado = 0; //Resultado final

	int auxiliar = 0; //numero do array divisores
	int primo = 0; //Se e primo ou nao 
	int x = 0; //numero de 0 ate o auxiliar para achar os decompositores
 
	for (int i = 0; i < cont1; i++) {	
		auxiliar = divisores[i];

		for (x = 0; x < auxiliar; x++) {
			primo = returnPrimo(x);
			if (primo == 1) {
				if (auxiliar % x == 0) {
					decompostos[cont2] = x;
					cont2++;
				}
			}
		}

		int aux = 1;
		if(cont2 >= 2){ //verificacao o numero so e decomposto por primos 
			for(int i = 0; i < cont2; i++) {
				aux *= decompostos[i];
			}
			if (aux == auxiliar) {
				resultado++; //RESULTADO FINAL
			}
		}
	
		iguais = 0;
		cont2 = 0;
		memset(decompostos, 0, sizeof(int));
		}

		printf("%d\n",resultado);
}


int *returnDivisores(int num, int *divisores)
{

	int cont = 0; //quantidade de divisores

	for (int i = 1; i <= num; i++) {
		if (num % i == 0 ) {
			divisores[cont] = i;
			cont++;
		}
	}
	return divisores;
}

int returnPrimo(int x)
{

	int resultado = 0;
	int cont = 0;

	for (int i = 1; i <= x; i++) {
    	if (x % i == 0) { 
     		cont++;
    	}
 	 }
    
  	if (cont == 2){
  		resultado = 1;
  		return resultado;

  	} else {
 		resultado = 0;
 		return resultado;
 	}	
}
