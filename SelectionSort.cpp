// Selection Sort
#include<stdio.h>
void test(int v[]){
	int menor, aux;
	for(int i=0; i<5-1; i++){
		menor = i;
		for(int j=i+1; j<5; j++)
		{
			if(v[menor]>v[j])
			menor = j;
		}
		aux = v[i];
		v[i]=v[menor];
		v[menor]=aux;
	}
	for(int w=0; w<5; w++){
		printf("%d\n", v[w]);
	}
}

int main(){
	int v[5];
	printf("Digite uma série de números (5): ");
	for(int k=0; k<5; k++){
		scanf("%d", &v[k]);
	}
	test(v);
	return 0;
}
