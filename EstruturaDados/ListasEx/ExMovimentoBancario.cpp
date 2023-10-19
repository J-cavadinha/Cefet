#include <iostream>
#include <string>
using namespace std;

struct no{
    int numero_conta;
    string nome_cliente;
    float saldo;
    struct no * prox;
};
typedef struct no *noPtr;
int qtdcliente = 0;
noPtr inicio = NULL;

void cadastro_cliente();
bool listavazia();
void operacao();
int deposito();
int retirada();
int visualizacao(float novosaldo);
int saldo(float novosaldo);
void encerrar();
bool contadup(int num_conta);

int main(){
    int op1;
    do{
    cout << "1 - Cadastro de cliente \t 2 - Operações \t 0 - Encerrar: ";
    cin >> op1;
    switch(op1){
        case 0: encerrar(); break;
        case 1: cadastro_cliente(); break;
        case 2: operacao(); break;
        default: cout << "Dígito inválido.";
        }
    }
    while(op1!=0);
}

void cadastro_cliente(){
    noPtr aux;
    noPtr p = new no;
    cout << "Digite o número da sua conta: ";
    cin >> p->numero_conta;
    while(contadup(p->numero_conta)){
        cout << "Conta já existente, tente novamente." << endl;
        cin >> p->numero_conta;
    }
    cout << "Digite o seu nome: ";
    cin.ignore();
    getline(cin, p->nome_cliente);
    cout << "Digite seu saldo: ";
    cin >> p->saldo;
    qtdcliente++;
    p->prox = NULL;

    if(listavazia()) inicio = p;
    else{
        aux = inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = p;
    }
    cout << "Cliente adicionado ao banco." << endl;
}

void operacao(){
    int op2;
    cout << "0 - Voltar\t 1 - Depósito\t 2 - Retirada: ";
    cin >> op2;
    switch(op2){
        case 0: break;
        case 1: deposito(); break;
        case 2: retirada(); break;
        default: cout << "Dígito inválido.";
    }
}

bool listavazia(){
    return inicio == NULL;
}

int deposito(){ // Acessar o nó do cliente pelo nome ou numero da conta, checar a operação e o valor em conta
    int num_conta, deposito;
    noPtr roll = inicio;
    cout << "Digite o número de sua conta: ";
    cin >> num_conta;
    while(roll!=NULL){
        if(num_conta == roll->numero_conta){
            cout << "Digite o valor que deseja depositar: ";
            cin >> deposito;
            roll->saldo += deposito;
            cout << "Depósito efetuado com sucesso. " << endl;
            visualizacao(roll->saldo);
            return 0;
        }
    }
    cout << "Conta não encontrada.";
    return 0;
}

int saldo(float novosaldo){
    cout << "Saldo: " << novosaldo << endl;
    return 0;
}

int retirada(){
    int num_conta, valor_retirada;
    cout << "Digite o número da sua conta: ";
    cin >> num_conta;
    noPtr roll = inicio;
    while(roll!=NULL){
        if(roll->numero_conta == num_conta){
            cout << "Digite quanto deseja retirar: ";
            cin >> valor_retirada;
            if(valor_retirada > roll->saldo){
                cout << "Saldo insuficiente :(" << endl;
            }
            else{
                roll->saldo -= valor_retirada;
                cout << "Retirada realizada com sucesso !" << endl;
                visualizacao(roll->saldo);
                return 0;
            }
        }
    }
    cout << "Conta não encontrada :(" << endl;
    return 0;
}

int visualizacao(float novosaldo){
    int opcao;
    cout << "Digite 1 para ver seu novo saldo ou 0 para voltar: ";
    cin >> opcao;
            switch(opcao){
                case 0: return 0;;
                case 1: saldo(novosaldo); break;
                default: cout << "Dígito inválido.\n";
            }
    return 0;
}

void encerrar(){
    noPtr temp;
    while (inicio != NULL)
    {
        temp = inicio;
        inicio = inicio->prox;
        delete temp;
    }
}

bool contadup(int num_conta){
    noPtr roll = inicio;
    while(roll!=NULL){
        if(roll->numero_conta == num_conta){
            return true;
        }
    roll = roll->prox;
    }
    return false;
}