//questao hazin
/*
ENTRADA-------------------
1º linha contem um inteiro N com a qtd inicial de pessoas na fila
2º linha contem N identificadores de pessoas na fila
primeiro corresponde a primeira pessoa na fila
duas pessoas nao pdem ter o mesmo identificador
3º linha contem um inteiro M com a qtd de pessoas que deixaram a fila
4º linha contem M inteiros com os identificadores 
das pessoas na ordem que deixaram a fila 
mesmo identificador nao aparece duas vezes
SAIDA--------------------
Seu programa deve imprimir uma linha contendo N − M inteiros 
com os identificadores das pessoas que permaneceram na fila, 
em ordem de chegada.
*/

#include <stdio.h>
#include <stdlib.h>

struct elemento{
	struct elemento *proximo;
	int numero;
	};

struct fila{
	struct elemento *inicio;
	struct elemento *fim;
	int tamanho;
};

void novoelemento(struct fila *info,int ordem){
	struct elemento *novo;
	novo=malloc(sizeof(struct elemento));
	info->fim->proximo=novo;
	info->tamanho++;
	info->fim=novo;
	novo->numero=ordem;


}



int main(){
	struct fila *info;
	int qtpessoas;
	int ordemfila;
	int deixaramfila;
	struct elemento *guia;
	struct elemento *guiaaux;
	info=malloc(sizeof(struct fila));
	info->inicio=NULL;
	info->fim=NULL;
	info->tamanho=0;


	scanf("%d",&qtpessoas);
		for (int i=0;i<qtpessoas;i++){
			scanf("%d", &ordemfila);
			if(i==0){
				struct elemento *novo;
				novo=malloc(sizeof(struct elemento));
				novo->numero=ordemfila;
				novo->proximo=NULL;
				info->inicio=novo;
				info->fim=novo;
				info->tamanho++;

	}
			else{
				novoelemento(info,ordemfila);

	}


	}

	scanf("%d", &deixaramfila);
		for (int i=0;i<deixaramfila;i++){
			guia = info->inicio;
			guiaaux = info->inicio;
			scanf("%d",&ordemfila);
			while(guia->numero != ordemfila){
				guiaaux=guia;
				guia=guia->proximo;
	}


		if (guia->numero==info->inicio->numero){
			info->inicio=guia->proximo;
			info->tamanho--;
}
		else if(guia->proximo==NULL){
			info->fim=guiaaux;
			info->tamanho--;

}

		else{
			guiaaux->proximo=guia->proximo;
			info->tamanho--;

}


}

guia = info->inicio;
while (guia!=NULL){
	printf("%d  ", guia->numero);
	guia=guia->proximo;

}

	

printf("\n\n\n");

	}

