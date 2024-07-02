#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Define the maximum size of the stack
#define MAX_SIZE 100

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function prototypes
void initStack(Stack* stack);
bool isFull(const Stack* stack);
bool isEmpty(const Stack* stack);
bool push(Stack* stack, int value);
bool pop(Stack* stack, int* value);
bool peek(const Stack* stack, int* value);

#endif // STACK_H

