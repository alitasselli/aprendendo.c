//Profundiade de um no

#include <stdlib.h>
#include <stdio.h>

struct no{
	int data;
	struct no* esquerda;
	struct no* direita;
};

struct noArvore{
	int data;
	struct noArvore* esquerda;
	struct noArvore* direita;
};

//funcao para criar um novo no
noArvore* criarNovoNo(int data);

//funcao para inserir elementos 
noArvore* inserir(noArvore* ponteiroRaiz, int data);

//funcao para procurar um elemento
posicao procurar(noArvore* ponteiroRaiz,int data);

int main(){

	struct noArvore* ponteiroRaiz; //ponteiro p o endereco da raiz da arvore
	ponteiroRaiz = NULL; //arvore is vazia


	char string[]="(12(7(3()())(10()(11()())))(23(17()())(31()())))";

	printf("%c\n",string[0]);
	int numero = 11;

	ponteiroRaiz = inserir(&ponteiroRaiz,15);
	ponteiroRaiz = inserir(&ponteiroRaiz,20);
	ponteiroRaiz = inserir(&ponteiroRaiz,10);

	posicao = procurar(&ponteiroRaiz,numero);
	
	if(posicao == -1){
		printf("NAO ESTA NA ARVORE\n");
		printf("-1\n");
	}
	if(posicao != -1){
		printf("ESTA NA ARVORE\n");
		printf("%d\n",posicao);
	}

}

noArvore* criarNovoNo(int data){
	
	noArvore* novoNo = (noArvore*)malloc(sizeof(noArvore));//Alocar espaco
	novoNo->data = data; //designar o numero ao novo no
	novoNo->esquerda = NULL; //Definir esquerda e direita como nulo
	novoNo->direita = NULL;
	return novoNo;
}


noArvore* inserir(noArvore* ponteiroRaiz, int data){

	if(ponteiroRaiz == NULL){ //Se for o primeiro no da raiz
		ponteiroRaiz = criarNovoNo(data);
		return ponteiroRaiz;
	}

	else if(data <= ponteiroRaiz->data){ //se for menor que o numero da raiz
		
		ponteiroRaiz->esquerda = inserir(ponteiroRaiz->esquerda, data);


	}

	else(data >= ponteiroRaiz->data){ //Se for maior que o numero da raiz
		
		ponteiroRaiz->direita = inserir(ponteiroRaiz->direita, data);


	}
	return ponteiroRaiz;


}



/*Duas linhas. Em uma delas, você irá dizer ESTA NA ARVORE, 
caso o nó cujo inteiro é N esteja na árvore, e NAO ESTA NA ARVORE,
 caso contrário. Na outra linha, você irá informar em que 
 profundidade da árvore o nó está. Caso não esteja, imprima -1.

Observe o exemplo de entrada e saída*/

posicao procurar(noArvore* ponteiroRaiz,int data){

	if(ponteiroRaiz == NULL){
		return; 
	}

	int posicao = 0;

	if(ponteiroRaiz != NULL){

	if(ponteiroRaiz->data == data){
		 posicao++;
	}
	posicao = 1;
	else if(data <= ponteiroRaiz->data){
		procurar(ponteiroRaiz->esquerda, data);
		posicao++;
	}
	posicao = 1;
	else if(data >= ponteiroRaiz->data){
		procurar(ponteiroRaiz->direita, data);
		posicao++;
	
	}
	else //Se nao estiver na arvore
		posicao = -1;

	}

	return posicao;
}



