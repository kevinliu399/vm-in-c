#include <stdio.h>
#include <stdbool.h>
#include "./utils/stack.h"

typedef enum {
    A, B, C, D, E, F, IP,
    NUM_OF_REGISTERS
} Registers;

typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT,
} InstructionSet;

const int program[] = {
    PSH, 10,
    SET, IP, 0,
    HLT,
};

/*
PSH 10        ;  0 1
PSH 20        ;  2 3
SET IP 0      ;  4 5 6
*/

int registers[NUM_OF_REGISTERS];

#define ip (registers[IP])

bool running = true;
Stack stack;

int fetch();
void eval(int instr);

int main() {
    init_stack(&stack, 256);
    
    // Initialize IP to 0
    ip = 0;
    
    while (running) {
        eval(fetch());
        ip++;  // This increment might be overwritten by SET instructions
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
        case SET: {
            Registers reg = program[++ip];
            int value = program[++ip];
            registers[reg] = value;
            if (reg == IP) {
                ip = value - 1;  // -1 because ip will be incremented after this instruction
            }
            break;
        }
    }
}