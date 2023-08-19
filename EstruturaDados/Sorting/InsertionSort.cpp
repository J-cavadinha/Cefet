/* Insertion Sort
Começa no 1o elemento da array, guarda o elemento seguinte em uma variável.
Caso o 1o elemento seja maior que a variável, ele troca o valor do 2o elemento pelo primeiro e troca o valor do 1o pela variável.
Agora ele guarda o 3o elemento na variável e compara com o 2o, caso TRUE, reproduz o processo acima e faz a nova comparação
com o 1o elemento. */

/* Processo demorado, pior case possível = ter que trocar todos os elementos de posição.
Ideal para pequenos arrays que necessitem de poucas alterações. */

// Código
#include<stdio.h>
void InsertionSort(int v[]){
    for(int i=1; i<6; i++){
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
    int v[] = {25, 10, 6, 15, 4, 11};
    InsertionSort(v);
    printf("Números em ordem ascendente:\n");
    for(int i=0; i<6; i++){
        printf("%d\t", v[i]);
    }
    return 0;
}