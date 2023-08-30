// Estrutura de Dados - Lista de exercícios - Ordenação

// 1a questão: algortimo descrito é o Bubble Sort
// Pior caso: Se o array estiver ordenado na forma decrescente

void BubbleSort(int v[]){
    for(int step=0; step < 50-1; step++){
        int swapped=0;
        for(int i=0; i<50-step-1; i++){
            if(v[i] > v[i+1]){
                int temp =v[i];
                v[i]=v[i+1];
                v[i+1]=temp;
                swapped=1;
            }
        }
        if(swapped == 0){
        break;
    }
    }
}

/*--------------------------------------------------------------------------*/

// 2a questão: algoritmo descrito é o Selection Sort
// Pior caso: Se o array estiver ordenado na forma decrescente

void SelectionSort(int v[]){
    int menor, aux;
    for(int i=0; i<20-1; i++){
        menor = i;
        for(int j=i+1; j<20; j++){
            if(v[menor]>v[j]){
                menor = j;
            }
            aux = v[i];
            v[i]=v[menor];
            v[menor]=aux;
        }
    }
}

/*---------------------------------------------------------------------------*/

// 3a questão: algoritmo descrito é o Insertion Sort
// Pior caso: Se tiver que trocar todos os elementos

void InsertionSort(int v[]){
    for(int i=1; i<10; i++){
        int chave=v[i];
        int j=i-1;
        while(chave < v[j] && j>=0){
            v[j+1]=v[j];
            --j;
        }
        v[j+1]=chave;
    }
}

/*----------------------------------------------------------------------------*/

/* 4a questão:
() - Complexidade?
() - COmplexidade?
(F) - O MergeSort intercala e o QuickSort concatena.
*/
