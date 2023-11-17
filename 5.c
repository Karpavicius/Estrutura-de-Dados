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
		printf("invalido\n");
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
					printf("invalido\n");
			}else
				printf("invalido\n");
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

void remove_inicio(node **l){
	if (*l!=NULL){
		node *aux = *l;
		*l=(*l)->prox;
		free(aux);
	}
}

void remove_fim(node **l){
	if (*l !=NULL){
		if ((*l)->prox!=NULL){
			node *aux = *l;
			node *aux_ant = NULL;
			while(aux->prox!=NULL){
				aux_ant=aux;
				aux=aux->prox;
			}
			free(aux);
			aux_ant->prox=NULL;		
		}else{
			free(*l);
			*l=NULL;
		}		
	}
}

void remove_indice(node **l, int i){
	if (i<0)
		printf("invalido\n");
	else
		if (i==0)
			remove_inicio(l);
		else{
			if (*l!=NULL){
				int idx=0;
				node *aux = *l;
				while (idx<i-1 && aux->prox!=NULL){
					idx++;
					aux=aux->prox;
				}
				if (idx==i-1 && aux->prox!=NULL){
					node *aux2 = aux->prox;
					aux->prox = aux2->prox;
					free(aux2);
				}else
					printf("invalido\n");
			}else
				printf("invalido\n");
		}
}

void remove_elemento(node **l, int e){
	if (*l!=NULL){
		if ((*l)->e == e)
			remove_inicio(l);
		else{
			node *aux = *l;
			int i=0;
			while(aux->e!=e && aux->prox!=NULL){
				aux=aux->prox;
				i++;
			}
			if (aux->e == e)
				remove_indice(l,i);
			else
				printf("invalido\n");
		}
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
	remove_elemento(&lista,50);
	imprimir(lista);
	printf("\n");
	return 0;
}