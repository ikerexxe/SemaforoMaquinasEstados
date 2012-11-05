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

#ifndef SEM_H
	#define SEM_H
	#include "sem.h"
#endif
#ifndef FRAMEBUFFER_H
	#define FRAMEBUFFER_H
	#include "frameBuffer.h"
#endif

/*********************************************************************
**																	**
** GLOBAL VARIABLES													**
** 																	**
**********************************************************************/
int get_id=0;

/*********************************************************************
**																	**
** LOCAL FUNCTIONS													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que espera 3 segundos hasta cambiar el color del semaforo
*/
void SEM_TRANS_tres_segundos(void){
	sleep(3000);
}

/**
 * @brief  Funcion que dibuja en pantalla el color verde
*/
void SEM_ACCION_verde(void){
	FRAME_BUFFER_deleteElement(get_id);
	get_id=FRAME_BUFFER_insertText("Verde", 10, 5);

}

/**
 * @brief  Funcion que dibuja en pantalla el color ambar
*/
void SEM_ACCION_ambar(void){
	FRAME_BUFFER_deleteElement(get_id);
	get_id=FRAME_BUFFER_insertText("Ambar", 10, 5);
}

/**
 * @brief  Funcion que dibuja en pantalla el color rojo
*/
void SEM_ACCION_rojo(void){
	FRAME_BUFFER_deleteElement(get_id);
	get_id=FRAME_BUFFER_insertText("Rojo", 10, 5);
}
