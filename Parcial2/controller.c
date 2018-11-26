#include "controller.h"
int controller_loadEmployees(LinkedList* pListaEmpleados, char* path)
{
    FILE* pArchivo;
    char idAux[100];
    char nameAux[TAMANIO_NOMBRE];
    char workHoursAux[100];
    char addressAux[TAMANIO_DIRECCION];
    int i = -1;
    Employee* empleadoAux;
    if(pListaEmpleados != NULL && path != NULL)
    {
        pArchivo = fopen(path,"r");
        if(pArchivo != NULL)
        {
            while(!feof(pArchivo))
            {
                fscanf(pArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux, addressAux,workHoursAux);
                if(i != -1)
                {
                    empleadoAux = employee_newParametros(idAux,nameAux,workHoursAux,addressAux);
                    if(empleadoAux != NULL)
                    {
                        ll_add(pListaEmpleados, empleadoAux);
                    }
                }
                i++;
            }
            fclose(pArchivo);
        }
    }
    return i;
}

int controller_sortEmployees(LinkedList* pListaEmpleados)
{
    int returnAux = -1;
    int len;
    int i;
    Employee* auxiliar;
    if(pListaEmpleados != NULL)
    {
        len = ll_len(pListaEmpleados);
        ll_sort(pListaEmpleados, employee_ordenNombre, 1);
        printf("%5s %15s %25s %15s %10s\n", "ID", "NOMBRE", "DIRRECION", "HORAS TRABAJADAS", "SUELDO");
        for(i=0; i<len; i++)
        {
            auxiliar =(Employee*) ll_get(pListaEmpleados, i);
            employee_print(auxiliar);
        }
        returnAux = 0;
    }

    return returnAux;
}

int controller_mapEmployeesSalaries(LinkedList* pListaEmpleados)
{
    int returnAux = -1;
    int proceso;
    int len;
    if(pListaEmpleados != NULL)
    {
        len =  ll_len(pListaEmpleados);
        if(len > 0)
        {
            proceso = ll_map(pListaEmpleados, employee_mapHoursToSalary);
            printf("Se Parsearon horas a sueldos de %d empleados\n", proceso);
            if(proceso == len)
            {
                returnAux = 0;
            }
            else
            {
                printf("ERROR:Varios Valores de la lista no se pudieron parsear\n");
            }
        }
    }

    return returnAux;
}


int controller_filterAndSaveEmployees(LinkedList* pListaEmpleados, char* path)
{
    int returnAux = -1;
    LinkedList* listaFiltrada;
    if(pListaEmpleados != NULL && path != NULL)
    {
        listaFiltrada = controller_filterEmployees(pListaEmpleados);
        if(listaFiltrada != NULL)
        {
            returnAux = controller_saveEmployees(path,listaFiltrada);
        }
    }
    return returnAux;
}

LinkedList* controller_filterEmployees(LinkedList* pListaEmpleados)
{
    int len;
    int i;
    Employee* auxiliar;
    int sueldoAuxiliar;
    int sueldoTotal = 0;
    int sueldoPromedio;
    LinkedList* listaFiltrada = NULL;
    if(pListaEmpleados != NULL)
    {
        len = ll_len(pListaEmpleados);
        if(len > 0)
        {
            for(i = 0; i<len; i++)
            {
                auxiliar = ll_get(pListaEmpleados, i);
                employee_getSueldo(auxiliar,&sueldoAuxiliar);
                sueldoTotal += sueldoAuxiliar;
            }
            sueldoPromedio = sueldoTotal / len;
            printf("Sueldo promedio %d\n", sueldoPromedio);
            listaFiltrada = ll_filterWithParameter(pListaEmpleados, employee_filterSalary, &sueldoPromedio);
        }
    }
    return listaFiltrada;
}

int controller_saveEmployees(char* path, LinkedList* pArrayListEmployee)
{
    int estado = -1;
    FILE* pArchivo;
    Employee* empleadoAux;
    int i;
    int listLen;
    int* idAux;
    char* nameAux;
    char* dirAux;
    int* sueldoAux;
    int* horasAux;
    if(pArrayListEmployee != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nameAux = malloc(sizeof(char)*TAMANIO_NOMBRE);
        nameAux = malloc(sizeof(char)*TAMANIO_DIRECCION);
        sueldoAux = malloc(sizeof(int));
        horasAux = malloc(sizeof(int));

        pArchivo = fopen(path,"w");
        listLen = ll_len(pArrayListEmployee);
        fprintf(pArchivo,"id,nombre,direccion,horasTrabajadas,sueldo\n");

        for(i=0; i<listLen; i++)
        {
            empleadoAux = ll_get(pArrayListEmployee,i);
            employee_getId(empleadoAux,idAux);
            employee_getSueldo(empleadoAux,sueldoAux);
            nameAux = employee_getNombre(empleadoAux);
            dirAux = employee_getDireccion(empleadoAux);
            employee_getHorasTrabajadas(empleadoAux,horasAux);
            fprintf(pArchivo,"%d,%s,%s,%d,%d\n",*idAux,nameAux,dirAux,*horasAux,*sueldoAux);
        }
        free(nameAux);
        free(idAux);
        free(sueldoAux);
        free(horasAux);
        free(dirAux);
        fclose(pArchivo);
    }
    return estado;
}
