CFLAGS = -Wall -I./include
SRCDIR = src
OBJDIR = obj
BINDIR = bin

SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))
TARGET = $(BINDIR)/main

$(shell mkdir -p $(BINDIR))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	gcc $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -r $(OBJDIR) $(BINDIR)

