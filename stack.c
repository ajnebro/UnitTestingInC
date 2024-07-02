#include "stack.h"

// Initialize the stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if the stack is full
bool isFull(const Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Check if the stack is empty
bool isEmpty(const Stack* stack) {
    return stack->top == -1;
}

// Push an element onto the stack
bool push(Stack* stack, int value) {
    if (isFull(stack)) {
        return false;
    }
    stack->data[++stack->top] = value;
    return true;
}

// Pop an element from the stack
bool pop(Stack* stack, int* value) {
    if (isEmpty(stack)) {
        return false;
    }
    *value = stack->data[stack->top--];
    return true;
}

// Peek at the top element of the stack without removing it
bool peek(const Stack* stack, int* value) {
    if (isEmpty(stack)) {
        return false;
    }
    *value = stack->data[stack->top];
    return true;
}

