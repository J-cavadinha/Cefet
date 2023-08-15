//Lista 9 ex 5
#include<stdio.h>
#define TOT 20
struct produtos{
	int codigo_produto;
	char nome_produto[21];
	int qtd_estoque;
};
typedef struct produtos Tprod;

struct movimento{
	int codigo_produto;
	char tipo_operacao;			// s - solicitação, d - devolução
	int qtdmovida;			    // quantidade solicitada/devolvida
};
typedef struct movimento Tmov;

void  leDadosProdutos(Tprod produtos[]){
	int i;
	for(i=0; i<TOT; i++){
		printf("Digite o codigo do produto: ");
		scanf("%d", &produtos[i].codigo_produto);
		
		printf("Digite o nome do produto: ");
		scanf("%s", produtos[i].nome_produto);
		
		printf("Digite a quantidade em estoque: ");
		scanf("%d", &produtos[i].qtd_estoque);			
	}
}

void geraSaida(Tprod produtos[], Tmov movimento[]){
	int i, qtde_pendente, qtde_estoque;
	for(i=0; i<TOT; i++){
	int qtde_devolvida = qtde_pendente = qtde_estoque = 0;
	calculaop(produtos, movimento);
	
	printf("Produto: %s\t Codigo: %d\n", produtos[i].nome_produto, produtos[i].codigo_produto);
	printf("Qtd solicitada/devolvida: %d\n", movimento[i].qtdmovida);
	printf("Qtde pendente: %d\n Qtde final em estoque: %d\n", qtde_pendente, produtos[i].qtd_estoque);
	}
}

int calculaop(Tprod produtos[], Tmov movimento[]){
	int i, qtde_pendente;
	for(i=0; i<TOT; i++){
	if(movimento[i].tipo_operacao == 's'){
		if(produtos[i].qtd_estoque > movimento[i].qtdmovida)
		produtos[i].qtd_estoque = produtos[i].qtd_estoque - movimento[i].qtdmovida;
		else{
		qtde_pendente = movimento[i].qtdmovida - produtos[i].qtd_estoque;
		produtos[i].qtd_estoque = produtos[i].qtd_estoque - movimento[i].qtdmovida;
		}
	}
	else if(movimento[i].tipo_operacao == 'd'){
		produtos[i].qtd_estoque = produtos[i].qtd_estoque + movimento[i].qtdmovida;
		}
	}
}

int main() {
    Tprod produtos[TOT];
    Tmov movimento[TOT];
    int i = 0;
    
    leDadosProdutos(produtos);
    do {
        printf("Movimentacao %d:\n", i + 1);
        
        printf("Codigo do produto (0 para terminar): ");
        scanf("%d", &movimento[i].codigo_produto);
        
        if (movimento[i].codigo_produto != 0) {
            printf("Tipo de operacao (s para solicitacao, d para devolucao): ");
            scanf(" %c", &movimento[i].tipo_operacao);
             printf("Quantidade: ");
            scanf("%d", &movimento[i].qtdmovida);
        }
        
        i++;
    } while (movimento[i - 1].codigo_produto != 0);
    geraSaida(produtos, movimento);
    
    return 0;
}
