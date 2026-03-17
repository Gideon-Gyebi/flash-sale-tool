# Makefile for Flash Sale Tool
# Automates compilation, cleaning, and optional data reset

# Compiler
CC = gcc

# Target executable
TARGET = flash_sale_tool

# Source files
SRC = main.c

# ----------------- DEFAULT: compile program -----------------
all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET)

# ----------------- CLEAN: delete only executable -----------------
clean:
	rm -f $(TARGET)

# ----------------- RESET: delete executable AND CSV data -----------------
reset:
	rm -f $(TARGET)
	rm -f data/*.csv

# Run the program
run: $(TARGET)
	./$(TARGET)

# Git Setup
git_setup1:
	/env/git_setup.bat
git_setup2:
	./env/git_setup.sh

# Phony targets to avoid conflicts with files named 'clean' or 'reset'
.PHONY: all clean reset run git_setup1 git_setup2

# Note: Ensure that the 'data' directory exists before running the program.