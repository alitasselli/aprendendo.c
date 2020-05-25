/*
base para exercicios de avaliacao
os mesmos do 2 periodo
tres problemas :
-multiplicacao de matrizes (3 lacos for), argc argv
receber dois arquivos e cada arquivo tem uma matriz
vai determinar a quantidade de linha ver se pode 
fazer a multiplicacao ou nao
-receber uma sequencia de 10 inteiros e dar a subsequencia 
com a maior soma
se tiver duas iguais retornar com a maior media
- implementar um fatorial e exponencial de forma
recurssiva em c 
o logaritimo de dois de forma recurssiva em c
-implementar um baralho (log 2 ^ 10 = 3)
--2 enum--(tipo de estrutura de dados em c que vai representar numeros por texto) 
enum weather {
	cloudy,
	sunny,
	rain,
	windy,
};
enum weather w = sunny
,1 struct,

tem um enum dentro da union
 1 union,  (numeros e letras) | union number n:
                              | n.i = 10;
                              | n.d = 2.0;
 union number{
	int i;
	double d;
 };

 1 array
1 enum: tipo da carta e valor numerico
1 enum: para as cartas que nao tem numero
assuntos: funcoes ,tipos de dados ,matrizes ,array ,leitura de arquivos.argc argv.
*/

#include <stdio.h>
#include <stdlib.h>

//Definir a estrutura baralho

struct carta { //define a carta , 52 elementos do mesmo tipo
		
		enum suit naipe;
		union rank valor;
};

struct carta baralho[52]; //deck de cartas

enum suit{ //ver ordem de valor

	clubs;
	diamonts;
	spades;
	hearts;
};

union rank{

	int i; //2 a 10
	enum letter c; //as damas valente e rei

};

enum letter {
	j=11;
	q=12;
	k=13;
	a=14;
};

