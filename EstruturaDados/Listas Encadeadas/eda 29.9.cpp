#include<iostream>
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

int main(){
	int op;
	do {
		op = menu();
		switch(op){
			case 1: inserir(); break;
			case 2: consultar(); break;
			default: cout << "Digito invalido.\n";
		}
	}while(op!=0);
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
				  /*  << "Digite 1 para retirar e qualquer número para sair: ";
				cin >> x2;
				switch(x2){
					case 1: 
				} */
				achei = true;
			}
			else if(!achei) cout << "Elemento não encontrado"; 
			else cout << "Lista vazia\n";
			p = p->prox;
		}
} }

int menu(){
	int x;
	cout << "1 - Inserir\t 2 - Consultar \t 3 - Encerrar: ";
	cin >> x;
	return x;
}
