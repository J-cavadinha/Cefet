/* Selection Sort - Compplexidade O(nˆ2)
   Consiste em 2 loops 'for', no qual o loop interno faz as comparações, percorrendo o array todo, e após ter realizado
   todo o ciclo (até que j<n), o loop externo realiza as mudanças, troca o primeiro elemento com o menor, e o último
   com o maior.

*/

#include<stdio.h>
void selection(int v[], int n){			
	int menor, aux;
	for(int i=0; i<n-1; i++){ // O(n)
		menor = i;
		for(int j=i+1; j<n; j++) // O(n)
		{
			if(v[menor]>v[j]) // O(1)
			menor = j;
		}
		aux = v[i];
		v[i]=v[menor];
		v[menor]=aux;
	}
} // Complexidade -> O(n) * O(n) = O(nˆ2)

int main(){
	int n;
	scanf("%d", &n);
	int v[n];
	for(int k=0; k<n; k++){
		scanf("%d", &v[k]);
	}

	selection(v, n);

	for(int i=0; i<n; i++){
		printf("%d\t", v[i]);
	}

	return 0;
}
