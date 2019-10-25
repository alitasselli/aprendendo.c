//BUBBLE SORT
/*
entrada[0]

1 - pegar tamanho da lista
2 - rodar lista vendo se primeiro eh maior que segundo
3 - se for maior trocar valores

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(void){
	int entrada[] = {2,4,10,6,8,1,3,5,0,7,-1};
	int i, aux, contador = 0;
	int tamanho = (sizeof(entrada)/sizeof(entrada[0]));

	clock_t tempo[2];
	tempo[0] = clock(); 


	for(i=0; i<tamanho-1; i++){
		if (entrada[i] > entrada[i+1]){
			aux = entrada[i];
			entrada[i] = entrada[i+1];
			entrada[i+1] = aux;
			contador++;
		}
		if (i == tamanho-2 && contador != 0){
			i = -1;
			contador = 0;
		}


	}

	for(i=0; i<tamanho; i++){
		printf("%d  ", entrada[i]);

	}

	tempo[1] = clock();
	printf("\n\n\n");
	double diferenca = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;


	printf("%g\n", diferenca);
	return 0;

}
