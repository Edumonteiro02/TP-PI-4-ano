#define _CRT_SECURE_NO_WARNINGS

#include "fileio.h"

int Lerdados(Data *circuito)
{
	char line[200];
	char File_name[50];
	int i = 0;
	printf("Insira nome de ficheiro:");
	scanf("%s", File_name);
	FILE* fp;
	fp = fopen(File_name, "r");
	if (fp != NULL)
	{
		fscanf(fp, "%*[^\n]\n");
		while (fgets(line, sizeof(line), fp) != NULL)
		{
			//printf("%s", line);
			//printf("%d", i);
			if (strcmp(line, ".END\0") == 0 || strcmp(line, ".end\0") == 0 || strcmp(line, ".END\n") == 0 || strcmp(line, ".end\n") == 0) //prof disse que podiamos ver pelo tamanho em conjunto
				break;
			else
				sscanf(line, "%c %s %c %c %d\n", &circuito[i].tipo, circuito[i].nome, &circuito[i].no_positivo, &circuito[i].no_negativo, &circuito[i].valor);

			i++;
		}
		fclose(fp);
	}
	else
	{
		printf("Erro ao abrir ficheiro"); 
		return 0;
	}
	return 1;
}