#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED
#include "LinkedList.h"
#include "Employee.h"


int controller_loadEmployees(LinkedList* pListaEmpleados, char* path);


int controller_sortEmployees(LinkedList* pListaEmpleados);

int controller_mapEmployeesSalaries(LinkedList* pListaEmpleados);

LinkedList* controller_filterEmployees(LinkedList* pListaEmpleados);


int controller_filterAndSaveEmployees(LinkedList* pListaEmpleados, char* path);

int controller_saveEmployees(char* path, LinkedList* pArrayListEmployee);

#endif // CONTROLLER_H_INCLUDED
