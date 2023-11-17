#include <stdio.h>
#include <stdlib.h>

struct No {
	int l;
	int c;
	int v;
	struct No *proxL;
	struct No *proxC;
};

typedef struct No no;

void inserir (no *linhas[], no *colunas[], int l, int c, int v){
	no *novo = malloc(sizeof(no));
	novo->v=v;
	novo->l=l;
	novo->c=c;
	novo->proxL = NULL;
	novo->proxC = NULL;
}

void remover (no *linhas[], no *colunas[], int l, int c){

}

void imprimirL(no *vetor){

}

void imprimirC(no *vetor){

}	

int main(){
	int nL;
	int nC;
	int mat[nL][nC];
	no *linhas[nL];
	no *colunas[nC];
	int i, j;
	for (i=0; i<nL; i++)
		linhas[i] = NULL;
	for (i=0; i<nC; i++)
		colunas[i] = NULL;
		
	return 0;
}
