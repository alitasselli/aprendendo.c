#include <stdio.h> 
#include <stdlib.h>

/* 
* Indente de acordo com o padrão de codificação do kernel do Linux e 
* faça as correções necessária a fim de que o programa funcione como esperado e 
* não apresente vazamento de memória. 
*/

int quantLines (FILE *fp)
{
	int count = 0; //propia contagem de linhas
	int prev = 0; //numero de linhas anterior
	char c;

	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == '\n') {
			count = count + 1;
			prev = 0;
		}
	}
	
	count ++;
	return count;
}
 
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

	int *lines = calloc(count, sizeof(int));
	for(i = 0; i < count; i++) {
		for(j = 0; j < count; j++) {
			lines[i] = lines[i] + matrix[i][j];
		}
	}

	int *columns = calloc(count, sizeof(int));
	for(j = 0; j <= count; j++) {
		for(i = 0; i < count; i++) {
			columns[j] = columns[j] + matrix[i][j];
		}
	}

	int win = 0;
	for(j = 0; j < count; j++) {
		for(i = 0; i < count; i++) {
			if (columns[j] > lines[i])
			win++;
		}
	}

	printf("%d \n", win);
	
	//free(columns);
	//free(lines);
	free(matrix);

	return 0;
}
