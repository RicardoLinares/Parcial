#include "pelicula.h"

int ePelicula_hardcode(ePelicula listadoPelicula[], int limite)
{
    int returnValue = -1;
    char nuevoPeliculas[5][TAMNOMBRES] = {"Volver al Mercado",
                                          "La caja",
                                          "dia del Parcial",
                                          "Mendoza Documental",
                                          "el senor de los alfajore"
                                         };
    int nuevasFechas[5] = {1985,1999,1996,2015,2001};
    char nacionalidad[5][TAMNACIONALIDAD] = {"Argentina","Argentina","Argentina","Mendocina","Uruguaya"};
    int idDirectores[5] = {100, 100, 102, 103, 104};
    int idPeliculas[5] = {50, 51, 52, 53, 54};
    int i;
    if(limite>=5)
    {
        returnValue = 0;
        for(i = 0; i < 5; i++)
        {
            strcpy(listadoPelicula[i].titulo, nuevoPeliculas[i]);
            strcpy(listadoPelicula[i].nacionalidad, nacionalidad[i]);
            listadoPelicula[i].anio = nuevasFechas[i];
            listadoPelicula[i].director = idDirectores[i];
            listadoPelicula[i].idPelicula = idPeliculas[i];
            listadoPelicula[i].estado = OCUPADO;
        }
    }

    return returnValue;
}


int ePelicula_buscarPorId(ePelicula listadoPelicula[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoPelicula != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listadoPelicula[i].estado == OCUPADO && listadoPelicula[i].idPelicula == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePelicula_initialize( ePelicula listadoPelicula[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoPelicula != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listadoPelicula[i].estado= LIBRE;
            listadoPelicula[i].idPelicula= 0;
        }
    }
    return retorno;
}

int ePelicula_siguienteId(ePelicula listadoPelicula[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listadoPelicula != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listadoPelicula[i].estado == OCUPADO)
            {
                if(listadoPelicula[i].idPelicula>retorno)
                {
                    retorno=listadoPelicula[i].idPelicula;
                }
            }
        }
    }

    return retorno+1;
}

int ePelicula_buscarLugarLibre(ePelicula listadoPelicula[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listadoPelicula != NULL)
    {
        retorno = -2;
        for(i=0; i<limite; i++)
        {
            if(listadoPelicula[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int ePelicula_alta(ePelicula  listadoPelicula[],int limite, eDirector listadoDirector[], int limiteDirector)
{
    int retorno = -1;
    int id;
    int idDirector;
    int indice;
    int listadoDirectorFlag;
    if(listadoDirector != NULL && limiteDirector > 0)
    {

        listadoDirectorFlag = eDirector_validarListar(listadoDirector, limiteDirector);
        if(listadoDirectorFlag != -1)
        {
            if(limite > 0 && listadoPelicula != NULL)
            {
                retorno = -2;
                indice = ePelicula_buscarLugarLibre(listadoPelicula,limite);
                if(indice >= 0)
                {
                    system("cls");
                    id = ePelicula_siguienteId(listadoPelicula,limite);
                    ePelicula_ingresarNombre(&listadoPelicula[indice], 0);
                    ePelicula_ingresarAnio(&listadoPelicula[indice], "ingrese anio de estreno: ", 0);
                    ePelicula_ingresarNacionalidad(&listadoPelicula[indice], 0);
                    ePelicula_ingresarIdDirector(&listadoPelicula[indice],"ingrese el ID del director: ", 0
                                                 , listadoDirector, limiteDirector);
                    listadoPelicula[indice].idPelicula = id;
                    listadoPelicula[indice].estado = OCUPADO;


                    idDirector = eDirector_buscarPorId(listadoDirector,limiteDirector, listadoPelicula[indice].director);
                    ePelicula_Mostrar(listadoPelicula[indice], 1, listadoDirector[idDirector]);
                    retorno = 0;
                }
            }
        }
        else
        {
            printf("No hay directores.");
        }
    }
    return retorno;
}

int ePelicula_baja(ePelicula listadoPelicula[],int limite, char mensaje[], eDirector listadoDirector[], int limiteDirector)
{
    int retorno = -1;
    char opcion;
    int auxiliar;
    int idDirector;
    int busqueda = -1;
    int listaEstado;

    listaEstado = ePelicula_MostrarListado(listadoPelicula, limite, listadoDirector,limiteDirector);
    if(listaEstado == 0)
    {
        if(limite > 0 && listadoPelicula != NULL)
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &auxiliar);
            busqueda = ePelicula_buscarPorId(listadoPelicula,limite,auxiliar);
            if(busqueda >= 0 && busqueda < limite)
            {
                idDirector = eDirector_buscarPorId(listadoDirector,limiteDirector, listadoPelicula[busqueda].director);
                ePelicula_Mostrar(listadoPelicula[busqueda], 1, listadoDirector[idDirector]);
                printf("Esta Seguro que quiere dar de baja (y): ");
                fflush(stdin);
                opcion = getchar();
                opcion = tolower(opcion);
                if(opcion == 'y')
                {
                    printf("BAJA exitosa");
                    listadoPelicula[busqueda].estado = DESHABILITADO;
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


int ePelicula_modificacion(ePelicula  listadoPelicula[],int limite, char mensaje[], eDirector listadoDirector[],
                           int limiteDirector)
{
    int retorno = -1;
    char opcion;
    int auxiliar;
    int salir;
    int idDirector;
    int busqueda = -1;
    int listaEstado;

    listaEstado = ePelicula_MostrarListado(listadoPelicula, limite,listadoDirector,limiteDirector);
    if(listaEstado == 0)
    {
        if(limite > 0 && listadoPelicula != NULL)
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", &auxiliar);
            busqueda = ePelicula_buscarPorId(listadoPelicula,limite,auxiliar);
            if(busqueda >= 0 && busqueda < limite)
            {
                clearConsoleQuick();
                do
                {
                    printf("Que desea modificar de:\n");
                    idDirector = eDirector_buscarPorId(listadoDirector,limiteDirector, listadoPelicula[busqueda].director);
                    ePelicula_Mostrar(listadoPelicula[busqueda], 1, listadoDirector[idDirector]);
                    printListStrings(5
                                     , "Modificar Titulo"
                                     , "Modificar anio de estreno"
                                     , "Modificar Nacionalidad"
                                     , "Modificar Director"
                                     , "Cancelar");
                    opcion = waitsForMenuInput(5, "Eliga su opcion: ");

                    switch(opcion)
                    {
                    case 0:
                        ePelicula_ingresarNombre(&listadoPelicula[busqueda], 1);
                        break;
                    case 1:
                        ePelicula_ingresarAnio(&listadoPelicula[busqueda], "Ingrese el anio de estreno: ", 1);
                        break;
                    case 2:
                        ePelicula_ingresarNacionalidad(&listadoPelicula[busqueda], 1);
                        break;
                    case 3:
                        ePelicula_ingresarIdDirector(&listadoPelicula[busqueda], "Ingrese el ID del director: ", 1,
                                                     listadoDirector, limiteDirector);
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
                        ePelicula_Mostrar(listadoPelicula[busqueda], 1, listadoDirector[idDirector]);
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
    }
    return retorno;
}


int ePelicula_Mostrar(ePelicula pelicula, int isAlone, eDirector director)
{
    int retorno = -1;
    if(isAlone == 1)
    {
        printf("%2s %4s %25s %20s %20s\n", "ID", "ANIO","Nacionalidad", "Director", "NOMBRE");
    }
    printf("%2d %4d %25s %20s %20s\n", pelicula.idPelicula
           , pelicula.anio
           , pelicula.nacionalidad
           , director.nombre
           , pelicula.titulo);
    retorno = 0;
    return retorno;
}

int ePelicula_MostrarPeliculaDirector(ePelicula pelicula, int isAlone, eDirector director)
{
    int retorno = -1;
    if(isAlone == 1)
    {
        printf("%s %30s\n","Director", "NOMBRE");
    }
    printf("%s %30s\n", director.nombre, pelicula.titulo);
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
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar el titulo? (y): ", 'y');
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
    system("cls");
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
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar la nacionalidad? (y): ", 'y');
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
    system("cls");
    return retorno;
}
int ePelicula_MostrarListado(ePelicula listadoPelicula[], int limite, eDirector listadoDirectores[], int limiteDirectores)
{
    int retorno;
    int indice;
    int idDirector;
    if(limite > 0 && listadoPelicula != NULL)
    {
        retorno = -2;
        for(indice = 0; indice < limite; indice++)
        {
            if(listadoPelicula[indice].estado == OCUPADO)
            {
                if(retorno == -2)
                {
                    printf("%2s %4s %25s %20s %20s\n", "ID", "ANIO","Nacionalidad", "Director", "NOMBRE");
                }
                idDirector = eDirector_buscarPorId(listadoDirectores,limiteDirectores, listadoPelicula[indice].director);
                ePelicula_Mostrar(listadoPelicula[indice], 0, listadoDirectores[idDirector]);
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
int ePelicula_mostrarPeliculasConDirectores(ePelicula listadoPelicula[], int limite, eDirector listadoDirectores[], int limiteDirectores)
{
    int retorno;
    int indice;
    int idDirector;
    if(limite > 0 && listadoPelicula != NULL)
    {
        retorno = -2;
        for(indice = 0; indice < limite; indice++)
        {
            if(listadoPelicula[indice].estado == OCUPADO)
            {
                if(retorno == -2)
                {
                    printf("%s %30s\n", "Director", "NOMBRE");
                }
                idDirector = eDirector_buscarPorId(listadoDirectores,limiteDirectores, listadoPelicula[indice].director);
                ePelicula_MostrarPeliculaDirector(listadoPelicula[indice], 0, listadoDirectores[idDirector]);
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

void ePelicula_ingresarIdDirector(ePelicula* pelicula, char mensaje[], int modificacion,
                                  eDirector* listaDirector, int limiteDirector)
{
    char buffer[1024];
    int invalido;
    int longitud;
    int modificacionFlag;
    int auxiliar;
    do
    {
        invalido = 0;
        eDirector_MostrarListado(listaDirector, limiteDirector);
        printf("%s", mensaje);
        fflush(stdin);
        fgets(buffer,1024,stdin);

        longitud = strlen(buffer);
        invalido = validateStringToInteger(buffer, longitud);
        if(invalido)
        {
            printf("ERROR: NO INGRESO UN NUMERO\n");
            clearConsole();
        }
        else
        {
            auxiliar = atoi(buffer);
            if(auxiliar < 0)
            {
                printf("ERROR: Id del director invalido( Tiene que ser positivo):\n");
                invalido = -1;
                clearConsole();

            }
            else
            {
                invalido = eDirector_buscarPorId(listaDirector, limiteDirector, auxiliar);
                if(invalido == -1)
                {
                    printf("ERROR: el id no esta en la lista :\n");
                    clearConsole();
                }
            }
        }
    }
    while(invalido == -1);

    if(modificacion)
    {
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar el Director? (y): ", 'y');
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
    int invalido;
    int longitud;
    int modificacionFlag;
    int auxiliar;
    do
    {
        invalido = 0;
        printf("%s", mensaje);
        fflush(stdin);
        fgets(buffer,1024,stdin);
        longitud = strlen(buffer);

        invalido = validateStringToInteger(buffer, longitud);

        if(invalido)
        {
            printf("ERROR: NO INGRESO UN NUMERO\n");
        }
        else
        {
            auxiliar = atoi(buffer);
            if(auxiliar < 1940 || auxiliar > 2020)
            {
                printf("ERROR: Fecha de estreno invalida( se valida con 1940-2020):\n");
                invalido = -1;
            }
        }
    }
    while(invalido == -1);
    if(modificacion)
    {
        modificacionFlag = ePelicula_confirmacion("Estas Seguro de cambiar el anio de estreno? (y): ", 'y');
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
        system("cls");
    }
}

int ePelicula_confirmacion(char mensaje[], char llave)
{
    int retorno = -1;
    int opcion;
    printf("%s", mensaje);
    fflush(stdin);
    opcion = getchar();
    opcion = tolower(opcion);
    llave = tolower(llave);
    if(opcion == llave)
    {
        retorno = 0;
    }
    return retorno;
}

int ePelicula_bajaDirector(eDirector listadoDirector[], int limiteDirector, ePelicula listadoPelicula[], int limite)
{
    int returnValue = -1;
    char opcion;
    int indexDirector;
    int idDirector;
    int funcionExitosaFlag;
    printf("ADVERTENCIA: al eliminar a un director se deshabilitaran sus peliculas.\n");

    indexDirector = eDirector_baja(listadoDirector, limiteDirector, "Ingrese el nombre del director: ");
    if(indexDirector != -1)
    {
        idDirector = listadoDirector[indexDirector].idDirector;
        eDirector_Mostrar(listadoDirector[indexDirector], 1);
        printf("\nSe van a Eliminar las siguientes peliculas:\n");
        funcionExitosaFlag = ePelicula_MostrarPeliculasPorIdDirector(listadoDirector, limiteDirector,listadoPelicula, limite, idDirector);
        if(funcionExitosaFlag != 0)
        {
            printf("Este director no tiene peliculas...\n");
        }
        printf("Esta Seguro que quiere dar de baja (y): ");
        fflush(stdin);
        opcion = getchar();
        opcion = tolower(opcion);
        if(opcion == 'y')
        {
            listadoDirector[indexDirector].estado = DESHABILITADO;
            ePelicula_bajarPeliculasPorIdDirector(listadoPelicula,limite,idDirector);
        }

    }

    return returnValue;
}

int ePelicula_MostrarPeliculasPorIdDirector(eDirector listadoDirector[], int limiteDirector,
        ePelicula listadoPelicula[], int limite, int idDirector)
{
    int retorno;
    int indice;
    int indexDirector;
    if(limite > 0 && listadoPelicula != NULL)
    {
        retorno = -2;
        indexDirector = eDirector_buscarPorId(listadoDirector,limiteDirector, idDirector);
        for(indice = 0; indice < limite; indice++)
        {
            if(listadoPelicula[indice].estado == OCUPADO)
            {
                if(listadoPelicula[indice].director == idDirector)
                {
                    if(retorno == -2)
                    {
                        printf("%s %2s %20s %20s %20s \n", "ID", "ANIO","Nacionalidad", "Director", "NOMBRE");
                    }
                    ePelicula_Mostrar(listadoPelicula[indice], 0, listadoDirector[indexDirector]);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;
}

int ePelicula_bajarPeliculasPorIdDirector(ePelicula listadoPelicula[], int limite, int idDirector)
{
    int returnValue = -2;
    int indice;
    if(limite > 0 && listadoPelicula != NULL)
    {
        returnValue = -1;
        for(indice = 0; indice < limite; indice++)
        {
            if(listadoPelicula[indice].director == idDirector)
            {
                listadoPelicula[indice].estado = DESHABILITADO;
            }
        }
    }
    return returnValue;
}

int ePelicula_menu(ePelicula listadoPelicula[], int limite, eDirector listadoDirector[], int limiteDirector)
{
    int returnValue = -1;
    int option;
    int proceso;
    do
    {
        printf("Peliculas del teatro:\n");
        printListStrings(7, "ALTAS PELICULAS:", "MODIFICAR DATOS DE UNA PELICULA:"
                         , "BAJA DE PELICULA:", "NUEVO DIRECTOR:"
                         , "ELIMINAR DIRECTOR:", "Consultas:", "SALIR");
        option = waitsForMenuInput(8,"Eliga su opcion: ");
        switch(option)
        {
        case 0:
            proceso = ePelicula_alta(listadoPelicula, limite, listadoDirector, limiteDirector);
            if(proceso == -2)
            {
                printf("ERROR: no hay mas espacio");
            }
            break;
        case 1:
            ePelicula_modificacion(listadoPelicula, limite, "Ingrese el id de la pelicula: ",
                                   listadoDirector, limiteDirector);
            break;
        case 2:
            ePelicula_baja(listadoPelicula, limite, "Ingrese el id de la pelicula: ", listadoDirector,
                           limiteDirector);
            break;
        case 3:
            proceso = eDirector_alta(listadoDirector, limiteDirector);
            if(proceso == -2)
            {
                printf("ERROR: no hay mas espacio");
            }
            break;
        case 4:
            ePelicula_bajaDirector(listadoDirector,limiteDirector,listadoPelicula,limite);
            break;
        case 5:
            proceso = ePelicula_menuConsultar(listadoPelicula,limite,listadoDirector,limiteDirector);
            break;
        case 6:
            printf("Adios");
            returnValue = 0;
            break;
        default:
            printf("No ingreso una opcion valida");
            break;
        }
        clearConsole();
    }
    while(option!=6);

    return returnValue;
}

int ePelicula_menuConsultar(ePelicula listadoPelicula[], int limite, eDirector listadoDirector[], int limiteDirector)
{
    int returnValue = -1;
    int option;
    int proceso;

    system("cls");
    do
    {
        printf("Consultar:\n");
        printListStringsChars(7, "Lista de peliculas:", "Lista de directores:"
                              , "la/s pelicula mas vieja:", "Lista de Peliculas con director:"
                              , "Los Directores con sus peliculas", "Peliculas Dirigidas por un director"
                              , "cancelar");
        option = waitsForMenuInputChars(7,"Eliga su opcion: ");
        switch(option)
        {
        case 0:
            proceso = ePelicula_MostrarListado(listadoPelicula, limite, listadoDirector,
                                               limiteDirector);
            break;
        case 1:
            proceso = eDirector_MostrarListado(listadoDirector, limiteDirector);
            break;
        case 2:
            proceso = ePelicula_MostrarPeliculasAntiguas(listadoPelicula,limite, listadoDirector, limiteDirector);
            break;
        case 3:
            proceso = ePelicula_mostrarPeliculasConDirectores(listadoPelicula, limite, listadoDirector,
                                                    limiteDirector);
            break;
        case 4:
            proceso = ePelicula_MostrarListadoDirectorConPeliculas(listadoPelicula,limite,listadoDirector,limiteDirector);
            break;

        case 5:
            proceso = ePelicula_buscarDirectorCantidadDePeliculas(listadoPelicula,limite,listadoDirector,limiteDirector);

            if(proceso == -1)
            {
                printf("El nombre no esta en la lista...\n");
            }
            break;
        case 6:
            printf("Cerrando Consultas...");
            returnValue = 0;
            break;
        default:
            printf("No ingreso una opcion valida");
            break;
        }
        if(option !=6)
        {
            clearConsole();
        }
    }
    while(option!=6);

    return returnValue;
}

int ePelicula_MostrarPeliculasAntiguas(ePelicula listadoPelicula[], int limite, eDirector listadoDirectores[]
                                       , int limiteDirectores)
{
    int retorno;
    int indice;
    int mayorAntiguedad;
    int idDirector;
    if(limite > 0 && listadoPelicula != NULL)
    {
        retorno = -2;
        mayorAntiguedad = ePelicula_buscarMayorAntiguedad(listadoPelicula,limite);
        for(indice = 0; indice < limite; indice++)
        {
            if(listadoPelicula[indice].estado == OCUPADO && listadoPelicula[indice].anio == mayorAntiguedad)
            {

                if(retorno == -2)
                {
                    printf("%2s %4s %25s %20s %20s\n", "ID", "ANIO","Nacionalidad", "Director", "NOMBRE");
                }
                idDirector = eDirector_buscarPorId(listadoDirectores,limiteDirectores, listadoPelicula[indice].director);
                ePelicula_Mostrar(listadoPelicula[indice], 0, listadoDirectores[idDirector]);
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

int ePelicula_buscarMayorAntiguedad(ePelicula listadoPeliculas[], int limite)
{
    int returnValue = -1;
    int indice;
    if(limite > 0 && listadoPeliculas != NULL)
    {
        returnValue = 3000;
        for(indice = 0; indice < limite; indice++)
        {
            if(listadoPeliculas[indice].estado == OCUPADO)
            {
                if(listadoPeliculas[indice].anio < returnValue)
                {
                    returnValue = listadoPeliculas[indice].anio;
                }

            }
        }
    }
    return returnValue;
}

int ePelicula_MostrarListadoDirectorConPeliculas(ePelicula listadoPelicula[], int limite, eDirector listadoDirector[], int limiteDirector)
{
    int returnValue = -3;
    int funcionExitosaFlag;
    int indexDirector;
    int idDirector;
    if(listadoDirector != NULL && limiteDirector > 0 && listadoPelicula != NULL && limite > 0)
    {
        returnValue = -2;
        for(indexDirector=0; indexDirector < limiteDirector; indexDirector++)
        {
            if(listadoDirector[indexDirector].estado == OCUPADO)
            {
                idDirector = listadoDirector[indexDirector].idDirector;
                eDirector_Mostrar(listadoDirector[indexDirector], 1);
                printf("\nDirgio las peliculas:\n");
                funcionExitosaFlag = ePelicula_MostrarPeliculasPorIdDirector(listadoDirector, limiteDirector,listadoPelicula, limite, idDirector);
                printf("\n\n");
                if(funcionExitosaFlag != 0)
                {
                    printf("Este director no tiene peliculas...\n");
                }
            }
        }

    }
    return returnValue;
}

int ePelicula_calcularPeliculasPorDirector(eDirector Director, ePelicula listadoPelicula[], int limite)
{
    int contCantidadDePeliculas = 0;
    int indice;
    if(limite > 0 && listadoPelicula != NULL)
    {
        for(indice = 0; indice < limite; indice++)
        {
            if(listadoPelicula[indice].estado == OCUPADO)
            {
                if(listadoPelicula[indice].director == Director.idDirector)
                {
                    contCantidadDePeliculas++;
                }
            }
        }
    }
    return contCantidadDePeliculas;
}

int ePelicula_buscarDirectorCantidadDePeliculas(ePelicula listadoPelicula[], int limite
        , eDirector listadoDirector[], int limiteDirector)
{
    int returnValue = -1;
    char buffer[1024];
    int busqueda;
    int cantidadDePeliculas;

    clearConsoleQuick();
    eDirector_MostrarListado(listadoDirector,limiteDirector);
    putLineInString(buffer, TAMNOMBRES, "Ingrese el nombre del director: ");
    RemoveSpaces(buffer);
    toCamelCase(buffer);
    busqueda = eDirector_buscarPorString(listadoDirector,limiteDirector,buffer);

    if(busqueda != -1)
    {
        cantidadDePeliculas = ePelicula_calcularPeliculasPorDirector(listadoDirector[busqueda], listadoPelicula, limite);
        printf("El Director %s dirigio %d peliculas...", listadoDirector[busqueda].nombre, cantidadDePeliculas);
        returnValue = 0;
    }
    return returnValue;
}
