#include<stdio.h>
int main()
{
	int num = 9;	//variável comum
	
	int *p;			//variável tipo ponteiro, que armazena um endereço de memória
	
	p = &num;		//atribuição o endereço da variável 'num' no ponteiro 'p'
	
	printf("Valor de n: %d\n", num);			//valor da variável num
	printf("Endereco de n: %p\n", &num);			//endereço dessa variável
	printf("Valor de p: %p\n", p);				//endereço de num (linha 8)
	printf("Valor apontado por p: %d\n", *p); 		//valor que p aponta (a partir do endereço)
	
	return 0;
}
