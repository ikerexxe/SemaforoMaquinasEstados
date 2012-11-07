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
	#include "frameBuffer.h"
#endif
/*#ifndef DISPLAYGENERICO_H
	#define DISPLAYGENERICO_H
	#include "displayGenerico.h"
#endif*/
#ifndef SEM_H
	#define SEM_H
	#include "sem.h"
#endif
#ifndef MOTOR_H
	#define MOTOR_H
	#include "motorAutomatas.h"
#endif

/*********************************************************************
** 																	**
** EXPORTED VARIABLES 												**
** 																	**
*********************************************************************/
extern TS_AUTOMATA Semaforo;

int main(void)
{
	SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |SYSCTL_XTAL_8MHZ);
	SysTickPeriodSet(8000000); // periodo=1 seg
	SysTickIntEnable();
	SysTickEnable();
	IntMasterEnable();
	Inicializar_pantalla();//DISPLAY_init();
	FRAME_BUFFER_insertar_texto("Rojo", 5, 5);
	FRAME_BUFFER_insertar_texto("Ambar", 25, 5);
	FRAME_BUFFER_insertar_texto("Verde", 45, 5);
    while(1)
    {
    	EjecutaAutomata(&Semaforo);
    }
}


