# Compiler settings
CC = clang
CFLAGS = -Wall -Werror -g

# Directories
SRC_DIR = src
TEST_DIR = tests
BUILD_DIR = build

# Source files using wildcards
SRC = $(wildcard $(SRC_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)


# Object files - put them all in BUILD_DIR
OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
TEST_OBJ = $(TEST_SRC:%.c=$(BUILD_DIR)/%.o)
LIBRARY_OBJS = $(BUILD_DIR)/src/library.o

# Output executables - one for each .c file in src
# EXECUTABLES = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%)
EXEC_SOURCES = $(filter-out $(SRC_DIR)/library.c, $(SRC))
EXECUTABLES = $(EXEC_SOURCES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%)

# Test executable
TEST_EXEC = $(BUILD_DIR)/test

# Include paths
INCLUDES = -I$(SRC_DIR)

# Create necessary build directories
$(shell mkdir -p $(BUILD_DIR)/src)
$(shell mkdir -p $(BUILD_DIR)/tests)

# Main target - builds all executables
all: $(EXECUTABLES)

# Test target (if you add test files later)
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Pattern rule for executables - one for each .c file
$(BUILD_DIR)/%: $(BUILD_DIR)/src/%.o $(LIBRARY_OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^

$(TEST_EXEC): $(OBJ) $(TEST_OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $^

# Pattern rules for object files
$(BUILD_DIR)/%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: test clean