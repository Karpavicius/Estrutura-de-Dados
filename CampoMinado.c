#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int i, j, k, nL, nC, nB;
	printf("Digite o número de linhas e colunas: ");
	scanf("%d %d",&nL, &nC);
	printf("Digite o número de bombas: ");
	scanf("%d", &nB);
	
	int tab[nL+2][nC+2];
	char tab2[nL+2][nC+2];
	for (i=0; i<nL+2; i++)
		for (j=0; j<nC+2; j++){
			tab[i][j]=0;
			tab2[i][j]='#';
		}
	
	for (k=0; k<nB; k++){
		i = (rand()%nL)+1;
		j = (rand()%nC)+1;
		while (tab[i][j]==-1){
			i = (rand()%nL)+1;
			j = (rand()%nC)+1;
		}
		tab[i][j]=-1;		
	}
	
	for (i=1; i<nL+1; i++){
		for (j=1; j<nC+1; j++){
			if(tab[i][j]!=-1){
				if(tab[i-1][j-1]==-1) //cima esquerda
					tab[i][j]++;
				if(tab[i-1][j]==-1) //cima
					tab[i][j]++;
				if(tab[i-1][j+1]==-1) //cima direita
					tab[i][j]++;
				if(tab[i][j-1]==-1) //esquerda
					tab[i][j]++;
				if(tab[i][j+1]==-1) //direita
					tab[i][j]++;
				if(tab[i+1][j-1]==-1) //baixo esquerda
					tab[i][j]++;
				if(tab[i+1][j]==-1) //baixo
					tab[i][j]++;
				if(tab[i+1][j+1]==-1) //baixo direita
					tab[i][j]++;
			}
		}
	}
	
	
	for (i=1; i<nL+1; i++){
		for (j=1; j<nC+1; j++)
			if(tab[i][j]!=-1)
				printf("%d ",tab[i][j]);
			else
				printf("* ");
		printf("\n");
	}
	
	printf("\n  ");
	for (i=1; i<nC+1; i++)
		printf("%d ",i);
	printf("\n");
	for (i=1; i<nL+1; i++){
		printf("%d ",i);
		for (j=1; j<nC+1; j++)
			printf("%c ",tab2[i][j]);
		printf("\n");
	}
	
	int jl, jc, perdeu=1, nj=0;
	
	while(perdeu){
		printf("Digite a jogada: ");
		scanf("%d %d",&jl, &jc);
		while(jl<1 || jl >nL || jc < 1 || 
		jc > nC || tab2[jl][jc]!='#'){
			printf("Digite a jogada: ");
			scanf("%d %d",&jl, &jc);
		}
		if (tab[jl][jc]!=-1){
			tab2[jl][jc]=tab[jl][jc]+'0';
		}else{
			tab2[jl][jc]='*';
			perdeu=0;
		}
		printf("\n  ");
		for (i=1; i<nC+1; i++)
			printf("%d ",i);
		printf("\n");
		for (i=1; i<nL+1; i++){
			printf("%d ",i);
			for (j=1; j<nC+1; j++)
				printf("%c ",tab2[i][j]);
			printf("\n");
		}
		nj++;
		if (nj==nL*nC-nB)
			break;
		
	}
		
	return 0;
}