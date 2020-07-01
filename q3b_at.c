#include <stdio.h> 
#include <stdlib.h>

/*
* Substitua os laços for por funções e quaisquer soma, incremento e
* comparação por MACROS.
*/

//MACROS
#define SUMLINES lines[i] + matrix[i][j] 
#define SUMCOLUMNS columns[j] + matrix[i][j] 
#define COMPARISON columns[j] > lines[i] 
#define WIN win + 1 
#define COUNT count + 1 

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

	//ALOCACAO DA MATRIX
	int **matrix = malloc(count * sizeof(int*));
	for(i = 0; i < count; i++) {
		matrix[i] = malloc(count * sizeof(int));   
	}

	//COLOCAR OS NUMEROS DA MATRIX EM INT 
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

//FUNCOES!

int quantLines (FILE *fp)
{
	int count = 0; //propia contagem de linhas
	int prev = 0; //numero de linhas anterior
	char c;

	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == '\n') {
			count = count + 1;
			prev = 0;
		} else {
			prev = 0;
		}

		if (prev) {
			count++;
		}
	}
	
	count ++;
	return count;
}

int *returnLines (int count, int *lines, int **matrix)
{
	for(int i = 0; i < count; i++) {
		for(int j = 0; j < count; j++) {
			lines[i] = SUMLINES;
		}
	}
	return lines;
}

int *returnColumns (int count, int *columns, int **matrix)
{
	for(int i = 0; i < count; i++) {
		for(int j = 0; j < count; j++) {
			columns[j] = SUMCOLUMNS;
		}
	}
	return columns;
}

int winners (int win, int count, int *lines, int *columns){

	for(int j = 0; j < count; j++) {
		for(int i = 0; i < count; i++) {
			if (COMPARISON)
			win = WIN;
		}
	}
	return win;
}