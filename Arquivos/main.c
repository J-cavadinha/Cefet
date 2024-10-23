#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct _Produto Produto;

struct _Produto
{
  char descricao[40];
  int quantidadeEstoque;
  int minimoEstoque;
  float precoVenda;
};

void incluirproduto(FILE *);
void buscacodigo(FILE *);
void registrarvenda(FILE *);
void relatorioabaixoestoque(FILE *);
void buscardescricao(FILE *);
void listarprodutos(FILE *);

int menu(FILE *arquivo)
{
  printf("---------------------------\n");
  printf("Controle de Estoque\n\n");
  printf("1 - Incluir produto\n2 - Registrar venda\n3 - Buscar por Código\n4 "
         "- Buscar por descrição\n5 - Relatório\n6 - Listar produtos\n7 - Sair\n");

  int opcao;
  scanf("%d", &opcao);
  fflush(stdin);
  printf("---------------------------\n");

  switch (opcao)
  {
  case 1:
    incluirproduto(arquivo);
    break;

  case 2:
    registrarvenda(arquivo);
    break;

  case 3:
    buscacodigo(arquivo);
    break;

  case 4:
    buscardescricao(arquivo);
    break;

  case 5:
    relatorioabaixoestoque(arquivo);
    break;

  case 6:
    listarprodutos(arquivo);
    break;

  case 7:
    return 1;
    break;

  default:
    break;
  }
  return 0;
}

void incluirproduto(FILE *arquivo)
{
  Produto produto;
  printf("Digite a descrição, estoque, quantidade mínima e o preco de venda: ");
  scanf("%s %d %d %f", produto.descricao, &produto.quantidadeEstoque, &produto.minimoEstoque, &produto.precoVenda);
  char descricaoTeste[40];
  sprintf(descricaoTeste, "%s %05d", produto.descricao, rand() % 10000);
  strcpy(produto.descricao, descricaoTeste);
  fseek(arquivo, 0, SEEK_END);
  fwrite(&produto, sizeof(Produto), 1, arquivo);
}

void registrarvenda(FILE *arquivo)
{
  int codigo_produto, qtdvendida;
  Produto produto;
  printf("Digite o código do produto e a quantidade vendida: ");
  scanf("%d %d", &codigo_produto, &qtdvendida);
  fseek(arquivo, codigo_produto * sizeof(Produto), SEEK_SET);
  fread(&produto, sizeof(Produto), 1, arquivo);

  if (produto.quantidadeEstoque >= qtdvendida)
  {
    produto.quantidadeEstoque -= qtdvendida;
    fseek(arquivo, codigo_produto * sizeof(Produto), SEEK_SET);
    fwrite(&produto, sizeof(Produto), 1, arquivo);
    printf("Venda registrada com sucesso!\n");
  }
  else
  {
    printf("Sem estoque suficiente.\n");
  }
}

void buscacodigo(FILE *arquivo)
{
  int codigoarquivo;
  printf("Digite o código do arquivo: ");
  scanf("%d", &codigoarquivo);

  Produto produto;
  fseek(arquivo, codigoarquivo * sizeof(Produto), SEEK_SET);
  fread(&produto, sizeof(Produto), 1, arquivo);
  printf("%s %d %d %.2f\n", produto.descricao, produto.quantidadeEstoque,
         produto.minimoEstoque, produto.precoVenda);
}

void buscardescricao(FILE *arquivo)
{
  char descricao[40];
  printf("Digite a descrição que deseja buscar: ");
  scanf("%s", descricao);
  Produto produto;
  fseek(arquivo, 0, SEEK_SET);
  while (fread(&produto, sizeof(Produto), 1, arquivo) == 1)
  {
    if (strstr(produto.descricao, descricao) != NULL)
    {
      printf("%s %d %d %.2f\n", produto.descricao, produto.quantidadeEstoque,
             produto.minimoEstoque, produto.precoVenda);
    }
  }
}

void relatorioabaixoestoque(FILE *arquivo)
{
  Produto produto;
  fseek(arquivo, 0, SEEK_SET);

  while (fread(&produto, sizeof(Produto), 1, arquivo) == 1)
  {
    if (produto.quantidadeEstoque < produto.minimoEstoque)
    {
      printf("Descrição: %s\n", produto.descricao);
      printf("Estoque: %d\n", produto.quantidadeEstoque);
      printf("Estoque mínimo: %d\n", produto.minimoEstoque);
      printf("Preço de venda: %.2f\n", produto.precoVenda);
      printf("---------------------------\n");
    }
  }
}

void listarprodutos(FILE *arquivo)
{
  Produto produto;
  fseek(arquivo, 0, SEEK_SET);

  while (fread(&produto, sizeof(Produto), 1, arquivo) == 1)
  {
    printf("Descrição: %s\n", produto.descricao);
    printf("Estoque: %d\n", produto.quantidadeEstoque);
    printf("Estoque mínimo: %d\n", produto.minimoEstoque);
    printf("Preço de venda: %.2f\n", produto.precoVenda);
    printf("---------------------------\n");
  }
  printf("Fim da lista.\n");
}

int main()
{
  FILE *arquivo;
  arquivo = fopen("estoque.bin", "r+b");
  if (arquivo == NULL)
  {
    printf("Erro ao abrir o arquivo!\n");
    return 1;
  }

  int sair = 0;

  do
  {
    sair = menu(arquivo);
  } while (sair != 1);

  return 0;
}
