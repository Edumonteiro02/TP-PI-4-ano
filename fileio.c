#define _CRT_SECURE_NO_WARNINGS

#include "fileio.h"

int Lerdados(Data *circuito)
{
	char line[200];
	char File_name[50];
	int i = 0;
	printf("Insira nome de ficheiro:");
	scanf("%[^\n]", File_name);
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
		printf("Erro ao abrir ficheiro\n"); 
		return 0;
	}
	return 1;
}

void outdados(float A1, float A2, float A3, float A4, float Ubc, float Uad, float Ucd, float Uef, float Uae, float Uac)
{
	FILE* fp;
	fp = fopen("Resultados.out", "w");
	if (fp != NULL)
	{
		fprintf(fp, "Ubc=%f\n", Ubc);
		fprintf(fp, "Uad=%f\n", Uad);
		fprintf(fp, "Ucd=%f\n", Ucd);
		fprintf(fp, "Uef=%f\n", Uef);
		fprintf(fp, "Uae=%f\n", Uae);
		fprintf(fp, "Uac=%f\n", Uac);
		fprintf(fp, "A1=%f\n", A1);
		fprintf(fp, "A2=%f\n", A2);
		fprintf(fp, "A3=%f\n", A3);
		fprintf(fp, "A4=%f\n", A4);

		fclose(fp);
	}
	else
		printf("Erro ao abrir ficheiro\n");
}