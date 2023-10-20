#include <iostream>
using namespace std;

struct no{
	int info;
	struct no * prox;
};
typedef struct no * noPtr;

noPtr inicio = NULL;
noPtr fim = NULL;

void inserir();
int menu();
void consultar();
void retirar();

int main(){
	int op;
	do {
		op = menu();
		switch(op){
			case 1: inserir(); break;
			case 2: consultar(); break;
			case 3: retirar(); break;
            case 4: return 0;
			default: cout << "Digito invalido.\n";
		}
	}while(op!=0);
    return 0;
}

void inserir(){
	noPtr aux, ant, p = new no;
	
	cout << "Digite o valor do elemento: ";
	cin >> p->info;
	
	if(inicio==NULL){
		p->prox = inicio;
		inicio = p;
	} else {
		aux = inicio;
		while(aux!= NULL && p->info > aux-> info){
			ant = aux;
			aux = aux->prox;
		}
	if(aux==inicio){
		p->prox = aux;
		inicio = p;
	} else { p->prox = aux; ant->prox = p;
		}
	}
}

void consultar(){
	noPtr p = inicio;
	int x, x2;
	bool achei = false;
	if(inicio != NULL){
		cout << "Digite o elemento a ser procurado: ";
		cin >> x;
		while(p!=NULL && achei==false){
			if(p->info==x){
				cout << "Elemento encontrado!\n";
				achei = true;
			} }
			if(!achei) cout << "Elemento não encontrado\n"; 
			else cout << "Lista vazia\n";
			p = p->prox;
		}
}

void retirar(){
    // Checa se há algum nó na fila, caso não: printa a msg e retorna
    if(inicio==NULL){ cout << "Lista Vazia!";
    return;  }

    // Declaração de variáveis da função
	noPtr p = inicio;
	noPtr previous = NULL;
	int valor;

    // Print dos valores da lista p ver qual deseja-se remover
    cout << "Lista atual: ";
	while(p!= NULL){
			cout << p->info << "\t";
			p = p->prox;
		} cout << endl;

	cout << "Digite o valor que deseja retirar: ";
	cin >> valor;

    p = inicio;
	while(p!=NULL && p->info != valor){
		previous=p;
		p=p->prox;
	}

	if(p==NULL){
        cout << "Valor inválido.";
        return;
    }

    if(previous == NULL){
        inicio = p->prox;
    } else{
        previous->prox = p->prox;
    } delete (p);

    p=inicio;
    cout << "Lista atual: ";
	while(p != NULL){
			cout << p->info << "\t";
			p = p->prox;
		} cout << endl;
}

int menu(){
	int x;
	cout << "1 - Inserir // 2 - Consultar // 3 - Retirar // 4 - Sair: ";
	cin >> x;
	return x;
}
