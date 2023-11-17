#include <stdio.h>
#include <stdlib.h>

int insertionsort(int v[], int n){
	int valor, i, j, cont=0;
	for (i=1; i<n; i++){
		valor = v[i];
		for (j=i-1; j>=0; j--){
			cont++;
			if (valor<v[j]){
				v[j+1] = v[j];
				v[j]=valor;
			}else
				break;
		}
	}
	return cont;
}

int selectionsort(int v[], int n){
	int menor, menori, i, j, cont=0;
	for (i=0; i<n-1; i++){
		menor = v[i];
		menori= i;
		for (j=i+1; j<n; j++){
			cont++;
			if (v[j]<menor){
				menor = v[j];
				menori = j;
			}
		}
		v[menori]=v[i];
		v[i]=menor;
	}
	return cont;
}
int bubblesort(int v[], int n){
	int i, j, aux,cont=0;
	for (i=0; i<n; i++){
		for (j=0; j<n-1; j++){
			cont++;
			if (v[j]>v[j+1]){
				aux = v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
	return cont;
}

int quicksort(int v[], int iniV, int fimV){
	int aux, k, cont=0;
	int i = iniV;
	int j = fimV;
	int pivo = v[(iniV+fimV)/2];
	while (i < j){
		while (v[i]<pivo && i<fimV){
			i++;
		}
		while (v[j]>pivo & j>iniV){
			j--;
		}
		if (i<=j){
			aux = v[i];
			v[i] = v[j];
			v[j] = aux;
			i++;
			j--;
		}
		cont++;
		for (k=0; k<8; k++)	
			printf("%d ",v[k]);
		printf("\n");
	}
	if (iniV < j)
		cont+=quicksort(v, iniV, j);
	if (i < fimV)
		cont+=quicksort(v, i, fimV);
	return cont;
}

int merge(int v[], int iniV1, int iniV2, int fim){
	int i = iniV1;
	int j = iniV2;
	int aux, k;
	
	while (i < fim+1 && j < fim+1 && i < j){
		if (v[i] > v[j]){
			aux = v[j];
			for (k=j-1; k>=i; k--){
				v[k+1]=v[k];
			}
			v[k+1]=aux;
			j++;
		}
		i++;
	}
	return iniV1;
}

int mergesort(int v[], int iniV, int fimV){
	if (iniV == fimV)
		return iniV;
	else
		return merge(v, mergesort(v, iniV, (iniV+fimV)/2), mergesort(v, (iniV+fimV)/2+1, fimV), fimV);
}

int main(){
	int v[6] = {6,5,4,0,7,1};
	int i, cont, n;
	n = (int)sizeof(v)/sizeof(int);
	for (i=0; i<n; i++)	
		printf("%d ",v[i]);
	printf("\n");
	cont = mergesort(v,0,n-1);
	for (i=0; i<n; i++)	
		printf("%d ",v[i]);
	printf("\n%d\n",cont);
	return 0;
}