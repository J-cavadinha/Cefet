#include <stdio.h>
#include <string.h>

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2]; // Ao Espaço no final da linha + quebra de linha
};

int main(int argc, char **argv)
{
	FILE *f;
	Endereco e;
	int qt;
	int linhaslidas;
	int encontrado = 0;

	linhaslidas = 0;
	f = fopen("cep_ordenado.dat", "rb");
	qt = fread(&e, sizeof(Endereco), 1, f);

	printf("Digite o cep que deseja procurar: ");
	char cep_procurado[8];
	scanf("%s", cep_procurado);

	int inicio = 0;
	fseek(f, 0, SEEK_END);
	long fileSize = ftell(f);
	long numRecords = fileSize / sizeof(Endereco);
	int fim = (numRecords - 1);
	fseek(f, 0, SEEK_SET);

	while (inicio <= fim)
	{
		linhaslidas++;
		int meio = inicio + (fim - inicio) / 2;
		fseek(f, meio * sizeof(e), SEEK_SET);
		fread(&e, sizeof(Endereco), 1, f);

		if (strncmp(cep_procurado, e.cep, 8) == 0)
		{
			printf("%.72s\n%.72s\n%.72s\n%.72s\n%.2s\n%.8s\n", e.logradouro, e.bairro, e.cidade, e.uf, e.sigla, e.cep);
			encontrado++;
			break;
		}
		else if (strncmp(cep_procurado, e.cep, 8) < 0)
		{
			fim = meio - 1;
		}
		else if (strncmp(cep_procurado, e.cep, 8) > 0)
		{
			inicio = meio + 1;
		}
	}

	if (encontrado == 0)
	{
		printf("Cep não encontrado.\n");
	}
	printf("Total Lido: %d\n", linhaslidas);
	fclose(f);
}