//Pequeno erro na qtd de funcionário com maior salário, as vezes da certo, as vezes não.
#include<stdio.h>
void umDepartamento (int qtdf, int *qtdmaiorsal, float *maiorsal)
{
	int matr, cont;
	float sal;
	*maiorsal = 0;
	*qtdmaiorsal = 0;
	
	for (cont = 0; cont < qtdf; cont++)
	{
		printf("Digite a matricula e o salario: ");
		scanf("%d%f", &matr, &sal);
		if(sal > *maiorsal)
		{
			*maiorsal = sal;
			*qtdmaiorsal = *qtdmaiorsal + 1;
		if (sal == *maiorsal)
		{
			*qtdmaiorsal = *qtdmaiorsal + 1;
		}
	}
}
	printf("O maior salario e: %.2f\t", *maiorsal);
	printf("%d pessoas tem  maior salario\n\n", *qtdmaiorsal);
}
float main ()
{
	int coddep, qtdf, qtdmaiorsal;
	float maiorsal;
	
	do{
	printf("Digite o codigo do departamento (0 - fim): ");
	scanf("%d", &coddep);
	if (coddep == 0)
		return 0;
	else{
	printf("Digite a quantidade de funcionarios: ");
	scanf("%d", &qtdf);
	umDepartamento (qtdf, &qtdmaiorsal, &maiorsal);
	}
	} while(coddep != 0);
return 0;
}
