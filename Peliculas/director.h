#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menuSystem.h"
#include "texto.h"

#define OCUPADO 1
#define DESHABILITADO -1
#define LIBRE 0

#define TAMNOMBRES 50
#define TAMNACIONALIDAD 30
#define DESHABILITADO -1


typedef struct
{
    char nombre[TAMNOMBRES];
    int idDirector;
    int estado;
}eDirector;

/** \brief Crea un id para un elemento de una estructura, en base la posicion en el array.
 *
 * \param eDirector[]   el array de estructura.
 * \param int la longitud del array.
 * \return int  ID generado.
 *
 */
int eDirector_siguienteId(eDirector[], int);

/** \brief Inicializa un array de estructura en un valor de estado libre
 *
 * \param eDirector[]   el array de estructura a inicializar
 * \param int   el tamanio del array
 * \return int  devuelve si se pudo hacer la operacion
 *
 */
int eDirector_init( eDirector[], int);

/** \brief Busca un elemento en un array de estructura que tenga el campo estado en LIBRE.
 *
 * \param eDirector[] el array de estructuras donde esta el elemento
 * \param int   el tamanio del array
 * \return int  la posicion dentro del array del elemento libre
 *
 */
int eDirector_buscarLugarLibre(eDirector[],int);

/** \brief busca en un array de estructura en base un identificardor
 *
 * \param eDirector[] array de estructura a buscar
 * \param int el tamanio del array
 * \param int  el identificador que se quiere encontrar
 * \return int la posicion del identificador dentro del array(sino devuelve -1 indicando que no existe)
 *
 */
int eDirector_buscarPorId(eDirector[],int, int);

/** \brief Ingresa la informacion para un elemento de un array de estructuras
 *
 * \param eDirector[] el array donde se guardara el elmento
 * \param int  el tamanio del array
 * \return int
 *
 */
int eDirector_alta(eDirector[],int);

/** \brief
 *
 * \param eDirector[]
 * \param int
 * \param char[]
 * \return int
 *
 */
int eDirector_baja(eDirector[],int, char[]);

/** \brief
 *
 * \param eDirector[]
 * \param int
 * \param char[]
 * \return int
 *
 */
int eDirector_modificacion(eDirector[],int, char[]);

/** \brief
 *
 * \param eDirector[]
 * \param int
 * \return int
 *
 */
int eDirector_MostrarListado(eDirector[], int);

/** \brief
 *
 * \param eDirector
 * \param int
 * \return int
 *
 */
int eDirector_Mostrar(eDirector, int);

/** \brief
 *
 * \param eDirector*
 * \param int
 * \return int
 *
 */
int eDirector_ingresarNombre(eDirector*, int);

/** \brief
 *
 * \param eDirector*
 * \param char[]
 * \param int
 * \return void
 *
 */
void eDirector_ingresarAnio(eDirector*, char[], int);

/** \brief
 *
 * \param eDirector*
 * \param char[]
 * \param int
 * \return void
 *
 */
void eDirector_ingresarIdDirector(eDirector*, char[], int);

/** \brief
 *
 * \param eDirector*
 * \param int
 * \return int
 *
 */
int eDirector_ingresarNacionalidad(eDirector*, int);


/** \brief
 *
 * \param char[]
 * \param char
 * \return int
 *
 */
int eDirector_confirmacion(char[], char);

int eDirector_validarListar(eDirector*, int);

int eDirector_buscarPorString(eDirector*, int, char*);
