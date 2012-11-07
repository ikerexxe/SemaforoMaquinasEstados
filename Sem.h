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
** EXPORTED VARIABLES 												**
** 																	**
*********************************************************************/
extern const unsigned char g_pucCirc[60];

/*********************************************************************
** 																	**
** PROTOTYPES OF LOCAL FUNCTIONS 									**
** 																	**
*********************************************************************/

/**
 * @brief  Funcion que espera 3 segundos hasta cambiar el color del semaforo
*/
tBoolean SEM_TRANS_tres_segundos(void);

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

/**
 * @brief  Funcion que decide si acabar el programa del automata
*/
tBoolean SEM_AUT_finish(void);
