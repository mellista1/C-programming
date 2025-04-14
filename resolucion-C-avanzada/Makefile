CC = gcc
CFLAGS = -Wall -Wextra -pedantic -g
TARGET = Solucion-guia

all: $(TARGET)

$(TARGET): Solucion-guia.o
		$(CC) $(CFLAGS) $^ -o $@

hola.o: Solucion-guia.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm *.o $(TARGET)

.PHONY: all cleans