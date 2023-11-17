#include <stdio.h>
#include <stdlib.h>

struct Node{
	int l;
	int c;
	int v;
	struct Node *proxL;
	struct Node *proxC;
};

typedef struct Node node;

void Inserir(node *linhas[], node *colunas[], int l, int c, int v){
	node *novo = malloc(sizeof(node));
	novo->v=v;
	novo->l=l;
	novo->c=c;
	novo->proxL = NULL;
	novo->proxC = NULL;
}

void Remover(node *linhas[], node *colunas[], int l, int c){
	
}

void imprimirL(node *vetor){
	
}

void imprimirC(node *vetor){
	
}

int main(){
	int nLinha;
	int nColuna;
	int m[nLinha][nColuna];
	int i, j;
	for(i=0;i<nLinha;i++)
		linhas[i] = NULL;
	for(i=0;i<nColuna;i++)
		coluna[i] = NULL;
}