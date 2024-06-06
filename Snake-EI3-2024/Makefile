# Compiler
CC = gcc

# Compilation flags
CFLAGS = -std=c99

# Source files
SRCS = main.c snakes.c arena.c snakeAPI.c clientAPI.c 

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
EXEC = main

# Default rule
all: $(EXEC)

# Rule to build the executable
$(EXEC): $(OBJS) $(HDRS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Rule to compile source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to clean generated files
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean