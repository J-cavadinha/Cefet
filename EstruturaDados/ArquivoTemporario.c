#include <iostream>

using namespace std;

struct no
{
	int info, hDir, hEsq;
	no *esq, *dir;	
};

typedef struct no * noPtr;

noPtr balancear(noPtr);
noPtr RSE(noPtr);
noPtr RSD(noPtr);
noPtr inserir(noPtr, int);
noPtr remover(noPtr, int);
noPtr atualizar(noPtr);
void listar(noPtr);
bool enderecoVazio(noPtr);
int menu();



main() {
	
    noPtr raiz = NULL;
	int opcao, valor;

	do {
		opcao = menu();

		switch(opcao) {
			case 1:
				cout << "\nDigite o elemento a ser inserido: ";
  		        cin >> valor;
				raiz = inserir(raiz, valor);
				break;
			case 2:
				if (enderecoVazio(raiz)) 
					cout << "\nArvore nao possui elementos" << endl;
				else {
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
    } while(opcao != 0);
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

bool enderecoVazio(noPtr p) {
    if (p == NULL)
        return true;
    else
        return false;
}

noPtr inserir(noPtr p, int valor) {
	
    if (enderecoVazio(p)) 
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
        if (valor < p->info) 
 		{
 			p->esq = inserir(p->esq, valor);
			if (p->esq->hDir > p->esq->hEsq)
				p->hEsq = p->esq->hDir + 1;
			else 
				p->hEsq = p->esq->hEsq + 1;
		}
        else 
        {
            p->dir = inserir(p->dir, valor);
            if (p->dir->hDir > p->dir->hEsq)
				p->hDir = p->dir->hDir + 1;
			else 
				p->hDir = p->dir->hEsq + 1;
		}
		p = balancear(p);    
    }
    return p;
}

noPtr remover(noPtr aux, int x){
    noPtr p, p2;
   	if (x == aux->info)
    {
    	if (aux->esq == aux->dir)
    	{
    		delete(aux);
    		return NULL;
       	}
       	if (enderecoVazio(aux->esq))
       	{
           	p = aux->dir;
           	delete(aux);
           	return p;
       	} else
		    if (enderecoVazio(aux->dir))
		    {
               	p = aux->esq;
               	delete (aux);
               	return p;
            } else
            {
               	p2 = aux->dir;
               	p = aux->dir;
               	while(!enderecoVazio(p->esq))
               		p = p->esq;
               	p->esq = aux->esq;
               	return p2;
            }
    }
    else
       	if (x < aux->info)
           	aux->esq = remover(aux->esq, x);
       	else
       		aux->dir = remover(aux->dir, x);
    return aux;
} 

noPtr balancear(noPtr p)
{
	int fb, df;
	
	fb = p->hDir - p->hEsq;
	
	if (fb == 2)
	{
		df =  p->dir->hDir - p->dir->hEsq;
		if (df >= 0)
			p = RSE(p);
		else
		{
			p->dir = RSD(p->dir);
			p = RSE(p);
		}
	}
	else 
		if (fb == -2)
		{
			df =  p->esq->hDir - p->esq->hEsq;
			if (df <= 0)
				p = RSD(p);
			else
			{
				p->esq = RSE(p->esq);
				p = RSD(p);
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
	else
		if (p->dir->hEsq > p->dir->hDir)
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
	else
		if (p->esq->hEsq > p->esq->hDir)
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
		else
			if (p->esq->hEsq > p->esq->hDir)
				p->hEsq = p->esq->hEsq + 1;
        	else 
        		p->hEsq = p->esq->hDir + 1;
        
        p->dir = atualizar(p->dir);
		if (enderecoVazio(p->dir))
			p->hDir = 0;
		else
			if (p->dir->hEsq > p->dir->hDir)
				p->hDir = p->dir->hEsq + 1;
        	else 
        		p->hDir = p->dir->hDir + 1;
		p = balancear(p);    
    }
    return p;
}

void listar(noPtr p) {
    if (!enderecoVazio(p))
	{
        cout << p->info << "\t";
	    listar(p->esq);
        listar(p->dir);
    }
}

