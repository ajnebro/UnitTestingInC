CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC_DIR = src
TEST_DIR = test
UNITY_DIR = $(TEST_DIR)/unity
TARGET = stack_app
TEST_TARGET = run_tests
SRC = $(SRC_DIR)/stack.c
OBJ = $(SRC_DIR)/stack.o $(SRC_DIR)/main.o
TEST_SRC = $(TEST_DIR)/test_stack.c $(UNITY_DIR)/unity.c
TEST_OBJ = $(TEST_DIR)/test_stack.o $(UNITY_DIR)/unity.o

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

$(SRC_DIR)/stack.o: $(SRC_DIR)/stack.c $(SRC_DIR)/stack.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/stack.c -o $(SRC_DIR)/stack.o

$(SRC_DIR)/main.o: $(SRC_DIR)/main.c $(SRC_DIR)/stack.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.c -o $(SRC_DIR)/main.o

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJ) $(SRC_DIR)/stack.o
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) $(SRC_DIR)/stack.o

$(TEST_DIR)/test_stack.o: $(TEST_DIR)/test_stack.c $(SRC_DIR)/stack.h $(UNITY_DIR)/unity.h
	$(CC) $(CFLAGS) -c $(TEST_DIR)/test_stack.c -o $(TEST_DIR)/test_stack.o

$(UNITY_DIR)/unity.o: $(UNITY_DIR)/unity.c $(UNITY_DIR)/unity.h
	$(CC) $(CFLAGS) -c $(UNITY_DIR)/unity.c -o $(UNITY_DIR)/unity.o

clean:
	rm -f $(OBJ) $(SRC_DIR)/*.o $(TEST_OBJ) $(UNITY_DIR)/*.o $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
