//Lista 8 - exercício
#include<stdio.h>
#define TOT 10573
struct cliente
{
	int nconta;
	float saldo;
};
typedef struct cliente Tcliente;

void exibe(Tcliente cliente[], int qtdclientes, float smbanco)
{
	int i;
	for(i=0; i<qtdclientes; i++)
	{
		printf("\nNumero da conta: %d \nSaldo: %.2f ", cliente[i].nconta, cliente[i].saldo);
		if(cliente[i].saldo > smbanco)
			printf("Saldo acima da media do banco.");
		else
		if(cliente[i].saldo == smbanco)
			printf("Saldo na media do banco.");
		else
			printf("Saldo abaixo da media do banco.");
	}
}

int main()
{
	int i;
	float saldobanco, smbanco, qtdclientes;
	saldobanco = smbanco = 0;
	Tcliente cliente[TOT];
	
	for(i=0; i<TOT; i++)
	{
		printf("Digite o numero da conta (Digite 0 para sair): ");
		scanf("%d", &cliente[i].nconta);
		if(cliente[i].nconta == 0)
		break;
		printf("Digite o numero do saldo: ");
		scanf("%f",&cliente[i].saldo);
		saldobanco = saldobanco + cliente[i].saldo;
		
	}
	smbanco = saldobanco/i;
	exibe(cliente, i, smbanco);
	return 0;
}
