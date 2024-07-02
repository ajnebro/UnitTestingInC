CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = stack_app
OBJ = stack.o main.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

main.o: main.c stack.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean

