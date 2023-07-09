#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include "fileio.h"
#include "utils.h"

int menu()
{
	int op;
	printf("-----------------------------\n");
	printf("|           M E N U         |\n");
	printf("-----------------------------\n\n");
	printf("[1] Ler Ficheiro;\n");
	printf("[2] Listar Circuitos;\n");
	printf("[3] Procurar Circuito;\n");
	printf("[0] Sair\n\n");
	printf("Opção:\n");
	scanf("%d", &op);
	return(op);
}

int main() {

	setlocale(LC_ALL, "Portuguese");

	int op;

	do
	{
		Dados d;
		op = menu();
		switch (op)
		{
		case 1: break;
		case 2: 
			listardados(d);
			break;
		case 3:
			printf("\n-----------------------------\n");
			printf("|       S U B M E N U       |\n");
			printf("-----------------------------\n\n");
			printf("[1] Por nome de elemento;\n");
			printf("[2] Por nós do elemento;\n\n");
			printf("Opção:\n");
			scanf("%d", &op);
			break;
		}

	} while (op != 0);
	/*
	EscritaFicheiro();
	LerFicheiro();
	solve();
	return 0;
	*/


	return 0;
}