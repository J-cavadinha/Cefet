//Lista 6 ex 1
#include<stdio.h>
int leValidaTipo ()
{
	char tipop;
	printf("Digite o tipo do produto (1-Fruta, 2-Legume, 3-Verdura): ");
	scanf(" %c", &tipop);
	return tipop;
}
int xxx (int qtdeprod, int *qtfruta, int *qtlegume, int *qtverdura)
{
	int cont, codigo, chamada;
	cont = 0;
	*qtfruta = *qtlegume = *qtverdura = 0;
	
	while (cont < qtdeprod)
	{
		cont = cont + 1;
		printf("Digite o código do produto: ");
		scanf("%d", &codigo);
		chamada = leValidaTipo ();
		
		if (chamada == '1'){
			*qtfruta = *qtfruta + 1;
		}
			
		if (chamada == '2'){
			*qtlegume = *qtlegume + 1;
		}
			
		if (chamada == '3'){
			*qtverdura = *qtverdura + 1;
		}
	}
}
/* int main()
{
    int qtfruta, qtlegume, qtverdura;
    int qtdeprod = 3; 

    xxx(qtdeprod, &qtfruta, &qtlegume, &qtverdura);

    printf("Quantidade de frutas: %d\n", qtfruta);
    printf("Quantidade de legumes: %d\n", qtlegume);
    printf("Quantidade de verduras: %d\n", qtverdura);

    return 0;
} */
// Main como comentário pois não foi pedido na questão
