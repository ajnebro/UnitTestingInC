#include <stdio.h>
#include "stack.h"

int main() {
    Stack stack;
    initStack(&stack);

    // Test pushing elements
    for (int i = 0; i < 5; ++i) {
        if (push(&stack, i)) {
            printf("Pushed %d onto the stack.\n", i);
        } else {
            printf("Failed to push %d onto the stack.\n", i);
        }
    }

    // Test peeking the top element
    int value;
    if (peek(&stack, &value)) {
        printf("Peeked at the top element: %d\n", value);
    } else {
        printf("Failed to peek at the top element.\n");
    }

    // Test popping elements
    while (!isEmpty(&stack)) {
        if (pop(&stack, &value)) {
            printf("Popped %d from the stack.\n", value);
        } else {
            printf("Failed to pop from the stack.\n");
        }
    }

    return 0;
}

