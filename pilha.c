//exercicio 3,Hazin
/*
1:pedir as variaveis de empilhar desempilhar imprimir 
2:quando for adicionando sempre pelo topo criando uma lista encadeada
3:o primeiro elemento aponta para o nada e o 
ponteiro de inicio aponta para o ult colocado
4:quando for remover, o ponteiro de inicio aponta 
para quem o primeiro ta apontando
5:comando de imprimir coloca printf na lista toda
6:dar um break para finalizar
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct elemento{
	struct elemento *proximo;
	int numero;
};

struct pilha{
	struct elemento *inicio;
	int tamanho;
};

void empilhar(struct pilha *pilha, int numero){
	struct elemento *novo;
	novo=malloc(sizeof(struct elemento));
	novo->proximo=pilha->inicio;
	pilha->inicio=novo;
	novo->numero=numero;
	pilha->tamanho++;
}

void imprimir(struct pilha *pilha){
	struct elemento *guia;
	guia=pilha->inicio;
	for(int i=0;i<pilha->tamanho;i++){
		printf("%d  ", guia->numero);
		guia=guia->proximo;
}
printf("\n");

}
void remover(struct pilha *pilha){
	pilha->inicio=pilha->inicio->proximo;
	pilha->tamanho--;


}
int main(){
	struct pilha *pilha;
	pilha=malloc(sizeof(struct pilha));
	pilha->tamanho=0;
	pilha->inicio=NULL;
	char operacao[15]; //empilhar desempilhar e imprimir
	int numero;
	do{
		scanf("%s",operacao);
		if(strcmp(operacao,"Empilhar")==0){
		scanf("%d",&numero);
		if(pilha->inicio==NULL){
			struct elemento *ultpilha;
			ultpilha=malloc(sizeof(struct elemento));
			ultpilha->numero=numero;
			pilha->tamanho++;
			pilha->inicio=ultpilha;



   } 
   		else{
   			empilhar(pilha,numero);

}

  }else if(strcmp(operacao,"Imprimir")==0){
  	imprimir(pilha);



}
	else if (strcmp(operacao,"Desempilhar")==0){
		remover(pilha);
	}
}while(strcmp(operacao,"Finalizar")!=0);






}


