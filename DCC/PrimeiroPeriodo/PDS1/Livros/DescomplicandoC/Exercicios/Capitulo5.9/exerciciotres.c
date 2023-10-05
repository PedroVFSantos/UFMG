/*
 * 3) Faça um programa que leia um número inteiro N e depois imprima os N primeiros números naturais ímpares.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	int inteiroPositivo;
	scanf("%d", &inteiroPositivo);

	int contadorImpares = 0;

	if (inteiroPositivo < 0){
		return EXIT_FAILURE;
	}

	for (int i = 1; i <= inteiroPositivo; i+=2) {
	
		printf("%d\n",i);
		contadorImpares++;
	}

	return EXIT_SUCCESS;
}
