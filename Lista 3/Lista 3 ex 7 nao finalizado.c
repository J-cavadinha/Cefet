#include<stdio.h>
float pagamento_dinheiro (float conta)
{
	float troco, valorpago;
	printf("Valor pago:");
	scanf ("%f", &valorpago);
	troco = conta - valorpago;
	if (troco > 0)
		printf("Troco: %.2f", troco);
	if (troco < 0){
		troco = troco * -1;
		printf("%.0f, a mais", troco);
	}
	else
		printf("Sem troco");
}
int main()
{
	float vconta;
	char metodopg;
	printf("Valor a ser pago: ");
	scanf("%f",&vconta);
	printf("Digite o metodo de pagamento: ");
	scanf(" &c ",&metodopg);
	
	if (metodopg == 'C' || metodopg == 'D')
		printf("Sem troco");

	if (metodopg == 'N')
		pagamento_dinheiro(vconta);
	
	else
		printf("Digito invalido.");
	
	return 0;
}
