//Acordaros de añadir comentarios a los documentos

//Definicion del tipo Accion y Evento
typedef void (*TPNF_ACC)(void);
typedef BOOLEAN (*TPNF_EVE)(void);

//Definicion del tipo de dato que representa una transicion
typedef struct{
	BYTE id; /*Identificador del estado destino */
	char *nombre; /*Nombre identificativo de depuración*/
	TPNF_EVE evento; /*Puntero a la función evento*/
	TPNF_ACC accion; /*Puntero a la función evento*/
}TS_EVEACC;

//Definición del tipo Estado
typedef struct {
	  BYTE          id;             /* Identificador del estado */
	  char        * nombre;         /* Nombre identificativo de depuraci¢n */
	  TPFN_ACC      controles;      /* Funci¢n de control del estado */
	  TS_EVEACC   * funcion;        /* Punteros las funciones del estado */
} TS_ESTADO;

//Definición del tipo Maquina de estado
typedef struct {
	  BYTE          id;             /* Identificador del automata */
	  char        * nombre;         /* Nombre identificativo de depuraci¢n */
	  TPFN_EVE      StopCond;       /* Condici¢n necesaria para la ejecuci¢n */
	  TS_ESTADO   **estado;         /* Matriz de punteros a los ESTADOS */
} TS_AUTOMATA;

void EjecutaAutomata( TS_AUTOMATA *elAutomata);
void EjecutaEstado  ( TS_ESTADO   *elEstado);

//MACROS
#define ITEM_EAC(ident,event,acci) { ident, #event, event, acci }
#define ESTADO(nombre) private const TS_EVEACC x##nombre[]={
#define FIN_ESTADO(nombre,ident,control),{0,NULL,NULL,NULL}}; private const TS_ESTADO nombre = {ident,#ident,control,(TS_EVEACC *)  x##nombre};
#define AUTOMATA(nombre) private const TS_ESTADO * const(x##nombre[]) = {
#define FIN_AUTOMATA(nombre,ident,StopC),NULL}; public const TS_AUTOMATA nombre = {ident,#nombre,StopC,(TS_ESTADO **) x##nombre};
