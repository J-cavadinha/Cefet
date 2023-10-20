#include <iostream>
#include <cstring>
#include <string>
using namespace std;

struct no{
    char telefone[3];
    string nome_contato;
    struct no *prox;
};
typedef struct no *noPtr;
noPtr inicio = NULL;


void adc_contato();
int retirar_contato();
bool listavazia();
bool contatodup(char numero[]);
int chamada();
void encerra();
void menu(int op);


int main(){
    int op;
    do{
    cout << "1 - Adicionar contato\t 2 - Retirar contato\t 3 - Realizar uma chamada\t 0 - Encerrar o programa: ";
    cin >> op;
    menu(op);
    }
    while(op!=0);
    encerra();
    return 0;
} 

void adc_contato(){
    noPtr aux, p = new no;
    cout << "Digite o número que deseja salvar: ";
    cin >> p->telefone;
    while(contatodup(p->telefone)){
        cout << "Já existe um contato com esse número, tente novamente: ";
        cin >> p->telefone;
        cout << endl;
    }
    cout << "Nome: ";
    cin.ignore();
    getline(cin, p->nome_contato);
    p->prox = NULL;

    if(listavazia()){
        inicio = p;
    }
    else{
        aux = inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = p;
    }
    cout << "Contato adicionado !" << endl;
}

int retirar_contato(){
    noPtr roll = inicio;
    noPtr pre_roll = NULL;
    char tchaunum[3];
    cout << "Qual o número que deseja retirar? ";
    cin >> tchaunum;
    while(roll!=NULL){
        if(strcmp(tchaunum, roll->telefone) == 0){
            if(pre_roll == NULL){
                inicio = roll->prox;
            }
            else{
                pre_roll->prox = roll->prox;
            }
            delete(roll);
            cout << "Contato retirado.";
            return 0;
        }
        pre_roll = roll;
        roll = roll->prox;
    }
    cout << "Contato não encontrado." << endl;
    return 0;
}

bool listavazia(){
    return inicio == NULL;
}

bool contatodup(char numero[]){
    noPtr roll = inicio;
    while(roll!=NULL){
        if(strcmp(numero, roll->telefone) == 0){
            return true;
        }
    roll = roll->prox;
    }
    return false;
}

int chamada(){
    noPtr roll = inicio;
    string ligacao;
    cout << "Digite o nome do contato que deseja chamar? ";
    cin >> ligacao;
    while(roll!=NULL){
        if(ligacao == roll->nome_contato){
            cout << "Efetuando chamada !" << endl;
            return 0;
        }
        else{
            roll = roll->prox;
        }
    }
    cout << "Contato não encontrado." << endl;
    return 0;
}

void menu(int op){
    switch(op){
        case 0: encerra(); break;
        case 1: adc_contato(); break;
        case 2: retirar_contato(); break;
        case 3: chamada(); break;
        default: cout << "Dígito errado.";
    }
}

void encerra(){
    noPtr temp;
    while(inicio!=NULL){
        temp = inicio;
        inicio = inicio->prox;
        delete(temp);
    }
}