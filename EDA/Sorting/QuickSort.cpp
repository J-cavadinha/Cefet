/* QuickSort - Divide and Conquer
Utiliza o método de recursão. Semelhante à MergeSort, porém aqui temos uma função que acha o termo
pivô e quebra o array em antes e depois do pivô, assim realiza a recursão chamando ela mesmo e
dividindo/concatenando os elementos.
*/

#include<stdio.h>

void swap(int *a, int *b){      // Função troca/swap
    int s= *a;
    *a = *b;
    *b = s;
}

int Particiona(int v[], int menor, int maior){      // Função que acha o termo pivô
    int pivot = v[maior];     // Seleciona o elemento 'high' como pivo
    int i = menor - 1;
    for(int j=menor; j<maior; j++){
        if(v[j]<=pivot){
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i+1], &v[maior]);
    return i+1;
}

void QuickSort(int v[], int menor, int maior){
    if(menor<maior){
        int pi = Particiona(v,menor, maior); // Pega o termo pivô e chama recursivamente

        QuickSort(v, menor, pi-1);
        QuickSort(v, pi+1, maior);
    }
}

int main(){
    
    int n;
    scanf("%d", &n);

    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    QuickSort(v, 0, n-1);

    for(int k=0; k<n; k++){
        printf("%d\t", v[k]);
    }
    return 0;
}
