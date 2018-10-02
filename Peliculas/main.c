#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pelicula.h"
#include "menuSystem.h"
#define PELICULAS_TAMANIO 3

int main()
{
    ePelicula listadoPeliculas[PELICULAS_TAMANIO];
    ePelicula_init(listadoPeliculas, PELICULAS_TAMANIO);
    int option;
    int proceso;
    do
    {
        printf("Peliculas del teatro:\n");
        printListStrings(5, "Agregar Una Pelicula"
                         , "Modificar Informacion de la pelicula"
                         , "Quitar Pelicula "
                         , "Mostrar Todas las peliculas"
                         , "Salir");
        option = waitsForMenuInput(5,"Eliga su opcion: ");

        switch(option)
        {
        case 0:
            proceso = ePelicula_alta(listadoPeliculas, PELICULAS_TAMANIO);
            if(proceso == -2)
            {
                printf("ERROR: no hay mas espacio");
            }
            break;
        case 1:
            ePelicula_modificacion(listadoPeliculas, PELICULAS_TAMANIO, "Ingrese el id de la pelicula: ");
            break;
            case 2:
            ePelicula_baja(listadoPeliculas, PELICULAS_TAMANIO, "Ingrese el id de la pelicula: ");
            break;
        case 3:
            ePelicula_MostrarListado(listadoPeliculas, 10);

            break;
        case 4:
            printf("Adios!!\n");
            break;
        default:
            printf("No ingreso una opcion valida");
        }
        clearConsole();
    }
    while(option!=4);
    return 0;
}
