//Função que recebe o valor desejado a ser sacado em um cx eletrônico, deve calcular
//e exibir a menor quantidade de cédulas a ser recebida pelo cliente
//considerar notas de 100, 50, 20, 10, 5, 2, 1
void calculaNotas (int valor)
{
	int notas100, notas50, notas20, notas10, notas5, notas2, moedas, qtdtotal;
	notas100 = valor / 100;
	valor = valor % 100;
	notas50 = valor / 50;
	valor = valor % 50;
	notas20 = valor /20;
	valor = valor % 20;
	notas10 = valor /10;
	valor = valor % 10;
	notas5 = valor /5;
	valor = valor % 5;
	notas2 = valor /2;
	valor = valor % 2;
	moedas = valor /1;
	qtdtotal = notas100 + notas50 + notas20 + notas10 + notas5 + notas2 + moedas;
	printf("\nMenor qtde de notas e moedas sera de: %d", qtdtotal);
}
