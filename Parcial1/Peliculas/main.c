#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuSystem.h"
#include "pelicula.h"
#define PELICULAS_TAMANIO 1000
#define DIRECTOR_TAMANIO 500

int main()
{
    int retorno;
    ePelicula listadoPeliculas[PELICULAS_TAMANIO];
    eDirector listadoDirector[DIRECTOR_TAMANIO];

    ePelicula_initialize(listadoPeliculas, PELICULAS_TAMANIO);
    eDirector_initialize(listadoDirector,DIRECTOR_TAMANIO);
    eDirector_hardcode(listadoDirector,DIRECTOR_TAMANIO);
    ePelicula_hardcode(listadoPeliculas,PELICULAS_TAMANIO);

    retorno = ePelicula_menu(listadoPeliculas,PELICULAS_TAMANIO,listadoDirector,DIRECTOR_TAMANIO);

    return retorno;
}
