#include<stdio.h>
void analise(int qt[4][31], float precos[4][31]){
	
	int i, j;
	float retorno[4];
	for(i=0; i<4; i++){
		for(j=0; j<31; j++){
		float retorno_dia = qt[i][j] * precos[i][j];	//Vetor para armazenar o retorno diário
		retorno[i] = retorno[i] + retorno_dia;
		}
	}
	printf("Combustivel %d: retorno de %d", i, retorno[i]);		//a)
	
	for(j=0; j<31; j++){
		total_dia = 0;
		
		for(i=0; i<4; i++){
		total_dia = qt[i][j] * preco[i][j]
		}
		printf("Valor total das vendas dos 4 comb. no dia %d: %d", j, total_dia);
	}
}
