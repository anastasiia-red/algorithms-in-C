CC = gcc
CFLAGS = -Wall -Iinclude

SRC_DIR = src
OBJ_DIR = build

SORT_DIR = $(SRC_DIR)/sorting
STACK_DIR = $(SRC_DIR)/stack
QUEUE_DIR = $(SRC_DIR)/queue
LIST_DIR = $(SRC_DIR)/linked_list
HASH_DIR = $(SRC_DIR)/hashtable

SRCS = \
    $(SORT_DIR)/bubbleSort.c \
    $(SORT_DIR)/heapSort.c \
    $(SORT_DIR)/insertSort.c \
    $(SORT_DIR)/quickSort.c \
    $(SORT_DIR)/radixSort.c \
    $(SORT_DIR)/selectionSort.c \
    $(STACK_DIR)/lstack.c \
    $(QUEUE_DIR)/lqueue.c \
    $(LIST_DIR)/llist.c \
    $(HASH_DIR)/hashtable.c \
    $(SRC_DIR)/main.c

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

TARGET = sort_project

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
