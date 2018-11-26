#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>


/** \brief Crea la visual de un menu. se enumera con Numeros
 *
 * \param int  cantidad de opciones
 * \param ...   descripcion de las opciones
 * \return int
 *
 */
int printListStrings(int, ...);
/** \brief el programa espera hasta que el usuario ingrese un Numero y devuelve la posicion indexada
 *
 *
 * \param int   la cantidad de opciones
 * \param char[]  el mensaje a mostrar
 * \return int  la posicion indexada(1=0... n=n+1)
 *
 */
int waitsForMenuInput(int,char[]);

/** \brief el programa se detiene haste el proximo enter y despues limpia la consola
 *
 * \param void No pide ningun valor
 * \return void no devuelve nada
 *
 */
void clearConsole(void);


/** \brief Limpia la consola instantaneamente(Funcion para linux)
 *
 * \param void No pide ningun valor
 * \return void No devuelve nada
 *
 */
void clearConsoleQuick(void);

/** \brief Crea la visual de un menu. se enumera con letras
 *
 * \param int  cantidad de opciones
 * \param ...   descripcion de las opciones
 * \return int
 *
 */
int printListStringsChars(int, ...);
 /** \brief el programa espera hasta que el usuario ingrese una letra y devuelve el orden que tiene
 *         en el abecedario.
 *
 * \param int   la cantidad de opciones
 * \param char[]  el mensaje a mostrar
 * \return int  el orden de la letra(A=0... z=26)
 *
 */
int waitsForMenuInputChars(int, char[]);
