// struct datas

/* programa que receba dois struct do tipo data 
cada um representando uma data valida com dia mes e ano, calcule o numero de dias 
que decorreram entre as duas datas
*/

#include <stdio.h>

typedef struct datas
{
int dia;
int mes;
int ano;

} data;

int main(){

data a;
data b;
data dif;
int dias=0;

scanf("%d",&a.dia);
scanf("%d",&a.mes);
scanf("%d",&a.ano);
scanf("%d",&b.dia);
scanf("%d",&b.mes);
scanf("%d",&b.ano);

if (a.dia > b.dia)
	dif.dia=a.dia - b.dia;

else 
	dif.dia=b.dia - a.dia;
//---------------------------------
if (a.mes > b.mes)
	dif.mes=a.mes - b.mes;

else 
	dif.mes=b.mes - a.mes;
//---------------------------------
if (a.ano > b.ano)
	dif.ano=a.ano - b.ano;

else 
	dif.ano=b.ano - a.ano;

dias= dif.dia+(dif.mes*30)+(dif.ano*365);

printf("a diferenca de dias e %d\n", dias);






}

