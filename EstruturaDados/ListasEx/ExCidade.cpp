#include <iostream>
#include <cstring>
using namespace std;

struct no
{
    char nome_cidade[20];
    char nome_prefeito[20];
    int qtdhabitantes;
    struct no *prox;
};
typedef struct no *noPtr;
noPtr inicio = NULL;
int qtdprefeitos;

int menu();
bool listavazia();
void novacidade();
void listagem();
int excluircidade();
void listaprefeitos();
void bubble(char v[][20]);
void listacidadesgrandes();
void limpalista();

int main()
{
    int op;
    do
    {
        op = menu();
        switch (op)
        {
        case 0:
            limpalista();
            return 0;
        case 1:
            novacidade();
            break;
        case 2:
            excluircidade();
            break;
        case 3:
            listaprefeitos();
            break;
        case 4:
            listacidadesgrandes();
            break;
        default:
            cout << "Dígito inválido" << endl;
        }
    } while (op != 0);
}

int menu()
{
    int op;
    cout << "1 - Nova cidade\t 2 - Excluir cidade\t 3 - Lista de prefeitos\t 4 - Lista cidades grandes\t 0 - Encerrar: ";
    cin >> op;
    return op;
}

void novacidade()
{
    noPtr aux, p = new no;

    cout << "Digite o nome da cidade: ";
    cin >> p->nome_cidade;
    cout << "Digite o nome do prefeito: ";
    cin >> p->nome_prefeito;
    cout << "Digite a quantidade de habitantes: ";
    cin >> p->qtdhabitantes;
    qtdprefeitos++;

    p->prox = NULL;

    if (listavazia())
        inicio = p;
    else
    {
        aux = inicio;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = p;
    }
    cout << "Cidade adicionada a lista!!!" << endl;
}

bool listavazia()
{
    return inicio == NULL;
}

int excluircidade()
{
    char tchaucidade[20];
    listagem();
    cout << "Digite o nome da cidade que deseja retirar: ";
    cin >> tchaucidade;

    noPtr roll = inicio;
    noPtr pre_roll = NULL;

    while (roll != NULL)
    {
        if (strcmp(roll->nome_cidade, tchaucidade) == 0)
        {
            if (pre_roll == NULL)
            {
                inicio = roll->prox;
            }
            else
            {
                pre_roll->prox = roll->prox;
            }
            delete (roll);
            cout << "Cidade retirada!" << endl;
            qtdprefeitos--;
            return 0;
        }
        pre_roll = roll;
        roll = roll->prox;
    }
    cout << "Cidade não encontrada :(" << endl;
    return 0;
}

void listagem()
{
    if (listavazia())
        cout << "Lista vazia :(";
    else
    {
        noPtr roll = inicio;
        cout << "Lista: ";
        while (roll != NULL)
        {
            cout << roll->nome_cidade << " ";
            roll = roll->prox;
        }
        cout << endl;
    }
}

void listaprefeitos()
{
    char nomeprefeitos[qtdprefeitos][20];
    if (listavazia())
        cout << "Lista vazia:(";
    else
    {
        noPtr roll = inicio;
        for (int i = 0; i < qtdprefeitos; i++)
        {
            strcpy(nomeprefeitos[i], roll->nome_prefeito);
            roll = roll->prox;
        }
    }
    bubble(nomeprefeitos);
    for (int j = 0; j < qtdprefeitos; j++)
    {
        cout << nomeprefeitos[j] << " " << endl;
    }
}

void bubble(char v[][20])
{
    for (int i = 0; i < qtdprefeitos - 1; i++)
    { // O(n)
        for (int j = 0; j < qtdprefeitos - 1; j++)
        { // O(n)
            if (strcmp(v[j], v[j + 1]) > 0)
            { // O(1)
                char aux[20];
                strcpy(aux, v[j]);
                strcpy(v[j], v[j + 1]);
                strcpy(v[j + 1], aux);
            }
        }
    }
}

void listacidadesgrandes()
{
    noPtr roll = inicio;
    while (roll != NULL)
    {
        if (roll->qtdhabitantes > 150000)
        {
            cout << roll->nome_cidade << endl;
        }
        roll = roll->prox;
    }
}

void limpalista()
{
    noPtr temp;
    while (inicio != NULL)
    {
        temp = inicio;
        inicio = inicio->prox;
        delete temp;
    }
}
