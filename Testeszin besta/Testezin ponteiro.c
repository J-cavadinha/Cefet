#include<stdio.h>
int main()
{
	int num =9;
	int *p;
	p = &num;
	printf("Valor de n: %d\n", num);
	printf("Endereço de n: %p\n", &num);
	printf("Valor de p: %p\n", p);
	printf("Endereço de p: %p", *p);
	return 0;
}
