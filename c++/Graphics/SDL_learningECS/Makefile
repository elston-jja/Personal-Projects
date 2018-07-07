SRC_DIR := src

# Name of file to compile
PROGRAM := $(wildcard $(SRC_DIR)/*.cpp)

# Compiler to use
CC = g++

# Compiler FLAGS
FLAGS := -Wall -g

# External libraries to include
LIBS := -lSDL2 -lSDL2_image

# Product name
OUT := main.out

install:

	make build;
	make run;

build:
	$(CC) $(FLAGS) $) $(LIBS) -o $(OUT) $(PROGRAM)

run:
	./main.out


clean:
	rm main.out;
