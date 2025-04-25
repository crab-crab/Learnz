
# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm -lncurses

# Source and Object Files
SRCS = main.c screen.c constants.c physics.c string.c
OBJS = $(SRCS:.c=.o)
TARGET = ball

# Default target
all: $(TARGET)

# Rule to build executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $(TARGET)

# Rule to compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

