#include <stdio.h>
#include <stdlib.h>

struct Node{
	int linha;
	int c;
	int e;
	struct Node *prox;
};

typedef struct Node node;


void imprimir(node *aux){
	while(aux!=NULL){
		printf("%p -> Linha:%d 	-> Coluna:%d -> Valor:%d -> %p\n", &(aux->e), aux->linha, aux->c, aux->e, aux->prox);
		aux=aux->prox;
	}
}

void inserir_inicio(node **l, int e){
	node *novo = malloc(sizeof(node));
	novo ->e = e;
	novo ->prox=*l;
	*l=novo; 
}

void inserir_final(node **l, int e, int linha, int c){
	node *novo = malloc(sizeof(node));
	novo->e = e;
	novo->linha=linha;
	novo->c=c;
	novo-> prox = NULL;
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

int main(){
	node *lista=NULL;
	int m[3][3];
	int i, j;
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			m[i][j] = 1;
		}
	}
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			if(m[i][j]!=0){
				inserir_final(&lista, m[i][j], i, j);
			}
		}
	}
	imprimir(lista);
	return 0;
}