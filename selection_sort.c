/*
Selection sort

1 - cria o array
2 - pega o menor numero do array e joga para o primeiro indice
3 - varre o array novamente a partir do segundo indice

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

	clock_t tempo[2];
	tempo[0] = clock(); 

	int arr[] = {2,4,10,55,9,201,33444};
	int tamanho = sizeof(arr) / sizeof(arr[0]);
	int menor = 999999, indice_menor;

	int inicio, i, aux;

	for (inicio=0; inicio<tamanho; inicio++){
		
		for(i=inicio;i<tamanho;i++){//FAZENDO i=inicio, VARREMOS OS SUB-ARRAYS DEPOIS DE ENCONTRARMOS OS MENORES NUMEROS
			if(arr[i] < menor){//-----DESSE JEITO SALVAMOS SEMPRE O MENOR NUMERO DO ARRAY
				menor = arr[i];//DEPOIS DE RODARMOS TODO O ARRAY O MENOR NUMERO SERA SALVO NESSA VARIAVEL
				indice_menor = i;//O INDICE QUE ESTE NUMERO SE ENCONTRA EH SALVO AQUI
			}
		}

		//---DEPOIS DO MENOR NUMERO SER ENCONTRADO ESTAS PROXIMAS LINHAS FAZEM A TROCA
			aux = arr[inicio];//aux SALVA O NUMERO QUE ESTA NO COMECO DO SUB-ARRAY
			arr[inicio] = menor;//COMECO DO SUB-ARRAY VIRA MENOR NUMERO
			arr[indice_menor] = aux;//POSICAO QUE ERA MENOR NUMERO AGORA EH O NUMERO QUE ESTAVA NO COMECO DO SUB-ARRAY
			menor = 999999;//--------REINICIA-SE MENOR NUMERO				

	}

//-------PRINTANDO ARRAY TODO APOS TODAS AS MUDANCAS
	printf("\n\n");
	for(i=0; i<tamanho; i++){
		printf("%d  ", arr[i]);
	}
//--------------------------------------------
	tempo[1] = clock();
	printf("\n\n\n");
	double diferenca = (tempo[1] - tempo[0]) * 1000.0 / CLOCKS_PER_SEC;


	printf("%g\n", diferenca);


	return 0;
}