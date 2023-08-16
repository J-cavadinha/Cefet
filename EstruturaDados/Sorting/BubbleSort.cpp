/* Bubble Sort - começa com o 1o elemento do array, compara então com o 2o
caso o segundo seja menor, é feita a troca deles(caso a ordem preferida seja a crescente) com o
auxílio de uma outra variável. Isso é realizado um número x de vezes, mesmo que o array já esteja
organizado.
*/

// Processo demorado e passível de otimização

#include<stdio.h>

/* void bubble(int v[]){				//Exemplo Bubble Sort
	for(int i=0; i<5; i++){
		for(int j=i+1; j<5; j++){
			if(v[i]>v[j]){
				int aux = v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}
	for(int w=0; w<5; w++){
		printf("%d\n", v[w]);
	}
}
*/

void bubbleotimizado (int v[]){

  for (int step = 0; step < 5 - 1; ++step) { // Loop que acessa cada elemento
    
    int swapped = 0; // Checa se houve alguma troca
    
    for (int i = 0; i < 5 - step - 1; ++i) { // Compara o elementos do array
      
      if (v[i] > v[i + 1]) {
    
        int temp = v[i];
        v[i] = v[i + 1];
        v[i + 1] = temp;
         swapped = 1;
      }
    }
	if (swapped == 0) break;// Se não tiver sido feito a troca, encerra o loop
	}
}

int main(){
	int v[5];
	printf("Digite 5 números: ");
	for(int k=0; k<5; k++){
		scanf("%d", &v[k]);
	}
	bubbleotimizado(v);
    for(int w=0; w<5; w++){ // Exibe
		printf("%d\t", v[w]);
	}
	return 0;
}
