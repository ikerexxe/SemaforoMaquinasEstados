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

/*********************************************************************
** 																	**
** GLOBAL VARIABLES 												**
** 																	**
**********************************************************************/
int ejecutado = 0; //sirve para saber si es la primera vez que ejecutamos el programa
const unsigned char g_pucCirc[60]  =  {
       0x00, 0x00, 0x44, 0x44, 0x00, 0x00,
       0x00, 0x4a, 0xaa, 0xaa, 0xa4, 0x00,
       0x04, 0xaa, 0xaa, 0xaa, 0xaa, 0x40,
       0x4a, 0xaa, 0xaa, 0xaa, 0xaa, 0xa4,
       0x4a, 0xaa, 0xaa, 0xaa, 0xaa, 0xa4,
       0x4a, 0xaa, 0xaa, 0xaa, 0xaa, 0xa4,
       0x4a, 0xaa, 0xaa, 0xaa, 0xaa, 0xa4,
       0x04, 0xaa, 0xaa, 0xaa, 0xaa, 0x40,
       0x00, 0x4a, 0xaa, 0xaa, 0xa4, 0x00,
       0x00, 0x00, 0x44, 0x44, 0x00, 0x00
};

const unsigned char g_pucVacio[60]  =  {
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

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
