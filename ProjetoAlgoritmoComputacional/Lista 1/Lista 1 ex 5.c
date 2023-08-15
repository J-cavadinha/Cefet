//a)Função que recebe dois num int, horas e min, função deve retornar o tempo em min
#include<stdio.h>
int Tempo (int horas, int min)
{
	int calculo_min;
	calculo_min = (horas * 60) + min;
	return calculo_min;
}

//b)Função que recebe 4 int, horas e min da hora prevista e horas e min efetivos de um
//voo, usar obrigatoriamente a função anterior e retornar a dif entre os 2 horarios
int Difvoo (int horap, int minp. int horae, int mine)
{
	int calculop, calculoe, dif_tempo;
	calculop = Tempo (horap, minp);
	calculoe = Tempo (horae, mine);
	dif_tempo = calculop - calculoe
	return dif_tempo;
}
