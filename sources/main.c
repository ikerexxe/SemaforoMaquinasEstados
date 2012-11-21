/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file main.c
* @brief Clase principal
*
* @version v0.0
* @date   	2012-10-31
*
* @note gpl2 license  2011, Iratxe Trevejo
*
* @par VERSION HISTORY
* Version : 1
* Date : 2012-10-31
* Revised by : iratxe.trevejo@alumni.mondragon.edu
* Description : Original version.
*
* @}
*/

/*********************************************************************
**																	**
** MODULES USED 													**
** 																	**
**********************************************************************/
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"

#ifndef FRAMEBUFFER_H
	#define FRAMEBUFFER_H
	#include "headers/frameBuffer.h"
#endif
#ifndef DISPLAYGENERICO_H
	#define DISPLAYGENERICO_H
	#include "headers/displayGenerico.h"
#endif
#ifndef MICRO_H
	#define MICRO_H
	#include "headers/microGenerico.h"
#endif
#ifndef SEM_H
	#define SEM_H
	#include "headers/sem.h"
#endif
#ifndef MOTORAUTOMATAS_H
	#define MOTORAUTOMATAS_H
	#include "motorAutomatas.h"
#endif

/*********************************************************************
** 																	**
** EXPORTED VARIABLES 												**
** 																	**
*********************************************************************/
extern TS_AUTOMATA Semaforo;
/*********************************************************************
** 																	**
** LOCAL FUNCTIONS 													**
** 																	**
**********************************************************************/

/**
 * @brief  Funcion que inicializa la aplicación
 * Se inicializa en dispositibo y empieza a ejecutar el automata
 *
*/
int main(void)
{
	MICRO_init();//inicializar el micro
	DISPLAY_init();//inicializar el display
	//Inserta texto en el display
	FRAME_BUFFER_insertText("Rojo", 5, 5);
	FRAME_BUFFER_insertText("Ambar", 5, 25);
	FRAME_BUFFER_insertText("Verde", 5, 45);
	//vuelca al display lo insertado en el buffer frame
	FRAME_BUFFER_writeToDisplay();

    while(1)
    {
    	EjecutaAutomata(&Semaforo);//ejecuta el automata
    }
}


