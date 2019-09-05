//exercicio 1,lista prova
//funcao que receba ponteiros como argumentos
//determine se duas strings de entrada sao anagramas
//so usar caracteres da tabelas ASCII
//retornar 1 se for, zero se nao for 
/*
1:antes do main declarar funcao com endereco de memoria das palavras
 que recebe duas strings
2:dentro do int main, receber as duas strings direto no terminarl
6:retornar zero se os tamanhos forem diferentes
3:contar a quantidade de palavras da primeira
4:comparar item por item com a segunda e ver se os itens sao iguais
5:dar um break retornando zero , caso no meio ja nao tenha uma letra 
na segunda palavra
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void anagramas(char *p1,char *p2){
	int contador=0;
	int i = 0, j = 0;
	int zeros=0;

	while (p2[i]!= '\0'){
		contador ++;
		i ++;
}
i=0;
//--------ZERANDO CADA CARECTERE IGUAL DA PRIMEIRA COM A SEGUNDA STRING
	while(p1[i] != '\0'){
		while(p2[j] != '\0'){
			if (p1[i] == p2[j]){
				p2[j] = '0';
				break;
	}
	j++;

	}

	j=0;
	i++;

}		
j=0;
while(p2[j]!= '\0'){
	if(p2[j]=='0')
		zeros++;
	j++;
}

if (zeros == contador)
	printf("1\n");
else 
	printf("0\n");


}



int main(int argc,char *argv[]){
	char *p1 , *p2;
	p1 = argv[1];
	p2 = argv[2];

anagramas(p1,p2);

}
