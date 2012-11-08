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

	if (elAutomata->StopCond())  return;

	for (Indx = elAutomata->estado; *Indx != NULL; ++Indx)
	{
	    if (fms_mv == (*Indx)->id)
	    {
			EjecutaEstado(*Indx);
			return;
	    }
	}
	get_id_motor=FRAME_BUFFER_insertText("ERROR!!!!!", 5, 55);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que ejecuta el estado vertical
 *
*/
void EjecutaEstado(TS_ESTADO *elEstado)
{
	TS_EVEACC *Indx;   /* Indice de rastreo */

	(*elEstado->controles)();

	for (Indx = elEstado->funcion; Indx->evento != NULL; ++Indx)
	{
		if (Indx->evento() == true)
		{
			if (Indx->accion != NULL)
			{
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
