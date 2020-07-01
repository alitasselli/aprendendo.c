#include <stdio.h> 
#include <stdlib.h>

/*
* Modifique o programa para que imprima, em forma de par, as posições vencedoras.
* Nomeie o arquivo com essas modificações por q3e_login.c. 
* Para o arquivo acima, tem-se:
* > ./q3e matrix.txt
*	(1,0) (1,1) (1,2) (2,0) (2,1) (2,2)
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
	
	//printf("%d \n", win);
	
	//free(columns);
	//free(lines);
	free(matrix);

	return 0;
}

int quantLines (FILE *fp)
{
	int count = 0; //propia contagem de linhas
	int prev = 0;  //numero de itens na primeira linha
	int total = 0; //numero total de itens na matrix
	char c;

	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == '\n') {
			count = COUNT;

		} if (c != ' ' && c != '\n' && count == 0){
			prev = PREV;

		} if (c != ' ' && c != '\n'){
			total = TOTAL;
		}
	}

	count = COUNT; //adicionar +1 ao numero de linhas para ser exato

	if (total % prev != count && total / prev != count) {
		printf("Error at matrix format\n");
		return 0;
	}

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
			if (COMPARISON){	
				win = WIN;
				printf("(%d,%d) ",i, j);
			}	
		}
	}
	
	printf("\n");
	return win;
}