#ifndef FILEIO_H
#define FILEIO_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <malloc.h>
#include <time.h>

#define nos 5

typedef struct
{
	char no_positivo, no_negativo, tipo;
	char nome[50];
	int valor;
}Data;

int Lerdados(Data *circuito);

#endif // FILEIO_H
