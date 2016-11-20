
#g++ -Wall test.cpp -o test

# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
CHEADER_DIR = -I src/include/
SRC_DIR = src/

# the build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): $(TARGET).c src/MyHeap.c
	$(CC) $(CFLAGS) -o bin/$(TARGET) $(TARGET).c src/MyHeap.c $(CHEADER_DIR)

testmyheap: test_my_heap.c src/MyHeap.c
	$(CC) $(CFLAGS) -o bin/test_my_heap test_my_heap.c src/MyHeap.c $(CHEADER_DIR)

run: bin/$(TARGET)
	./bin/$(TARGET) $(ARGS)

clean:
	$(RM) $(TARGET)

