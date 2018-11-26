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
        fflush(stdin);
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
        if(origin[index] == ' ' && firstLetterFlag == 1)
        {

        }
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

int strcicmp(char const *cadenaUno, char const *cadenaDos)
{
    int comparacion;
    for (;; cadenaUno++, cadenaDos++)
    {
        comparacion = tolower((unsigned char)*cadenaUno) - tolower((unsigned char)*cadenaDos);
        if (comparacion != 0 || !*cadenaUno)
            return comparacion;
    }
}

int validateFormatName(char *nameString, int size)
{
    int returnValue = 0;
    int i;

    for(i=0; i<size; i++)
    {
        if(size < 1)
        {
            returnValue = -1;
            break;
        }
        if(nameString[i] == '\0')
        {
            break;
        }
        if(isalpha(nameString[0]) == 0)
        {
            printf("ERROR: Solo se permiten letras del abecedario\n");

            returnValue = -2;
            break;
        }
    }
    return returnValue;
}

void RemoveSpaces(char* source)
{
    char* i = source;
    char* j = source;
    int firstLetterFlag = 1;
    do
    {
        *i = *j++;
        if(*i != ' ')
        {
            firstLetterFlag = 0;
            i++;
        }
        else
        {
            if(firstLetterFlag == 0)
            {
                firstLetterFlag = 1;
                i++;
            }
        }
    }
    while(*j != 0); // mientras no el caracter J no sea \0
    *i = 0;
}
