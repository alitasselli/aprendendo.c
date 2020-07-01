#include <stdio.h> 
#include <stdlib.h>
#include "q3_at.h"

/*
* Mova todas as funções, com exceção da main, 
* nomeie o arquivo que contêm a main por q3c_login.c,
* aqui tem a modificacao da funcao quantLines feita no arquivo q3d
*/

//MACROS
#define SUMLINES lines[i] + matrix[i][j] 
#define SUMCOLUMNS columns[j] + matrix[i][j] 
#define COMPARISON columns[j] > lines[i] 
#define WIN win + 1 
#define COUNT count + 1 
#define PREV prev + 1
#define TOTAL total + 1

//DECLARACAO DAS FUNCOES
int quantLines (FILE *fp);
int *returnLines (int count, int *lines, int **matrix);
int *returnColumns (int count, int *columns, int **matrix);
int winners (int win, int count, int *lines, int *columns);

int main(int argc, char **argv){

	int count, i, j;

	FILE *fp;
	fp = fopen(argv[1], "r");
	count = quantLines(fp);
	
	fseek(fp, 0, SEEK_SET);

	//alocacao da matrix
	int **matrix = malloc(count * sizeof(int*));
	
	for(i = 0; i < count; i++) {
		matrix[i] = malloc(count * sizeof(int));   
	}

	//colocar os numeros da matrix dentro dela em int 
	for(i = 0; i < count; i++) {
		for(j = 0; j < count; j++) {
			if (!fscanf(fp, "%d", &matrix[i][j]))
			break;
		}
	}

	fclose(fp);	

	//CHAMAR A FUNCAO DAS COLUNAS
	int *lines = calloc(count, sizeof(int));
	lines = returnLines(count, lines, matrix);

	//CHAMAR A FUNCAO DAS COLUNAS
	int *columns = calloc(count, sizeof(int));
	columns = returnColumns(count, columns, matrix);

	//CHAMAR A FUNCAO DAS POSICOES VENCEDORAS
	int win = 0;
	win = winners (win, count, lines, columns);
	
	printf("%d \n", win);
	
	//free(columns);
	//free(lines);
	free(matrix);

	return 0;
}