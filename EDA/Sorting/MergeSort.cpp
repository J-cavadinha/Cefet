/* Merge Sort - Divide and Conquer
Esse método divide uma array em várias partes, resolve as partes e depois junta todas elas
Suponha um array 10 8 2 3 9 4, o algoritmo vai dividir em duas arrays menores:
1o pega da posição 0 até a metade (3): 10 8 2 // 2o pega da metade + 1 até o fim: 3 9 4
E então ele vai dividindo até sobrar apenas um elemento por array, organiza e então temos as duas
partes iniciais ordenadas, que por fim são ordenadas formando uma só array.

É composto por duas funções, a 1a faz a divisão sucessiva e ordenação e a 2a faz a junção.

https://www.programiz.com/dsa/merge-sort#google_vignette */

#include<stdio.h>

void Intercala(int v[], int inicio, int fim, int meio){ // Função que une os arrays
    int i, aux[fim], posl = inicio, inicioA1 = inicio, inicioA2 = meio+1; // Declaração de var
    while(inicioA1 <= meio && inicioA2 <= fim){ // inicio menor/igual ao meio e meio+1 menor/igual ao fim
        if(v[inicioA1] > v[inicioA2]){    // Se inicio menor que meio +1
            aux[posl]=v[inicioA2];  // Var auxiliar[inicio] = posição vetor[meio+1]
            inicioA2++;             // Acrescenta 1 pro meio+1
        } else{
            aux[posl]=v[inicioA1];  // Var auxiliar[posição livre] = vetor[inicio]
            inicioA1++;             // Acrescenta 1 pro inicio
        }
        posl++;                     // Acrescenta 1 pra posição livre
    } //Fim while

    for(i=inicioA1; i<=meio;i++){
        aux[posl]=v[i]; 
        posl++;
    }
    for(i=inicioA2; i<=fim; i++){
        aux[posl]=v[i];
        posl++;
    }
    for(i=inicio; i<=fim; i++){
        v[i]=aux[i];
    }
}

void MergeSort(int v[], int inicio, int fim){   //Função que realiza as divisões do array
    int meio;
    if(inicio<fim){
        meio = (inicio+fim)/2;
        MergeSort(v,inicio,meio);               // Função Recursiva - chama ela mesma
        MergeSort(v,meio+1,fim);                // Função Recursiva
        Intercala(v,inicio,fim,meio);        // Chama a 2a função que faz a união
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int v[n];
    for(int i=0; i<n; i++){
        scanf("%d", &v[i]);
    }

    MergeSort(v,0,n-1); 
    
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    return 0;
}
