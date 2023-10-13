#include <iostream>
#include <cstring>
using namespace std;

struct no{
    char nome_cidade[20];
    char nome_prefeito[20];
    int qtdhabitantes;
    struct no * prox;
};
typedef struct no * noPtr;
noPtr inicio = NULL;

int menu();
bool listavazia();
void novacidade();
void listagem();
int excluircidade();


int main(){
    int op;
    do{
        op = menu();
        switch(op){
            // case 0: limpalista(); return 0;
            case 1: novacidade(); break;
            case 2: excluircidade(); break;
            
            // case 3: listaprefeitos(); break;
            // case 4: listacidadesgrandes(); break;
            default: cout << "Dígito inválido" << endl;
        }
    } while(op!=0); 
}

int menu(){
    int op;
    cout << "1 - Nova cidade\t 2 - Excluir cidade\t 3 - Lista de prefeitos\t 4 - Lista cidades grandes\t 0 - Encerrar: ";
    cin >> op;
    return op;
}

void novacidade(){
    noPtr aux, p = new no;

	cout << "Digite o nome da cidade: ";
	cin >> p->nome_cidade;
    cout << "Digite o nome do prefeito: ";
    cin >> p->nome_prefeito;
    cout << "Digite a quantidade de habitantes: ";
    cin >> p->qtdhabitantes;

	p->prox = NULL;

	if(listavazia()) inicio = p;
	else{
		aux = inicio;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = p;
	}
	cout << "Cidade adicionada a lista!!!" << endl;
    
}

bool listavazia(){
    return inicio == NULL;
}

int excluircidade(){
    char tchaucidade[20];
    listagem();
    cout << "Digite o nome da cidade que deseja retirar: ";
    cin >> tchaucidade;

    noPtr roll = inicio;
    noPtr pre_roll = NULL;

    while(roll!=NULL){
        if(strcmp(roll->nome_cidade, tchaucidade)==0){
            if(pre_roll==NULL){
                inicio = roll->prox;
            }
            else{
                pre_roll->prox = roll->prox;
            }
            delete(roll);
            cout << "Cidade retirada!" << endl;
            return 0;
        }
        pre_roll = roll;
        roll = roll->prox;
    }
    cout << "Cidade não encontrada :(" << endl;
    return 0;
}

void listagem(){
    if(listavazia()) cout << "Lista vazia :(";
    else{
        noPtr roll = inicio;
        cout << "Lista: ";
        while(roll!=NULL){
            cout << roll->nome_cidade << roll->nome_prefeito << roll->qtdhabitantes << " \t";
            roll=roll->prox;
        }
        cout << endl;
    }
}