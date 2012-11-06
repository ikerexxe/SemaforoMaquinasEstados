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
	#include "sem.h"
#endif
#ifndef FRAMEBUFFER_H
	#define FRAMEBUFFER_H
	#include "frameBuffer.h"
#endif

/*********************************************************************
** 																	**
** DEFINITIONS AND MACROS 											**
** 																	**
**********************************************************************/

const TS_EVEACC xVerde[] = {
	{2, "SEM_TRANS_tres_segundos", SEM_TRANS_tres_segundos, NULL}
};
const TS_ESTADO verde = {1,"verde",SEM_ACCION_verde,(TS_EVEACC *) xVerde};

const TS_EVEACC xAmbar[] = {
	{3, "SEM_TRANS_tres_segundos", SEM_TRANS_tres_segundos, NULL}
};
const TS_ESTADO ambar = {2,"ambar",SEM_ACCION_ambar,(TS_EVEACC *) xAmbar};

const TS_EVEACC xRojo[] = {
	{1, "SEM_TRANS_tres_segundos", SEM_TRANS_tres_segundos, NULL}
};
const TS_ESTADO rojo = {3,"rojo",SEM_ACCION_rojo,(TS_EVEACC *) xRojo};

const TS_ESTADO * const (xSemaforo[]) = {
	&verde,
	&ambar,
	&rojo
};
const TS_AUTOMATA semaforo = {101, "semaforo", SEM_AUT_finish, (TS_ESTADO **) xSemaforo};


/*
//Definicion de los estados
ESTADO(verde)
	ITEM_EAC(E2, SEM_TRANS_tres_segundos, SEM_ACCION_ambar),
FIN_ESTADO(verde, E1, NULL)

ESTADO(ambar)
	ITEM_EAC(E3, SEM_TRANS_tres_segundos, SEM_ACCION_rojo),
FIN_ESTADO(ambar, E2, NULL)

ESTADO(rojo)
	ITEM_EAC(E1, SEM_TRANS_tres_segundos, SEM_ACCION_verde),
FIN_ESTADO(rojo, E3, NULL)

//Definicion del automata del semaforo
AUTOMATA(semaforo)
    &verde,
	&ambar,
	&rojo
FIN_AUTOMATA(semaforo, A1, NULL)
*/

/*********************************************************************
**																	**
** GLOBAL VARIABLES													**
** 																	**
**********************************************************************/
int get_id_sem=0;

/*********************************************************************
**																	**
** LOCAL FUNCTIONS													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que espera 3 segundos hasta cambiar el color del semaforo
*/
tBoolean SEM_TRANS_tres_segundos(void){
	//sleep(3000);
	int i = 0, j = 0;

	while(i < 1000){
		j = 0;
		while(j < 1000){
			j++;
		}
		i++;
	}

	return true;
}

/**
 * @brief  Funcion que dibuja en pantalla el color verde
*/
void SEM_ACCION_verde(void){
	FRAME_BUFFER_deleteElement(get_id_sem);
	get_id_sem=FRAME_BUFFER_insertText("Verde", 10, 5);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que dibuja en pantalla el color ambar
*/
void SEM_ACCION_ambar(void){
	FRAME_BUFFER_deleteElement(get_id_sem);
	get_id_sem=FRAME_BUFFER_insertText("Ambar", 10, 5);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que dibuja en pantalla el color rojo
*/
void SEM_ACCION_rojo(void){
	FRAME_BUFFER_deleteElement(get_id_sem);
	get_id_sem=FRAME_BUFFER_insertText("Rojo", 10, 5);
	FRAME_BUFFER_writeToDisplay();
}

/**
 * @brief  Funcion que decide si acabar el programa del automata
*/
tBoolean SEM_AUT_finish(void){
	return false;
}
