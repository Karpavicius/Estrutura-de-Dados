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

void inserir_indice(node **l, int e, int i){
	if (i<0)
		printf("invalido");
	else
		if (i==0)
			inserir_inicio(l,e);
		else{
			if (*l!=NULL){
				int idx=0;
				node *aux = *l;
				while (idx<i-1 && aux->prox!=NULL){
					idx++;
					aux=aux->prox;
				}
				if (idx==i-1){
					node *novo = malloc(sizeof(node));
					novo->e=e;
					novo->prox=aux->prox;
					aux->prox=novo;
				}else
					printf("invalido");
			}else
				printf("invalido");
		}
}

void inserir_fim(node **l, int e){
	node *novo = malloc(sizeof(node));
	novo->e = e;
	novo->prox = NULL;
	if(*l==NULL)
		*l=novo;
	else{
		node *aux = *l;
		while(aux->prox!=NULL)
			aux=aux->prox;
		aux->prox=novo;
	} 	
}



int main(){
	node *lista=NULL;
	printf("%p -> %p\n\n",&lista, lista);
	inserir_fim(&lista, 1);
	imprimir(lista);
	printf("\n");
	inserir_fim(&lista,2);
	imprimir(lista);
	printf("\n");
	inserir_fim(&lista,3);
	imprimir(lista);
	printf("\n");
	inserir_indice(&lista,4,0);
	imprimir(lista);
	printf("\n");
	inserir_indice(&lista,5,2);
	imprimir(lista);
	printf("\n");
	inserir_indice(&lista,6,5);
	imprimir(lista);
	printf("\n");
	return 0;
}