/** @addtogroup Semaforo maquinas estados
*
* @{

* @file miniPiano.c
* @brief La interfaz de acceso al semaforo
*
* @version v0.0
* @date   	2012-10-24
*
* @note gpl2 license  2011, Iker Pedrosa
*
* @par VERSION HISTORY
* Version : 1
* Date : 2012-10-08
* Revised by : 	iker.pedrosa@alumni.mondragon.edu
* Description : Original version.
*
* @}
*/

/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/
#ifndef MOTOR_H
	#define MOTOR_H
	#include "motorAutomatas.h"
#endif

/*********************************************************************
** 																	**
** DEFINITIONS AND MACROS 											**
** 																	**
**********************************************************************/

/*
//Definicion de las transiciones
TRANSICION(SEM_TRANS_tres_segundos)
	????(T1, espera3seg, ?????, &SEM_TRANS_tres_segundos)
FIN_TRANSICION(espera3seg, T1, ????)

//Definicion de los estados
ESTADO(verde)
	ITEM_EAC(E2, SEM_EVENTO_finVerde, SEM_ACCION_ambar),
FIN_ESTADO(verde, E1, NULL)

ESTADO(ambar)
	ITEM_EAC(E3, SEM_EVENTO_finAmbar, SEM_ACCION_rojo),
FIN_ESTADO(ambar, E2, NULL)

ESTADO(rojo)
	ITEM_EAC(E1, SEM_EVENTO_finRojo, SEM_ACCION_verde),
FIN_ESTADO(rojo, E3, NULL)

//Definicion del automata del semaforo
AUTOMATA(semaforo)
    &verde,
	&ambar,
	&rojo
FIN_AUTOMATA(semaforo, A1, StopCondi_sem)
*/

/*********************************************************************
** 																	**
** PROTOTYPES OF LOCAL FUNCTIONS 									**
** 																	**
*********************************************************************/

/**
 * @brief  Funcion que espera 3 segundos hasta cambiar el color del semaforo
*/
void SEM_TRANS_tres_segundos(void);

/**
 * @brief  Funcion que dibuja en pantalla el color verde
*/
void SEM_ACCION_verde(void);

/**
 * @brief  Funcion que dibuja en pantalla el color ambar
*/
void SEM_ACCION_ambar(void);

/**
 * @brief  Funcion que dibuja en pantalla el color rojo
*/
void SEM_ACCION_rojo(void);
