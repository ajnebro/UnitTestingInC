CC = gcc
CFLAGS = -Wall -Wextra -std=c11
INCLUDE_DIRS = -I src
SRC_DIR = src
TARGET = app
SRC = $(SRC_DIR)/doubly_linked_list.c
OBJ = $(SRC_DIR)/doubly_linked_list.o $(SRC_DIR)/main.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(SRC_DIR)/doubly_linked_list.o: $(SRC_DIR)/doubly_linked_list.c $(SRC_DIR)/doubly_linked_list.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $(SRC_DIR)/doubly_linked_list.c -o $(SRC_DIR)/doubly_linked_list.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/doubly_linked_list.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $(SRC_DIR)/main.c -o $(SRC_DIR)/main.o

clean:
	rm -f $(OBJ) $(SRC_DIR)/*.o 

.PHONY: all clean test
