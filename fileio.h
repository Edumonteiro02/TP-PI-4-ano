#include <stdio.h>
#include "utils.h"

typedef struct
{
	char tipo;
	char nome[50];
	int no_positivo, no_negativo, valor;
}*Dados [nos];

void Lerdados(Dados* dados);