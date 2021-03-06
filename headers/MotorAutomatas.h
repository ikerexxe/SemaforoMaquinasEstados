/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file MotorAutomatas.h
* @brief La definicion de las estructuras utilizadas para crear un semaforo
* Definici�n de:
* 	Definicion de la estructura Accion y Evento
*	Definicion de la estructura Estado
*	Definicion de la estructura  Maquina de estado
*	Ademas de las funciones y macros utilizadas
* @version v0.0
* @date   	2012-11-08
*
* @note gpl2 license  2011, Daniel Collado
*
* @par VERSION HISTORY
* Version : 1
* Date : 2012-11-08
* Revised by : 	daniel.collado@alumni.mondragon.edu
* Description : Original version.
*
* @}
*/


/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"

#ifndef FRAMEBUFFER_H
	#define FRAMEBUFFER_H
	#include "frameBuffer.h"
#endif

/*********************************************************************
** 																	**
** TYPEDEFS AND STRUCTURES 											**
** 																	**
**********************************************************************/
typedef char BYTE;

//Definicion del tipo Accion y Evento
typedef void (*TPNF_ACC)(void);
typedef tBoolean (*TPNF_EVE)(void);

//Definicion del tipo de dato que representa una transicion
typedef struct{
	BYTE 			id; /*Identificador del estado destino */
	char 		  * nombre; /*Nombre identificativo de depuraci�n*/
	TPNF_EVE 		evento; /*Puntero a la funci�n evento*/
	TPNF_ACC 		accion; /*Puntero a la funci�n evento*/
} TS_EVEACC;

//Definici�n del tipo Estado
typedef struct {
	  BYTE          id;             /* Identificador del estado */
	  char        * nombre;         /* Nombre identificativo de depuraci�n */
	  TPNF_EVE      controles;      /* Funci�n de control del estado */
	  TS_EVEACC   * funcion;        /* Punteros a las funciones del estado */
} TS_ESTADO;

//Definici�n del tipo Maquina de estado
typedef struct {
	  BYTE          id;             /* Identificador del automata */
	  char        * nombre;         /* Nombre identificativo de depuraci�n */
	  TPNF_EVE      StopCond;       /* Condici�n necesaria para la ejecuci�n */
	  TS_ESTADO   **estado;         /* Matriz de punteros a los ESTADOS */
} TS_AUTOMATA;

/*********************************************************************
** 																	**
** DEFINITIONS AND MACROS 											**
** 																	**
**********************************************************************/
#define ESTADO(nombre_estado) const TS_EVEACC x##nombre_estado[] =
#define TRANSICION(id,evento,accion) {id, #evento, evento, accion}
#define FIN_ESTADO(nombre_fin_estado,id,control) const TS_ESTADO nombre_fin_estado = {id,#id,control,(TS_EVEACC *) x##nombre_fin_estado};
#define AUTOMATA(nombre_automata) const TS_ESTADO * const (x##nombre_automata[]) =
#define FIN_AUTOMATA(nombre_automata,id,StopC) const TS_AUTOMATA nombre_automata = {id, #nombre_automata, StopC, (TS_ESTADO **) x##nombre_automata};
#define NULL 0

/*********************************************************************
** 																	**
** PROTOTYPES OF LOCAL FUNCTIONS 									**
** 																	**
*********************************************************************/

/**
 * @brief  Funcion que ejecuta el automata
 *
*/
void EjecutaAutomata( TS_AUTOMATA *elAutomata);
/**
 * @brief  Funcion que ejecuta el estado
 *
*/
void EjecutaEstado  ( TS_ESTADO   *elEstado);
