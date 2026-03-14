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