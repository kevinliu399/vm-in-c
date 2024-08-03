#include <stdlib.h>
#include "stack.h"

void init_stack(Stack *stack, int size) {
    stack -> items = (int *) malloc(size * sizeof(int));
    stack -> top = -1; // Empty stack
    stack -> size = size;
}

void free_stack(Stack *stack) {
    free(stack -> items);
}

// Push the value at the end of the list
void push(Stack *stack, int value) {
    // first we need to check the size
    if (stack -> top == stack -> size - 1) {
        int new_size = stack -> size * 2;
        int *new_items = (int *) realloc(stack -> items, new_size * sizeof(int));
        if (new_items == NULL) {
            return ;
        } 
        stack -> items = new_items;
        stack -> size = new_size;
    }

    stack -> top ++;
    stack -> items[stack -> top] = value;
}

// remove the last top value an return it
int pop(Stack *stack) {
    // no element in the list - can't pop
    if (stack -> top == -1) {
        return -1;
    }

    int value = stack -> items[stack -> top];
    stack -> items[stack -> top] = 0; // clear the value
    stack -> top --;

    return value;
}

// check the top stack value
int peek(Stack *stack) {
    // can't peek empty stack
    if (stack -> top == -1) {
        return -1;
    }
    return stack -> items[stack -> top];
}