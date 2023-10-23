#include <iostream>
using namespace std;

struct no{
    int info;
    struct no * prox;
};
typedef struct no * noPtr;


// Declaração de funções.
int inserir(noPtr *, noPtr *,  int *);
void retirar(noPtr *, noPtr *, int *);
void listar(noPtr, noPtr, int);
bool listavazia(noPtr);
void limpalista(noPtr *);

int main(){
    // Ponteiros apontando para o inicio e o fim.
    noPtr inicio = NULL;
    noPtr fim = NULL;

    int op, qtde = 0;
    
    do{
        cout << "1 - Inserir\t 2 - Retirar(topo)\t 3 - Listar\t 0 - Encerrar: ";
        cin >> op;
        switch(op){
            case 0: limpalista(&inicio); break;
            case 1: qtde = inserir(&inicio, &fim, &qtde);
            cout << "Elemento adicionado!" << endl; break;
            case 2: retirar(&inicio, &fim, &qtde); break;
            case 3: listar(inicio, fim, qtde); break;
        }
    } while(op!=0);
}

int inserir(noPtr * inicioP, noPtr * fimP, int * q){
    noPtr p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p->info;
    if(listavazia(*fimP)){
        p->prox = p;
        *inicioP = p;
        *fimP = p;
    }
    else{
        p->prox = *inicioP;
        (*fimP)->prox = p;
        *(fimP) = p;
    }
    *q = *q + 1;
    return *q;
}

void retirar(noPtr * inicioP, noPtr * fimP, int * q){
    noPtr p = *inicioP;
    if(!listavazia(*fimP)){
        if(*q == 1){
            *inicioP = NULL;
            *fimP = NULL;
        }
        else{
            *inicioP = p->prox;
            (*fimP)->prox = *inicioP;
        }
        delete(p);
        cout << "O elemento foi retirado da lista!" << endl;
        *q = *q -1;
    } else cout << "Lista vazia :(" << endl;
}

void listar(noPtr i, noPtr f, int q){
    if(!listavazia(f)){
        noPtr temp = i;
        do{
            cout << i->info << " ";
            i = i->prox;
        } while(i != temp);
        cout << endl;
        } else {
            cout << "\nLista vazia :(";
        }
}

bool listavazia(noPtr fimP){
    return fimP == NULL;
}

void limpalista(noPtr *inicio)
{
    noPtr temp;
    while (*inicio != NULL)
    {
        temp = *inicio;
        *inicio = temp->prox;
        delete temp;
    }
}
