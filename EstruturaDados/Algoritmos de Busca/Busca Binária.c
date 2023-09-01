// EDA - Implementação de Busca Binária

#include<stdio.h>

void searchbi(int v[], int x, int inicio, int fim){
	int meio = (inicio + fim)/2;
	
	// Procura se é == ao meio
	if(x == v[meio]){
		printf("%d", meio+1);
	}
	// Caso não seja, verifica se é maior ou menor que o meio
	else{
		if(x<v[meio]){
			if(x<inicio){
				printf("Nao consta na lista.");
			}
			else{
			searchbi(v, x, inicio, meio);
			}
		}
		else{
			if(x>fim){
				printf("Nao consta na lista.");
			}
			else{
			searchbi(v, x, meio+1, fim);
			}
		}
	}
}

int main(){
	int num, v[7]={9, 15, 25, 32, 44, 50, 90};
	
	printf("Digite o numero a ser buscado: ");
	scanf("%d", &num);
	searchbi(v, num, 0, 7);
}
