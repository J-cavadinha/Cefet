//Lista 4 ex 4
#include<stdio.h>
float menu ()
{
	char escolha;
	printf("\t Digite o numero correspondente: \t1 - Horista\t2 - Contratado\t3 - Prestador de servico");
	scanf("%c", &escolha);
	switch(escolha)
	{
		case '1':
		horista ();
		break;
		case '2':
		contratado ();
		break;
		case '3':
		prestador ();
		break;
	}
}
float horista ()
{
	int horast;
	float valorhora, salario;
	printf("Digite a quantidade de horas trabalhadas: ");
	scanf("%d", &horast);
	printf("Digite o valor recebido por hora: ");
	scanf("%f", &valorhora);
	salario = horast * valorhora;
	return salario;
}
float contratado ()
{
	float salario;
	printf("Digite seu salario: ");
	scanf("%f", &salario);
	return salario;
}
float prestador ()
{
	int servicosp, contador;
	float valorservico, faturamento;
	printf("Digite a quantidade de servicos prestados: ");
	scanf("%d", &servicosp);
	contador = 0;
	faturamento = 0;
	while (contador < servicosp)
	{
		contador = contador + 1;
		printf("Digite o valor pelo serviço: ");
		scanf("%f", valorservico);
		faturamento = faturamento + valorservico;
	}
	return faturamento;
}
void main ()
{
	contador = 0;
	while (contador < 50)
	{
		menu ();
	}
}
