/* Exercício 1 - Slide de Ordenação 1
Insertion Sort foi escolhido devido ao seu tamanho e velocidade comparado ao Bubble e Selection 
Como fazer sem as repetições? Na leitura?
*/

#include<stdio.h>

#include<stdio.h>
void InsertionSort(int v[]){
    for(int i=0; i<50; i++){
        int key = v[i]; // 1a iteração i = 0, logo: key assume o valor da variável que estiver em 0
        int j = i - 1;  // j vai assumir -1
        while(key < v[j] && j>=0){  // Não roda na 1a it. pois j<0
            v[j+1] = v[j];
            --j;
        }
        v[j+1] = key;
    }
}

void inicializa(int v[]){
    for(int i=0; i<50; i++){
        v[i] = 0;
    }
}

int main(){
    int v[50];
    inicializa(v);
    printf("Digite 50 números: ");
    for(int i=0; i<50; i++){
        scanf("%d", &v[i]);
    }
    InsertionSort(v);
    printf("Números em ordem ascendente:\n");
    for(int i=0; i<50; i++){
        printf("%d\t", v[i]);
    }
    return 0;
}
