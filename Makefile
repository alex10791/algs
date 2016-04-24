
#g++ -Wall test.cpp -o test

# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall
CHEADER_DIR = -I src/include/

# the build target executable:
TARGET = main

all: $(TARGET)

$(TARGET): src/$(TARGET).cpp
	$(CC) $(CFLAGS) -o bin/$(TARGET) src/$(TARGET).cpp $(CHEADER_DIR)

run: bin/$(TARGET)
	./bin/$(TARGET) $(ARGS)

clean:
	$(RM) $(TARGET)

