#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"


/**
 * @brief Función para crear y devolver un nuevo nodo

 *
 * @param value
 * @return DList
 */

DList createNode(const char* value) {
    DList newNode = (DList)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}
/**
 * @brief Inserción al frente (al principio)
 *
 * @param head
 * @param value
 */

void insertAtFront(DList* head, const char* value) {
    DList newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}


/**
 * @brief   Inserción al final
 *
 * @param head
 * @param value
 */
void insertAtEnd(DList* head, const char* value) {
    DList newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        DList temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

/**
 * @brief Eliminación de un elemento desde el frente
 *
 * @param head
 */
void deleteFromFront(DList* head) {
    if (*head != NULL) {
        DList temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }

}

// Función para imprimir la lista
void printList(DList head) {
    DList current = head;
     if (current==NULL) {
        printf("Lista vacia\n");
    } else {
        while (current != NULL) {
            printf("%s ", current->data);
            current = current->next;
        }
    }
    printf("\n");
}
/**
 * @brief  Devuelvo el puntero que tiene la canción
 *          o NULL si no existe
 *
 * @param head
 * @param value
 * @return DList
 */
DList FindNode (DList head, const char *value){
    DList current;
    current =head;
    while (current !=NULL && (strcmp(value, current->data)!=0)) {
        current=current->next;
    }
    return current;
}


/**
 * @brief Elimina el nodo que contenga la canción value
 *
 * @param list
 * @param value
 * @return int
 */
//
int deleteNode(DList *list, const char *value) {
    DList current;;
    DList prev=NULL;
    int found= 0;

    current= FindNode (*list, value);
    if (current == NULL) {
        printf("Elemento no existe.\n");
        found=0;
    } else {

        if (current==*list) {
        *list = current->next;
        (*list)->prev=NULL;

        } else{
                prev -> next=current -> next;
                current->next->prev=prev;
        }

    // Free memory of the deleted node
        free(current);
        found=1;
    }
    return found;
}

/**
 * @brief Inserción después de una canción
 *
 * @param head
 * @param cancion: Canción existente en la lista
 * @param value: Nueva canción a añadir

 */
void insertAfter(DList *head, const char *cancion, const char* value){

    DList node, newnode;
    node=FindNode(*head, cancion);
    if (node !=NULL) {
        newnode= createNode(value);
        newnode->next=node->next;
        newnode->prev=node;
        //Si el nuevo nodo no es el último
        if (node->next!=NULL) {
            node->next->prev=newnode;
        }
        node->next=newnode;
    }
}

/**
 * @brief Inserción después de una canción
 *
 * @param head
 * @param cancion: Canción existente en la lista
 * @param value: Nueva canción a añadir

 */
void insertBefore(DList *head, const char *cancion, const char* value){

    DList node, newnode;
    node=FindNode(*head, cancion);
    if (node !=NULL) {
        newnode= createNode(value);
        newnode->next=node;
        newnode->prev=node->prev;
        //Si no va antes del primero
        if (node!=*head) {
            node->prev->next=newnode;
            node->prev=newnode;
        } else {
            node->prev=newnode;
            *head=newnode;
        }
    }
}

// Función para insertar un nodo de manera ordenada
void insertarOrdenado(DList* lista, const char* valor) {
    DList nuevoNodo = createNode(valor);

    if (*lista == NULL) {
        // Si la lista está vacía, el nuevo nodo es el único elemento
        *lista = nuevoNodo;
    } else {
        DList actual = *lista;
        while (actual->next != NULL && strcmp(actual->data, valor) < 0) {
            actual = actual->next;
        }

        // Insertar el nuevo nodo antes o después del actual según el orden
        if (strcmp(actual->data, valor) < 0) {
            nuevoNodo->prev = actual;
            actual->next = nuevoNodo;
        } else {
            nuevoNodo->next = actual;
            nuevoNodo->prev = actual->prev;
            if (actual->prev != NULL) {
                actual->prev->next = nuevoNodo;
            } else {
                *lista = nuevoNodo;
            }
            actual->prev = nuevoNodo;
        }
    }
}




// Función para ordenar la lista utilizando el algoritmo de burbuja
void ordenarLista(DList* lista) {
    int intercambiado;
    struct Node* actual;
    struct Node* siguiente = NULL;

    if (*lista == NULL) {
        return; // La lista está vacía, no hay nada que ordenar
    }

    do {
        intercambiado = 0;
        actual = *lista;

        while (actual->next != siguiente) {
            if (strcmp(actual->data, actual->next->data) > 0) {
                // Intercambiar nodos si están en el orden incorrecto
                const char* temp = actual->data;
                actual->data = actual->next->data;
                actual->next->data = temp;
                intercambiado = 1;
            }
            actual = actual->next;
        }
        siguiente = actual;
    } while (intercambiado);
}


/**
 * @brief Borro todos los elementos de la lista
 *
 * @param head
 */
void DeleteAll (DList *head){
    while (*head != NULL) {
        deleteFromFront(head);
    }

}
