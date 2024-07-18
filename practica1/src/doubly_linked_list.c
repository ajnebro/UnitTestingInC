#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doubly_linked_list.h"

/**
 * @brief Create and return a new node with the given value.
 *
 * @param value The value to store in the new node.
 * @return A pointer to the newly created node.
 */
DoublyLinkedList createNode(const char *value) {
    DoublyLinkedList newNode = (DoublyLinkedList)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Insert a new node with the given value at the front of the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value to insert at the front.
 */
void insertAtFront(DoublyLinkedList *head, const char *value) {
    DoublyLinkedList newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

/**
 * @brief Insert a new node with the given value at the end of the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value to insert at the end.
 */
void insertAtEnd(DoublyLinkedList *head, const char *value) {
    DoublyLinkedList newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
    } else {
        DoublyLinkedList temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

/**
 * @brief Insert a new node with the given value after a specified node.
 *
 * @param head A pointer to the head of the list.
 * @param existingValue The value of the existing node to insert after.
 * @param newValue The value to insert.
 */
void insertAfter(DoublyLinkedList *head, const char *existingValue, const char* newValue) {
    DoublyLinkedList temp = *head;
    while (temp != NULL && strcmp(temp->data, existingValue) != 0) {
        temp = temp->next;
    }
    if (temp != NULL) {
        DoublyLinkedList newNode = createNode(newValue);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

/**
 * @brief Insert a new node with the given value before a specified node.
 *
 * @param head A pointer to the head of the list.
 * @param existingValue The value of the existing node to insert before.
 * @param newValue The value to insert.
 */
void insertBefore(DoublyLinkedList* head, const char *existingValue, const char* newValue) {
    DoublyLinkedList temp = *head;
    while (temp != NULL && strcmp(temp->data, existingValue) != 0) {
        temp = temp->next;
    }
    if (temp != NULL) {
        DoublyLinkedList newNode = createNode(newValue);
        newNode->next = temp;
        newNode->prev = temp->prev;
        if (temp->prev != NULL) {
            temp->prev->next = newNode;
        } else {
            *head = newNode;
        }
        temp->prev = newNode;
    }
}

/**
 * @brief Delete the node at the front of the list.
 *
 * @param head A pointer to the head of the list.
 */
void deleteFromFront(DoublyLinkedList *head) {
    if (*head != NULL) {
        DoublyLinkedList temp = *head;
        *head = (*head)->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
    }
}

/**
 * @brief Print the entire list.
 *
 * @param head The head of the list.
 */
void printList(DoublyLinkedList head) {
    DoublyLinkedList current = head;
    if (current == NULL) {
        printf("Empty list\n");
    } else {
        while (current != NULL) {
            printf("%s ", current->data);
            current = current->next;
        }
    }
    printf("\n");
}

/**
 * @brief Delete a node with the specified value from the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value of the node to delete.
 * @return 1 if the node was deleted, 0 if the node was not found.
 */
int deleteNode(DoublyLinkedList *head, const char *value) {
    DoublyLinkedList temp = *head;
    while (temp != NULL && strcmp(temp->data, value) != 0) {
        temp = temp->next;
    }
    if (temp != NULL) {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else {
            *head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        free(temp);
        return 1;
    }
    return 0;
}

/**
 * @brief Insert a node in an ordered manner in the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value to insert in order.
 */
void insertOrdered(DoublyLinkedList* head, const char* value) {
    if (*head == NULL || strcmp((*head)->data, value) >= 0) {
        insertAtFront(head, value);
    } else {
        DoublyLinkedList temp = *head;
        while (temp->next != NULL && strcmp(temp->next->data, value) < 0) {
            temp = temp->next;
        }
        DoublyLinkedList newNode = createNode(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
}

/**
 * @brief Sort the list using bubble sort.
 *
 * @param head A pointer to the head of the list.
 */
void sortList(DoublyLinkedList* head) {
    if (*head == NULL) {
        return;
    }
    int swapped;
    DoublyLinkedList ptr1;
    DoublyLinkedList lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (strcmp(ptr1->data, ptr1->next->data) > 0) {
                const char *temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

/**
 * @brief Delete all nodes in the list.
 *
 * @param head A pointer to the head of the list.
 */
void deleteAll(DoublyLinkedList *head) {
    DoublyLinkedList current = *head;
    DoublyLinkedList next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}