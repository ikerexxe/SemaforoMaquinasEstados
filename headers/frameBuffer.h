/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file displayGenerico.h
* @brief La interfaz de acceso al buffer de memoria grafica
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
#include <string.h>
#ifndef DISPLAY_H
	#define DISPLAY_H
	#include "displayGenerico.h"
#endif

/*********************************************************************
** 																	**
** DEFINITIONS AND MACROS 											**
** 																	**
**********************************************************************/

/**
 * Definimos el número de líneas que tiene el display, de columnas que que tiene el
 * display, el numero maximo de elementos y el valor del pixel vacio
*/
#define MAX_ROWS 11
#define MAX_LINES 12
#define MAX_ELEMS 4
#define PIXEL_VACIO 0

/*********************************************************************
** 																	**
** EXPORTED VARIABLES 												**
** 																	**
*********************************************************************/
extern const unsigned char g_pucVacio[60]; //cuadrado vacio de un tamaño de 12x10

/*********************************************************************
** 																	**
** TYPEDEFS AND STRUCTURES 											**
** 																	**
**********************************************************************/
typedef struct {
	int id;
	int x;
	int y;
	int xOld;
	int yOld;
	int width;
	int height;
	char* picture_or_text;
	int what; /* 0=IMAGE 1=TEXT */
} TIPO_DISPLAY_ELEMENT;

/*********************************************************************
** 																	**
** PROTOTYPES OF LOCAL FUNCTIONS 									**
** 																	**
*********************************************************************/

/**
 * @brief  Funcion que inicializa el buffer intermedio
 *
*/
void FRAME_BUFFER_init();

/**
 * @brief  Funcion que inserta una imagen en el buffer intermedio
 *
 * @return        Valor numerico que representa el identificador de la imagen insertada
 *
*/
int FRAME_BUFFER_insertImage(char *pic, int x, int y, int w, int h);

/**
 * @brief  Funcion que inserta texto en el buffer intermedio
 *
 * @return        Valor numerico que representa el identificador del texto insertado
 *
*/
int FRAME_BUFFER_insertText(char *texto, int x, int y);

/**
 * @brief  Funcion que quita un elemento del buffer intermedio
 *
*/
void FRAME_BUFFER_deleteElement(int id);

/**
 * @brief  Funcion que actualiza la posicion del elemento
 *
*/
void FRAME_BUFFER_actualizarPosicionElemento(int id,int x, int y);

/**
 * @brief  Funcion que escribe la informacion del buffer intermedio en el display
 *
*/
void FRAME_BUFFER_writeToDisplay(void);
