/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file displayStellaris.c
* @brief La implementacion del motor interno de la maquina de estados.
*
* @version v0.0
* @date   	2012-10-31
*
* @note gpl2 license  2011, Ibon Ortega
*
* @par VERSION HISTORY
* Version : 1
* Date : 2012-10-31
* Revised by : 	ibon.ortega@alumni.mondragon.edu
* Description : Original version.
*
* @}
*/

/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/
#ifndef MOTORAUTOMATAS_H
	#define MOTORAUTOMATAS_H
	#include "motorAutomatas.h"
#endif

/*********************************************************************
** 																	**
** GLOBAL VARIABLES 												**
** 																	**
**********************************************************************/
BYTE fms_mv = 1;
BYTE fms_mv_anterior;
int get_id_motor = 0;

/*********************************************************************
**																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que ejecuta el automata
 *
*/
void EjecutaAutomata(TS_AUTOMATA *elAutomata)
{
	TS_ESTADO **Indx;    /* Valor indice rastreador */

	//Si ha llegado a la condicion final, termina de ejecutar el automata.
	if (elAutomata->StopCond())  return;

	//Ira pasando por cada uno de los estados hasta que no haya mas
	for (Indx = elAutomata->estado; *Indx != NULL; ++Indx)
	{
	    if (fms_mv == (*Indx)->id)
	    {
	    	//En cada estado ejecutara las funciones que le corresponda.
			EjecutaEstado(*Indx);
			return;
	    }
	}
	//Si falla mostrará un error.
	get_id_motor=FRAME_BUFFER_insertText("ERROR!!!!!", 5, 55);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que ejecuta el estado
 *
*/
void EjecutaEstado(TS_ESTADO *elEstado)
{
	TS_EVEACC *Indx;   /* Indice de rastreo */

	(*elEstado->controles)();
	//recorre las funciones dentro del estado hasta que no haya mas.
	for (Indx = elEstado->funcion; Indx->evento != NULL; ++Indx)
	{
		//Ejecuta esto si existe una transicion para acceder al siguiente evento
		if (Indx->evento() == true)
		{
			//Ejecuta esto si existe una accion dentro de este evento.
			if (Indx->accion != NULL)
			{
				//Ejecuta la accion correspondiente dentro del evento.
				Indx->accion();
			}
			if (Indx->id != fms_mv)
			{
				fms_mv_anterior = fms_mv;
				fms_mv = Indx->id;

				return;
			}
		}
	}
}
