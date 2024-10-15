#include <iostream>
using namespace std;

struct no{
	int info;
	struct no * prox;
};
typedef struct no * noPtr;
noPtr topo = NULL;

void enqueue();
void dequeue();
bool listaVazia();
void leituralista();
void comprimentolista();

int main(){
	int op;
	
	do{
		cout << "Escolha 1-Enqueue\t2-Dequeue\t3-Visualização\t4-Comprimento: ";
		cin >> op;
		switch(op){
			case 1: enqueue(); break;
			case 2: dequeue(); break;
			case 3: leituralista(); break;
			case 4: comprimentolista(); break;
			default: cout << "\nDígito inválido";
		}
	} while(op!=0);
}

void enqueue(){
	noPtr aux, p = new no;
	cout << "Digite o valor do elemento: ";
	cin >> p->info;
	p->prox = NULL;
	if(listaVazia()) topo = p;
	else{
		aux = topo;
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = p;
	}
	cout << "Elemento adicionado a lista\n";
}

void dequeue(){
	noPtr p;
	if(listaVazia()) cout <<"\nFila Vazia!";
	else{
		p = topo;
		topo = p -> prox;
		delete p;
		cout << "O elemento foi retirado da fila!\n";
	}
}

bool listaVazia(){
	return topo == NULL;
}

void leituralista(){
	if(listaVazia()) cout << "Lista Vazia!\n";
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

/* Lista de Exercícios */
// 1
void comprimentolista(){
	int count = 0;
	noPtr roll = topo;
	while(roll != NULL){
			count += 1;
			roll = roll->prox;
		}
	cout << count << " \n";
}

// 2
