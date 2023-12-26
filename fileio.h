#ifndef FILEIO_H
#define FILEIO_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define nos 7

typedef struct
{
	char no_positivo, no_negativo, tipo;
	char nome[50];
	int valor;
}Data;

int Lerdados(Data *circuito);
void outdados(float A1, float A2, float A3, float A4, float Ubc, float Uad, float Ucd, float Uef, float Uae, float Uac);

#endif // FILEIO_H
