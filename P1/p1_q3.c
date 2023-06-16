//P1 - 3)
int leValidaIdade()
{
	int idade;
	printf("Digite a sua idade: ");
	scanf("%d", &idade);
	
	if(idade > -1 && idade < 121)
		return idade;
	else
		printf("Idade invalida.");
}

void mensagem()
{
	int idade;
	idade = leValidaIdade();
	if(idade >= 0 && idade <= 11)
		printf("Crianca");
	else if(idade >= 12 && idade < 21)
		printf("Adolescencia");
	else if(idade >= 21 && idade < 66)
		printf("Adulto");
	else if (idade > 65)
		printf("Terceira Idade");
	else
		printf("Erro.")
}
