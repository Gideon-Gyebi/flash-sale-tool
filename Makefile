# Makefile for Flash Sale Tool
# Automates compilation, cleaning, and optional data reset

# ----------------- COMPILER -----------------
CC = gcc

# ----------------- DIRECTORIES -----------------
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
DATA_DIR = data
ENV_DIR = env

# ----------------- FILES -----------------
SRC = $(SRC_DIR)/main.c
OBJ = $(OBJ_DIR)/main.o
TARGET = $(BIN_DIR)/flash_sales_tool

# ----------------- DEFAULT: compile program -----------------
all: $(TARGET)

# Ensure obj/ and bin/ exist before compiling
$(TARGET): $(OBJ) | $(OBJ_DIR) $(BIN_DIR)
	$(CC) $(OBJ) -o $(TARGET)

# Compile object file
$(OBJ): $(SRC) | $(OBJ_DIR)
	$(CC) -c $(SRC) -o $(OBJ)

# Create required directories if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# ----------------- CLEAN: delete only executable -----------------
clean:
	rm -f $(TARGET)

# ----------------- RESET: delete executable AND CSV data -----------------
reset:
	rm -f $(TARGET)
	rm -f $(DATA_DIR)/*.csv

# ----------------- RUN: execute program -----------------
ifeq ($(OS),Windows_NT)
run: $(TARGET)
	$(TARGET).exe
else
run: $(TARGET)
	./$(TARGET)
endif

# ----------------- GIT SETUP: unified cross-platform -----------------
# Detect OS: Windows uses CMD, Linux/Bash uses ./ script
ifeq ($(OS),Windows_NT)
git_setup:
	$(ENV_DIR)/git_setup.bat
else
git_setup:
	./$(ENV_DIR)/git_setup.sh
endif

# ----------------- PHONY TARGETS -----------------
# Ensures make treats these as commands, not files
.PHONY: all clean reset run git_setup