#include "director.h"


int eDirector_hardcode(eDirector listado[], int limite)
{
    int returnValue = -1;
    char nuevoDirectores[5][51] = {"Pepito Dual", "Jonny Vacio","Ricardo Linares","Mendoza Firme","Rodrigez Martin"};

    int idDirectores[5] = {100, 101, 102, 103, 104};
    int i;
    if(limite>=5)
    {
        returnValue = 0;
        for(i = 0; i < 5; i++)
        {
            strcpy(listado[i].nombre, nuevoDirectores[i]);
            listado[i].idDirector = idDirectores[i];
            listado[i].estado = OCUPADO;
        }
    }
    return returnValue;
}
int eDirector_buscarPorId(eDirector listado[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && listado[i].idDirector == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eDirector_initialize( eDirector listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;
            listado[i].idDirector= 0;
        }
    }
    return retorno;
}

int eDirector_siguienteId(eDirector listado[], int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO)
            {
                if(listado[i].idDirector>retorno)
                {
                    retorno=listado[i].idDirector;
                }
            }
        }
    }

    return retorno+1;
}

int eDirector_buscarLugarLibre(eDirector listado[],int limite)
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

int eDirector_alta(eDirector  listado[],int limite)
{
    int retorno = -1;
    int id;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        indice = eDirector_buscarLugarLibre(listado,limite);
        if(indice >= 0)
        {
            id = eDirector_siguienteId(listado,limite);
            eDirector_ingresarNombre(&listado[indice], listado, limite);
            listado[indice].idDirector = id;
            listado[indice].estado = OCUPADO;
            eDirector_Mostrar(listado[indice], 1);
            retorno = 0;
        }
    }
    return retorno;
}

int eDirector_baja(eDirector listado[],int limite, char mensaje[])
{
    int retorno = -1;
    char buffer[1024];
    int busqueda = -1;
    int listaEstado;

    listaEstado = eDirector_MostrarListado(listado, limite);
    if(listaEstado == 0)
    {
        if(limite > 0 && listado != NULL)
        {
            putLineInString(buffer, 1024, mensaje);
            RemoveSpaces(buffer);
            busqueda = eDirector_buscarPorString(listado,limite,buffer);
            if(busqueda >= 0 && busqueda < limite)
            {
                retorno = busqueda;
            }
            else
            {
                printf("No se encontro el elemento");
            }
        }
    }
    return retorno;
}

int eDirector_Mostrar(eDirector estructura, int isAlone)
{
    int retorno = -1;
    if(isAlone == 1)
    {
        printf("%2s %25s\n", "ID", "NOMBRE");
    }
    printf("%2d %25s\n", estructura.idDirector, estructura.nombre);
    retorno = 0;
    return retorno;
}

int eDirector_ingresarNombre(eDirector *estructura, eDirector listado[], int limite)
{
    int retorno = -1;
    int alreadyExist;
    int invalido;
    char buffer[1024];
    do
    {
        putLineInString(buffer, TAMNOMBRES, "Ingrese el nombre del director: ");
        RemoveSpaces(buffer);
        toCamelCase(buffer);
        invalido = validateFormatName(buffer,TAMNOMBRES);
        switch(invalido)
        {
        case -1:
            printf("ERROR: la cadena ingresada es muy corta");
            break;
        case -2:
            printf("ERROR: No se permiten numeros para los nombres");
            break;
        case -3:
            printf("ERROR: El nombre debe empezar con una letra");
            break;
        }
        alreadyExist = eDirector_buscarPorString(listado,limite,buffer);
        if(alreadyExist != -1)
        {
            invalido = -1;
            printf("ERROR: este director ya existe.\n");
        }
    }
    while(invalido!=0);

    strcpy(estructura->nombre, buffer);

    return retorno;
}

int eDirector_MostrarListado(eDirector listado[], int limite)
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
                if(retorno == -2)
                {
                    printf("%2s %25s\n", "ID", "NOMBRE");
                }
                eDirector_Mostrar(listado[indice], 0);
                retorno = 0;
            }
        }
    }
    if(retorno == -2)
    {
        printf("No hay director en la lista...\n");
    }
    return retorno;
}

int eDirector_confirmacion(char mensaje[], char llave)
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

int eDirector_validarListar(eDirector* lista, int limite)
{
    int returnValue = -1;
    int i;
    if(lista != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                returnValue = 0;
                break;
            }
        }
    }


    return returnValue;

}

int eDirector_buscarPorString(eDirector *listado, int limite, char* nombre)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].estado == OCUPADO && stricmp(nombre, listado[i].nombre) == 0)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;

}
