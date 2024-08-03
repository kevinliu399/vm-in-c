SRC_FILES = main.c
CC_FLAGS = -Wall -Wextra -Werror -g -std=c11
CC = gcc

all:
	$(CC) $(CC_FLAGS) $(SRC_FILES) -o main

clean:
	rm -f main