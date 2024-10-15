#include <iostream>
using namespace std;

struct no
{
    int info;
    struct no *esq, *dir;
};
typedef struct no *noPtr;

int menu();
int listarNos();
void inserir(noPtr *, int);
void remover(noPtr *, int);
bool busca(noPtr, int);
noPtr maior(noPtr *);
void listar_em_ordem(noPtr);
void listar_pre_ordem(noPtr);
void listar_pos_ordem(noPtr);

void inserir(noPtr *p, int x)
{
    if (!*p)
    {
        *p = new no;
        (*p)->info = x;
        (*p)->esq = NULL;
        (*p)->dir = NULL;
    }
    else
    {
        if (x < ((*p)->info))
            inserir(&((*p)->esq), x);
        else
            inserir(&((*p)->dir), x);
    }
}

/* Lógica função remover (recebe um nó e um elemento a ser removido)
    1o if -> Verifica se a lista não está vazia (Se p tiver valor é true, senão false)
    2o if -> Elemento buscado (x) == nó ?
        True:
                1. Tem filho na esquerda?
                    1.1 Sim -> 2.
                    1.2 Não -> nó direito vira pai -> remove o nó

                2. Tem filho na direita?
                    2.1 Sim -> função "maior(esquerda)" -> remove o nó
                    2.2 Não -> nó esquerdo vira pai -> remove o nó

        False:
                1. Elemento buscado < nó ?
                    1.1 Sim -> recursão mas passando o nó da esquerda em vez da raiz
                    1.2 Não -> recursão mas passando o nó da direita
*/
void remover(noPtr *p, int x)
{
    noPtr aux;
    if (p)
    {
        if (x == ((*p)->info))
        {
            aux = *p;
            if (((*p)->esq) == NULL)
            {
                *p = (*p)->dir;
                cout << "Elemento removido :)" << endl;
            }
            else
            {
                if (((*p)->dir) == NULL)
                {
                    *p = (*p)->esq;
                    cout << "Elemento removido :)" << endl;
                }
                else
                {
                    aux = maior(&((*p)->esq));
                    (*p)->info = aux->info;
                    cout << "Elemento removido :)" << endl;
                }
                // delete(aux);
            }
            delete (aux);
        }
        else
        {
            if ((x < ((*p)->info)))
            {
                remover(&((*p)->esq), x);
            }
            else
            {
                remover(&((*p)->dir), x);
            }
        }
    }
    else
    {
        cout << "A Árvore não possui elementos :p" << endl;
    }
}

noPtr maior(noPtr *p)
{ // Função tipo noPtr por causa do tipo de retorno
    noPtr t;
    t = *p;
    if ((t->dir) == NULL)
    {
        *p = (*p)->esq;
        return (t);
    }
    else
    {
        return (maior(&((*p)->dir)));
    }
}

/* Lógica função de busca (recebe um elemento a ser procurado e a raiz)
    1o if -> Verifica se o valor de p é diferente de true, se for, a árvore é vazia
    1o else -> Compara se a raiz é igual ao elemento a ser procurado
        True:
                1. Mensagem de elemento encontrado + elemento

        False:
                Compara se a raiz é maior que o elemento
                    True: recursividade com o elemento da esquerda da raiz como a raiz
                    False: recursividade com o elemento da direita da raiz como a raiz

    *** Ambos os if's internos assinalados servem para checar se o filho é null, caso True, retorna para evitar output "vazio"
*/
bool busca(noPtr p, int x)
{
    if (!p)
    {
        cout << "Árvore vazia :p" << endl;
        return false;
    }
    if (x == p->info)
    {
        cout << "Elemento encontrado :)"
             << " " << x << endl;
        return true;
    }
    else
    {
        if (x > p->info)
        {
            if (!(p->dir)) // ***
                return false;
            return busca(p->dir, x);
        }
        else
        {
            if (!(p->esq)) // ***
                return false;
            return busca(p->esq, x);
        }
    }
}

void listar_em_ordem(noPtr p)
{
    if (p)
    {
        listar_em_ordem(p->esq);
        cout << " " << p->info;
        listar_em_ordem(p->dir);
    }
}

void listar_pre_ordem(noPtr p)
{
    if (p)
    {
        cout << " " << p->info;
        listar_pre_ordem(p->esq);
        listar_pre_ordem(p->dir);
    }
}

void listar_pos_ordem(noPtr p)
{
    if (p)
    {
        listar_pos_ordem(p->esq);
        listar_pos_ordem(p->dir);
        cout << " " << p->info;
    }
}

int menu()
{
    int opcao;
    cout << "\n --- Menu Principal ---\n";
    cout << "\n1 - Inserir nó"
         << "\n2 - Remover nó"
         << "\n3 - Listar todos os nós"
         << "\n4 - Buscar nó"
         << "\n0 - Encerrar"
         << "\nDigite uma opção: ";
    cin >> opcao;
    return (opcao);
}

int listarNos()
{
    int opcao;
    cout << "\nTipos de exibição"
         << "\n1 - Em ordem"
         << "\n2 - Pré ordem"
         << "\n3 - Pós ordem"
         << "\nDigite a opção desejada: ";
    cin >> opcao;
    return (opcao);
}

void liberar_memoria(noPtr p)
{
    if (p != NULL)
    {
        liberar_memoria(p->esq);
        liberar_memoria(p->dir);
        delete (p);
    }
}

/* Função main
    1. Integração com menu usando switch case's
    2. Verificação do tipo de input do usuário
*/
int main()
{
    int op1, op2, x;
    noPtr raiz = NULL;

    do
    {
        op1 = menu();
        switch (op1)
        {
        case 1:
            cout << "\nElemento a inserir: ";
            if (cin >> x)
            {
                inserir(&raiz, x);
                cout << "Elemento adicionado :)" << endl;
                break;
            }
            else
            {
                cout << "Entrada inválida. Tente novamente :(" << endl;
                cin.clear();
                cin.ignore();
                break;
            }

        case 2:
            listar_em_ordem(raiz);
            if (!raiz)
            {
                cout << "Lista vazia :p" << endl;
                break;
            }
            else
            {
                cout << "\nElemento para remover: ";
                if (cin >> x)
                {
                    if (busca(raiz, x))
                    {
                        remover(&raiz, x);
                        listar_em_ordem(raiz);
                        break;
                    }
                    else
                    {
                        cout << "Dígito inválido :p" << endl;
                        break;
                    }
                }
                else
                {
                    cout << "Entrada inválida. Tente novamente :(" << endl;
                    cin.clear();
                    cin.ignore();
                    break;
                }
            }

        case 3: // Estrutura de if's mantida para evitar confusão
            op2 = listarNos();
            if (op2 == 1)
            {
                cout << "Lista de elementos: ";
                listar_em_ordem(raiz);
                cout << endl;
            }
            if (op2 == 2)
            {
                cout << "Lista de elementos: ";
                listar_pre_ordem(raiz);
                cout << endl;
            }
            if (op2 == 3)
            {
                cout << "Lista de elementos: ";
                listar_pos_ordem(raiz);
                cout << endl;
            }
            break;

        case 4:
            cout << "\nElemento a buscar: ";
            if (cin >> x)
            {
                if (!busca(raiz, x))
                    cout << "Elemento não encontrado :(" << endl;
                break;
            }
            else
            {
                cout << "Entrada inválida. Tente novamente :(" << endl;
                cin.clear();
                cin.ignore();
                break;
            }

        case 0:
            liberar_memoria(raiz);
            break;

        default:
            cout << "Opção inválida, tente novamente :p" << endl;
            cin.clear();
            cin.ignore();
        }

    } while (op1 != 0);
    return 0;
}