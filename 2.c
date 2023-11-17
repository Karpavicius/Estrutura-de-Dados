#include <stdio.h>
#include <stdlib.h>

struct Node{
	int e;
	struct Node *prox;
};

typedef struct Node node;


void imprimir(node *aux){
	while(aux!=NULL){
		printf("%p -> %d -> %p\n",&(aux->e)	, aux->e, aux->prox);
		aux=aux->prox;
	}
}

void inserir_inicio(node **l, int e){
	node *novo = malloc(sizeof(node));
	novo->e = e;
	novo->prox=*l;
	*l=novo;
}

int main(){
	node *lista=NULL;
	inserir_inicio(&lista, 5);
	imprimir(lista);
	printf("\n");	
	inserir_inicio(&lista, 10);
	imprimir(lista);
	printf("\n");	
	inserir_inicio(&lista, 15);
	imprimir(lista);
	printf("\n");	
	inserir_inicio(&lista, 20);
	imprimir(lista);
	printf("\n");	
	inserir_inicio(&lista, 25);
	imprimir(lista);	
	return 0;
}