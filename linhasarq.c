//questao 18
// escreva um programa para determinar o numero de linhas de um arquivo
#include <stdio.h>
#include <stdlib.h>
int main(){
FILE *arquivo;
arquivo= fopen("usuarios.txt", "r");
char c;
int linhas=0;
while(fread (&c, sizeof(char), 1, arquivo)){
    printf("%c\n", c);
    if(c == '\n')
        linhas++;
}
printf("%d\n", linhas);
}
