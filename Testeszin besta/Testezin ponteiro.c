#include<stdio.h>
int main()
{
	int num =9;
	int *p;
	p = &num;
	printf("Valor de n: %d\n", num);
	printf("Endere�o de n: %p\n", &num);
	printf("Valor de p: %p\n", p);
	printf("Endere�o de p: %p", *p);
	return 0;
}
