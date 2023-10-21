// Lista básica duplamente encadeada
// Funções básicas (a de retirar retira o primeiro elemento)
#include <iostream>
using namespace std;

struct no{
    int info;
    struct no * ant;
    struct no * prox;
};
typedef struct no * noPtr;

void inserir(noPtr *);
void retirar(noPtr *);
void listar(noPtr);
bool listavazia(noPtr);

int main(){
    noPtr inicio = NULL;
    int op;

    do{
        cout << "1 - Inserir\t 2 - Retirar(o primeiro)\t 3 - Listar: ";
        cin >> op;
        switch(op){
            case 1: inserir(&inicio); break;
            case 2: retirar(&inicio); break;
            case 3: listar(inicio); break;
            default: cout << "Dígito errado.";
        }
    } while(op!=0);
}

void inserir(noPtr * i){
    noPtr p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p->info;
    
    p->ant=NULL;

    if(listavazia(*i)){
        p->prox = NULL;
    }
    else{
        p->prox = *i;
        (*i)->ant = p;
    }
    *i = p;
}

void retirar(noPtr *i){
    noPtr p = *i;

    if(!listavazia(*i)){
        if(p->prox == NULL) *i = NULL;
        else{
            *i = p->prox;
            (*i)->ant = NULL;
        }
        delete(p);
        cout << "O elemento foi retirado da lista" << endl;
    }
    else cout << "Lista vazia !" << endl;
}

void listar(noPtr p){
    if(!listavazia(p)){
        cout << "Lista: ";
        cout << "INICIO";
        while(p != NULL){
            cout << " -> " << p->info;
            p=p->prox;
        }
        cout << " -> NULL" << endl;
    }
    else cout << "\nLista vazia !";
}

bool listavazia(noPtr roll){
    return roll == NULL;
}