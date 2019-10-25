/*
1 - Cria uma estrutura de lista
2 - Cria uma funcao que implementa a lista atraves de um array
3 - Roda 


*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elementos{
	int numero;
	struct elementos* proximo;

}elemento;


int main(){
	elemento *navegador;
	elemento *aux;
	elemento *anterior;
	elemento *imprime;


	int arr[] = {4,3,2,10,12,1,5,6};
	int tamanho = sizeof(arr) / sizeof(arr[0]);
	int i, contador = 0;;
	int modificou = 0;

	elemento *cabeca = NULL;
	cabeca = malloc(sizeof(elemento));
	cabeca->numero= arr[0];
	cabeca->proximo = NULL;

	//CRIANDO UMA LISTA LINKADA COM OS ELEMENTOS DO ARRAY
	aux = cabeca;
	navegador = cabeca->proximo;
	for(i=1; i<tamanho; i++){
		navegador = malloc(sizeof(elemento));
		navegador->proximo = NULL;
		navegador->numero = arr[i];
		aux->proximo = navegador;

		aux = navegador;
		navegador = navegador->proximo;

	}
	//IMPRIMINDO LISTA LINKADA
	navegador = cabeca;
	for(i=0; i<tamanho; i++){
		printf("%d  ", navegador->numero);
		navegador = navegador->proximo;
	}


	//COMECANDO O INSERTION SORT

	//SEMPRE TEREMOS UM PONTEIRO APONTANDO PARA O ANTERIOR DO INDICE A SER ALTERADO
	//SEMPRE Q UM NUMERO MENOR QUE O ANTERIOR->PROXIMO FOR ENCONTRADO ELE EH 
	//JOGADO PARA A POSICAO DO ANTERIOR->PROXIMO
	//CASO A LISTA SEJA VARRIDA SEM ALTERACAO O ANTERIOR APONTARA PARA O ANTERIOR->PROXIMO


	anterior = malloc(sizeof(elemento));
	anterior->proximo = cabeca;
	navegador = cabeca;
	do{
		if(navegador->proximo->numero < anterior->proximo->numero){//ESTE IF ESTA JOGANDO O NUMERO MENOR PARA FRENTE DO NUMERO A SER MODIFICADO
			aux = navegador->proximo;//PONTEIRO AUXILIAR GUARDA INFORMACOES DO ELEMENTO A SER RETIRADO DA LISTA
			navegador->proximo = navegador->proximo->proximo;//ELEMENTO EH RETIRADO DA LISTA
			aux->proximo = anterior->proximo;//ELEMENTO AGORA APONTA PARA O ANTIGO NUMERO QUE ESTAVA NO "COMECO" DA LISTA
			if (anterior->proximo == cabeca)
				cabeca = aux;//-CASO A CABECA DA LISTA SEJA ALTERADA TEMOS QUE MUDAR O PONTEIRO
			anterior->proximo = aux;
			modificou++;



//-------------IMPRIMINDO LISTA MODIFICADA---------------
			printf("\n");
			imprime = cabeca;
			for(i=0; i<tamanho; i++){
				printf("%d  ", imprime->numero);
				imprime = imprime->proximo;
			}
//-----------FIM IMPRIMINDO LISTA MODIFICADA-----------------


		}

		if (modificou == 0){
			navegador = navegador->proximo;//CASO NAO OCORRA MODIFICACAO O NAVEGADOR APONTA PARA O PROXIMO ELEMENTO DA LISTA

		}
		modificou = 0;

		if (navegador->proximo == NULL){//CASO NAVEGADOR CHEGUE NO FINAL DA LISTA
			anterior = anterior->proximo;//PONTEIRO QUE APONTA PARA O ANTERIOR DO ELEMENTO A SER MODIFICADO AGORA VAI PARA O PROXIMO
			navegador = anterior->proximo;//NAVEGADOR VOLTA PARA O NOVO INICIO DA LISTA
			contador++;//CONTADOR AUMENTA ATE CHEGAR NO TAMANHO DA LISTA (QUANDO O CONTADOR CHEGA NO TAMANHO DA LISTA SIGNIFICA QUE O PONTEIRO "ANTERIOR" CHEGOU NO FINAL DA LISTA)

		}


	}while(contador < tamanho-1);



	printf("\n\n\n");

	imprime = cabeca;
	for(i=0; i<tamanho; i++){
		printf("%d  ", imprime->numero);
		imprime = imprime->proximo;
	}




	printf("\n\n\n");





	return 0;
}