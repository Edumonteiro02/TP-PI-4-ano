#include "utils.h"

int menu()
{
	int op;
	printf("-----------------------------\n");
	printf("|           M E N U         |\n");
	printf("-----------------------------\n\n");
	printf("[1] Calcular Correntes e Tensões;\n");
	printf("[2] Listar Componentes;\n");
	printf("[3] Procurar Componente;\n");
	printf("[0] Sair\n\n");
	printf("Opção:\n");
	scanf("%d", &op);
	return(op);
}

int main(void) 
{

	setlocale(LC_ALL, "Portuguese");

	int op, x;
	Data *circuito[nos];
	char nome[50];
	char no1, no2;
	x = Lerdados(circuito);
	if (x==0)
	{
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
					printf("[2] Por nós do elemento;\n");
					printf("[3] Voltar para tras;\n\n");
					printf("Opção:\n");
					scanf("%d", &op);
					switch (op)
					{
						case 1:
							printf("Qual o nome do elemento?\n");
							scanf("%s", nome);
							procuranome(nome, circuito);
							break;
						case 2:
							printf("1º no?\n");
							scanf(" %c", &no1);
							printf("2º no?\n");
							scanf(" %c", &no2);
							procurano(no1, no2, circuito);
							break;
						case 3:break;
					}		
					break;
				}

			} while (op != 0);
	}

	return 0;
}