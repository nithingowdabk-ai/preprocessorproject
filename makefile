CC = gcc
CFLAGS = -Wall

TARGET = mypreprocessor

SOURCES = main.c comment_removal.c header_includes.c macro_replace.c

OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.c preprocessor.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)
