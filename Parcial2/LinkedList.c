#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int len;
    int i;

    if(this != NULL && nodeIndex >= 0)
    {
        len = ll_len(this);
        if(nodeIndex <= len - 1)
        {
            pNode = this->pFirstNode;
            for(i = 0; i<nodeIndex; i++)
            {
                pNode =  pNode->pNextNode;
            }
        }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodeAux = NULL;
    Node* pNewNode = NULL;
    int i = 0;

    if(this != NULL && nodeIndex >= 0)
    {
        pNewNode = (Node*) malloc(sizeof(Node));
        if(pNewNode != NULL)
        {
            pNodeAux = this->pFirstNode;
            while(pNodeAux != NULL && i < nodeIndex)
            {
                i++;
                if(pNodeAux->pNextNode != NULL)
                {
                    pNodeAux =  pNodeAux->pNextNode;
                }
                else
                {
                    break;
                }

            }
        }

        pNewNode->pElement = pElement;
        if(i > 0) // se sabe que tengo un Nodo atras
        {
            if(pNodeAux->pNextNode != NULL) // NO hay un nodo adelante
            {
                pNewNode->pNextNode = pNodeAux->pNextNode;
            }
            else // hay un nodo adelante
            {
                pNewNode->pNextNode = NULL;
            }
            pNodeAux->pNextNode = pNewNode;

        }
        else // Primera iteracion se sabe que NO tengo un nodo atras
        {
            this->pFirstNode = pNewNode;
            if(pNodeAux != NULL) // si estoy remplazando a otro nodo
            {
                pNewNode->pNextNode = pNodeAux;
            }
            else // si este nodo es el unico nodo en la lista.
            {
                pNewNode->pNextNode = NULL;
            }
        }
        this->size += 1;
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int success;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);
        success = test_addNode(this, len, pElement);

        if(success == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len;
    Node* pNode = NULL;

    if(this != NULL && index >= 0)
    {
        len = ll_len(this);
        if(index < len)
        {
            pNode = test_getNode(this, index);
            if(pNode != NULL)
            {
                returnAux = pNode->pElement;
            }
        }
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pNode = NULL;

    if(this != NULL && index >= 0)
    {
        len = ll_len(this);
        if(index < len)
        {
            pNode = test_getNode(this, index);
            if(pNode != NULL)
            {
                pNode->pElement = pElement;
                returnAux = 0;
            }

        }
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* pNode = NULL;
    Node* pNodeAnterior = NULL;

    if(this != NULL && index >= 0)
    {
        len = ll_len(this);
        if(index < len)
        {
            pNode = test_getNode(this, index);
            if(pNode != NULL)
            {
                if(index > 0)
                {
                    pNodeAnterior = test_getNode(this, index - 1);
                    pNodeAnterior->pNextNode = pNode->pNextNode;
                }
                else
                {
                    this->pFirstNode = pNode->pNextNode;
                }

                this->size -= 1;
                free(pNode);
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;
    int errorCont;
    if(this != NULL)
    {
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            errorCont += ll_remove(this,i);
        }

        if(errorCont == 0)
        {
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    int errorFlag;
    if(this != NULL)
    {
        errorFlag = ll_clear(this);
        if(errorFlag != -1)
        {
            free(this);
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* pElementAux;
    int len;
    int i;
    if(this != NULL)
    {
        len = ll_len(this);

        for(i=0; i<=len - 1; i++)
        {
            pElementAux = ll_get(this, i);

            if(pElement == pElementAux)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len != 0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len;
    int success;
    if(this != NULL && index >= 0)
    {
        len = ll_len(this);
        if(len >= index)
        {
            success = test_addNode(this, index, pElement);
            if(success == 0)
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;
    int success;
    if(this != NULL && index >= 0)
    {
        len = ll_len(this);
        if(len >= index)
        {
            returnAux = ll_get(this,index);
            success = ll_remove(this, index);
            if(success != 0)
            {
                returnAux = NULL;
            }
        }
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    int success;
    if(this != NULL)
    {
        len = ll_len(this);
        returnAux = 0;
        if(len != 0)
        {
            success = ll_indexOf(this, pElement);
            if(success != -1)
            {
                returnAux = 1;
            }
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* pAuxiliar;
    int success;
    int contSuccess;
    int len;
    int len2;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 0;
        len = ll_len(this);
        len2 = ll_len(this2);
        if(len2<=len)
        {
            for(i=0; i<len2; i++)
            {
                pAuxiliar = ll_get(this2,i);
                success = ll_contains(this,pAuxiliar);
                if(success == 1)
                {
                    contSuccess++;
                }
                else
                {
                    break;
                }
            }

            if(contSuccess == len2)
            {
                returnAux = 1;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElementAux;
    int len;
    int i;
    int success;
    if(this != NULL)
    {
        len = ll_len(this);
        if(from >= 0 && to <= len && from < to)
        {
            cloneArray = ll_newLinkedList();
            if(cloneArray != NULL)
            {


                for(i=from; i<to; i++)
                {
                    pElementAux = ll_get(this,i);
                    success = ll_add(cloneArray,pElementAux);
                    if(success != 0)
                    {
                        break;
                    }
                }

            }
        }
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        cloneArray = ll_subList(this,0,len);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1;
    int len;
    int i;
    int j;
    int proceso;
    Node* pElementoA;
    Node* pElementoB;
    void* pAuxiliar;
    if(this != NULL && pFunc != NULL && (order == 0 || order == 1))
    {
        len = ll_len(this);

        for(i=0; i<len; i++)
        {
            for(j=i+1; j<len; j++)
            {
                pElementoA = test_getNode(this,i);
                pElementoB = test_getNode(this,j);
                proceso = pFunc(pElementoA->pElement,pElementoB->pElement);
                if(proceso != 0)
                {
                    if((order == 1 && proceso == 1 )||(order == 0 && proceso == -1))
                    {
                        pAuxiliar = pElementoA->pElement;
                        pElementoA->pElement = pElementoB->pElement;
                        pElementoB->pElement = pAuxiliar;
                    }
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;

}


LinkedList* ll_filter(LinkedList* this, int (*function) (void*) )
{
    LinkedList* filteredList = NULL;
    void* auxiliar;
    int i;
    int len;
    if(this != NULL && function != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
            filteredList = ll_newLinkedList();
            if(filteredList != NULL)
            {
                for(i=0; i<len; i++)
                {
                    auxiliar = ll_get(this, i);
                    if(function(auxiliar) == 1)
                    {
                        ll_add(filteredList, auxiliar);
                    }
                }
            }
        }
    }
    return filteredList;
}

LinkedList* ll_filterWithParameter(LinkedList* this, int (*function) (void*,void*), void* parameter)
{
    LinkedList* filteredList = NULL;
    void* auxiliar;
    int i;
    int len;
    if(this != NULL && function != NULL && parameter != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
            filteredList = ll_newLinkedList();
            if(filteredList != NULL)
            {
                for(i=0; i<len; i++)
                {
                    auxiliar = ll_get(this, i);
                    if(function(auxiliar, parameter) == 1)
                    {
                        ll_add(filteredList, auxiliar);
                    }
                }
            }
        }
    }
    return filteredList;
}

int ll_map(LinkedList* this, int (*function) (void*) )
{
    int returnAux = 0;
    void* auxiliar;
    int i;
    int proceso;
    int len;
    if(this != NULL && function != NULL)
    {
        len = ll_len(this);
        if(len > 0)
        {
                for(i=0; i<len; i++)
                {
                    auxiliar = ll_get(this, i);
                    proceso = function(auxiliar);
                    if(proceso == 0)
                    {
                        returnAux++;
                    }
                }
        }
    }
    return returnAux;
}
