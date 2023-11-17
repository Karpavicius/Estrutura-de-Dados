#include <stdio.h>
#include <stdlib.h>

int main(){
	int **m;
	printf("%p -> %p\n",&m, m);
	m = malloc(sizeof(int *)*3);
	int i, j;
	for (i=0; i<3; i++){
		m[i] = malloc(sizeof(int *)*3);
		for (j=0; j<3; j++){
			m[i][j]= rand()%20;
		}
	}
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("%p -> %d\n",&m[i][j],m[i][j]);
		}
		printf("\n");
	}
			
	
	/*printf("%p -> %p\n",&m, m);
	
	m[0] = malloc(sizeof(int)*3);
	m[1] = malloc(sizeof(int)*3);
	m[2] = malloc(sizeof(int)*3);
	printf("\n\n");
	printf("%p -> %p\n",&m[0], m[0]);
	printf("\n\n");
	int i;
	for (i=0; i<3; i++){
		m[0][i]=i*2;
		printf("%p -> %d\n", &m[0][i], m[0][i]);
	}
	printf("\n\n");
	printf("%p -> %p\n",&m[1], m[1]);
	printf("\n\n");
	for (i=0; i<3; i++){
		m[1][i]=10+i;
		printf("%p -> %d\n", &m[1][i], m[1][i]);
	}
	printf("\n\n");
	printf("%p -> %p\n",&m[2], m[2]);
	printf("\n\n");
	for (i=0; i<3; i++){
		m[2][i]=10-i;
		printf("%p -> %d\n", &m[2][i], m[2][i]);
	}*/
	return 0;
}