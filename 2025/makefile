# -------------------------------------------------
# 	makefile
#
#	(c) Noah Gergel 2025
# -------------------------------------------------

# Compiler and flags.
CC := gcc
INCLUDES := -I.
CFLAGS := -std=c11 -O2 $(INCLUDES)
LDFLAGS := -std=c11 -O2 -lm

# Target.
TARGET := aoc

# Source files.
SRCS := \
	main.c \
	days/day1.c \
	days/day2.c \
	days/day3.c \
	days/day4.c

# Object files.
OBJS := $(SRCS:.c=.o)


# Rules.
all: $(TARGET)

# Link.
$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

# Compile.
%.o: %.c aoc.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean-up rules.
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean