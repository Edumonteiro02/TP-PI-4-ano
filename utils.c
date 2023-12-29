#include "utils.h"

void calculos(Data* circuito) {
	float R1 = 0, R2 = 0, R3 = 0, R4 = 0, R5 = 0, R6 = 0, U1 = 0, U2 = 0;
	float I1 = 0, I2 = 0, I3 = 0, Ubc = 0, Uad = 0, Ucd = 0, Uef = 0, Uae = 0, Uac = 0, A1 = 0, A2 = 0, A3 = 0, A4 = 0;
	int x;
	for (x = 0; x <= nos; x++) {
		if (circuito[x].no_positivo == 'a' && circuito[x].no_negativo == 'b' || circuito[x].no_positivo == 'b' && circuito[x].no_negativo == 'a') {
			U1 = circuito[x].valor;
		}
		if (circuito[x].no_positivo == 'c' && circuito[x].no_negativo == 'f' || circuito[x].no_positivo == 'f' && circuito[x].no_negativo == 'c') {
			U2 = circuito[x].valor;
		}
		if (circuito[x].no_positivo == 'c' && circuito[x].no_negativo == 'b' || circuito[x].no_positivo == 'b' && circuito[x].no_negativo == 'c') {
			R1 = circuito[x].valor;
		}
		if (circuito[x].no_positivo == 'a' && circuito[x].no_negativo == 'd' || circuito[x].no_positivo == 'd' && circuito[x].no_negativo == 'a') {
			R2 = circuito[x].valor;
		}
		if (circuito[x].no_positivo == 'd' && circuito[x].no_negativo == 'c' || circuito[x].no_positivo == 'c' && circuito[x].no_negativo == 'd') {
			R3 = circuito[x].valor;
		}
		if (circuito[x].no_positivo == 'e' && circuito[x].no_negativo == 'f' || circuito[x].no_positivo == 'f' && circuito[x].no_negativo == 'e') {
			R4 = circuito[x].valor;
		}
		if (circuito[x].no_positivo == 'a' && circuito[x].no_negativo == 'e' || circuito[x].no_positivo == 'e' && circuito[x].no_negativo == 'a') {
			R5 = circuito[x].valor;
		}
		if (circuito[x].no_positivo == 'a' && circuito[x].no_negativo == 'c' || circuito[x].no_positivo == 'c' && circuito[x].no_negativo == 'a') {
			R6 = circuito[x].valor;
		}
	}
	I2 = ((U2 + ((R3 * U1) / (R1 + R2 + R3)) + ((R2 * U1) / (R1 + R2 + R3)) + ((-R5 * U2) / (R4 + R5 + R6)) + ((-R4 * U2) / (R4 + R5 + R6))) / (((-R3 * R2) / (R1 + R2 + R3)) + ((-R3 * R3) / (R1 + R2 + R3)) + ((-R2 * R2) / (R1 + R2 + R3)) + ((-R2 * R3) / (R1 + R2 + R3)) + R3 + R2 + R5 + R4 + ((-R5 * R4) / (R4 + R5 + R6)) + ((-R5 * R5) / (R4 + R5 + R6)) + ((-R4 * R4) / (R4 + R5 + R6)) + ((-R4 * R5) / (R4 + R5 + R6))));
	I1 = ((U1 + (R2 * I2) + (R3 * I2)) / (R1 + R2 + R3));
	I3 = ((-U2 + (R4 * I2) + (R5 * I2)) / (R4 + R5 + R6));
	Ubc = R1 * I1;
	Uad = R2 * (I1 - I2);
	Ucd = R3 * (I1 - I2);
	Uef = R4 * (I2 - I3);
	Uae = R5 * (I2 - I3);
	Uac = R6 * I3;
	A1 = I1;
	A2 = I2 - I3;
	A3 = I3;
	A4 = I1 - I2;

	outdados(A1, A2, A3, A4, Ubc, Uad, Ucd, Uef, Uae, Uac);

	printf("Valores das variáveis:\n");
	printf("R1: %.2f\n", R1);
	printf("R2: %.2f\n", R2);
	printf("R3: %.2f\n", R3);
	printf("R4: %.2f\n", R4);
	printf("R5: %.2f\n", R5);
	printf("R6: %.2f\n", R6);
	printf("U1: %.2f\n", U1);
	printf("U2: %.2f\n", U2);

	printf("I1=%f\n", I1);
	printf("I2=%f\n", I2);
	printf("I3=%f\n", I3);
	printf("Ubc=%f\n", Ubc);
	printf("Uad=%f\n", Uad);
	printf("Ucd=%f\n", Ucd);
	printf("Uef=%f\n", Uef);
	printf("Uae=%f\n", Uae);
	printf("Uac=%f\n", Uac);
	printf("A1=%f\n", A1);
	printf("A2=%f\n", A2);
	printf("A3=%f\n", A3);
	printf("A4=%f\n", A4);
}

void ordenardados(Data* circuitos)
{
	int i, j, x;
	Data temp;
	char temp_c1, temp_c2;
	char temp_name1[50], temp_name2[50];

	for (i = 0; i < nos; i++)
	{
		temp_c1 = circuitos[i].tipo;

		if (temp_c1 > 64 && temp_c1 < 91)
			temp_c1 = temp_c1 + 32;

		for (j = i + 1; j < nos; j++)
		{
			temp_c2 = circuitos[j].tipo;

			if (temp_c2 > 64 && temp_c2 < 91)
				temp_c2 = temp_c2 + 32;

			if (temp_c1 > temp_c2)
			{
				temp = circuitos[j];
				circuitos[j] = circuitos[i];
				circuitos[i] = temp;
			}

		}
	}

	for (i = 0; i < nos; i++)
	{
		temp_c1 = circuitos[i].tipo;
		strcpy(temp_name1, circuitos[i].nome);

		for (x = 0; temp_name1[x] != 0; x++)
		{
			if (temp_name1[x] > 64 && temp_name1[x] < 91)
			{
				temp_name1[x] = temp_name1[x] + 32;
			}
		}

		if (temp_c1 > 64 && temp_c1 < 91)
			temp_c1 = temp_c1 + 32;


		for (j = i + 1; j < nos; j++)
		{
			temp_c2 = circuitos[j].tipo;
			strcpy(temp_name2, circuitos[j].nome);

			for (x = 0; temp_name2[x] != 0; x++)
			{
				if (temp_name2[x] > 64 && temp_name2[x] < 91)
				{
					temp_name2[x] = temp_name2[x] + 32;
				}
			}

			if (temp_c2 > 64 && temp_c2 < 91)
				temp_c2 = temp_c2 + 32;
			if (temp_c1 == temp_c2)
			{
				if (strcmp(temp_name1, temp_name2) > 0)
				{
					temp = circuitos[j];
					circuitos[j] = circuitos[i];
					circuitos[i] = temp;
				}
				else if (strcmp(temp_name1, temp_name2) == 0 && circuitos[i].valor > circuitos[j].valor)
				{
					temp = circuitos[j];
					circuitos[j] = circuitos[i];
					circuitos[i] = temp;
				}
			}
		}
	}
}


void listardados(int op, Data *circuitos) 
{
	int i;
	ordenardados(circuitos);
	switch (op)
	{
	case 1 :
		printf("\n----------------------------------\n");
		printf("|           C I R C U I T        |\n");
		printf("----------------------------------\n\n");
		
		for (i = 0; i < nos; i++) 
		{	
			//if(circuitos[i].nome != NULL) ver com circuito2.cir ultima linha ta a dar mal
			printf("<%c> <%s> <%d>\n", circuitos[i].tipo, circuitos[i].nome, circuitos[i].valor);
		}
		break;
	case 2:
		printf("\n----------------------------------\n");
		printf("|           S O U R C E S        |\n");
		printf("----------------------------------\n\n");
		
		for (i = 0; i < nos; i++)
		{
			if(circuitos[i].tipo =='V'|| circuitos[i].tipo == 'v')
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
	default:
		printf("Opção Inválida\n");
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
