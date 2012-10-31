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

#ifndef framBuffer_h
	#define framBuffer_h
	#include "frameBuffer.h"
#endif

#ifndef displayGenerico_h
	#define displayGenerico_h
	#include "displayGenerico.h"
#endif
#ifndef sem_h
	#define sem_h
	#include "sem.h"
#endif

int main(void)
{
	DISPLAY_init();
    while(1)
    {

    }
}
