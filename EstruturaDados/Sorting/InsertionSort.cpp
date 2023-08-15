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
    for(int i=0; i<5; i++){
        int key = v[i];
        int j = i - 1;
        while(key < v[j] && j>=0){
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = key;
    }
}

void Visualizacao(int v[]){
    for(int i=0; i<5; i++){
        printf("%d\n", v[i]);
    }
}

void inicializa(int v[]){
    for(int i=0; i<5; i++){
        v[i] = 0;
    }
}

int main(){
    int v[5];
    inicializa(v);
    printf("Digite x números: ");
    for(int i=0; i<5; i++){
        scanf("%d", &v[i]);
    }
    InsertionSort(v);
    printf("Números em ordem ascendente: ");
    Visualizacao(v);
    return 0;
}