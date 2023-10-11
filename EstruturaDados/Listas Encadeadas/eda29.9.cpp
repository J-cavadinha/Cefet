// Lista encadeada em ordem - um elemento é inserido na posição tal qual a lista continue em ordem.
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

void inserir();
int menu();
void consultar();
int retirar();
void leitura();
void limparlista();

int main()
{
	int op;
	do
	{
		op = menu();
		switch (op)
		{
		case 1:
			inserir();
			break;
		case 2:
			consultar();
			break;
		case 3:
			retirar();
			break;
		default: limparlista(); return 0;
		}
	} while (op != 0);
}

void inserir()
{
	noPtr aux, ant, p = new no;

	cout << "Digite o valor do elemento: ";
	cin >> p->info;

	if (inicio == NULL)
	{
		p->prox = inicio;
		inicio = p;
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
		}
		else
		{
			p->prox = aux;
			ant->prox = p;
		}
	}
}

void consultar()
{
	noPtr p = inicio;
	int x, x2;
	bool achei = false;
	if (inicio != NULL)
	{
		cout << "Digite o elemento a ser procurado: ";
		cin >> x;
		while (p != NULL && achei == false)
		{
			if (p->info == x)
			{
				cout << "Elemento encontrado!\n";
				achei = true;
			}
		}
		if (achei != true) cout << "Elemento não encontrado";
		else{
			cout << "Lista vazia\n";
			p = p->prox;
		}
	}
}


int menu()
{
	int x;
	cout << "1 - Inserir\t 2 - Consultar \t 3 - Retirar \t Qualquer tecla para encerrar: ";
	cin >> x;
	return x;
}

int retirar()
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
			cout << "Elemento retirado.";
			return 0;
		}
		pre_roll = roll;
		roll = roll->prox;
	}
	cout << "Elemento não encontrado.";
	return 0;
}

void leitura()
{
	if (inicio == NULL)
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
	}
}

void limparlista() {
    noPtr temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->prox;
        delete temp;
    }
}