// Lista encadeada em ordem - um elemento é inserido na posição tal qual a lista continue em ordem.
// Implemenar funções de visualização crescente e decrescente
#include <iostream>
using namespace std;

struct no
{
	int info;
	struct no *prox;
};
typedef struct no *noPtr;

noPtr inicio = NULL;
noPtr fim = NULL; 
int counter = 0;

void inserir();
int menu();
int consultar();
int retirar();
void leitura();
void limparlista();
bool listavazia();
void visualizacao_decres();

int main()
{
	int op;
	do
	{
		op = menu();
		switch (op)
		{
		case 0:
			limparlista(); 
			return 0;
		case 1:
			inserir();
			break;
		case 2:
			consultar();
			break;
		case 3:
			retirar();
			break;
		case 4:
			visualizacao_decres();
			break;
		default:
			cout << "Dígito inválido" << endl;
		}
	} while (op != 0);
}

void inserir() // O(n)
{
	noPtr aux, ant, p = new no;

	cout << "Digite o valor do elemento: ";
	cin >> p->info;

	if (listavazia())
	{
		p->prox = inicio;
		inicio = p;
		counter++;
	}
	else
	{
		aux = inicio;
		while (aux != NULL && p->info > aux->info)
		{
			ant = aux;
			aux = aux->prox;
		}
		if (aux == inicio)
		{
			p->prox = aux;
			inicio = p;
			counter++;
		}
		else
		{
			p->prox = aux;
			ant->prox = p;
			counter++;
		}
	}
}

int consultar() // O(n)
{
	noPtr p = inicio;
	int x;
	bool achei = false;
	if (listavazia()) cout << "Lista vazia!";
	else
	{
		cout << "Digite o elemento a ser procurado: ";
		cin >> x;
		while (p != NULL && achei == false)
		{
			if (p->info == x)
			{
				cout << "Elemento encontrado!" << endl;
				achei = true;
			}
			p = p->prox;
		}
		if (!achei) cout << "Elemento não encontrado" << endl;
	
	return 0;
	}
}

int menu() // O(1)
{
	int x;
	cout << "1 - Inserir\t 2 - Consultar \t 3 - Retirar \t 4 - Visualizar em decrescente\t 0 - Encerrar: ";
	cin >> x;
	return x;
}

int retirar() // O(n)
{ // Conectar o nó que vem antes de tchaunum ao nó que vem depois
	int tchaunum;
	leitura();
	cout << "Digite o elemento que deseja retirar: ";
	cin >> tchaunum;
	noPtr roll = inicio;
	noPtr pre_roll = NULL;
	while (roll != NULL)
	{
		if (roll->info == tchaunum)
		{
			if (pre_roll == NULL)
			{
				inicio = roll->prox;
			}
			else
				pre_roll->prox = roll->prox;
			delete (roll);
			cout << "Elemento retirado." << endl;
			counter--;
			return 0;
		}
		pre_roll = roll;
		roll = roll->prox;
	}
	cout << "Elemento não encontrado." << endl;
	return 0;
}

void leitura() // O(1)
{
	if (listavazia())
		cout << "Lista vazia!";
	else
	{
		noPtr roll = inicio;
		cout << "Lista: ";
		while (roll != NULL)
		{
			cout << roll->info << " ";
			roll = roll->prox;
		}
		cout << endl;
	}
}

void limparlista() { // O(n)
    noPtr temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        delete temp;
    }
}

bool listavazia(){ // O(n)
	return inicio == NULL;
}

void visualizacao_decres(){ // O(n)
	noPtr roll = inicio;
	int v[counter];

	if(listavazia()) cout << "Lista vazia" << endl;
	 else{
		for(int i=0; i<counter; i++){
			v[i] = roll->info;
			roll = roll->prox;
		}
	 }
	for(int j=counter-1; j>=0; j--){
		cout << v[j] << " ";
	}
	cout << endl;
}