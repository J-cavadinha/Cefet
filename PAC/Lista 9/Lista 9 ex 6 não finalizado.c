//Lista 9 ex 6
#include<stdio.h>
void leDadosCandidatos(char nomes[15]){
	int i;
	for(i=0; i<TOT; i++){
		printf("Digite o nome do canditado %d: ", i+1);
		scanf("%s", nomes[i]);
	}
}

void ordena(char nomes[15]){
	int i,j;
	
	for(i=0; i<15-1; i++){
		for(j=0; j<15-2; j++){
			if(strcmp(nomes[j], nomes[j+1]) > 0){
				temp = nomes[j];
				nomes[j] = nomes[j+1];
				nomes[j+1] = temp;
			}
		}
	}
}

struct voto{
	char nome[21];
	int localresid;		//0 - mora no pais, 1 - mora fora.
};
typedef struct voto Tvoto;

void geraRelatorio(Tvoto voto[])
