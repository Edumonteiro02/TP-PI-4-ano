#include <stdio.h>
#include "utils.h"

void listardados(Data *circuitos[nos]) 
{
	int i;

	printf("\n----------------------------------\n");
	printf("|           C I R C U I T         |\n");
	printf("----------------------------------\n\n");

		for (i = 0;i < nos;i++) 
		{
			printf("<%c> <%s> <%d>", (*circuitos[i]).tipo, (*circuitos[i]).nome, (*circuitos[i]).valor);
		}
}

int procuranome(char nome[50], Data *circuitos[nos])
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
		strcpy(temp, (*circuitos[i]).nome);
		for (j = 0; temp[j] != 0; j++)
		{
			if (temp[j] > 64 && temp[j] < 91)
			{
				temp[j] = temp[j] + 32;
			}
		}
		if (strcmp(temp, nome) == 0)
		{
			printf("<%c> <%s> <%d>", (*circuitos[i]).tipo, (*circuitos[i]).nome, (*circuitos[i]).valor);
			return 0;
		}
	}

	if (i == nos)
	{
		printf("Nao foi encontrado componente com esse nome\n");
	}
	return 0;
}

int procurano(char no1, char no2, Data *circuitos[nos])
{
	int i;
	if (!((no1 > 96 && no1 < 123) || (no1 > 64 && no1 < 91)) || !((no2 > 96 && no2 < 123) || (no2 > 64 && no2 < 91)))
	{
		printf("\nCaracter invalido inserido!");
		return 0;
	}
	if (no1 > 64 && no1 < 91)
		no1 = no1 + 32;
	if (no2 > 64 && no2 < 91)
		no2 = no2 + 32;

	for (i = 0; i < nos; i++)
	{
		if ((*circuitos[i]).no_positivo > 64 && (*circuitos[i]).no_positivo < 91)
			(*circuitos[i]).no_positivo = (*circuitos[i]).no_positivo + 32;
		if ((*circuitos[i]).no_negativo > 64 && (*circuitos[i]).no_negativo < 91)
			(*circuitos[i]).no_negativo = (*circuitos[i]).no_negativo + 32;



		if ((no1 == (*circuitos[i]).no_positivo && no2 == (*circuitos[i]).no_negativo) || (no2 == (*circuitos[i]).no_positivo && no1 == (*circuitos[i]).no_negativo))
		{
			printf("<%c> <%s> <%d>", (*circuitos[i]).tipo, (*circuitos[i]).nome, (*circuitos[i]).valor);
			return 0;
		}
	}

	if (i == nos)
	{
		printf("Nao foi encontrado o no");
	}

	return 0;
}