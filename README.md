# Simple Virtual Machine (VM) Implementation

This project implements a basic Virtual Machine (VM) that can execute a simple set of instructions. The VM is designed to demonstrate fundamental concepts of computer architecture and low-level programming.

## Features

- Custom instruction set
- Stack-based operations
- Basic branching capabilities
- Register system
- Modular design with separate stack implementation

## Instruction Set

The VM supports the following instructions:

- `PSH`: Push a value onto the stack
- `ADD`: Pop two values from the stack, add them, and push the result
- `POP`: Pop a value from the stack and print it
- `SET`: Set a value to a specific register
- `HLT`: Halt the VM execution

## Registers

The VM includes the following registers:

- General-purpose registers: A, B, C, D, E, F
- Instruction Pointer (IP): Points to the current instruction

## Stack

The VM uses a stack for most of its operations. The stack is implemented in a separate module (`stack.c` and `stack.h`), providing modularity and ease of maintenance.

## Usage

To use the VM, follow these steps:

1. Ensure you have a C compiler installed on your system.
2. Clone this repository.
3. Compile the project:
`make all`
4. Run the VM:
./main

## Customizing the Program

You can modify the `program` array in `main.c` to change the instructions executed by the VM. For example:

```c
const int program[] = {
 PSH, 5,
 PSH, 6,
 ADD,
 POP,
 SET, IP, 0,  // This will create an infinite loop
 HLT,
};
```

This VM was made by following this https://blog.felixangell.com/virtual-machine-in-c/
