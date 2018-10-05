#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "director.h"
#include "menuSystem.h"
#include "texto.h"


int eGen_buscarPorId(eGenerica listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idGenerica == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_init( eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idGenerica= 0;
        }
    }
    return retorno;
}

int eGen_siguienteId(eGenerica listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idGenerica>retorno)
                {
                    retorno=listado[i].idGenerica;
                }
            }
        }
    }

    return retorno+1;
}

int eGen_buscarLugarLibre(eGenerica listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eGen_alta(eGenerica  listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eGen_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            retorno = -3;
            id = eGen_siguienteId(listado,limite);

            //if(!getValidString("Nombre?","Error","Overflow", nombre,50,2))
            //{
            retorno = 0;
            eGen_ingresarNombre(&listado[indice].nombre);
            listado[indice].idGenerica = id;
            listado[indice].estado = OCUPADO;
            eGen_Mostrar(listado[indice], 1);
            //}
        }
    }
    return retorno;
}

int eGen_baja(eGenerica  listado[],int limite, char mensaje[])
{
    int retorno = -1;
    char opcion;
    int auxiliar;
    int busqueda = -1;
    if(limite > 0 && listado != NULL)
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        scanf("%d", &auxiliar);
        busqueda = eGen_buscarPorId(listado,limite,auxiliar);
        if(busqueda >= 0 && busqueda < limite)
        {
            eGen_Mostrar(listado[busqueda], 1);
            printf("Esta Seguro que quiere dar de baja (y): ");
            __fpurge(stdin);
            opcion = getchar();
            opcion = tolower(opcion);
            if(opcion == 'y')
            {
                printf("BAJA exitosa");
                listado[busqueda].estado = DESHABILITADO;
            }
        }
        else
        {
            printf("No se encontro el elemento");
        }
    }
    return retorno;
}


int eGen_modificacion(eGenerica  listado[],int limite, char mensaje[])
{
    int retorno = -1;
    char opcion;
    int auxiliar;
    int salir;
    int busqueda = -1;
    if(limite > 0 && listado != NULL)
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        scanf("%d", &auxiliar);
        busqueda = eGen_buscarPorId(listado,limite,auxiliar);
        if(busqueda >= 0 && busqueda < limite)
        {
            clearConsoleQuick();
            do
            {
                printf("Que desea modificar de:\n");
                eGen_Mostrar(listado[busqueda], 1);
                printListStrings(2,"Modificar Nombre", "Cancelar");
                opcion = waitsForMenuInput(2, "Eliga su opcion: ");

                switch(opcion)
                {
                case 0:
                    eGen_ingresarNombre(&listado[busqueda]);
                    salir = 1;
                    break;
                case 1:
                    printf("Modificacion Cancelada\n");
                    salir = 1;
                    break;
                default:
                    printf("No ingreso una opcion valida\n");
                    break;
                }
                if(!salir)
                {
                    clearConsole();
                }
            }
            while(salir!=1);
        }
        else
        {
            printf("No se encontro el elemento");
        }
    }
    return retorno;
}


int eGen_Mostrar(eGenerica estructura, int isAlone)
{
    int retorno = -1;
    if(isAlone == 0)
    {
        printf("%15s %10s\n", "NOMBRE", "ID");
    }
    printf("%15s %10d\n", estructura.nombre, estructura.idGenerica);
    retorno = 0;
    return retorno;
}

int eGen_ingresarNombre(eGenerica *estructura)
{
    int retorno = -1;
    putLineInString(estructura->nombre, 50, "Ingrese el nombre: ");
    toCamelCase(estructura->nombre);
    return retorno;
}
int eGen_MostrarListado(eGenerica listado[], int limite)
{
    int retorno;
    int indice;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(indice = 0; indice < limite; indice++)
        {
            if(listado[indice].estado == OCUPADO)
            {
                eGen_Mostrar(listado[indice], indice);
            }
        }
        retorno = -3;
    }

    return retorno;
}
