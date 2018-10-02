/** \brief Crea la visual de un menu. se enumera con letras
 *
 * \param int  cantidad de opciones
 * \param ...   descripcion de las opciones
 * \return int
 *
 */
int printListStrings(int, ...);
/** \brief el programa espera hasta que el usuario ingrese una letra y devuelve el orden que tiene
 *         en el abecedario.
 *
 * \param int   la cantidad de opciones
 * \param char[]  el mensaje a mostrar
 * \return int  el orden de la letra(A=0... z=26)
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
