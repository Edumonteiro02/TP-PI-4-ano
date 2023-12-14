#ifndef FILEIO_H
#define FILEIO_H

#include <stdio.h>

#define nos 5

typedef struct
{
	char no_positivo, no_negativo, tipo;
	char nome[50];
	int valor;
}Data;

int Lerdados(Data *dados);

#endif // FILEIO_H
