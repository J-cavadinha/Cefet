#include <iostream>
#define T 10
using namespace std;

// Declaração de funções
void heapsort(int A[] , int n);
void heap(int *, int);
void descer(int *, int, int);
void troca(int *, int *);

int main(){
    int A[T] = {50, 2, 75, 8, 10, 6, 15, 4, 9, 3};
    int i;
    
    heapsort(A, T);
    for(int i=0; i<T; i++){
        cout << " " << A[i];
    }
    return 0;
}

void heapsort(int A[], int n){
    int i;

    heap(A,T);

    for(i = n-1; i>=1; i--){
        troca(&A[0], &A[i]);
        descer(A, 0, i-1);
    }
}

void heap(int A[], int t){
    for(int i = (t/2); i>=0; i--){
        descer(A, i, t-1);
    }
}

void descer(int A[], int i, int q){
    int dir = 2*i +2;
    int esq = 2*i +1;
    int maior = i;

    if(dir <= q && A[dir]>A[i]){
        maior = dir;
    }
    if(esq <= q && A[esq] > A[maior]){
        maior = esq;
    }
    if(maior != i){
        troca(&A[i], &A[maior]);
        descer(A, maior, q);
    }
}

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}