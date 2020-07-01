#include <stdio.h> 
#include <stdlib.h>

//ESSE ARQUIVO TA OK

/*Mova todas as funções, com exceção da main, para um outro arquivo c (a
ser nomeado por aux_login.c)*/

#define SUMLINES lines[i] + matrix[i][j] 
#define SUMCOLUMNS columns[j] + matrix[i][j] 
#define COMPARISON columns[j] > lines[i] 
#define WIN win + 1 
#define COUNT count + 1 
#define PREV prev + 1
#define TOTAL total + 1

int quantLines (FILE *fp)
{
	int count = 0; //propia contagem de linhas
	int prev = 0;  //numero de itens na primeira linha
	int total = 0; //numero total de itens na matrix
	char c;

	for (c = getc(fp); c != EOF; c = getc(fp))
	{
		if (c == '\n') {
			count = COUNT;

		} if (c != ' ' && c != '\n' && count == 0){
			prev = PREV;

		}if (c != ' ' && c != '\n'){
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
	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < count; j++)
		{
			lines[i] = SUMLINES;
		}
	}
	return lines;
}

int *returnColumns (int count, int *columns, int **matrix)
{
	for(int i = 0; i < count; i++)
	{
		for(int j = 0; j < count; j++)
		{
			columns[j] = SUMCOLUMNS;
		}
	}
	return columns;
}

int winners (int win, int count, int *lines, int *columns){

	for(int j = 0; j < count; j++)
	{
		for(int i = 0; i < count; i++)
		{
			if (COMPARISON)
			win = WIN;
		}
	}
	return win;
}