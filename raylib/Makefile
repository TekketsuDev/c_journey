# Makefile sencillo para compilar main.c con raylib
CC      = gcc
CFLAGS  = -Wall -std=c99
LDFLAGS = -lraylib -lm -ldl -lpthread -lGL -lX11

SRC     = main.c
OUT     = main

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) $(LDFLAGS)

run: $(OUT)
	./$(OUT)

clean:
	rm -f $(OUT)

