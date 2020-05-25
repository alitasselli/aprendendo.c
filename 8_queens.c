/*Crie um programa em C que dada a posição de uma rainha num tabuleiro de xadrez 
(por linha de comando), imprima a posição de outras 7 rainhas nesse mesmo tabuleiro, 
de forma que nenhuma seja atacada por outra.
Exemplo 1: Considere que a entrada seja referente a rainha posicionada na linha 7,
coluna g (quadrado em vermelho da figura abaixo).
Uma possível solução é apresentada na mesma figura.

matriz 8x8


eles nao podem se encontrar na diagonal
eles nao podem se encontrar na vertical
eles nao podem se encontrar na horizontal
1 rainha= 8 opcoes de coluna
2 rainha= 7 opcoes de coluna ...

 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char*argv[]){

	//DEFININDO LINHAS E COLUNAS
	int linha=atoi(&argv[1][0]);
	
	int coluna=argv[1][1];

	if(argv[1][1]=='a'){
		coluna=0;
	}
	else if(argv[1][1]=='b'){
		coluna=1;
	}
	else if(argv[1][1]=='c'){
		coluna=2;
	}
	else if(argv[1][1]=='d'){
		coluna=3;
	}
	else if(argv[1][1]=='e'){
		coluna=4;
	}
	else if(argv[1][1]=='f'){
		coluna=5;
	}
	else if(argv[1][1]=='g'){
		coluna=6;
	}
	else
		coluna=7;
	

	//CRIAR MATRIZ 8X8 JA ZERADA
	int **tabuleiro;
	*tabuleiro = calloc(8, sizeof(int*));
	for(int i=0; i<8; i++)
		tabuleiro[i] = calloc(8, sizeof(int));

	tabuleiro[linha][coluna]=2; //DEF RAINHA UM


	for(int i=0;i<8;i++){  //linhas
		if(tabuleiro[linha][i] == 0)
		tabuleiro[linha][i]=1;
	}

	for(int i=0;i<8;i++){//colunas
		if(tabuleiro[i][coluna] == 0)
		tabuleiro[i][coluna]=1;

	}

	for(int i=linha; i<8 && tabuleiro[i][i] != 0; i++){
		if(tabuleiro[i][i] == 0) //diagonal
		tabuleiro[i][i] = 1;
	}

	for(int i=linha; i>=0 && tabuleiro[i][i] != 0; i--){
		if(tabuleiro[i][i] == 0) //diagonal
		tabuleiro[i][i] = 1;
	}


	//POSICIONAR AS OUTRAS RAINHAS
	int temRainha=0;

	for(int i=0; i<8; i++){
		for(int j=0;j<8;j++){
			for(int k=0; k<8; k++){
				if (tabuleiro[k][j] == 2){
					temRainha = 1;
				}
			}
			if(temRainha != 1 && tabuleiro[j][i] == 0){
				tabuleiro[j][i] = 2;

				for(int i=0;i<8;i++){  //linhas
					if(tabuleiro[linha][i] == 0)
						tabuleiro[linha][i]=1;
				}
				for(int i=0;i<8;i++){//colunas
					if(tabuleiro[i][coluna] == 0)
					tabuleiro[i][coluna]=1;

				}

				for(int i=linha; i<8 && tabuleiro[i][i] != 0; i++){
					if(tabuleiro[i][i] == 0) //diagonal
					tabuleiro[i][i] = 1;
				}

				for(int i=linha; i>=0 && tabuleiro[i][i] != 0; i--){
					if(tabuleiro[i][i] == 0) //diagonal
					tabuleiro[i][i] = 1;
				}

			}
		}
		
		temRainha=0;

	}




}

		

