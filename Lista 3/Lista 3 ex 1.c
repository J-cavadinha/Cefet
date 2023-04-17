//Programa que leia: educa��o (E), longevidade (L) e riqueza (R) e exiba o IDH, todos os valores s�o reais.
//Incluir fun��o calculaIdh que recebe como par�metro as 3 dimens�es, calcula e retorna o IDH.
#include<stdio.h>
float calculaIdh (float e, float l, float r)
{
      float idh;
      
      if(e >= (l+r))
      {
           idh = e*l*r/((e+l+r)/3);
           printf("O IDH e: %.2f", idh);
           }
      else
      {
          idh = (e+l+r)/3;
          printf("O IDH e: %.2f", idh);
          }
      return idh;
}
int main()
{
      float ed, longv, riq;
      printf("Digite o indicador da educacao: ");
      scanf("%f", &ed);
      printf("Digite o indicador da longevidade: ");
      scanf("%f", &longv);
      printf("Digite o indicador da riqueza: ");
      scanf("%f", &riq);
      calculaIdh (ed, longv, riq);
      return 0;
}
