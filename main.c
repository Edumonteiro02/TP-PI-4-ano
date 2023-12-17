#include "utils.h"

int menu()
{
	int op;
	printf("-----------------------------\n");
	printf("|           M E N U         |\n");
	printf("-----------------------------\n\n");
	printf("[1] Calcular Correntes e Tens�es;\n");
	printf("[2] Listar Componentes;\n");
	printf("[3] Procurar Componente;\n");
	printf("[0] Sair\n\n");
	printf("Op��o:\n");
	scanf("%d", &op);
	return(op);
}

int main(void) 
{

	setlocale(LC_ALL, "Portuguese");

	int op, x;
	Data* circuito[nos];
	char nome[50];
	char no1, no2;
	for (int i = 0; i < nos; i++)
	{
		// Ap�s cada chamada a malloc ou ap�s cada leitura
		printf("Alocando mem�ria para o �ndice %d.\n", i);
		circuito[i] = (Data*)malloc(sizeof(Data));
	}

	x = Lerdados(circuito);
	if (x == 0) 
	{
		for (int i = 0; i < nos; i++) 
		{
			printf("Liberando mem�ria para o �ndice %d.\n", i);
			free(circuito[i]);
		}
		return 0;
	}	
	else
	{
			do
			{
				op = menu();
				switch (op)
				{
				case 1: break;
				case 2: 
					listardados(circuito);
					break;
				case 3:
					printf("\n-----------------------------\n");
					printf("|       S U B M E N U       |\n");
					printf("-----------------------------\n\n");
					printf("[1] Por nome de elemento;\n");
					printf("[2] Por n�s do elemento;\n");
					printf("[3] Voltar para tras;\n\n");
					printf("Op��o:\n");
					scanf("%d", &op);
					switch (op)
					{
						case 1:
							printf("Qual o nome do elemento?\n");
							scanf("%*c");
							scanf("%[^\n]", nome);
							procuranome(nome, circuito);
							break;
						case 2:
							printf("1� n�?\n");
							scanf(" %c", &no1);
							printf("2� n�?\n");
							scanf(" %c", &no2);
							procurano(no1, no2, circuito);
							break;
						case 3:break;
					}		
					break;
				}

			} while (op != 0);
	}


	for (int i = 0; i < nos; i++) 
	{
		// Antes de cada chamada a free
		printf("Liberando mem�ria para o �ndice %d.\n", i);
		free(circuito[i]);
	}

	// Antes do retorno bem-sucedido no main
	printf("Programa encerrado com sucesso.\n");

	return 0;
}