#include <stdio.h>
#include <stdlib.h>

struct Node{
	int e;
	struct Node *prox;
};

int main(){
	struct Node *lista = malloc(sizeof(struct Node));
	//(*lista).e=80;
	//(*lista).prox=malloc(sizeof(struct Node));
	lista->e=1;
	lista->prox=malloc(sizeof(struct Node));
	lista->prox->e=2;
	lista->prox->prox=malloc(sizeof(struct Node));	
	lista->prox->prox->e=3;
	lista->prox->prox->prox=malloc(sizeof(struct Node));
	lista->prox->prox->prox->e=4;
	lista->prox->prox->prox->prox=malloc(sizeof(struct Node));
	lista->prox->prox->prox->prox->e=5;
	lista->prox->prox->prox->prox->prox=NULL;		
	printf("Lista: %p -> %p\n",&lista,lista);
	printf("e1: %p -> %d -> %p\n",&(lista->e),lista->e,lista->prox);
	printf("e2: %p -> %d -> %p\n",&(lista->prox->e),lista->prox->e,lista->prox->prox);
	printf("e3: %p -> %d -> %p\n",&(lista->prox->prox->e),lista->prox->prox->e,lista->prox->prox->prox);
	printf("e4: %p -> %d -> %p\n",&(lista->prox->prox->prox->e),lista->prox->prox->prox->e,lista->prox->prox->prox->prox);
	printf("e5: %p -> %d -> %p\n",&(lista->prox->prox->prox->prox->e),lista->prox->prox->prox->prox->e,lista->prox->prox->prox->prox->prox);
	return 0;
}