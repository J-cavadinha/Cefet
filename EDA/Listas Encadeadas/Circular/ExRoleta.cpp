#include <iostream>
#include <random>
using namespace std;

struct no{
    int numero;
    struct no * prox;
};
typedef struct no * noPtr;

// Declaração de funções:
void roleta(noPtr *, int);
int jogada();
void casas(noPtr *);
int num_aleat();

int main(){
    int entrada;

    do{
    cout << "1 - Jogar ou Qualquer tecla para sair: ";
    cin >> entrada;
    noPtr inicio = NULL;
    casas(&inicio);
    int aposta = jogada();
    roleta(&inicio, aposta);
    } while(entrada == 1);
}

void roleta(noPtr *inicioP, int aposta){
    int num = num_aleat();

    float resultado;
    noPtr roll = *inicioP;
    resultado = (num) % 37;
    for(int i=0; i<resultado; i++){
        roll = roll->prox;
    }
    if(roll->numero == aposta) cout << "Você ganhou!!!!" << endl;
    else{
        cout << "Errou rude!" << endl;
        cout << "Sua aposta: " << aposta;
        cout << "\tRoleta: " << roll->numero << endl;
    }
}

// Função para ler a aposta do jogador
int jogada(){
    int aposta;
    do{
    cout << "Digite o valor que deseja jogar (0-36): ";
    cin >> aposta;
    } while(aposta < 0 || aposta > 36);
    return aposta;
}

// Função que cria 37 casas (0-36)
void casas(noPtr *inicioP){
    int num_casas = 37;
    noPtr finalP = NULL;

    for(int j=0; j<num_casas; j++){
        noPtr roll = new no;
        roll->numero = j;

        if(!*inicioP){
            *inicioP = roll;
        } else{
            finalP->prox = roll;
        }
        finalP = roll;
    }
    finalP->prox = *inicioP;
}

int num_aleat(){
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0,100);

    int random = dist(mt);
    return random;
}