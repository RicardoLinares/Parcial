#include "texto.h"



int putLineInString(char origin[], int size, char mensaje[])
{
    char buffer[BUFFER];
    int index;
    int stringSize;
    int cadenaInvalida;
    do
    {
        printf("%s", mensaje);
        __fpurge(stdin);
        fgets(buffer, BUFFER, stdin);

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
    }
    while(cadenaInvalida != 0);

    strcpy(origin,buffer);

    return 0;
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

int validateStringToInteger(char* numberString, int length)
{
    int returnValue = 0;
    int i;
    for(i=0; i<length; i++)
    {
        if(length == 1)
        {
            returnValue = -1;
            break;
        }
        if(numberString[i] == '\n')
        {
            break;
        }
        if(!(numberString[i] >= '0' && numberString[i] <= '9'))
        {
            returnValue = -1;
            break;
        }
    }
    return returnValue;
}

int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (d != 0 || !*a)
            return d;
    }
}

int validateFormatName(char *nameString, int size)
{


}
