/* Insertion Sort
   Inicia selecionando uma variável chave, que recebe oo valor da 2 posição, e 'j'que recebe i-1
   Enquanto chave for menor que o elemento na posição 'j' e 'j' for maior ou = a 0
   a posição 'j'+1 recebe o valor da pos. 'j', e 'j' é decrescido 1, até o while encerrar
   Ao fim do while temos que j = -1, então a posição j+1 recebe o valor da variável chave.

   Útil para pequenos arrays
*/

// Código
#include<stdio.h>
void InsertionSort(int v[], int n){
    for(int i=1; i<n; i++){
        int key = v[i];
        int j = i - 1; 
        while(key < v[j] && j>=0){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = key;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    InsertionSort(v, n);

    for(int i=0; i<n; i++){
        printf("%d\t", v[i]);
    }
    return 0;
}
