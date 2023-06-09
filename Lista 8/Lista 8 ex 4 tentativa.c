//Lista 8 ex 4
#define TOT 10
#define NDEPTOS 11 //De 10 a 20
struct depto
{
	int codigodep;
	int somaidade;
};
typedef struct depto Tdepto;

void inicializa(Tdepto depto[])
{
	int i;
	for(i=10; i<NDEPTOS; i++)
	{
		depto[i].codigodep = 0;
		depto[i].somaidade = 0;
	}
}

void exibe(Tdepto depto[])
{
	int i;
	for(depto[10]; depto[10]<NDEPTOS; depto[10]++)
	{
		printf("Codigo departamento: %d\n Idade media: %f", depto[10].codigodep, (depto[10].somaidade)/2);
	}
}

int main()
{
	int i;
	for(i=0; i<TOT; i++)
	{
		printf("Digite sua matricula, codigo do departamento e idade: ");
		scanf("%d%d%d", &matr, &depto[i].codigodep, &depto[i].idade)
	}
}
