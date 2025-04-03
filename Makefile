# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g -Iimports

# Executable name
TARGET = main

# Source and object files
SRCDIR = src
INCDIR = imports
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:.c=.o)

# Detect OS
OS := $(shell uname -s 2>/dev/null || echo Windows)

# Set platform-specific commands
ifeq ($(OS), Windows)
    RM = del /F
    EXE = .exe
else
    RM = rm -f
    EXE =
endif

# Default target
all: $(TARGET)$(EXE)

# Build the executable
$(TARGET)$(EXE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET)$(EXE) $(OBJECTS)

# Compile object files
$(SRCDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/*.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	$(RM) $(OBJECTS) $(TARGET)$(EXE)

