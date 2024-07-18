#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

typedef struct Node {
    const char *data;
    struct Node *prev;
    struct Node *next;
} Node, *DoublyLinkedList;

/**
 * @brief Create and return a new node with the given value.
 *
 * @param value The value to store in the new node.
 * @return A pointer to the newly created node.
 */
DoublyLinkedList createNode(const char* value);

/**
 * @brief Insert a new node with the given value at the front of the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value to insert at the front.
 */
void insertAtFront(DoublyLinkedList* head, const char* value);

/**
 * @brief Insert a new node with the given value at the end of the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value to insert at the end.
 */
void insertAtEnd(DoublyLinkedList* head, const char* value);

/**
 * @brief Insert a new node with the given value after a specified node.
 *
 * @param head A pointer to the head of the list.
 * @param existingValue The value of the existing node to insert after.
 * @param newValue The value to insert.
 */
void insertAfter(DoublyLinkedList *head, const char *existingValue, const char* newValue);

/**
 * @brief Insert a new node with the given value before a specified node.
 *
 * @param head A pointer to the head of the list.
 * @param existingValue The value of the existing node to insert before.
 * @param newValue The value to insert.
 */
void insertBefore(DoublyLinkedList* head, const char *existingValue, const char* newValue);

/**
 * @brief Delete the node at the front of the list.
 *
 * @param head A pointer to the head of the list.
 */
void deleteFromFront(DoublyLinkedList* head);

/**
 * @brief Print the entire list.
 *
 * @param head The head of the list.
 */
void printList(DoublyLinkedList head);

/**
 * @brief Delete a node with the specified value from the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value of the node to delete.
 * @return 1 if the node was deleted, 0 if the node was not found.
 */
int deleteNode(DoublyLinkedList *head, const char *value);

/**
 * @brief Insert a node in an ordered manner in the list.
 *
 * @param head A pointer to the head of the list.
 * @param value The value to insert in order.
 */
void insertOrdered(DoublyLinkedList* head, const char* value);

/**
 * @brief Sort the list using bubble sort.
 *
 * @param head A pointer to the head of the list.
 */
void sortList(DoublyLinkedList* head);

/**
 * @brief Delete all nodes in the list.
 *
 * @param head A pointer to the head of the list.
 */
void deleteAll(DoublyLinkedList *head);

#endif // DOUBLY_LINKED_LIST_H