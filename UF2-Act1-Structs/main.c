#include "Cartas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

Carta	jugador1[10];
Carta	jugador2[10];
int	accion;
int	turno;

int	main(void)
{
	int	opc;

	opc = -1;
	srand(time(NULL));
	turno = rand() % 2;
	IniciarCartas(jugador1);
	IniciarCartas(jugador2);
	while (opc != 0)
	{
		system("cls");
		printf("Jugador # 1: \n");
		MostrarCartas(jugador1);
		printf("Vida Promedio : %.2f \n\n", CalculaVidaPromedio(jugador1));
		printf("Jugador # 2: \n");
		MostrarCartas(jugador2);
		printf("Vida Promedio : %.2f \n\n", CalculaVidaPromedio(jugador2));
		printf("\tTurno del jugador # %d\n", (turno + 1));
		printf("\t\tElige la accion a realiza en tu turno: \n");
		printf("\t\t1.Intercambiar Cartas\n");
		printf("\t\t2.Atacar\n");
		printf("\t\t3.Pasar Turno\n");
		printf("\t\t0.Terminar Juego\n");
		printf("\tAccion: ");
		scanf("%d", &opc);
		if (opc == 1)
		{
			int	indice1;
			int	indice2;

			printf("Ingresa la carta 1: ");
			scanf("%d", &indice1);
			printf("Ingresa la carta 2: ");
			scanf("%d", &indice2);
			IntercambiarCartas((turno == 0) ? jugador1:jugador2, indice1, indice2);
			turno = (turno + 1) % 2;
		}
		else if (opc == 2)
		{
			int	carta;
			int	tipo_carta;

			printf("Ingrese la carta con la que desea atacar: ");
			scanf("%d", &carta);
			tipo_carta = (turno == 0) ? (jugador1 + carta)->type : (jugador2 + carta)->type;
			switch (tipo_carta)
			{
				case 0:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackSLD((turno == 0) ? jugador2 : jugador1, carta);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				case 1:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackKNG((turno == 0) ? jugador2 : jugador1);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				case 2:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackSCV((turno == 0) ? jugador2 : jugador1);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				case 3:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackPRD((turno == 0) ? jugador2 : jugador1);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				case 4:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackDRW((turno == 0) ? jugador2 : jugador1);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				case 5:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackPLG((turno == 0) ? jugador2 : jugador1);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				case 6:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackDOO((turno == 0) ? jugador2 : jugador1);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				case 7:
					{
						if (((turno == 0) ? (jugador1 + carta)->life : (jugador2 + carta)->life) > 0.0f)
							AttackWLD((turno == 0) ? jugador2 : jugador1, carta);
						else
						{
							printf("LA CARTA NO ESTA VIVA!. PIERDES TURNO!\n");
							Sleep(3000);
						}
						break ;
					}
				default:
					{
						printf("Ayuda no funciona!");
						Sleep(5000);
						break ;
					}
			}
			turno = (turno + 1) % 2;
		}
		else if (opc == 3)
			turno = (turno + 1) % 2;
		if (CalculaVidaMaxima(jugador1) == 0.0f)
		{
			system("cls");
			printf("El jugador # 2 HA GANADO!");
			Sleep(5000);
			opc = 0;
		}
		else if (CalculaVidaMaxima(jugador2) == 0.0f)
		{
			system("cls");
			printf("El jugador # 1 HA GANADO!");
			Sleep(5000);
			opc = 0;
		}
	}
}

