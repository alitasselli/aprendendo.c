#include <stdio.h>
#include <stdlib.h>

struct folha {
	int numero;
	struct folha* esquerda;
	struct folha* direita;
};

struct folha* novoelem(int numero){
	struct folha* novo;
	novo=malloc(sizeof(struct folha));
	novo->numero=numero;
	novo->esquerda=NULL;
	novo->direita=NULL;
	return novo;

}



struct folha* addarvore(struct folha* raiz,int num){
	if(raiz==NULL){
		raiz=novoelem(num);
	}
	else if(num>raiz->numero){
		raiz->direita=addarvore(raiz->direita,num);
	}
	else
		raiz->esquerda=addarvore(raiz->esquerda,num);

	return raiz;	
}

void preordem(struct folha* raiz){
	if(raiz != NULL){
	printf(" %d",raiz->numero);
	preordem(raiz->esquerda);
	preordem(raiz->direita);
	}
}

void intordem(struct folha* raiz){
	if(raiz != NULL){
	intordem(raiz->esquerda);
	printf(" %d",raiz->numero);
	intordem(raiz->direita);
	}
}

void posordem(struct folha* raiz){
	if(raiz != NULL){
	posordem(raiz->esquerda);
	posordem(raiz->direita);
	printf(" %d",raiz->numero);
	}
}

int main() {

int casos;
int elem; 
int num;
struct folha* raiz;

scanf("%d",&casos);

for(int i=0;i<casos;i++){
	raiz=NULL;
	scanf("%d",&elem);
	for(int j=0;j<elem;j++){
		scanf("%d",&num);
		//chamar addarvore
		raiz=addarvore(raiz,num);

}
printf("Case %d:",i+1);
printf("\nPre.:");
preordem(raiz);
printf("\nIn..:");
intordem(raiz);
printf("\nPost:");
posordem(raiz);
printf("\n\n");

free(raiz);

}

}
