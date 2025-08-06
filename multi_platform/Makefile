
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2
LDFLAGS =
LDLIBS =

SRC = main.c platform.c
OBJ = $(SRC:.C=.o)
OUT = program

ifeq ($(OS),Windows_NT)
	TARGET = windows
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		TARGET = linux
	endif
endif

ifeq ($(TARGET),windows)
	CC = x86_64-w64-mingw32-gcc
	OUT := $(OUT).exe
	CFLAGS += -Wl,--subsystem,console
	LDLIBS = -lws2_32
endif

all: $(OUT)
$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -O $@

run: $(OUT)
ifeq ($(TARGET),windows)
	wine $(OUT)
else
	./$(OUT)
endif

clean: 
	rm -f $(OUT) *.o
