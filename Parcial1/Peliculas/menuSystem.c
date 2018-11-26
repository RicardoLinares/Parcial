#include "menuSystem.h"

int printListStrings(int size, ...)
{
    va_list ap;
    char *auxiliar;
    int option = 1;
    int i;

    va_start(ap, size);

    for(i=0; i<size; i++)
    {
        auxiliar = va_arg(ap,char *);
        printf("%d) %s\n", option ,auxiliar);
        option++;
    }

    va_end(ap);


    return 0;
}

int printListStringsChars(int size, ...)
{
    va_list ap;
    char *auxiliar;
    char option = 'a';
    int i;

    va_start(ap, size);

    for(i=0; i<size; i++)
    {
        auxiliar = va_arg(ap,char *);
        printf("%c) %s\n", option ,auxiliar);
        option++;
    }

    va_end(ap);


    return 0;
}

int waitsForMenuInput(int size, char mensaje[])
{
    int retorno;
    int optionValidationFlag = 0;
    int opcion;
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%d", &opcion);

    for(i=0; i<size; i++)
    {
        if(opcion == 1+i)
        {
            retorno = i;
            optionValidationFlag = 1;
            break;
        }
    }

    if(optionValidationFlag == 0)
    {
        retorno = -1;
    }
    return retorno;
}

int waitsForMenuInputChars(int size, char mensaje[])
{
    int retorno;
    int optionValidationFlag = 0;
    char opcion;
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &opcion);

    opcion = tolower(opcion);
    for(i=0; i<size; i++)
    {
        if(opcion == 'a'+i)
        {
            retorno = i;
            optionValidationFlag = 1;
            break;
        }
    }

    if(optionValidationFlag == 0)
    {
        retorno = -1;
    }
    return retorno;
}



void clearConsole(void)
{
    printf("\npulse ENTER para continuar...");
    fflush(stdin);
    getchar();
    system("cls");
}

void clearConsoleQuick(void)
{
    system("cls");
}
