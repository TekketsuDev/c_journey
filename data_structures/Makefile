TARGET := ds_visual
CC     := gcc

CFLAGS  := -Wall -Wextra -Wpedantic -std=c11 -Iinclude
LDFLAGS := -lraylib -lm -lpthread -ldl -lrt -lX11

BUILD_DIR := build
OBJ_DIR   := $(BUILD_DIR)/obj
BIN_DIR   := $(BUILD_DIR)/bin

SRC := \
	src/controller/main.c \
	src/model/t_queue.c \
	src/model/t_stack.c \
	src/model/t_manager.c \
	src/view/visual_queue.c \
	src/view/visual_factory.c

# opcionales
# SRC += src/common/helpers.c

OBJ := $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))

all: $(BIN_DIR)/$(TARGET)

$(BIN_DIR)/$(TARGET): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
	./$(BIN_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all run clean

