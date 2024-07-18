#include <stdio.h>
#include <stdlib.h>
#include "EEDD/doubly_linked_list.h"

int main(void) {
    DList myList = NULL;
    printf("****Inserto canciones al principio y al final\n");

    printf("****Inserto cancion2 al principio \n");
    insertAtFront(&myList, "cancion2");
    printList(myList);

    printf("****Inserto cancion1 al principio\n");
    insertAtFront(&myList, "cancion1");
    printList(myList);

    printf("Inserto cancion3 al final\n");
    insertAtEnd(&myList, "cancion3");
    printList(myList);

    printf("Inserto cancion4 al final\n");
    insertAtEnd(&myList, "cancion4");
    printList(myList);

    printf("Inserto una canción despues de cancion2\n");
    insertAfter(&myList,"cancion2","otracancion2");
    printList(myList);

    printf("Inserto una canción antes de cancion1\n");
    insertBefore(&myList,"cancion1","otracancion1"); 
    printList(myList);


    ordenarLista(&myList);
    printList(myList);


    printf("Borro la cancion1\n");
    deleteNode(&myList, "cancion1");
    printList(myList);

    printf("Borro la cancion no existe\n");
    deleteNode(&myList, "no existe");
    printList(myList);

    printf("Elimino el primero\n");
    deleteFromFront(&myList);
    printList(myList);

    printf("Elimino todos\n");
    DeleteAll (&myList);
    printList(myList);


    return 0;
}