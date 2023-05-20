//Lista 4 - ex 1 a)
//Tabuada (1x10 ~ 10x10)
#include<stdio.h>
int tabuada() 	//Para executar; trocar 'tabuada' para 'main'
{
	int count, tabuada, n;
		
	for (count = 1; count <= 10; count++)
	{
		for (n = 0; n<=10; n++)
		{
			tabuada = count * n;
			printf("\n%d x %d = %d", count, n, tabuada);
		}
	}
}
