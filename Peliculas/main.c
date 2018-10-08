#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuSystem.h"
#include "pelicula.h"
#define PELICULAS_TAMANIO 1000
#define DIRECTOR_TAMANIO 500

int main()
{
    ePelicula listadoPeliculas[PELICULAS_TAMANIO];
    eDirector listadoDirector[DIRECTOR_TAMANIO];

    ePelicula_initialize(listadoPeliculas, PELICULAS_TAMANIO);
    eDirector_initialize(listadoDirector,DIRECTOR_TAMANIO);
    eDirector_hardcode(listadoDirector,DIRECTOR_TAMANIO);
    ePelicula_hardcode(listadoPeliculas,PELICULAS_TAMANIO);

    int option;
    int proceso;

    do
    {
        printf("Peliculas del teatro:\n");
        printListStrings(8, "ALTAS PELICULAS:"
                         , "MODIFICAR DATOS DE UNA PELICULA:"
                         , "BAJA DE PELICULA:"
                         , "NUEVO DIRECTOR:"
                         , "ELIMINAR DIRECTOR:"
                         , "LISTAR PELICULAS:"
                         , "LISTAR DIRECTORES:"
                         , "SALIR");
        option = waitsForMenuInput(8,"Eliga su opcion: ");

        switch(option)
        {
        case 0:
            proceso = ePelicula_alta(listadoPeliculas, PELICULAS_TAMANIO, listadoDirector, DIRECTOR_TAMANIO);
            if(proceso == -2)
            {
                printf("ERROR: no hay mas espacio");
            }
            break;
        case 1:
            ePelicula_modificacion(listadoPeliculas, PELICULAS_TAMANIO, "Ingrese el id de la pelicula: ",
                                    listadoDirector, DIRECTOR_TAMANIO);
            break;
        case 2:
            ePelicula_baja(listadoPeliculas, PELICULAS_TAMANIO, "Ingrese el id de la pelicula: ", listadoDirector,
                            DIRECTOR_TAMANIO);
            break;
        case 3:
            proceso = eDirector_alta(listadoDirector, DIRECTOR_TAMANIO);
            if(proceso == -2)
            {
                printf("ERROR: no hay mas espacio");
            }
            break;
        case 4:
            ePelicula_bajaDirector(listadoDirector,DIRECTOR_TAMANIO,listadoPeliculas,PELICULAS_TAMANIO);
            break;
        case 5:
            proceso = ePelicula_MostrarListado(listadoPeliculas, PELICULAS_TAMANIO, listadoDirector,
                                                DIRECTOR_TAMANIO);
            break;
        case 6:
            proceso = eDirector_MostrarListado(listadoDirector, DIRECTOR_TAMANIO);
            break;
        case 7:
            printf("Adios");
            break;
        default:
            printf("No ingreso una opcion valida");
        }
        clearConsole();
    }
    while(option!=7);
    return 0;
}
