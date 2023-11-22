#include <iostream>
using namespace std;

struct no
{
    int info, hDir, hEsq;
    no *esq, *dir;
};

typedef struct no *noPtr;

noPtr balancear(noPtr);
noPtr RSE(noPtr);
noPtr RSD(noPtr);
noPtr inserir(noPtr, int);
noPtr remover(noPtr, int);
noPtr atualizar(noPtr);
void listar(noPtr);
bool enderecoVazio(noPtr);
int menu();

int main()
{

    noPtr raiz = NULL;
    int opcao, valor;

    do
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            cout << "\nDigite o elemento a ser inserido: ";
            cin >> valor;
            raiz = inserir(raiz, valor);
            break;
        case 2:
            if (enderecoVazio(raiz))
                cout << "\nArvore nao possui elementos" << endl;
            else
            {
                cout << "\nDigite o elemento a ser removido: ";
                cin >> valor;
                raiz = remover(raiz, valor);
                raiz = atualizar(raiz);
            }
            break;
        case 3:
            listar(raiz);
            break;
        }
    } while (opcao != 0);
    return 0;
}

int menu()
{
    int op;
    cout << "\n\n\n---- Menu Principal ----\n\n"
            "\n1.Inserir no na arvore"
            "\n2.Remover no na arvore"
            "\n3.Listar todos os nos da arvore"
            "\n0.Sair"
            "\nDigite uma opcao: ";
    cin >> op;
    return op;
}

bool enderecoVazio(noPtr p)
{
    if (p == NULL)
        return true;
    else
        return false;
}

noPtr inserir(noPtr p, int valor)
{

    if (!p)
    {
        noPtr novo = new no;
        novo->info = valor;
        novo->hDir = 0;
        novo->hEsq = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        p = novo;
    }
    else
    {
        if (valor < p->info) // if valor a ser inserido < valor de p
        {
            p->esq = inserir(p->esq, valor);
            // Atualiza a altura de p
            if (p->esq->hDir > p->esq->hEsq) // Caso FB for negativo
                p->hEsq = p->esq->hDir + 1;  // Altura do filho esquerdo de p = altura do filho
                                             // direito do filho esquerda de p + 1
            else
                p->hEsq = p->esq->hEsq + 1; // Caso FB seja positivo
                                            // Altura do filho esquerdo de p = altura do filho esquerdo
                                            // do filho esquerdo de p + 1
        }
        else
        {
            p->dir = inserir(p->dir, valor);
            // Atualiza a altura de p
            if (p->dir->hDir > p->dir->hEsq) // Caso FB for negativo
                p->hDir = p->dir->hDir + 1;  // Altura do filho da direita de p = altura do filho direito
                                             // do filho direito de p + 1
            else
                p->hDir = p->dir->hEsq + 1; // Caso FB seja positivo
                                            // Altura do filho da direita de p = altura do filho esquerdo
                                            // do filho direito de p
        }
        p = balancear(p);
    }
    return p;
}

noPtr remover(noPtr aux, int x)
{
    noPtr p, p2;
    if (x == aux->info) // O valor a ser removido é igual ao nó?
    {
        if (aux->esq == aux->dir) // Se o nó não tiver filhos
        {
            delete (aux); // Apenas deleta o nó
            return NULL;
        }
        if (enderecoVazio(aux->esq)) // Se não existir nó na esquerda:
        {
            p = aux->dir; // Agora p aponta diretamente para o filho direito do nó a ser removido
            delete (aux); // Nó é deletado
            return p;     // Esse ponteiro vai ser atribuido ao pai do nó removido
        }
        else if (enderecoVazio(aux->dir)) // Se existir filho esquerdo, mas não existir filho direito:
        {
            p = aux->esq; // p aponta para o filho esquerdo do nó a ser removido
            delete (aux); // Nó é deletado
            return p;     // p é atribuido ao pai do nó que foi removido
        }
        else // Se existirem dois filhos:
        {
            p2 = aux->dir;
            p = aux->dir;
            while (!enderecoVazio(p->esq)) // p percorre toda a subárvore direita até encontrar o menor nó
                p = p->esq;
            p->esq = aux->esq; // p->esq aponta para o filho direto do nó a ser removido
            return p2;         // p2 retorna para ser atribuido ao pai do nó removido
        }
    }
    else if (x < aux->info)              // Caso o valor a ser removido não seja igual ao nó atual
        aux->esq = remover(aux->esq, x); // Se for menor que o nó atual, recursão com o filho esquerdo
    else
        aux->dir = remover(aux->dir, x); // Se for maior, recursão com o filho direito
    return aux;
}

noPtr balancear(noPtr p)
{
    int fator_balanceamento, df;

    fator_balanceamento = p->hDir - p->hEsq;

    if (fator_balanceamento == 2)
    {
        df = p->dir->hEsq - p->dir->hDir;
        if (df >= 0)
            p = RSD(p);
        else
        {
            p->dir = RSE(p->dir);
            p = RSD(p);
        }
    }
    else if (fator_balanceamento == -2)
    {
        df = p->esq->hEsq - p->esq->hDir;
        if (df >= 0)
        { // RSD + RSE
            p->esq = RSD(p->esq);
            p = RSE(p);
        }
        else
        {
            p = RSE(p);
        }
    }
    return p;
}

noPtr RSE(noPtr p)
{
    noPtr aux1, aux2;
    aux1 = p->dir;
    aux2 = aux1->esq;
    p->dir = aux2;
    aux1->esq = p;

    if (enderecoVazio(p->dir))
        p->hDir = 0;
    else if (p->dir->hEsq > p->dir->hDir)
        p->hDir = p->dir->hEsq + 1;
    else
        p->hDir = p->dir->hDir + 1;

    if (aux1->esq->hEsq > aux1->esq->hDir)
        aux1->hEsq = aux1->esq->hEsq + 1;
    else
        aux1->hEsq = aux1->esq->hDir + 1;
    return aux1;
}

noPtr RSD(noPtr p)
{
    noPtr aux1, aux2;
    aux1 = p->esq;
    aux2 = aux1->dir;
    p->esq = aux2;
    aux1->dir = p;

    if (enderecoVazio(p->esq))
        p->hEsq = 0;
    else if (p->esq->hEsq > p->esq->hDir)
        p->hEsq = p->esq->hEsq + 1;
    else
        p->hEsq = p->esq->hDir + 1;

    if (aux1->dir->hEsq > aux1->dir->hDir)
        aux1->hDir = aux1->dir->hEsq + 1;
    else
        aux1->hDir = aux1->dir->hDir + 1;
    return aux1;
}

noPtr atualizar(noPtr p)
{
    if (!enderecoVazio(p))
    {
        p->esq = atualizar(p->esq);
        if (enderecoVazio(p->esq))
            p->hEsq = 0;
        else if (p->esq->hEsq > p->esq->hDir)
            p->hEsq = p->esq->hEsq + 1;
        else
            p->hEsq = p->esq->hDir + 1;

        p->dir = atualizar(p->dir);
        if (enderecoVazio(p->dir))
            p->hDir = 0;
        else if (p->dir->hEsq > p->dir->hDir)
            p->hDir = p->dir->hEsq + 1;
        else
            p->hDir = p->dir->hDir + 1;
        p = balancear(p);
    }
    return p;
}

void listar(noPtr p)
{
    if (!enderecoVazio(p))
    {
        cout << p->info << "\t";
        listar(p->esq);
        listar(p->dir);
    }
}
