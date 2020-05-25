#include <stdio.h>
#include <stdlib.h>

/*
transdormar os numeros de string p int usando atoi
pegar o tamanho = argc -1;
comparacao = tamanho/2;

fazer um for para comparar os numeros com  o resto e se for igual
add ao contador
se o contador for maior que comparacao 
printar o numero comparado

*/
int main(int argc, char*argv[]){

	int tamanho= argc-1;
	int contador=0;
	int comparacao = tamanho/2;
	int num_maior = 0;
	
	//printf("c= %d\n",comparacao );
	//printf("t= %d\n",tamanho );

	int *numeros=malloc(sizeof(int)*tamanho);

	for(int i=0;i<tamanho;i++){
		numeros[i]=atoi(argv[i+1]);
	}

	for(int j=0;j<tamanho;j++){
		for(int k=j;k<tamanho;k++){
			//printf("NUMERO J %d\n",numeros[j] );
			//printf("CONTADOR COMECO %d\n",contador );
			if(numeros[j]==numeros[k]){
				contador++;	
				//printf("contador %d\n",contador );
			}
		}
			if(contador >= comparacao){
					num_maior= numeros[j];
			}
			contador=0;

	}

	printf("%d\n",num_maior );	
}