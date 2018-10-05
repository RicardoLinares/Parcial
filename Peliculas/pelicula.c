#include "pelicula.h"



int ePelicula_buscarPorId(ePelicula listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idPelicula == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePelicula_init( ePelicula listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idPelicula= 0;
        }
    }
    return retorno;
}

int ePelicula_siguienteId(ePelicula listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idPelicula>retorno)
                {
                    retorno=listado[i].idPelicula;
                }
            }
        }
    }

    return retorno+1;
}

int ePelicula_buscarLugarLibre(ePelicula listado[],int limite)
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

int ePelicula_alta(ePelicula  listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = ePelicula_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            id = ePelicula_siguienteId(listado,limite);
            ePelicula_ingresarNombre(&listado[indice], 0);
            ePelicula_ingresarAnio(&listado[indice], "ingrese año de estreno: ", 0);
            ePelicula_ingresarNacionalidad(&listado[indice], 0);
            ePelicula_ingresarIdDirector(&listado[indice],"ingrese el ID del director: ", 0);
            listado[indice].idPelicula = id;
            listado[indice].estado = OCUPADO;
            ePelicula_Mostrar(listado[indice], 1);
            retorno = 0;
        }
    }
    return retorno;
}

int ePelicula_baja(ePelicula  listado[],int limite, char mensaje[])
{
    int retorno = -1;
    char opcion;
    int auxiliar;
    int busqueda = -1;
    int listaEstado;

    listaEstado = ePelicula_MostrarListado(listado, limite);
    if(listaEstado == 0)
    {
        if(limite > 0 && listado != NULL)
        {
            printf("%s", mensaje);
            __fpurge(stdin);
            scanf("%d", &auxiliar);
            busqueda = ePelicula_buscarPorId(listado,limite,auxiliar);
            if(busqueda >= 0 && busqueda < limite)
            {
                ePelicula_Mostrar(listado[busqueda], 1);
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
    }
    return retorno;
}


int ePelicula_modificacion(ePelicula  listado[],int limite, char mensaje[])
{
    int retorno = -1;
    char opcion;
    int auxiliar;
    int salir;
    int busqueda = -1;
    int listaEstado;

    listaEstado = ePelicula_MostrarListado(listado, limite);
    if(listaEstado == 0)
    {
        if(limite > 0 && listado != NULL)
        {
            printf("%s", mensaje);
            __fpurge(stdin);
            scanf("%d", &auxiliar);
            busqueda = ePelicula_buscarPorId(listado,limite,auxiliar);
            if(busqueda >= 0 && busqueda < limite)
            {
                clearConsoleQuick();
                do
                {
                    printf("Que desea modificar de:\n");
                    ePelicula_Mostrar(listado[busqueda], 1);
                    printListStrings(5
                                     , "Modificar Titulo"
                                     , "Modificar Año de estreno"
                                     , "Modificar Nacionalidad"
                                     , "Modificar Director"
                                     , "Cancelar");
                    opcion = waitsForMenuInput(5, "Eliga su opcion: ");

                    switch(opcion)
                    {
                    case 0:
                        ePelicula_ingresarNombre(&listado[busqueda], 1);
                        salir = 1;
                        break;
                    case 1:
                        ePelicula_ingresarAnio(&listado[busqueda], "Ingrese el Año de estreno: ", 1);
                        salir = 1;
                        break;
                    case 2:
                        ePelicula_ingresarNacionalidad(&listado[busqueda], 1);
                        salir = 1;
                        break;
                    case 3:
                        ePelicula_ingresarIdDirector(&listado[busqueda], "Ingrese el ID del director: ", 1);
                        salir = 1;
                        break;
                    case 4:
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
                if(opcion != 4)
                {
                    ePelicula_Mostrar(listado[busqueda], 1);
                }
            }
            else
            {
                printf("No se encontro el elemento");
            }
        }
    }
    return retorno;
}


int ePelicula_Mostrar(ePelicula estructura, int isAlone)
{
    int retorno = -1;
    if(isAlone == 1)
    {
        printf("%2s %4s %20s %17s %25s\n", "ID", "AÑO","Nacionalidad", "Director", "NOMBRE");
    }
    printf("%2d %4d %20s %15d %25s\n", estructura.idPelicula
           , estructura.anio
           , estructura.nacionalidad
           , estructura.director
           , estructura.titulo);
    retorno = 0;
    return retorno;
}

int ePelicula_ingresarNombre(ePelicula *estructura, int modificacion)
{
    int retorno = -1;
    int modificacionFlag;
    char buffer[1024];
    putLineInString(buffer, TAMNOMBRES, "Ingrese el titulo: ");
    toCamelCase(buffer);
    if(modificacion)
    {
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar el año de estreno? (y): ", 'y');
        if(modificacionFlag == -1)
        {
            printf("Modificacion Cancelada...\n");
        }
        else
        {
            strcpy(estructura->titulo, buffer);
        }
    }
    else
    {
        strcpy(estructura->titulo, buffer);
    }
    return retorno;
}

int ePelicula_ingresarNacionalidad(ePelicula *estructura, int modificacion)
{
    int retorno = -1;
    int modificacionFlag;
    char buffer[1024];
    putLineInString(buffer, TAMNOMBRES, "Ingrese el nacionalidad: ");
    toCamelCase(buffer);

    if(modificacion)
    {
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar el año de estreno? (y): ", 'y');
        if(modificacionFlag == -1)
        {
            printf("Modificacion Cancelada...\n");
        }
        else
        {
            strcpy(estructura->nacionalidad, buffer);
        }
    }
    else
    {
        strcpy(estructura->nacionalidad, buffer);
    }

    return retorno;
}
int ePelicula_MostrarListado(ePelicula listado[], int limite)
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
                if(indice == 0)
                {
                    printf("%2s %4s %20s %17s %25s\n", "ID", "AÑO","Nacionalidad", "Director", "NOMBRE");
                }
                ePelicula_Mostrar(listado[indice], 0);
                retorno = 0;
            }
        }
    }
    if(retorno == -2)
    {
        printf("No hay peliculas en la lista...\n");
    }
    return retorno;
}

void ePelicula_ingresarIdDirector(ePelicula* pelicula, char mensaje[], int modificacion)
{
    char buffer[1024];
    int i;
    int invalido;
    int longitud;
    int modificacionFlag;
    int auxiliar;
    do
    {
        invalido = 0;
        printf("%s", mensaje);
        __fpurge(stdin);
        fgets(buffer,1024,stdin);

        longitud = strlen(buffer);
        for(i=0; i<1024; i++)
        {
            if(longitud == 1)
            {
                invalido = 1;
                break;
            }
            if(buffer[i] == '\n')
            {
                break;
            }
            if(!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                invalido = 1;
                break;
            }
        }
        if(invalido)
        {
            printf("ERROR: NO INGRESO UN NUMERO\n");
        }
        else
        {
            auxiliar = atoi(buffer);
            if(auxiliar < 0)
            {
                printf("ERROR: Id del director invalido( Tiene que ser positivo):\n");
                invalido = 1;
            }
        }

    }
    while(invalido == 1);

    if(modificacion)
    {
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar el año de estreno? (y): ", 'y');
        if(modificacionFlag == -1)
        {
            printf("Modificacion Cancelada...\n");
        }
        else
        {
            pelicula->director = atoi(buffer);
        }
    }
    else
    {
        pelicula->director = atoi(buffer);
    }

}

void ePelicula_ingresarAnio(ePelicula* pelicula, char mensaje[], int modificacion)
{
    char buffer[1024];
    int i;
    int invalido;
    int longitud;
    int modificacionFlag;
    int auxiliar;
    do
    {
        invalido = 0;
        printf("%s", mensaje);
        __fpurge(stdin);
        fgets(buffer,1024,stdin);

        longitud = strlen(buffer);
        for(i=0; i<1024; i++)
        {
            if(longitud == 1)
            {
                invalido = 1;
                break;
            }
            if(buffer[i] == '\n')
            {
                break;
            }
            if(!(buffer[i] >= '0' && buffer[i] <= '9'))
            {
                invalido = 1;
                break;
            }
        }
        if(invalido)
        {
            printf("ERROR: NO INGRESO UN NUMERO\n");
        }
        else
        {
            auxiliar = atoi(buffer);
            if(auxiliar < 1990 || auxiliar > 2020)
            {
                printf("ERROR: Fecha de estreno invalida( se valida con 1990-2020):\n");
                invalido = 1;
            }
        }

    }
    while(invalido == 1);
    if(modificacion)
    {
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar el año de estreno? (y): ", 'y');
        if(modificacionFlag == -1)
        {
            printf("Modificacion Cancelada...\n");
        }
        else
        {
            pelicula->anio = atoi(buffer);
        }
    }
    else
    {
        pelicula->anio = atoi(buffer);
    }
}

int ePelicula_confirmacion(char mensaje[], char llave)
{
    int retorno = -1;
    int opcion;
    printf("%s", mensaje);
    __fpurge(stdin);
    opcion = getchar();
    opcion = tolower(opcion);
    llave = tolower(llave);
    if(opcion == llave)
    {
        retorno = 0;
    }
    return retorno;
}
