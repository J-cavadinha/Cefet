// Lista básica duplamente encadeada
// Funções básicas
// Função Inserir foi modificada para que a lista fique na ordem crescente devido a questão 1) c.
// if(*i) --> Se um ponteiro for NULL, ele é "falso" em C++, logo if(*i) verifica se o ponteiro
// tem algum valor (verdadeiro) ou se é NULL (falso)

#include <iostream>
using namespace std;

struct no
{
    int info;
    struct no *ant;
    struct no *prox;
};
typedef struct no *noPtr;
int qtdnos = 0;

void inserir_ordem(noPtr *, noPtr *);
void retirar(noPtr *, noPtr *);
void listar(noPtr);
bool listavazia(noPtr);
int retirada_especifica(noPtr *, noPtr *);
void modifica_final(noPtr *);
void encerrar(noPtr *);
void listar_ao_contrario(noPtr *, noPtr *);

// Main com menu integrado
int main()
{
    noPtr inicio = NULL;
    noPtr final = NULL;
    int op;

    do
    {
        cout << "1 - Inserir(crescente)\t 2 - Retirar(o primeiro)\t 3 - Listar\t 4 - Retirar um elemento" << endl;
        cout << "5 - Modificar o final\t 6 - Listar descrescente\t 0 - Encerrar: ";
        cin >> op;
        switch (op)
        {
        case 0:
            encerrar(&inicio);
            break;
        case 1:
            inserir_ordem(&inicio, &final);
            break;
        case 2:
            retirar(&inicio, &final);
            break;
        case 3:
            listar(inicio);
            break;
        case 4:
            retirada_especifica(&inicio, &final);
            break;
        case 5:
            modifica_final(&final);
            break;
        case 6:
            listar_ao_contrario(&inicio, &final);
            break;
        default:
            cout << "Dígito errado." << endl;
        }
    } while (op != 0);
}

// Faz a inserção de elementos na lista de forma ordenada (crescente)
void inserir_ordem(noPtr *i, noPtr *finalP)
{
    noPtr aux, ant = NULL, p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p->info;

    p->ant = NULL;
    p->prox = NULL;

    if (!(*i))
    { // Lista vazia
        *i = p;
        *finalP = p;
    }
    else
    {
        aux = *i;
        while (aux && p->info > aux->info)
        {
            ant = aux;
            aux = aux->prox;
        }
        if (!ant)
        { // Quando não tem antecessor, é o começo
            p->prox = *i;
            (*i)->ant = p;
            *i = p;
        }
        else
        { // Caso geral
            p->ant = ant;
            p->prox = aux;
            ant->prox = p;
            if (aux)
            {
                aux->ant = p;
            }
            else
            {
                *finalP = p; // Se aux é NULL, então p é o último nó
            }
        }
    }
    cout << "Elemento adicionado!" << endl;
}

//
void retirar(noPtr *i, noPtr *finalP)
{
    if (*i)
    {
        noPtr p = *i;
        *i = (*i)->prox;
        if (*i)
        {
            (*i)->ant = NULL;
        }
        else
        {
            *finalP = NULL;
        }
        delete (p);
        cout << "O elemento foi retirado da lista" << endl;
    }
    else
    {
        cout << "Lista vazia !" << endl;
    }
}

void listar(noPtr p)
{
    if (p)
    {
        cout << "Lista: ";
        while (p)
        {
            cout << " " << p->info;
            p = p->prox;
        }
        cout << endl;
    }
    else
        cout << "\nLista vazia !";
}

bool listavazia(noPtr roll)
{
    return !roll;
}

// Função que busca determinado elemento na lista e o retira, caso não seja encontrado, exiba uma msg
int retirada_especifica(noPtr *inicioP, noPtr *finalP)
{
    int valor;

    cout << "Digite o elemento que deseja retirar: ";
    cin >> valor;

    noPtr roll = *inicioP, pre_roll = NULL;

    while (roll && roll->info != valor)
    {
        pre_roll = roll;
        roll = roll->prox;
    }
    if (!roll)
    {
        cout << "Elemento não encontrado." << endl;
        return -1;
    }
    if (pre_roll)
    {
        pre_roll->prox = roll->prox;
        if (roll->prox)
        {
            roll->prox->ant = pre_roll;
        }
        else
        {
            *finalP = roll;
        }
    }
    else
    {
        *inicioP = roll->prox;
        if (roll->prox)
        {
            roll->prox->ant = NULL;
        }
        else
        {
            *finalP = NULL;
        }
    }
    delete (roll);
    cout << "Valor removido!" << endl;
    return 0;
}

// Função para inserir ou retirar do final da lista O(1)
void modifica_final(noPtr *finalP)
{
    int op;
    cout << "1 - Inserir (final)\t 2 - Retirar (final)\t 0 - Voltar: ";
    cin >> op;

    switch (op)
    {
    case 0:
    {
        break;
    }

    case 1:
    {
        // Código para inserir um elemento no final
        noPtr roll = new no;
        cout << "Digite o valor do elemento: ";
        cin >> roll->info;

        roll->ant = *finalP;
        roll->prox = NULL;

        if (*finalP)
            (*finalP)->prox = roll;
        *finalP = roll;
        cout << "Elemendo adicionado !" << endl;
        break;
    }

    case 2:
    {
        // Código para retirar um elemento no final
        if (*finalP)
        {
            noPtr roll = *finalP;
            *finalP = roll->ant;
            if (*finalP)
            {
                (*finalP)->prox = NULL;
            }
            delete (roll);
            cout << "Elemento retirado!" << endl;
        }
        else
        {
            cout << "Lista Vazia!" << endl;
        }
        break;
    }
    default:
    {
        break;
    }
    }
}

// Encerra o programa
void encerrar(noPtr *inicioP)
{
    while (*inicioP)
    {
        noPtr roll = *inicioP;
        *inicioP = (*inicioP)->prox;
        delete (roll);
    }
}

// Mostra os elementos da lista começando do final, indo até o início
void listar_ao_contrario(noPtr *inicioP, noPtr *finalP)
{
    noPtr roll = *finalP;
    while (roll)
    {
        cout << roll->info << " ";
        roll = roll->ant;
    }
    cout << endl;
}

/* Função inserir padrão

void inserir(noPtr *i, noPtr *finalP)
{
    noPtr p = new no;
    cout << "Digite o valor do elemento: ";
    cin >> p->info;

    p->ant = NULL;
    p->prox = NULL;

    if (listavazia(*i))
    {
        *i = p;
        qtdnos++;
    }
    else
    {
        (*finalP)->prox = p;
        p->ant = *finalP;
        qtdnos++;
    }

    *finalP = p;
    cout << "Elemento adicionado!" << endl;
} */