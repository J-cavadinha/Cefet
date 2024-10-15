/* Bubble Sort - Complexidade O(nˆ2)
   Através de loops 'for', compara o primeiro elemento com o segundo, depois o primeiro elemento com o terceiro...
   Após percorrer todo o array; compara-se o segundo elemento com o terceiro, depois o segundo com o quarto...
   Realiza a troca de elementos com uma variável auxiliar

   Apenas útil para pequenos arrays devido ao tempo para processar uma array inteira.
*/

#include<stdio.h>

void bubble(int v[], int n){ 
	for(int i=0; i<n; i++){	// O(n)
		for(int j=i+1; j<n; j++){ // O(n)
			if(v[i]>v[j]){ // O(1)
				int aux = v[i];
				v[i]=v[j];
				v[j]=aux;
			}
		}
	}
} // Complexidade -> O(n) * O(n) = O(nˆ2)

/*void bubbleotimizado (int v[]){

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
} */

int main(){
	int n;
	scanf("%d", &n);
	int v[n];
	for(int k=0; k<n; k++){
		scanf("%d", &v[k]);
	}

	bubble(v, n);
    for(int w=0; w<n; w++){ // Exibe
		printf("%d\t", v[w]);
	}
	return 0;
}
