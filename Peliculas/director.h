#define OCUPADO 1
#define DESHABILITADO -1
#define LIBRE 0

typedef struct
{
    char nombre[50];
    //------------ agregar en base lo que se necesite
    // int NumeroNatural
    // int
    int idGenerica;
    int estado;
}eGenerica;


/** \brief Crea un id para un elemento de una estructura, en base la posicion en el array.
 *
 * \param eGenerica[]   el array de estructura.
 * \param int la longitud del array.
 * \return int  ID generado.
 *
 */
int eGen_siguienteId(eGenerica[], int);

/** \brief Inicializa un array de estructura en un valor de estado libre
 *
 * \param eGenerica[]   el array de estructura a inicializar
 * \param int   el tamanio del array
 * \return int  devuelve si se pudo hacer la operacion
 *
 */
int eGen_init( eGenerica[], int);

/** \brief Busca un elemento en un array de estructura que tenga el campo estado en LIBRE.
 *
 * \param eGenerica[] el array de estructuras donde esta el elemento
 * \param int   el tamanio del array
 * \return int  la posicion dentro del array del elemento libre
 *
 */
int eGen_buscarLugarLibre(eGenerica[],int);

/** \brief busca en un array de estructura en base un identificardor
 *
 * \param eGenerica[] array de estructura a buscar
 * \param int el tamanio del array
 * \param int  el identificador que se quiere encontrar
 * \return int la posicion del identificador dentro del array(sino devuelve -1 indicando que no existe)
 *
 */
int eGen_buscarPorId(eGenerica[],int, int);

/** \brief Ingresa la informacion para un elemento de un array de estructuras
 *
 * \param eGenerica[] el array donde se guardara el elmento
 * \param int  el tamanio del array
 * \return int
 *
 */
int eGen_alta(eGenerica[],int);

int eGen_baja(eGenerica[],int, char[]);

int eGen_modificacion(eGenerica[],int, char[]);

int eGen_MostrarListado(eGenerica[], int);

int eGen_Mostrar(eGenerica, int);

int eGen_ingresarNombre(eGenerica*);

int eGen_InfoGrid(void);
