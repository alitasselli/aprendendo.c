/*exercicio 1,lista prova
funcao que receba ponteiros como argumentos
determine se duas strings de entrada sao anagramas
so usar caracteres da tabelas ASCII
retornar 1 se for, zero se nao for*/
/* PASSO A PASSO+-
1:antes do main declarar funcao
2:vai receber no main direto no terminar as palavras,
isso e para nao precisar alocar memoria
3:contar a quantidade de palavras
4:comparar item por item com e ver se os itens sao iguais
e ir transformando as letras em zero criando um contador
5:se a quantidade de zeros for igual ao contador e um anagrama
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
