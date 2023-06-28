#include<stdio.h>
void vendasGol(int matriz[6][12], float vet[6])	/* Matriz - qtd mensal, vet - preço */
{
	int i, j, cont, somames;
	float vendas_ano[6];
	somames = 0;
	
	for(cont=0; cont<6; cont++){
		vendas_ano[cont] = 0;
	}
	
	for(i=0; i<6; i++){
		for(j=0; j<12; j++){
			somames = somames + matriz[i][j]; //Qtde de carros vendidos por ano
		}
		valor_ano[i] = somames * vet[i]; 	//Valor total = qtde de carros vendidos * preco p/carro
	}
	for(cont=0; cont<6; cont++){
	printf("Total de carros vendidos no ano de 201%d: %d", cont, valor_ano[cont]);
	}
}

