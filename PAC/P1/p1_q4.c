//P1 - 4)
#include<stdio.h>
float calcPesoCubico(float comprimento, float altura, float largura)
{
	float pesocubico;
	pesocubico = (comprimento * altura * largura)/6000 ;
	return pesocubico;
}
float PesoEscolhido(float pesofisico, float pesocubico)
{
	if(pesocubico < 5)
		return pesofisico;
	else if(pesocubico > 5)
	{
		if(pesocubico > pesofisico)
			return pesocubico;
		else
			return pesofisico;
	}
}
float ValorPg(float comprimento, float altura, float largura, float pesofisico, float precobasico)
{
	float pesocubico, pescolhido, valorapg;
	pesocubico = calcPesoCubico(comprimento, altura, largura);
	pescolhido = PesoEscolhido(pesofisico, pesocubico);
	valorapg = precobasico * pescolhido;
	return valorapg;
}
void main()
{
	float precobasico, pesofisico, comprimento, largura, altura, precoaserpago;
	printf("Digite o preco basico: ");
	scanf("%f", &precobasico);
	printf("Digite o peso fisico: ");
	scanf("%f", &pesofisico);
	printf("Digite o comprimento, largura e altura: ");
	scanf("%f%f%f", &comprimento, &largura, &altura);
	precoaserpago = ValorPg(comprimento, altura, largura, pesofisico, precobasico);
	printf("O valor a ser pago e: %.2f", precoaserpago);
}
