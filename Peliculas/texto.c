#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "texto.h"



int putLineInString(char origin[], int size, char mensaje[])
{
    char buffer[1024];
    int index;
    int stringSize;
    int cadenaInvalida;
    do
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        fgets(buffer, 1024, stdin);

        for(index = 0; index < strlen(buffer); index++)
        {
            if(buffer[index] == '\n')
            {
                buffer[index] = '\0';
            }
        }

        stringSize = strlen(buffer);

        if(stringSize < 1)
        {
            printf("ERROR: la cadena es muy corta\n");
            cadenaInvalida = 1;
        }
        else if(stringSize > size - 1)
        {
            printf("ERROR: la cadena es muy larga\n");
            cadenaInvalida = 1;
        }
        else
        {
            cadenaInvalida = 0;
        }
    }while(cadenaInvalida != 0);

    strcpy(origin,buffer);

    return 0;
}

int fullName(char destination[], char originOne[], char originTwo[])
{
    int operation;

    strcat(destination, originOne);
    strcat(destination, ", ");
    strcat(destination, originTwo);

    operation = 1;

    return operation;

}

int toCamelCase(char origin[])
{
    int firstLetterFlag = 1;
    int index;

    for(index = 0; index < strlen(origin) && origin[index] != '\0'; index++)
    {
        if(origin[index] == ' ')
        {
            firstLetterFlag = 1;
        }
        else if(firstLetterFlag)
        {
            origin[index] = toupper(origin[index]);
            firstLetterFlag = 0;
        }
        else
        {
            origin[index] = tolower(origin[index]);
        }

    }
    return 0;
}
