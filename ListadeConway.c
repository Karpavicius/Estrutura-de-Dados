#include <stdio.h>
#include <stdlib.h>

struct Node{
	int valor;
	struct Node *prox;
};

typedef struct Node node;

void inserirInicio(node **l, int e){
    node *novo = malloc(sizeof(node));
    novo -> valor = e;
    novo -> prox = *l;
    *l = novo;
}

void imprimir(node *aux){
	while(aux!=NULL){
		printf("%d", aux->valor);
		aux=aux->prox;
		}
	printf("\n");
}

void ListadeConway(node **l, int linha){
	node *ListaAtual=*l;
	node *remover;
	node *aux;
	int qnt, i=1;

	while(i < linha){
		ListaAtual = *l;

        while(ListaAtual!=NULL){

        	qnt = 1;
            aux = ListaAtual -> prox;

			while(aux != NULL && ListaAtual->valor == aux->valor){
					remover=aux;
					qnt++;
					aux=aux->prox;
					free(remover);
			}

			node *novo = malloc(sizeof(node));
	   		novo->valor = ListaAtual->valor;
	    	novo->prox = aux;
	    	ListaAtual->valor = qnt;
	    	ListaAtual->prox = novo;
			ListaAtual = aux;

			}
			imprimir(*l);
		    i++;
    }
}

int main(){	

	 node *lista = NULL;

	 int n, linha;

	printf("Digite um numero para iniciar a lista: \n");
	scanf("%d", &n);

	inserirInicio(&lista, n);
    puts("");

	printf("Digite a linha final da lista: \n");
	scanf("%d", &linha);
	
    puts("");

    ListadeConway(&lista, linha);

    printf("Linha final da lista: ");
    imprimir(lista);
}