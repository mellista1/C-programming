CC = gcc
CFLAGS = -Wall -Wextra -pedantic
TARGET = hola

all: $(TARGET)

$(TARGET): hola.o
		$(CC) $(CFLAGS) $^ -o $@

hola.o: holaOrga.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all clean