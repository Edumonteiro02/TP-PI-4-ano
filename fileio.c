#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

void Lerdados(Dados* dados)
{
    FILE* fp;
    char linha[100];  // Tamanho adequado para armazenar uma linha

    fp = fopen("circuito.cir", "r");

    if (fp == NULL)
    {
        printf("Ficheiro não encontrado\n");
        return;
    }

    int linhaAtual = 0;

    while (fgets(linha, sizeof(linha), fp) != NULL)
    {
        if (linhaAtual == 0)
        {
            linhaAtual++;
            continue;  // Ignora a primeira linha
        }

        if (strcmp(linha, ".end\n") == 0 || strcmp(linha, ".END\n") == 0)
        {
            break;  // Termina a leitura quando encontrar a linha de fim
        }

        if (sscanf(linha, " %c %49s %d %d %d", &dados[linhaAtual].tipo, dados[linhaAtual].nome, &dados[linhaAtual].no_positivo, &dados[linhaAtual].no_negativo, &dados[linhaAtual].valor) == 5)
        {
            linhaAtual++;
        }
    }

    fclose(fp);
}