#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){

	int tamanho = argc-1;

	char operacao = argv[2][0];
	//printf("%c\n",operacao );
	
	int *numeros=malloc(sizeof(int)*tamanho); //alocar espaco

	for(int j=0;j<tamanho;j++){ //converter em int
		numeros[j] = atoi(argv[j+1]);
	}
	//fazer calculadora
	//printf("digite a operacao que deseja fazer: 1(+) 2(-) 3(x) 4(/) 5(//) \n");
	//scanf("%d",&operacao);

	if(operacao == '+'){
		int soma = numeros[0]+numeros[2];
		printf("sum %d\n",soma);
    }
	
	else if(operacao == '-'){
		int subtracao = numeros[0]-numeros[2];
		printf("sub %d\n",subtracao);

	}

	else if(operacao == '*'){
		int multiplicacao = numeros[0]*numeros[2];
		printf("mult %d\n",multiplicacao);
	}

	else if(operacao == '/' ){
		int divisao = numeros[0]/numeros[2];
		printf("div %d\n",divisao);
	}

	else {
		int divisaoresto = numeros[0] % numeros[2];
		printf("div rest %d\n",divisaoresto);
	}

}