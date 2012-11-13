/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file stellaris.c
* @brief La implementacion de las configuraciones de la LM3S8962
*
* @version v0.0
* @date   	2012-10-10
*
* @note gpl2 license  2011, Iker Pedrosa
*
* @par VERSION HISTORY
* Version : 1
* Date : 2012-10-11
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
#ifndef MICRO_H
	#define MICRO_H
	#include "microGenerico.h"
#endif

/*********************************************************************
** 																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que inicializa el reloj de la LM3S8962 y que habilita las interrupciones
 * para que se puedan hacer funciones de tipo sleep
 *
*/
void MICRO_init(){
	//Configuramos el reloj del sistema a 8 MHz
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |SYSCTL_XTAL_8MHZ);
	//Configuramos cada cuantos ciclos de reloj tiene que interrumpirnos el reloj del sistema.
	SysTickPeriodSet(8000000); // periodo=1 seg
	//habilitamos la interrupcion del Systick del sistema.
	SysTickIntEnable();
	//habilitamos el conteo de los tick del sistema.
	SysTickEnable();
	//Habilitamos las interrupciones.
	IntMasterEnable();
}


