#include <stdio.h>
#include <stdlib.h>


void main(){

	int vet[10];
	int x, y, a;

	for(x=0;x<10;x++){
		scanf("%d", &vet[x]);
	}
	for(x=0;x<10;x++){
		for(y=0;y<10;y++){
			if(vet[y]>	vet[y+1]){
				a = vet[y];
				vet[y] = vet[y+1];
				vet[y+1] = a;
			}
		}
	}
	for(x=0;x<10;x++){
	printf("%d\n", vet[x]);
	}
}