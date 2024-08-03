#ifndef STACK_H
#define STACK_H

// Stack data structure - LIFO

typedef struct {
    int *items;
    int top; // Index of the top element
    int size;
} Stack;

void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
void init_stack(Stack *stack, int size);
void free_stack(Stack *stack);

#endif // STACK_H