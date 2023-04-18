//Programa p calcular o salário de um funcionário a partir da matrícula, valor da hora e qtde de hrs
//Programa deve exibir a matrícula, o salário base, o desconto do INSS, desconto IR e o salário liq.
#include<stdio.h>
float salarioBase (int horast, float valorhora)
{
	int horastrab;
	float vhora, salario_base;
	salario_base = horastrab * vhora;
	return salario_base;
}
float descontoInss (float salario_base)
{
	float desconto_inss;
	desconto_inss = salario_base * 0.11;
	if (desconto_inss > 450.27)
	{
		desconto_inss = 450.27;
		return desconto_inss;
	}
	else
		return desconto_inss;
}
float descontoIR (salario_base)
{
	float desconto_IR;
	if (salario_base <= 1800)
	{
		desconto_IR = 0;
		return desconto_IR;
	}
	if (salario_base > 1800 && salario_base < 2900)
	{
		desconto_IR = salario_base * 0.15;
		return desconto_IR;
	}
	else
	{
		desconto_IR = salario_base * 0.275;
		return desconto_IR;
	}
}
void main()
{
	int matricula, horastrab;
	float valorhora, salario, desconto1, desconto2, salarioliquido;
	printf("Digite sua matrícula:");
	scanf("%d", &matricula);
	printf("Digite o valor recebido por hora:");
	scanf ("%f", &valorhora);
	printf("Digite a qtde de horas trabalhadas:");
	scanf("%d", &horastrab);
	salario = salarioBase (valorhora, horastrab);
	desconto1 = descontoInss (salario);
	desconto2 = descontoIR (salario);
	salarioliquido = (salario - desconto1) - desconto2;
	printf("Matricula: %d", matricula);
	printf("\nSalario base: %.2f", salario);
	printf("\nDesconto do INSS: %.2f", desconto1);
	printf("\nDesconto do IR: %.2f", desconto2);
	printf("\nSalario liquido: %.2f", salarioliquido);
}
