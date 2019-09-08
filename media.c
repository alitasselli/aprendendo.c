/* 8  escreva uma funcao que calcule a media de numeros inteiros 
positivos mas que nao passe o numero total de numeros como parametro
*/

#include <stdio.h>
#include<stdlib.h>

struct numeros{
	int nota;
	struct numeros *proximo;
};

struct tamanho{
	int tamanho;
	struct numeros *inicio;
};

void media(struct tamanho *tamanho){
	int media=0;
	struct numeros *guia;
	guia=tamanho->inicio;
	for(int i=0;i<tamanho->tamanho;i++){
		media+=guia->nota;
		guia=guia->proximo;
}

media=media/tamanho->tamanho;
printf("a media é %d ",media );
printf("\n");

}
	



int main(){
	int entrada=1;
	struct tamanho *quantidade;
	quantidade=malloc(sizeof(struct tamanho));
	quantidade->tamanho=0;
	quantidade->inicio=NULL;
	while(entrada>0){
		scanf("%d",&entrada);
		if(entrada<0)
			break;
		struct numeros *notas;
		notas=malloc(sizeof(struct numeros));
		notas->nota=entrada;
		notas->proximo=quantidade->inicio;
		quantidade->inicio=notas;
		quantidade->tamanho++;

}
media(quantidade);

}



