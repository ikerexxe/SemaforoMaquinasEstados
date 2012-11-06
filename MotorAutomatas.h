//Acordaros de añadir comentarios a los documentos

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
** TYPEDEFS AND STRUCTURES 											**
** 																	**
**********************************************************************/
typedef char BYTE;

//Definicion del tipo Accion y Evento
typedef void (*TPNF_ACC)(void);
typedef tBoolean (*TPNF_EVE)(void);

//Definicion del tipo de dato que representa una transicion
typedef struct{
	BYTE 			id; /*Identificador del estado destino */
	char 		  * nombre; /*Nombre identificativo de depuración*/
	TPNF_EVE 		evento; /*Puntero a la función evento*/
	TPNF_ACC 		accion; /*Puntero a la función evento*/
} TS_EVEACC;

//Definición del tipo Estado
typedef struct {
	  BYTE          id;             /* Identificador del estado */
	  char        * nombre;         /* Nombre identificativo de depuraci¢n */
	  TPNF_EVE      controles;      /* Funci¢n de control del estado */
	  TS_EVEACC   * funcion;        /* Punteros a las funciones del estado */
} TS_ESTADO;

//Definición del tipo Maquina de estado
typedef struct {
	  BYTE          id;             /* Identificador del automata */
	  char        * nombre;         /* Nombre identificativo de depuraci¢n */
	  TPNF_EVE      StopCond;       /* Condici¢n necesaria para la ejecuci¢n */
	  TS_ESTADO   **estado;         /* Matriz de punteros a los ESTADOS */
} TS_AUTOMATA;

/*********************************************************************
** 																	**
** DEFINITIONS AND MACROS 											**
** 																	**
**********************************************************************/
#define ITEM_EAC(ident,event,acci) { ident, #event, event, acci }
#define ESTADO(nombre_estado) private const TS_EVEACC x##nombre_estado[]={
#define FIN_ESTADO(nombre_fin_estado,ident_fin_estado,control),{0,NULL,NULL,NULL}};private const TS_ESTADO nombre_fin_estado = {ident_fin_estado,#ident_fin_estado,control,(TS_EVEACC *)  x##nombre_fin_estado};
#define AUTOMATA(nombre_automata) private const TS_ESTADO * const(x##nombre_automata[]) = {
#define FIN_AUTOMATA(nombre_fin_automata,ident,StopC),NULL}; public const TS_AUTOMATA nombre_fin_automata = {ident,#nombre_fin_automata,StopC,(TS_ESTADO **) x##nombre_fin_automata};

#define NULL 0

/*********************************************************************
** 																	**
** PROTOTYPES OF LOCAL FUNCTIONS 									**
** 																	**
*********************************************************************/

void EjecutaAutomata( TS_AUTOMATA *elAutomata);
void EjecutaEstado  ( TS_ESTADO   *elEstado);
