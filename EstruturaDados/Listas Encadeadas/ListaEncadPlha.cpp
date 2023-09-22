/*  Código de uma Pilha (stack) - lista encadeada simples
	Last in First out - imagine uma pilha de pratos, o prato que foi colocado mais recente será o primeiro a ser retirado

	Funções: Push - cria um novo nó (valor e o endereço do próximo nó) no *topo* da lista
	Pop - remove o nó do topo da lista
*/
#include<iostream>
using namespace std;

struct no{
	int info;
	struct no * prox;
};
typedef struct no * noPtr;
noPtr topo= NULL;

void push();
void pop();
bool listaVazia();
void leituratopo();
void leituracompleta();

int main(){
	int op, op2;
	
	do{
		cout << "Digite 1 para adicionar, 2 para retirar, 3 para ver as opcoes de visualizacao: ";
		cin >> op;
		switch(op){
			case 1: push(); break;
			case 2: pop(); break;
			case 3:{
				cout << "Digite 4 para ver o topo da lista, 5 para ver a lista completa, Ou outro número para voltar: ";
				cin >> op2;
				switch(op2){
					case 4: leituratopo(); break;
					case 5: leituracompleta(); break;
					default: break;
				}
			} break;
			default: cout << "\nDígito inválido";
		}	
	} while(op!=0);
}

void push(){
	noPtr p;
	int valor;
	
	p = new no;
	cout << "Digite o valor do elemento: ";
	cin >> valor;
	p->info = valor;
	p->prox=topo;
	topo=p;
    cout << "O elemento" << valor << "foi adicionado a lista." << endl;
}

void pop(){
	noPtr p = topo;
	if(!listaVazia()){
		topo = topo->prox;
		delete(p);
		cout << "O elemento foi retirado da pilha." << endl;
	}
	else cout << "\nLista vazia!" << endl;
}

bool listaVazia(){ // Função para verificar se a lista tem elementos
	return topo == NULL;
}

void leituratopo(){
	if(!listaVazia()){
		cout << topo->info << "Elemento do topo da lista: %d\n";

	}
	else cout << "\nLista vazia!" << endl;
}

void leituracompleta(){
	if(listaVazia()){
		cout << "Lista vazia!";
	}
	else{
		noPtr roll = topo;
		cout << "Lista: ";
		while(roll != NULL){
			cout << roll->info << " ";
			roll = roll->prox;
		}
	cout << endl;
	}
}
