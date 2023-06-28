#include<stdio.h>
#include<string.h>
#define TOT 30
struct produto{
	float preco;
	int qtde;
};
typedef struct produto Tprod;

int leitura(char nome[][31], Tprod v[]){
	int i;
	
	for(i=0; i<TOT; i++){
		printf("Digite o nome do produto (Digite Fim para sair): ");
		scanf(" %30[^\n]", nome[i]);
		if(strcmp(nome[i], "Fim")==0)
		break;
		printf("Digite tambem o preco unitario e a quantidade: ");
		scanf("%f%d", &v[i].preco , &v[i].qtde);
	}
	return i;
}

int busca(char nome[][31], char procuraprod[], int qtd){
	int i;
	for(i=0; i<qtd; i++){
		if(strcmp(procuraprod, nome[i]) == 0)
			return i;
	}
	return -1;
}

int main(){
	Tprod produto[30];
	char nome[30][31], cadeprod[31];
	int j;
	int qtd = leitura(nome, produto);
	
	for(j=0; j<TOT; j++){
	printf("Digite o produto a ser pesquisado (Digite Fim para terminar): ");
	scanf("%s", &cadeprod);
		int resultado = busca(nome, cadeprod, qtd);
		if (resultado == -1)
	   	 printf("Produto inexistente\n");
		else {
	    printf("Preco: %.2f\n", produto[resultado].preco);
	    printf("Quantidade em estoque: %d\n", produto[resultado].qtde);
	}
	}
	return 0;
}

