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
#ifndef FRAMEBUFFER_H
	#define FRAMEBUFFER_H
	#include "frameBuffer.h"
#endif

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
