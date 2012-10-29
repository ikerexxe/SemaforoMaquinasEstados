/*********************************************************************
** 																	**
** project : SEMAFORO      										**
** filename : sem.c               							**
** version : 1														**
** date : 29/10/2012       											**
** 																	**
**********************************************************************
** 																	**
** Copyright (c) 2012, Iratxe Trevejo Garcia						**
** All rights reserved. 											**
** 																	**
**********************************************************************
**																	**
**VERSION HISTORY:													**
**----------------													**
**Version : 1   													**
**Date : 09/10/2012     											**
**Revised by : iratxe.trevejo@mondragon.edu 						**
**Description : esta clase implementa las funciones                 **
**definidas en el sem.h										      	**
*********************************************************************/

/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/

#ifndef sem_h
	#define sem_h
	#include "sem.h"
#endif

/*********************************************************************
**																	**
** LOCAL FUNCTIONS													**
** 																	**
**********************************************************************/
void SEM_TRANS_tres_segundos(void){
	sleep(3000);
}

/**
 * @brief  Funcion que dibuja en pantalla el color verde
*/
void SEM_ACCION_verde(void){
	RIT128x96x4StringDraw("Verde", 10, 5, 15);
}

/**
 * @brief  Funcion que dibuja en pantalla el color ambar
*/
void SEM_ACCION_ambar(void){
	RIT128x96x4StringDraw("AMBAR", 10, 5, 15);
}

/**
 * @brief  Funcion que dibuja en pantalla el color rojo
*/
void SEM_ACCION_rojo(void){
	RIT128x96x4StringDraw("Rojo", 10, 5, 15);
}
