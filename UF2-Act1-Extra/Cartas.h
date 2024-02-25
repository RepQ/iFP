#ifndef	__CARTAS_H__
#define __CARTAS_H__

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
//########################	DEFINICION DE ESTRUCTURA	#################################
typedef struct	
{
	float		life;
	int		type;
} Carta;

void	free_memory(Carta *, int);
//#######################	PROTOTIPO INICIAR/MOSTRAR	#################################
void	IniciarCartas(Carta *);
void	MostrarCartas(Carta *);
//#######################	PROTOTIPOS CALCULAR	#######################################
float	CalculaVidaMaxima(Carta *);
float	CalculaVidaMinima(Carta *);
float	CalculaVidaPromedio(Carta *);
//#######################	PROTOTIPOS DANYAR	#########################################
void	DanyarPorDebajoDe(Carta *, float, float);
void	DanyarPorEncimaDe(Carta *, float, float);
void	DanyarIgualesA(Carta *, float, float);
void	DanyarCercanas(Carta *, int, int, int);
//#######################	PROTOTIPOS CONTEO	########################################
int	ContarPorDebajoDe(Carta *, float);
int	ContarPorEncimaDe(Carta *, float);
int	ContarIgualesA(Carta *, float);
//#######################	FUNCION DE BUSQUEDA	######################################
int	BuscarTrioMaximo(Carta *);
//#######################	FUNCION INTERCAMBIAR	#####################################
void	IntercambiarCartas(Carta *, int, int);
//##############################################################################################
//
//
//						CARTAS
void	AttackSLD(Carta *, int);
void	AttackKNG(Carta *);
void	AttackSCV(Carta *);
void	AttackPRD(Carta *);
void	AttackDRW(Carta *);
void	AttackPLG(Carta *);
void	AttackDOO(Carta *);
void	AttackWLD(Carta *, int);
#endif
