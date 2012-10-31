/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file displayStellaris.c
* @brief La implementacion del acceso al display de la LM3S8962
*
* @version v0.0
* @date   	2012-10-10
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
#include "rit128x96x4.h"
#ifndef DISPLAY_H
	#define DISPLAY_H
	#include "displayGenerico.h"
#endif
#ifndef KEYPAD_H
	#define KEYPAD_H
	#include "keypadGenerico.h"
#endif
#ifndef KEYPADLM3S_H
	#define KEYPADLM3S_H
	#include "keypadLM3S.h"
#endif

/*********************************************************************
** 																	**
** GLOBAL VARIABLES 												**
** 																	**
**********************************************************************/
int ejecutado = 0; //sirve para saber si es la primera vez que ejecutamos el programa

/*********************************************************************
** 																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que inicializa el display
 *
*/
void DISPLAY_init(){
	RIT128x96x4Init(1000000);
}

/**
 * @brief  Funcion que asigna el valor de la nota a reproducir en las variables globales
 * y tambien muestra en pantalla estos valores
 *
 * @return        Valor booleano que representa si se ha tocado una tecla distinta
 *
*/
tBoolean DISPLAY_displayNote(){
	tBoolean ret = false; //guarda si se ha pulsado una tecla distinta
	unsigned char changedBit; //guarda la diferencia del cambio de tecla

	if(ejecutado == 0){
		FRAME_BUFFER_insertText("do re mi fa sol", 10, 15);
		FRAME_BUFFER_insertText("----------------", 10, 25);
		g_ucChangedData = 1;
		ejecutado = 1;
	}

	if( g_ucNote == MI ){
		FRAME_BUFFER_deleteElement(2);
		FRAME_BUFFER_insertText("mi", 10, 35);
	} else	if( g_ucNote == FA ){
		FRAME_BUFFER_deleteElement(2);
		FRAME_BUFFER_insertText("fa", 10, 35);
	} else	if( g_ucNote == RE ){
		FRAME_BUFFER_deleteElement(2);
		FRAME_BUFFER_insertText("re", 10, 35);
	} else	if( g_ucNote == SOL ){
		FRAME_BUFFER_deleteElement(2);
		FRAME_BUFFER_insertText("sol", 10, 35);
	} else	if( g_ucNote == DO ){
		FRAME_BUFFER_deleteElement(2);
		FRAME_BUFFER_insertText("do", 10, 35);
	} else	if( g_ucNote == SILENCE ){
		FRAME_BUFFER_deleteElement(2);
		FRAME_BUFFER_insertText("silence", 10, 35);
	}

	if(g_ucChangedData != 0){
		FRAME_BUFFER_writeToDisplay();
	}

	changedBit = g_ucChangedData  & 0x01;

	if (  changedBit != 0 ){
		if ( g_ucKeypadSwitches  == KEY_UP){
			ret = true;
		}
	}

	return ret;
}

/**
 * @brief  Funcion que escribe el texto que hay en el buffer intermedio
 * en el display
 *
*/
void DISPLAY_dibujarTexto(char * texto, int x, int y, int grayScale){
	RIT128x96x4StringDraw(texto,x,y,grayScale);
}

/**
 * @brief  Funcion que escribe la imagen que hay en el buffer intermedio
 * en el display
 *
*/
void DISPLAY_dibujarImagen(char * pic, int x, int y, int width, int height){
	RIT128x96x4ImageDraw(pic,x,y,width,height);
}

/**
 * @brief  Funcion que limpia el display
 *
*/
void DISPLAY_borrar(){
	RIT128x96x4Clear();
}
