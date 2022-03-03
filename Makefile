# 参考 https://docs.oracle.com/cd/E19620-01/805-5827/6j5gfrank/index.html
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -MMD -MP

ONJ_DIR = ./obj/

init: obj
obj:
	mkdir obj
all: $(BIN_DIR)cgradient.o
$(BIN_DIR)cgradient.o: cgradient.c
	$(CC) $(CFLAGS) -c $^ $@


clean:
