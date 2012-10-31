/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file displayGenerico.h
* @brief La interfaz generica de acceso al display
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
#ifndef KEYPAD_H
	#define KEYPAD_H
	#include "keypadGenerico.h"
#endif
#ifndef FRAMEBUFFER_H
	#define FRAMEBUFFER_H
	#include "frameBuffer.h"
#endif
#ifndef PWM_H
	#define PWM_H
	#include "pwmGenerico.h"
#endif

/*********************************************************************
** 																	**
** EXPORTED VARIABLES 												**
** 																	**
*********************************************************************/
extern unsigned char g_ucKeypadSwitches; //valor de la tecla pulsada en el keypad
extern unsigned char g_ucChangedData; //si se ha cambiado la tecla que se esta pulsando
extern unsigned long g_ulNoteFrecuency; //frecuencia a la que emite el PWM
extern unsigned char g_ucNote; //nota que se esta pulsando

/*********************************************************************
** 																	**
** PROTOTYPES OF LOCAL FUNCTIONS 									**
** 																	**
*********************************************************************/

/**
 * @brief  Funcion que inicializa el display
 *
*/
void DISPLAY_init();

/**
 * @brief  Funcion que asigna el valor de la nota a reproducir en las variables globales
 * y tambien muestra en pantalla estos valores
 *
 * @return        Valor booleano que representa si se ha tocado una tecla distinta
 *
*/
tBoolean DISPLAY_displayNote();

/**
 * @brief  Funcion que escribe el texto que hay en el buffer intermedio
 * en el display
 *
*/
void DISPLAY_dibujarTexto(char * texto, int x, int y, int grayScale);

/**
 * @brief  Funcion que escribe la imagen que hay en el buffer intermedio
 * en el display
 *
*/
void DISPLAY_dibujarImagen(char * pic, int x, int y, int width, int height);

/**
 * @brief  Funcion que limpia el display
 *
*/
void DISPLAY_borrar();
