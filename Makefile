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
