/*
 * 2) Faça um programa que leia um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem decrescente.*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	int inteiroPositivo;
	scanf("%d", &inteiroPositivo);

	for (int i = inteiroPositivo; i >=0; i--) {
	

		printf("%d\n",i);
	}
	
	return EXIT_SUCCESS;
}
