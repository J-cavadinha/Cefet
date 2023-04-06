//Função que receba o valor do litro de gas e a qtd em litros. Deve calcular e 
//exibir o valor a ser pago
//void ou float???????????
#include<stdio.h>
void valorapagar (float precolitros, float qtdlitros)
{
	float calc_conta;
	calc_conta = precolitros * qtdlitros;
	print("%.2f", calc_conta);
}
