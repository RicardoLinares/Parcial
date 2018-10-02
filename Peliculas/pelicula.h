#define OCUPADO 1
#define DESHABILITADO -1
#define LIBRE 0

#define TAMNOMBRES 50
#define TAMNACIONALIDAD 30
#define DESHABILITADO -1


typedef struct
{
    char titulo[TAMNOMBRES];
    int director;
    int anio;
    char nacionalidad[TAMNACIONALIDAD];

    //------------ agregar en base lo que se necesite
    // int NumeroNatural
    // int
    int idPelicula;
    int estado;
}ePelicula;

/** \brief Crea un id para un elemento de una estructura, en base la posicion en el array.
 *
 * \param ePelicula[]   el array de estructura.
 * \param int la longitud del array.
 * \return int  ID generado.
 *
 */
int ePelicula_siguienteId(ePelicula[], int);

/** \brief Inicializa un array de estructura en un valor de estado libre
 *
 * \param ePelicula[]   el array de estructura a inicializar
 * \param int   el tamanio del array
 * \return int  devuelve si se pudo hacer la operacion
 *
 */
int ePelicula_init( ePelicula[], int);

/** \brief Busca un elemento en un array de estructura que tenga el campo estado en LIBRE.
 *
 * \param ePelicula[] el array de estructuras donde esta el elemento
 * \param int   el tamanio del array
 * \return int  la posicion dentro del array del elemento libre
 *
 */
int ePelicula_buscarLugarLibre(ePelicula[],int);

/** \brief busca en un array de estructura en base un identificardor
 *
 * \param ePelicula[] array de estructura a buscar
 * \param int el tamanio del array
 * \param int  el identificador que se quiere encontrar
 * \return int la posicion del identificador dentro del array(sino devuelve -1 indicando que no existe)
 *
 */
int ePelicula_buscarPorId(ePelicula[],int, int);

/** \brief Ingresa la informacion para un elemento de un array de estructuras
 *
 * \param ePelicula[] el array donde se guardara el elmento
 * \param int  el tamanio del array
 * \return int
 *
 */
int ePelicula_alta(ePelicula[],int);

int ePelicula_baja(ePelicula[],int, char[]);

int ePelicula_modificacion(ePelicula[],int, char[]);

int ePelicula_MostrarListado(ePelicula[], int);

int ePelicula_Mostrar(ePelicula, int);

int ePelicula_ingresarNombre(ePelicula*, int);

void ePelicula_ingresarAnio(ePelicula*, char[], int);

void ePelicula_ingresarIdDirector(ePelicula*, char[], int);

int ePelicula_ingresarNacionalidad(ePelicula*, int);


int ePelicula_confirmacion(char[], char);