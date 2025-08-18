# === Compiler and Flags ===
CFLAGS   = -Wall -Wextra -Werror -O2 -Iinclude
WIN_LDFLAGS   = -Wl,--subsystem,console -lws2_32 -Include -Wno-error=unknown-pragmas -Wno-unkwnown-pragmas
LINUX_LDFLAGS =

# === Platform Detection ===
ifeq ($(OS),Windows_NT)
    TARGET = windows
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        TARGET = linux
    endif
endif

ifeq ($(TARGET),windows)
    CC      = x86_64-w64-mingw32-gcc
    OUT     = program.exe
    LDFLAGS = $(WIN_LDFLAGS)
else
    CC      = gcc
    OUT     = program
    LDFLAGS = $(LINUX_LDFLAGS)
endif

# === Source Discovery ===
COMMON_DIR   = common
PLATFORM_DIR = $(TARGET)

SRCS = $(wildcard $(COMMON_DIR)/*.c) $(wildcard $(PLATFORM_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

# === Default Target ===
all: $(OUT)

$(OUT): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.c
ifeq ($(TARGET),windows)
	$(CC) -Wall -Wextra -O2 -Iinclude -Wno-error=unknown-pragmas -c $< -o $@
else
	$(CC) $(CFLAGS) -c $< -o $@
endif

# === Run Target ===
run: $(OUT)
ifeq ($(TARGET),windows)
	WINEDEBUG=-all wine $(OUT)
else
	./$(OUT)
endif

# === Clean Target ===
clean:
	rm -f $(OUT) $(COMMON_DIR)/*.o $(PLATFORM_DIR)/*.o

.PHONY: all clean run

