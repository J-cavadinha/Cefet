// EDA - Implementação de Busca Sequencial
#include<stdio.h>

int search(int v[], int n, int num){
	int i=0;
	while(i!=n){
		
		if(v[i]==num){
			return i;
		}
		else{
			i++;
		}
	}
	return -1;
}

int main(){
	int v[]={10, 9, 5, 4, 6, 2, 3, 6, 0, 8};
	int num;
	printf("Digite o elemento que deseja procurar: ");
	scanf("%d", &num);
	int ans = search(v, 10, num);
	
	if(ans == -1){
		printf("Elemento nao encontrado.");
	}
	else{
		printf("%d", ans);
	}
}
