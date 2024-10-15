#include <iostream>
using namespace std;

void subir(int, int);
void troca(int *, int *);
void descer(int, int, int);
void inserir(int A[], int, int *);
void remover(int A[], int *);
int mensagem(int);
void visualizar(int A[], int *);

int main(){
    int TAM = 10, op, num, A[TAM], tam_heap;
    tam_heap = 0;
    op = 0;

    do{
    cout << "1 - Inserir\t 2 - Remover\t 3 - Visualizar\t 0 - Sair: ";
    cin >> op;
    switch(op){
        case 1: 
            num = mensagem(1);
            inserir(A, num, &tam_heap);
            cout << "Elemento adicionado!" << endl;
            break;
        case 2:
            num = mensagem(-1);
            remover(A, &tam_heap);
            cout << "Elemento retirado!" << endl; 
            break;
        case 3:
            visualizar(A, &tam_heap);
            break;
        case 0:
            exit(0);
        default: cout << "Entrada inválida." << endl;
    }
    } while(op != 0);
    return 0;
}

void subir(int A[], int i){
    int j = i/2; // j = índice do "pai" do nó i

    if(j >= 0){ // Verifica se a posição é maior/igual a 0, afim de evitar erros

        if(A[i] > A[j]){
            troca(&A[i], &A[j]);
            subir(A, j);
        }
    }
}

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

void descer(int A[], int i, int qtd_elem){
    int dir = (i * 2) + 1;
    int esq = (i * 2);
    
    int maior = i;
    
    if(dir <= qtd_elem && A[dir] > A[i]){
        maior = dir;
    }
    if(esq <= qtd_elem && A[esq] > A[maior]){
        maior = esq;
    }
    if(maior != i){
        troca(&A[i], &A[maior]);
        descer(A, maior, qtd_elem);
    }
}

void inserir(int A[], int valor, int *t){
    *t = *t + 1;
    A[*t] = valor;
    subir(A, *t);
}

void remover(int A[], int *q){
    A[1] = A[*q];
    *q = *q -1;
    descer(A, 1, *q);
}

int mensagem(int i){
    int num;

    if(i > 0){
        cout << "Digite o número que deseja inserir: ";
        cin >> num;
    }
    else if(i < 0){
        cout << "Digite o número que deseja retirar: ";
        cin >> num;
    }
    return num;
}

void visualizar(int A[], int * tam_heap){
    for(int i = 1; i <= *tam_heap; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}