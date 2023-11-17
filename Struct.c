#include <stdio.h>
#include <stdlib.h>

struct Aluno{
	char nome[10];
	char matricula[5];
	int idade;
};

int main(){
	struct Aluno *a1 = malloc(sizeof(struct Aluno));
	printf("%p -> %p\n",&a1, a1);
	strcpy(a1->nome,"mauricio");
	strcpy(a1->matricula,"56723");
	a1->idade = 28;
	printf("%p -> %s\n", &a1->nome, a1->nome);
	printf("%p -> %s\n", &a1->matricula, a1->matricula);
	printf("%p -> %d\n", &a1->idade, a1->idade);
	return 0;
}
