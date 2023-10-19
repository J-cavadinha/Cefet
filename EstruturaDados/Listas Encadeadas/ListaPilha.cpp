/*  Código de uma Pilha (stack) - lista encadeada simples
	Last in First out - imagine uma pilha de pratos, o prato que foi colocado mais recente será o primeiro a ser retirado
*/
#include<iostream>
using namespace std;
struct no{
	int info;
	struct no * prox;
};
typedef struct no * noPtr;
noPtr inicio = NULL;
noPtr fim = NULL;
int sizenode=0;

void push(); // Adiciona um novo nó
void pop();  // Retira um nó (como é uma pilha, retira do fim)
void leituratopo(); // Printa o topo da pilha
void leituracompleta(); // Printa a lista completa
void contador(); // Printa o tamanho da lista

int main(){
	int op, op2;
	
	do{
		cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "Digite 1 para adicionar, 2 para retirar, 3 para ver as opcoes de visualizacao e 4 para ver a quantidade de elementos: " << endl;
		cin >> op;
		switch(op){
			case 1: push(); break;
			case 2: pop(); break;
			case 3:{
				cout << "Digite 4 para ver o topo da lista, 5 para ver a lista completa, ou outro número para voltar: ";
				cin >> op2;
				switch(op2){
					case 4: leituratopo(); break;
					case 5: leituracompleta(); break;
					default: break;
				}
			} break;
			case 4: contador(); break;
			default: cout << "\nDígito inválido";
		}	
	} while(op!=0);
}

void push(){
	noPtr p;
	int valor;
	
	p = new no;
	cout << "Digite o valor do elemento: "<< endl;
	cin >> valor;
	p->info = valor;
	p->prox=inicio;
	inicio=p;
	sizenode++;
    cout << "O elemento " << valor << " foi adicionado a lista." << endl;
}

void pop(){
	noPtr p = inicio;
	if(inicio != NULL){
		inicio = inicio->prox;
		cout << "O elemento "<< p->info << " foi retirado da lista." << endl;
		delete(p);
		sizenode--;
	}
	else cout << "Lista vazia!" << endl;
}

void leituratopo(){
	if(inicio != NULL){
		cout << "Elemento do topo da lista: " << inicio->info << endl;
	}
	else cout << "\nLista vazia!" << endl;
}

void leituracompleta(){
	if(inicio == NULL){
		cout << "Lista vazia!";
	}
	else{
		noPtr roll = inicio;
		cout << "Lista: ";
		while(roll != NULL){
			cout << roll->info << " ";
			roll = roll->prox;
		}
	cout << endl;
	}
}

void contador(){
	cout << sizenode << " elementos."<< endl;
}
