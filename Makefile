CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -I$(INCDIR)
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = hexdump

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(BUILDDIR)/%.o)

.PHONY: all clean

all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(BUILDDIR)
	$(CC) $(OBJECTS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR)

run: $(BUILDDIR)/$(TARGET)
	./$(BUILDDIR)/$(TARGET)

debug: $(BUILDDIR)/$(TARGET)
	gdb ./$(BUILDDIR)/$(TARGET)
