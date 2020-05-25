#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
passos:
abrir arquivo
contar a quantidade de numeros ate o primeiro /n
contar a quantidade de /n
alocar espaco para uma matriz
transformar as strings da matriz em numeros

multiplicacao
usando for alinhado

-multiplicacao de matrizes (3 lacos for), argc argv
receber dois arquivos e cada arquivo tem uma matriz
vai determinar a quantidade de linha ver se pode 
fazer a multiplicacao ou nao

*/
int *numero_cl(FILE *fp){
	
	int colunas=0,linhas=1;
	int linha_ok=0;

	//contando o numero de colunas e linhas
	while(!feof(fp)){
		char c=fgetc(fp);
		if(c != '\n' && c != ' ' && c!= '-' && linha_ok != 1){
			colunas++; }

		if(c == '\n'){
			linhas++;
			linha_ok=1; }
	}

	int *numeros=malloc(sizeof(int)*2);
	numeros[0]=colunas;
	numeros[1]=linhas;

	return numeros;
}

int main(int argc , char*argv[]){

	FILE *file1=fopen(argv[1],"r"); 
	FILE *file2=fopen(argv[2],"r");

	int *num1=numero_cl(file1);
	int *num2=numero_cl(file2);

	for(int i=0;i<2;i++){
		printf("numeros = %d\n", num1[i]);
	}


	







}