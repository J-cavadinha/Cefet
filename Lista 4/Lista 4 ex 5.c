//Lista 4 ex 5
//Falta fazer a soma de salario de todos os departamentos
#include<stdio.h>
float departamento (codigo, qtdefunc) //*Função recebe o código e a qtde de funcionários/depart
{
	int contador, matricula;
	float salario, somasalario;
	contador = 0;
	somasalario = 0;
	while (contador < qtdefunc)
	{
		contador = contador + 1;
		printf("\nDigite a matricula: ");
		scanf("%d",&matricula);
		printf("Digite o salario: ");
		scanf("%f", &salario);
		somasalario = somasalario + salario;
	}
	printf("\nCodigo do departamento: %d\tSoma dos salarios: %.2f\n\n", codigo, somasalario);
	return somasalario;
}
void main ()
{
	int contador, codigo, qtdefunc;
	contador = 0;
	while (contador < 2) //Trocar 2 por 30
	{
		contador = contador + 1;
		printf("Digite o codigo do departamento: ");
		scanf("%d", &codigo);
		printf("Digite a quantidade de funcionarios do departamento: ");
		scanf("%d", &qtdefunc);
		departamento (codigo, qtdefunc);
	}
}
		
		


