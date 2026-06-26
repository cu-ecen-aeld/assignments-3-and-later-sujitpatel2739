# Compiler
CC := $(CROSS_COMPILE)gcc

# Compiler flags
CFLAGS := -Wall -Wextra -g

# Target executable
TARGET := writer

# Source files
SRCS := writer.c

# Object files
OBJS := $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target
clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean
