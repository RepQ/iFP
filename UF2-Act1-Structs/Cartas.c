#include "Cartas.h"

static void	fill(Carta *cards)
{
	Carta	*ptr;
	int	i;

	i = 0;
	ptr = cards;
	while (i++ < 10)
	{
		ptr->type = -1;
		ptr++;
	}
}

static void	soldier(Carta	*cards)
{
	Carta	*ptr;
	int	i;
	int	cont_soldier;

	ptr = cards;
	cont_soldier = 5;
	while (cont_soldier != 0)
	{
		i = rand() % 10;
		if ((ptr + i)->type  == -1)
		{
			printf("%d", i);
			(ptr + i)->type = 0;
			cont_soldier--;
		}
	}
}

static void	other(Carta *cards)
{
	Carta	*ptr;
	int	i;
	int	aux;

	ptr = cards;
	i = 0;
	while (i++ < 10)
	{
		if (ptr->type == -1)
		{
			aux = (rand() % 7) + 1;
			ptr->type = aux;
			ptr++;
		}
		else
			ptr++;
	}
}
/*					FUNCIONES PRINCIPALES					*/
/*	INICIAR CARTA										*/
void	IniciarCartas(Carta *cards)
{
	Carta	*ptr;
	int	i;

	ptr = cards;
	i = -1;
	while (++i < 10)
	{
		ptr->life = rand() % 100 + 1;
		ptr->type = 0;
		ptr++;
	}
	fill(cards);
	soldier(cards);
	other(cards);
}

/*	MOSTRAR CARTA										*/
void	MostrarCartas(Carta *cards)
{
	Carta	*ptr;

	ptr = cards;
	int	i;

	i = -1;
	printf("==================================================================================================\n");
	i = -1;
	while (++i < 10)
		printf("\t%d", i);
	printf("\n");
	i = -1;
	while (++i < 10)
	{
		switch((ptr + i)->type)
		{
			case 0:
				printf("\tSLD");
				break;
			case 1:
				printf("\tKNG");
				break;
			case 2:
				printf("\tSCV");
				break;
			case 3:
				printf("\tPRD");
				break;
			case 4:
				printf("\tDRW");
				break;
			case 5:
				printf("\tPLG");
				break;
			case 6:
				printf("\tDOO");
				break;
			case 7:
				printf("\tWLD");
				break;
			default:
				break;
		}
	}
	i = -1;
	printf("\n");
	while (++i < 10)
	{
		if ((ptr + i)->life > 0)
			printf("\t%.2f", (ptr + i)->life);
		else
			printf("\tX");
	}
	printf("\n==================================================================================================\n");
}

/*	FUNCIONES DE CALCULO									*/
/*	VIDA MAXIMA										*/
float	CalculaVidaMaxima(Carta *cards)
{
	Carta	*ptr;
	int	i;
	float	vida_max;

	ptr = cards;
	i = 0;
	vida_max = 0;
	while (i++ < 10)
	{
		if (ptr->life > vida_max)
			vida_max = ptr->life;
		ptr++;
	}
	return (vida_max);
}

/*	VIDA MINIMA										*/
float	CalculaVidaMinima(Carta *cards)
{
	Carta	*ptr;
	int	i;
	float	vida_min;

	ptr = cards;
	i = 0;
	vida_min = ptr->life;
	while (i++ < 10)
	{
		if ((ptr->life < vida_min) && ptr->life > 0)
			vida_min = ptr->life;
		ptr++;
	}
	return (vida_min);
}

/*	VIDA PROMEDIO										*/
float	CalculaVidaPromedio(Carta *cards)
{
	Carta	*ptr;
	int	i;
	float	vida_prom;

	ptr = cards;
	i = 0;
	vida_prom = 0;
	while (i++ < 10)
	{
		vida_prom += ptr->life;
		ptr++;
	}
	vida_prom /= 10;
	return (vida_prom);
}

/*	FUNCIONES DE DANYO									*/
/*	POR DEBAJO DE										*/
void	DanyarPorDebajoDe(Carta *cards, float valor, float danyo)
{
	Carta	*ptr;
	int	i;

	ptr = cards;
	i = 0;
	while (i++ < 10)
	{
		if (ptr->life < valor)
			ptr->life -= danyo;
		ptr++;
	}
}

/*	POR ENCIMA DE										*/
void	DanyarPorEncimaDe(Carta *cards, float valor, float danyo)
{
	Carta	*ptr;
	int	i;

	ptr = cards;
	i = 0;
	while (i++ < 10)
	{
		if (ptr->life > valor)
			ptr->life -= danyo;
		ptr++;
	}
}

/*	IGUALES A										*/
void	DanyarIgualesA(Carta *cards, float valor, float danyo)
{
	Carta	*ptr;
	int	i;

	ptr = cards;
	i = 0;
	while (i++ < 10)
	{
		if (ptr->life == valor)
			ptr->life -= danyo;
		ptr++;
	}
}

/*	CERCANAS A										*/
void	DanyarCercanas(Carta *cards, int pos, int dist, int danyo)
{
	Carta	*ptr;
	int	i;

	ptr = cards;
	i = 0;
	while (i++ < 10)
	{
		if (abs(ptr - (cards + pos)) <= dist)
			ptr->life -= danyo;
		ptr++;
	}
}

/*	FUNCIONES DE CONTEO									*/
/*	POR DEBAJO DE										*/
int	ContarPorDebajoDe(Carta *cards, float valor)
{
	Carta	*ptr;
	int	i;
	int	counter;

	ptr = cards;
	i = 0;
	counter = 0;
	while (i++ < 10)
	{
		if (ptr->life < valor)
			counter++;
		ptr++;
	}
	return (counter);
}

/*	POR ENCIMA DE										*/
int	ContarPorEncimaDe(Carta *cards, float valor)
{
	Carta	*ptr;
	int	i;
	int	counter;

	ptr = cards;
	i = 0;
	counter = 0;
	while (i++ < 10)
	{
		if (ptr->life > valor)
			counter++;
		ptr++;
	}
	return (counter);
}

/*	IGUALES A										*/
int	ContarIgualesA(Carta *cards, float valor)
{
	Carta	*ptr;
	int	i;
	int	counter;

	ptr = cards;
	i = 0;
	counter = 0;
	while (i++ < 10)
	{
		if (ptr->life == valor)
			counter++;
		ptr++;
	}
	return (counter);
}

/*	FUNCION DE BUSQUEDA									*/
int	BuscarTrioMaximo(Carta *cards)
{
	Carta	*ptr;
	float	life;
	int	i;
	int	index_life;

	i = -1; 
	index_life = 0;
	ptr = cards;
	life = (ptr->life) + ((ptr + 1)->life) + ((ptr + 2)->life);
	while (++i < 8)
	{
		if (((ptr->life) + (ptr + 1)->life + (ptr + 2)->life) > life)
		{
			index_life = i;
			life = ((ptr->life) + (ptr + 1)->life + (ptr + 2)->life);
		}
		ptr++;
	}
	return (index_life);
}

/*	FUNCION DE INTERCAMBIO									*/
void	IntercambiarCartas(Carta *cards, int indice1, int indice2)
{
	Carta	*ptr;
	Carta	aux;

	ptr = cards;
	aux = *(ptr + indice1);
	*(ptr + indice1) = *(ptr + indice2);
	*(ptr + indice2) = aux;
}
/*						ATAQUES						*/

/*	SOLDIER											*/
void	AttackSLD(Carta *cards, int pos)
{
	float	danyo;

	danyo = (rand() % 5) + 1;
	(cards + pos)->life -= danyo;
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}

/*	KINGSLAYER										*/
void	AttackKNG(Carta *cards)
{
	Carta	*ptr;
	float	danyo;
	float	life_max;
	int	i;

	i = 0;
	ptr = cards;
	life_max = CalculaVidaMaxima(cards);
	danyo = (rand() % 11) + 20;
	while (i++ < 10)
	{
		if (ptr->life == life_max)
			ptr->life -= danyo;
		ptr++;
	}
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}

/*	SCAVENGER										*/
void	AttackSCV(Carta *cards)
{
	Carta	*ptr;
	float	danyo;
	float	life_min;
	int	i;

	i = 0;
	ptr = cards;
	life_min = CalculaVidaMinima(cards);
	danyo = (rand() % 11) + 20;
	while (i++ < 10)
	{
		if (ptr->life == life_min)
			ptr->life -= danyo;
		ptr++;
	}
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}

/*	PREDATOR										*/
void	AttackPRD(Carta *cards)
{
	Carta	*ptr;
	float	danyo;
	float	life_prom;
	int	i;

	i = 0;
	ptr = cards;
	life_prom = CalculaVidaPromedio(cards);
	danyo = (rand() % 6) + 5;
	while (i++ < 10)
	{
		if (ptr->life > life_prom)
			ptr->life -= danyo;
		ptr++;
	}
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}

/*	DARWIN											*/
void	AttackDRW(Carta *cards)
{
	Carta	*ptr;
	float	danyo;
	float	life_prom;
	int	i;

	i = 0;
	ptr = cards;
	life_prom = CalculaVidaPromedio(cards);
	danyo = (rand() % 6) + 5;
	while (i++ < 10)
	{
		if (ptr->life <= life_prom)
			ptr->life -= danyo;
		ptr++;
	}
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}

/*	PLAGUE											*/
void	AttackPLG(Carta *cards)
{
	Carta	*ptr;
	float	danyo;
	int	less_life;
	int	more_life;

	ptr = cards;
	danyo = (rand() % 6) + 5;
	less_life = ContarPorDebajoDe(cards, 50);
	more_life = ContarPorEncimaDe(cards, 50);
	if (less_life < more_life)
		DanyarPorEncimaDe(cards, 50, danyo);
	else if (less_life > more_life)
		DanyarPorDebajoDe(cards, 50, danyo);
	else
		DanyarIgualesA(cards, 50, danyo);
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}

/*	DOOM											*/
void	AttackDOO(Carta *cards)
{
	Carta	*ptr;
	int	i;
	float	danyo;

	ptr = cards;
	i = BuscarTrioMaximo(cards);
	danyo = (rand() % 11) + 10;
	DanyarCercanas(cards, i + 1, 1, danyo);
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}

/*	WILDFIRE										*/
void	AttackWLD(Carta *cards, int pos)
{
	Carta	*ptr;
	float	danyo;

	ptr = cards;
	danyo = (rand() % 6) + 5;
	DanyarCercanas(cards, pos, 2, danyo);
	printf("Haz realizado %.2f de danyo", danyo);
	Sleep(3000);
}
