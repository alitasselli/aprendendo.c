#include <stdlib.h>
#include <stdio.h>
//receber uma matriz 3x3 e retornar os elem da diagonal principal
// a 11 , a 22 , a 33

int main(int argc, char*argv[]){

	FILE*file=fopen(argv[1],"r"); //ABRIR ARQUIVO

	int i,linhas=1,colunas=0,linha_ok;

	while(!feof(file)){ //DESCOBRIR QUANTIDADE DE LINHAS E COLUNAS
		char c=fgetc(file);
	
		if(c !=' ' && c!= '\n' && linha_ok!=1){
			colunas++;
		}
		if(c == '\n'){
			linhas++;
			linha_ok=1;
		}
	}
	
	rewind(file); //AJEITAR O PONTEIRO P COMECO DNV

	int **array=malloc(sizeof(int*)*linhas);//ALOCAR ESPACO

  	for(int i = 0; i < colunas; i++){
    	array[i] = malloc(colunas*sizeof(int));
  	}


	for(int i=0;i<linhas;i++){ //COLOCAR OS NUMEROS JA NA MATRIZ 
		for(int j=0;j<colunas;j++){
			fscanf(file,"%d",&array[i][j]); 
		}
	}

	for(int i=0;i<linhas;i++){ //IMPRIMIR DIAGONAL
		for(int j=0;j<1;j++){
			printf("%d ",array[i][i]);
		}
	}






}