/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file displayGenerico.h
* @brief La implementacion del acceso al buffer intermedio de la memoria grafica
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
** GLOBAL VARIABLES 												**
** 																	**
**********************************************************************/
TIPO_DISPLAY_ELEMENT displayElements[MAX_ELEMS]; //array que guarda los elementos en la memoria intermedia
int display_element_kop = 0; //contador del numero de elemenos que hay guardados en la memoria intermedia

/*********************************************************************
** 																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que inicializa el buffer intermedio
 *
*/
void FRAME_BUFFER_init(){
	int i = 0; //contador para la inicializacion de los elementos

	DISPLAY_init();

	for(i = 0; i < MAX_ELEMS; i++){
		displayElements[i].id = i;
		displayElements[i].x = 0;
		displayElements[i].y = 0;
		displayElements[i].width = 0;
		displayElements[i].height = 0;
		displayElements[i].picture_or_text = 0;
		displayElements[i].what = 0;
	}
}

/**
 * @brief  Funcion que inserta una imagen en el buffer intermedio
 *
 * @return        Valor numerico que representa el identificador de la imagen insertada
 *
*/
int FRAME_BUFFER_insertImage(char *pic, int x, int y, int w, int h){
	if(display_element_kop < MAX_ELEMS){
		displayElements[display_element_kop].id = display_element_kop;
		displayElements[display_element_kop].x = x;
		displayElements[display_element_kop].y = y;
		displayElements[display_element_kop].width = w;
		displayElements[display_element_kop].height = h;
		displayElements[display_element_kop].picture_or_text = pic;
		displayElements[display_element_kop].what = 0;

		display_element_kop++;
	}

	return (display_element_kop - 1);
}

/**
 * @brief  Funcion que inserta texto en el buffer intermedio
 *
 * @return        Valor numerico que representa el identificador del texto insertado
 *
*/
int FRAME_BUFFER_insertText(char *texto, int x, int y){
	if(display_element_kop < MAX_ELEMS){
		displayElements[display_element_kop].id = display_element_kop;
		displayElements[display_element_kop].xOld = displayElements[display_element_kop].x + strlen(displayElements[display_element_kop].picture_or_text);
		displayElements[display_element_kop].yOld = displayElements[display_element_kop].y;
		displayElements[display_element_kop].x = x;
		displayElements[display_element_kop].y = y;
		displayElements[display_element_kop].picture_or_text = texto;
		displayElements[display_element_kop].what = 1;

		display_element_kop++;
	}

	return (display_element_kop - 1);
}

/**
 * @brief  Funcion que quita un elemento del buffer intermedio
 *
*/
void FRAME_BUFFER_deleteElement(int id){
	int i = 0; //contador primario para mover el elemento de la posicion primaria a la secundaria
	int j = 0; //contador secundario para mover el elemento de la posicion primaria a la secundaria

	while(i < display_element_kop){
		if(displayElements[i].id == id){
			j = i + 1;
			while(j < display_element_kop){
				displayElements[i].id = displayElements[j].id;
				displayElements[i].x = displayElements[j].x;
				displayElements[i].y = displayElements[j].y;
				displayElements[i].width = displayElements[j].width;
				displayElements[i].height = displayElements[j].height;
				displayElements[i].picture_or_text = displayElements[j].picture_or_text;
				displayElements[i].what = displayElements[j].what;
				i++;
				j++;
			}
			display_element_kop--;
		}
		i++;
	}
}

/**
 * @brief  Funcion que actualiza la posicion del elemento
 *
*/
void FRAME_BUFFER_actualizarPosicionElemento(int id, int x, int y){
	int x_actual; //posicion horizontal actual
	int y_actual; //posicion vertical actual

	// 1-Obtener posicion actual
	x_actual = displayElements[id].x;
	y_actual = displayElements[id].y;

	// 2-Borrar del frame buffer
	displayElements[id].xOld = displayElements[id].x;
	displayElements[id].yOld = displayElements[id].y;

	// 3-Actualiza el valor
	displayElements[id].x = x;
	displayElements[id].y = y;
}

/**
 * @brief  Funcion que escribe la informacion del buffer intermedio en el display
 *
*/
void FRAME_BUFFER_writeToDisplay(void){
	int i = 0; //contador
	int size = 0; //tamaño del texto que hay introducido en la memoria
	int index = 0; //contador para borrar el texto de la memoria
	char str[30]; //memoria temporal que se usa para borrar el display

	for(i = 0; i < display_element_kop; i++){
		if((displayElements[i].xOld != displayElements[i].x) || (displayElements[i].yOld != displayElements[i].y)){
			if(displayElements[i].what == 1){
				size = displayElements[i].xOld;
				for(index = 0; index <size; index++){
					str[index] = ' ';
				}
				str[index] = '\0';

				DISPLAY_dibujarTexto(str,displayElements[i].xOld, displayElements[i].yOld, 15);
				DISPLAY_dibujarTexto(displayElements[i].picture_or_text, displayElements[i].x,
						displayElements[i].y, 15);
			} else{
				DISPLAY_dibujarImagen(PIXEL_VACIO, displayElements[i].xOld, displayElements[i].yOld,
						displayElements[i].width, displayElements[i].height);
				DISPLAY_dibujarImagen(displayElements[i].picture_or_text, displayElements[i].x, displayElements[i].y,
						displayElements[i].width, displayElements[i].height);
			}
		}
	}
}
