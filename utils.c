#include "utils.h"
/*
void ordenardados(Data* circuitos)
{
	Data temp;
	for(int i = 0; i < nos; i++)
	{
		if(circuitos[i+1].tipo > circuitos[i].tipo)
		{
			temp = circuitos[i + 1];
			circuitos[i + 1] = circuitos[i];
			circuitos[i] = circuitos[i + 1];
		}
	}
}
*/


void listardados(int op, Data *circuitos) 
{
	int i;
	//ordenardados(circuitos);
	switch (op)
	{
	case 1 :
		printf("\n----------------------------------\n");
		printf("|           C I R C U I T        |\n");
		printf("----------------------------------\n\n");
		
		for (i = 0; i < nos; i++) 
		{	
			printf("<%c> <%s> <%d>\n", circuitos[i].tipo, circuitos[i].nome, circuitos[i].valor);
		}
		break;
	case 2:
		printf("\n----------------------------------\n");
		printf("|           S O U R C E S        |\n");
		printf("----------------------------------\n\n");
		
		for (i = 0; i < nos; i++)
		{
			if(circuitos[i].tipo=='V'|| circuitos[i].tipo == 'v')
				printf("<%c> <%s> <%d>\n", circuitos[i].tipo, circuitos[i].nome, circuitos[i].valor);
		}
		break;
	case 3:
		printf("\n----------------------------------------\n");
		printf("|           R E S I S T O R S          |\n");
		printf("----------------------------------------\n\n");
		
		for (i = 0; i < nos; i++)
		{
			if (circuitos[i].tipo == 'R' || circuitos[i].tipo == 'r')
				printf("<%c> <%s> <%d>\n", circuitos[i].tipo, circuitos[i].nome, circuitos[i].valor);
		}
		break;
	}
}

void procuranome(char nome[50], Data *circuitos)
{
	int i, j;
	char temp[50];

	for (i = 0; nome[i] != 0; i++)
	{
		if (nome[i] > 64 && nome[i] < 91)
		{
			nome[i] = nome[i] + 32;
		}
		/*
		else if(nome[i] == 32) //secalhar colocar se o i+1 vai ser \0 porque ao colocar espaço depois do nº da erro de procura
		{						//Prof não gostou disto xd as letras dão na mesma
			nome[i] = 95;
		}
		*/
	}

	for (i = 0; i < nos; i++)
	{
		strcpy(temp, circuitos[i].nome);
		for (j = 0; temp[j] != 0; j++)
		{
			if (temp[j] > 64 && temp[j] < 91)
			{
				temp[j] = temp[j] + 32;
			}
		}
		if (strcmp(temp, nome) == 0)
		{
			printf("\n<%c> <%s> <%d>\n", circuitos[i].tipo, circuitos[i].nome, circuitos[i].valor);
			return;
		}
	}

	if (i == nos)
	{
		printf("Nao foi encontrado componente com esse nome\n");
	}
}

void procurano(char no1, char no2, Data *circuitos)
{
	int i;
	if (!((no1 > 96 && no1 < 123) || (no1 > 64 && no1 < 91)) || !((no2 > 96 && no2 < 123) || (no2 > 64 && no2 < 91)))
	{
		printf("\nCaracter invalido inserido!");
		return;
	}
	if (no1 > 64 && no1 < 91)
		no1 = no1 + 32;
	if (no2 > 64 && no2 < 91)
		no2 = no2 + 32;

	for (i = 0; i < nos; i++)
	{
		if (circuitos[i].no_positivo > 64 && circuitos[i].no_positivo < 91)
			circuitos[i].no_positivo = circuitos[i].no_positivo + 32;
		if (circuitos[i].no_negativo > 64 && circuitos[i].no_negativo < 91)
			circuitos[i].no_negativo = circuitos[i].no_negativo + 32;



		if ((no1 == circuitos[i].no_positivo && no2 == circuitos[i].no_negativo) || (no2 == circuitos[i].no_positivo && no1 == circuitos[i].no_negativo))
		{
			printf("\n<%c> <%s> <%d>\n", circuitos[i].tipo, circuitos[i].nome, circuitos[i].valor);
			return;
		}
	}

	if (i == nos)
	{
		printf("Nao foi encontrado o no\n");
	}
}