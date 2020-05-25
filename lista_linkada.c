//lista linkada! 
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data; //store the actual data
	struct node *next; //aponta para o node e
				
}node;

//funcao para criar a lista linkada
node *createLinkedList(int n);

void displayList(node*head);

int main(){

	int n=0; //number of nodes
	node *HEAD=NULL;//first node
	printf("how many nodes?\n");
	scanf("%d",&n);
	HEAD = createLinkedList(n);
	displayList(HEAD);

}

node *createLinkedList(int n){

	int i=0;
	node *head=NULL; //comeco
	node *temp=NULL; //node temporario
	node *p=NULL; //add the node at the correct position

	for(i=0;i<n;i++){
		//criar node individual desatacado da linked list
		temp= (node*)malloc(sizeof(node));
		printf("enter data\n");
		scanf("%d",&(temp->data));
		temp->next=NULL;

		if(head==NULL){ //Se a lista estiver vazia
			head=temp;//temp vai ser a cabeca
		}

		else{
			p=head;
			while(p->next!=NULL){
				p=p->next;
			p->next=temp;
			}

		}
	}

	return head;
}

void displayList(node*head){ //display

	node* p=head;

	while(p !=NULL){
		printf("%d\n",p->data );
		p=p->next;
	}

}