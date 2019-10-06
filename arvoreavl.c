#include <stdio.h>
#include <stdlib.h>

typedef struct folha{
	int num;
	struct folha* esquerda;
	struct folha* direita;
	int altura;
	int fesq;
	int fdir;	
}folha;

//ver altura do no, senao existir zero
int altura(folha* no){
	if(no==NULL)
		return 0;
	else
		return no->altura;
}

//ver o maior numero p ver altura depois
int maximo(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}

//atualizar a altura de um no
folha* attaltura(folha* no){
	int altdireita;
	int altesquerda;
	if(no != NULL){
		altdireita=altura(no->direita);
		altesquerda=altura(no->esquerda);
		no->altura=maximo(altdireita,altesquerda)+1;
	}
	return no;
}

folha* rotSimplesEsq(folha* no){
	folha* aux;
	aux=malloc(sizeof(folha));
	aux=no->direita;
	no->direita=aux->esquerda;
	aux->esquerda=no;
	attaltura(no->esquerda);
	attaltura(no);
	no->fdir=aux->fesq;
	aux->fesq=no->fesq+no->fdir+1;

	return aux;
}


folha* rotSimplesDir(folha* no){
	folha* aux;
	aux=malloc(sizeof(folha));
	aux=no->esquerda;
	no->esquerda=aux->direita;
	aux->direita=no;
	attaltura(no->direita);
	attaltura(no);
	no->fesq=aux->fdir;
	aux->fdir=no->fesq+no->fdir+1;
	
	return aux;
}

folha* rotDuplaEsq(folha* no){
	folha* resultado;
	resultado=malloc(sizeof(folha));
	no->direita=rotSimplesDir(no->direita);
	resultado=rotSimplesEsq(no);
	return resultado;
}

folha* rotDuplaDir(folha* no){
	folha* resultado;
	resultado=malloc(sizeof(folha));
	no->esquerda=rotSimplesEsq(no->esquerda);
	resultado=rotSimplesDir(no);
	return resultado;
}

folha* addarvore(int numero,folha* no){
	if(no==NULL){
		folha*  nova;
		nova=malloc(sizeof(folha));
		nova->num=numero;
		nova->esquerda=NULL;
		nova->direita=NULL;
		nova->altura=1;
		nova->fdir=0;
		nova->fesq=0;

		return nova;
	}
	else if(numero<no->num){
		no->fesq++;
		no->esquerda=addarvore(numero,no->esquerda);
		if(altura(no->esquerda)-altura(no->direita)==2){
			if(numero<no->esquerda->num)
				no=rotSimplesDir(no);
			else
				no=rotDuplaDir(no);
		}
	}
	else{
		no->fdir++;
		no->direita=addarvore(numero,no->direita);
		if(altura(no->direita)-altura(no->esquerda)==2){
			if(numero>no->direita->num)
				no=rotSimplesEsq(no);
			else
				no=rotDuplaEsq(no);
		}

	}
	no=attaltura(no);
	return no;
}


void buscaArvore(folha* no,int numero){
	int indice=1;
	folha* aux;
	aux=no;
	while(aux!=NULL){
		if(numero==aux->num){
			indice+=aux->fesq;
			break;
		}
		else if(numero<aux->num)
			aux=aux->esquerda;
		else{
			indice+=aux->fesq+1;
			aux=aux->direita;
		}

	}
	if(aux!=NULL)
		printf("%d\n", indice);
	else
		printf("Data tidak ada\n");
}


int main(){

	int qtcasos;
	int tipo;
	int numero;
	folha* raiz=NULL;

	scanf("%d",&qtcasos);
	for(int i=0;i<qtcasos;i++){
		scanf("%d",&tipo);
		if(tipo==1){
			scanf("%d",&numero);
			raiz=addarvore(numero,raiz);
		}
		else if(tipo==2){
			scanf("%d",&numero);
			buscaArvore(raiz,numero);

		}
	}

return 0;
}

