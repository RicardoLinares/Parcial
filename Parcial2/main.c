#include <stdio.h>
#include <stdlib.h>
#include "controller.h"

int main()
{
    LinkedList* ListaEmpleados;
    ListaEmpleados = ll_newLinkedList();

    controller_loadEmployees(ListaEmpleados, "Employee.csv");

    controller_sortEmployees(ListaEmpleados);

    controller_mapEmployeesSalaries(ListaEmpleados);

    controller_sortEmployees(ListaEmpleados);

    controller_filterAndSaveEmployees(ListaEmpleados,"sueldos.csv");
    printf("Hello world!\n");
    return 0;
}
