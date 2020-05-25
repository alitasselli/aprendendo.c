#include <stdlib.h>
#include <stdio.h>

int transformar_linhas(char num){ //transformar de char para int
	
	int numero = (num - '0') - 1;

	return numero;
}

int transformar_colunas(char letra){ //transformar de letra para int

		if(letra == 'a'){
			return 0;
		}
	
		if(letra == 'b'){
			return 1;
		}
	
		if(letra == 'c'){
			return 2;
		}

		if(letra == 'd'){
			return 3;
		}
	
		if(letra == 'e'){
			return 4;
		}
	
		if(letra == 'f'){
			 return 5;
		}
	
		if(letra == 'g'){
			 return 6;
		}
	
		if(letra == 'h'){
			return 7;
		}
		
		return -1;
}


int main(int argc, char* argv[]){

	int tamanho = argc - 1;

	int contador = 0;
	
	int **tabuleiro = calloc(8,sizeof(int*)); //criar tabuleiro zerado
			for(int i = 0; i < 8; i++)
			tabuleiro[i] = calloc(8, sizeof(int));


	for(int i = 1; i < 9; i++){//colocar no tabuleiro as posicoes ocupadas
					
		int linha = transformar_linhas(argv[i][0]);

		int coluna = transformar_colunas(argv[i][1]);

		tabuleiro[linha][coluna] = 1;
			
	}

	/*for(int i= 0; i<8 ; i++){ //printar tabuleiro
		for(int j= 0; j<8 ; j++){
			printf("%d ",tabuleiro[i][j] );

		}
		printf("\n");
	}*/

	int contador_linha = 0;
	int contador_coluna = 0;
	int contador_diagonal = 0;

	int encontros_linha = 0;
	int encontros_diagonal = 0;
	int encontros_coluna = 0;

	for( int i = 0 ; i < 8 ; i++){ //linhas
		for(int j = 0; j < 8 ;j++)
			if( tabuleiro[i][j] !=  0){
				contador_linha++;
				if(contador_linha >= 2){
					encontros_linha++;
				}

			}
		contador_linha = 0;		
		
	}
		
	for( int i = 0 ; i < 8 ; i++){ //colunas
		for(int j = 0; j < 8 ; j++)
			if(tabuleiro[j][i] !=  0){
				contador_coluna++;
				if(contador_coluna >= 2){
					encontros_coluna++;
				}

			}
		contador_coluna = 0;		
		
	}

	int linha = 0;
	int coluna = 0;

	for(int i = 0; i < 8; i++){//Diagonal normal pt de cima
		linha = 0;
		coluna = i;
		contador_diagonal = 0;

		for(int j=0; j<8-i; j++){
			if( tabuleiro[linha++][coluna++] !=  0){
				contador_diagonal++;
				if(contador_diagonal >= 2){
					encontros_diagonal++;
				}
			}
		}
	}

	
	for(int i = 1; i<8; i++){//diagonal normal pt de baixo
		linha = i;
		coluna = 0;
		contador_diagonal = 0;

		for(int j=0; j<8-i; j++){
			if( tabuleiro[linha++][coluna++] !=  0){
				contador_diagonal++;
				if(contador_diagonal >= 2){
					encontros_diagonal++;
				}
			}
		}
	}

	for(int i = 8-1; i >= 0; i--){ //diagonal invertida
		linha = 0;
		coluna = i;
		contador_diagonal = 0;

		for(int j = i+1; j>0; j--){
				if( tabuleiro[linha++][coluna--] !=  0){
					contador_diagonal++;
					if(contador_diagonal >= 2){
						encontros_diagonal++;
					}
				}
			}
		}


	for(int i = 8-1; i >= 0; i--){ //diagonal invertida
			linha = 8 - i;
			coluna = 8 - 1;
			contador_diagonal = 0;

			for(int j = i; j>0; j--){
				if( tabuleiro[linha++][coluna--] !=  0){
					contador_diagonal++;
					if(contador_diagonal >= 2){
						encontros_diagonal++;
					}
				}
			
			}
		}

	printf("%d \n",encontros_linha+encontros_coluna+encontros_diagonal );
}
