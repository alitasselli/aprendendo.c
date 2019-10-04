//questao 19
//converter todas as maiusculas em minusculas 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//pode usar duas funcoes : toupper( ) - int toupper (int ch); OU strupr(string)

int main(){
FILE *arquivo;
char c ;
arquivo= fopen("estpython.txt", "r+"); 

while(c != EOF){
	printf("%c\n", c);
	c = fgetc(arquivo);


	if (islower(c)){
		c = toupper(c);
		fseek(arquivo, -1, SEEK_CUR);
		fputc(c, arquivo);
		//fseek(arquivo, 0, SEEK_CUR);
	}

}

}