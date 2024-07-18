#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

/**
 * @brief The main function demonstrates various operations on the doubly linked list.
 *
 * @return Exit status code.
 */
int main() {
    DoublyLinkedList head = NULL;

    // Demonstrating insertion at the front
    insertAtFront(&head, "World");
    insertAtFront(&head, "Hello");
    printf("List after inserting 'Hello' and 'World' at the front: ");
    printList(head);

    // Demonstrating insertion at the end
    insertAtEnd(&head, "!");
    printf("List after inserting '!' at the end: ");
    printList(head);

    // Demonstrating insertion in an ordered manner
    insertOrdered(&head, "A");
    insertOrdered(&head, "Z");
    insertOrdered(&head, "M");
    printf("List after ordered insertions of 'A', 'Z', 'M': ");
    printList(head);

    // Demonstrating deletion of a node
    deleteNode(&head, "Z");
    printf("List after deleting 'Z': ");
    printList(head);

    // Demonstrating insertion before and after a specific node
    insertBefore(&head, "M", "B");
    insertAfter(&head, "M", "Y");
    printf("List after inserting 'B' before 'M' and 'Y' after 'M': ");
    printList(head);

    // Demonstrating deletion from the front
    deleteFromFront(&head);
    printf("List after deleting from the front: ");
    printList(head);

    // Demonstrating sorting the list
    sortList(&head);
    printf("List after sorting: ");
    printList(head);

    // Demonstrating deleting all nodes
    deleteAll(&head);
    printf("List after deleting all nodes: ");
    printList(head);

    return 0;
}