/**	@mainpage Project: Semaforo con maquinas de estado
 *
 *  DESCRIPCION DE LA APLICACCÓN:
 *  @brief Esta aplicacion ofrece un ejemplo de como implementar un semaforo mediante una
 *  maquina de estados basado en una placa ARM Cortex-m3 TI lm3s8962 .
 *
 * ORGANIZACIÓN DEL PROGRAMA:
 *	
 *	El proyecto consta de un fichero principal llamado "main.c".
 *  Las funciones correspondientes al clock del micro ("microLM3S.c"),
 *  al Display ("display.c"),y al automata del semaforo ("MotorAutomatas.c" y "Sem.c")
 *  han sido definidas en 	distintos ficheros, cada uno con sus respectivos 
 *	nombres y ficheros de cabecera, de manera que pueden ser reemplazadas fácilmente en el
 *	caso de que el HW utilizado no sea exactamnete el mismo. 
 *	Por otra parte, el fichero "Sem.c" y "MotorAutomatas.c" hacen uso del Frame Buffer
 *  definido en "frameBuffer.c" para hacer mejor uso de la pantalla.
 *  Éste Frame Buffer es genérico, es decir,no está especificado para ningún display en concreto,
 *  por lo tanto, hace uso del fichero "displaylm3s.c" para utilizar las funciones específicas
 *  del display RIT128x94x4.
 * 
 *  Todos los ficheros. c se encuentran en la carpeta "sources" y los ficheros cabecera
 *  en la carpeta "headers"
 *
 *	
 *  @version v0.0
 *
 *  @date 2012-24-10
 *
 *  @par Descripcion
 *  Esta aplicacion recrea un semaforo con tres colores, rojo, amarillo y verde,
 *	utilizando la plataform ARM Cortex-m3 TI lm3s8962. Cada color tiene una duracion en
 *  pantalla de tres segundos.
 *  Para ello se usa una maquina de estados.
 *
 *	@par
 *	El cambio de colores se visualiza mediante el display.
*/