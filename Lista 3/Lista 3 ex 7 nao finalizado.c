//Lista 03 ex 07
//Programa para exibir o troco do cliente dependendo da forma de pagamento
//D para débito, C para crédito e N para dinheiro
#include<stdio.h>
float pagamento_dinheiro (float vdespesa, float vpago)
{
	float troco;
	troco = vpago - vdespesa;
	return troco;
}
void main()
{
	float valorconta, valortroco;
	int mpgto, valorpago;
	printf("Digite o valor a ser pago:");
	scanf("%f", &valorconta);
	printf("Digite o metodo de pagamento:");
	scanf("%d", &mpgto);
	
	if (mpgto == 'D' && mpgto == 'C')
		printf("Nao ha troco");
		
	if (mpgto == 'N')
	{
		printf("Valor pago:");
		scanf("%f", &valorpago);
		valortroco = pagamento_dinheiro (valorconta, valorpago);
		printf("O valor do troco e: %.2f", valortroco);
	}
}
