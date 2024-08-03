#include <stdio.h>
#include <stdbool.h>
#include "./utils/stack.h"

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT,
} InstructionSet;

typedef enum {
    A,B,C,D,E,F,
    NUM_OF_REGISTERS
} Registers;

const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    POP,
    HLT,
};

Stack stack;
bool running = true;
int ip = 0; // Instruction Pointer, serves as the index of the current instruction
int registers[NUM_OF_REGISTERS]; // enum -> A=0, B=1, ...


int fetch();
void eval(int instr);

int main() {
    init_stack(&stack, 256);
    printf("%d\n", registers[A]);

    while (running) {
        eval(fetch());
        ip ++;
    }

    free_stack(&stack);
    return 0;
}

int fetch() {
    return program[ip];
}

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            break;
        }
        case PSH: {
            push(&stack, program[++ip]);
            break;
        }
        case POP: {
            int popped_value = pop(&stack);
            printf("popped %d\n", popped_value);
            break;
        }
        case ADD: {
            add(&stack);
            break;
        }
    }
}