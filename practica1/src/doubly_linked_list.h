// doubly_linked_list.h

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

/**
 * @brief Estructura para un nodo de la lista
 * 
 */
 
struct Node {
    const char* data;
    struct Node* prev;
    struct Node* next;
};

/**
 * @brief Definición del tipo
 * 
 */
typedef struct Node * DList;

/**
 * @brief Función para crear un nuevo nodo. Devuelve
 * un puntero al nodo creado.
 * 
 * @param value 
 * @return DList 
 */
DList createNode(const char* value);

// 
/**
 * @brief Inserción al frente (al principio)
 * 
 * @param head 
 * @param value 
 */
void insertAtFront(DList* head, const char* value);

/**
 * @brief  Inserción al final. 
 * Lo inserta como último elemento
 * 
 * @param head 
 * @param value 
 */
void insertAtEnd(DList* head, const char* value);

/**
 * @brief Inserción después de una canción. Busca una
 * canción y si existe añade un nuevo nodo con la nueva canción
 * después de la canción existente. 
 * 
 * @param head 
 * @param cancion: Canción existente en la lista 
 * @param value: Nueva canción a añadir 

 */
void insertAfter(DList *head, const char *cancion, const char* value);

/**
* @brief Inserción antes de una canción. Busca una
 * canción y si existe añade un nuevo nodo con la nueva canción
 * antes de la canción existente. 
 * 
 * 
 * @param head 
 * @param cancion: Canción existente en la lista 
 * @param value: Nueva canción a añadir 
 */
void insertBefore(DList* head, const char *cancion, const char* value);

/**
 * @brief Eliminación desde el frente. Se eliminan
 * todos los nodos por el primero de la lista.
 * 
 * @param head 
 */
void deleteFromFront(DList* head);

/**
 * @brief Mostrar toda lista
 * 
 * @param head 
 */
void printList (DList head);

/**
 * @brief Borrar un elemento de la lista si existe.
 * Devuelve 1 si lo borra, 0 si no existe la canción
 * 
 * @param list 
 * @param value 
 * @return int 
 */
int deleteNode(DList *list, const char *value);

/**
 * @brief Procedimiento para insertar un nodo de manera ordenada
 *  
 * @param lista 
 * @param valor 
 */
void insertarOrdenado(DList* lista, const char* valor);

/**
 * @brief Procedimiento para ordenar la lista utilizando el algoritmo de burbuja 
 * 
 * @param lista 
 */
void ordenarLista(DList* lista);

/**
 * @brief Borro todos los elementos de la lista
 * 
 * @param head 
 */
void DeleteAll (DList *head);

#endif // DOUBLY_LINKED_LIST_H
