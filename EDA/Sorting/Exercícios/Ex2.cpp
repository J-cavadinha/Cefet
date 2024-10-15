/* Exercício 2 - Slide de Ordenação 1*/

#include<stdio.h>

struct func{
    int matricula[14];
    float salario[14]; 
};
typedef struct func Tfunc;

void InsertionSort(Tfunc func){
    for(int i=0; i<15; i++){
        int aux = func.salario[i];
        int j = i - 1;
        while(aux > func.salario[j] && j>=0){
            func.salario[j+1] = func.salario[j];
            --j;
        }
        func.salario[j+1] = aux;
    }
}

void somasal(Tfunc func, int qtd){
    float soma = 0.0;
    for(int i=0; i<qtd; i++){
        soma += func.salario[i];
    }
    return soma;
}

int main(){
    InsertionSort(func);
    
    somasal(func, 15);
    printf("Soma salários: %.2f", soma);
}
