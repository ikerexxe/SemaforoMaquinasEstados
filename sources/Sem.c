/*********************************************************************
** 																	**
** project : SEMAFORO      							    			**
** filename : sem.c               					         		**
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
	#include "headers/sem.h"
#endif
#ifndef FRAMEBUFFER_H
	#define FRAMEBUFFER_H
	#include "frameBuffer.h"
#endif
#ifndef MOTORAUTOMATAS_H
	#define MOTORAUTOMATAS_H
	#include "motorAutomatas.h"
#endif

/*********************************************************************
** 																	**
** DEFINITIONS AND MACROS 											**
** 																	**
**********************************************************************/

ESTADO(Verde){
	TRANSICION(2,SEM_TRANS_tres_segundos,NULL)
};
FIN_ESTADO(Verde,1,SEM_ACCION_verde)

ESTADO(Ambar){
	TRANSICION(3,SEM_TRANS_tres_segundos,NULL)
};
FIN_ESTADO(Ambar,2,SEM_ACCION_ambar)

ESTADO(Rojo){
	TRANSICION(1,SEM_TRANS_tres_segundos,NULL)
};
FIN_ESTADO(Rojo,3,SEM_ACCION_rojo)

AUTOMATA(Semaforo){
	&Verde,
	&Ambar,
	&Rojo
};
FIN_AUTOMATA(Semaforo,101,SEM_AUT_finish)

/*********************************************************************
**																	**
** GLOBAL VARIABLES													**
** 																	**
**********************************************************************/
int get_id_sem=3;
unsigned int ticks=0, ticksOld=0;
unsigned int uticks=0;

/*********************************************************************
**																	**
** LOCAL FUNCTIONS													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que espera 3 segundos hasta cambiar el color del semaforo
*/
tBoolean SEM_TRANS_tres_segundos(void){
	while(ticksOld==ticks);
	ticksOld++;

	return true;
}

/**
 * @brief  Funcion que crea una interrupcion cada segundo
*/
void __attribute__((interrupt)) IntUnSegundo(void){
	uticks=(uticks+1)%3;

	if(uticks==0){
		ticks++;
	}
}

/**
 * @brief  Funcion que dibuja en pantalla el color verde
*/
void SEM_ACCION_verde(void){
	FRAME_BUFFER_deleteElement(get_id_sem);
	get_id_sem = FRAME_BUFFER_insertImage(g_pucCirc, 45, 44, 12, 10);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que dibuja en pantalla el color ambar
*/
void SEM_ACCION_ambar(void){
	FRAME_BUFFER_deleteElement(get_id_sem);
	get_id_sem = FRAME_BUFFER_insertImage(g_pucCirc, 45, 24, 12, 10);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que dibuja en pantalla el color rojo
*/
void SEM_ACCION_rojo(void){
	FRAME_BUFFER_deleteElement(get_id_sem);
	get_id_sem = FRAME_BUFFER_insertImage(g_pucCirc, 45, 4, 12, 10);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que decide si acabar el programa del automata
*/
tBoolean SEM_AUT_finish(void){
	return false;
}
