
# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lm

# Source and Object Files
SRCS = main.c csv.c city.c string.c math_helper.c constants.c random.c time.c user_input.c geo.c
OBJS = $(SRCS:.c=.o)
TARGET = hunt

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

