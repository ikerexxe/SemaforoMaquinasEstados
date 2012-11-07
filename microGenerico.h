/** @addtogroup MINI_PIANO_MODULE
*
* @{

* @file stellaris.h
* @brief La interfaz generica de acceso a las configuraciones del microprocesador
*
* @version v0.0
* @date   	2012-10-10
*
* @note gpl2 license  2011, Iker Pedrosa
*
* @par VERSION HISTORY
* Version : 1
* Date : 2012-10-11
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
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/gpio.h"

/*********************************************************************
** 																	**
** PROTOTYPES OF LOCAL FUNCTIONS 									**
** 																	**
*********************************************************************/

/**
 * @brief  Funcion que inicializa el reloj
 *
*/
void MICRO_init();
