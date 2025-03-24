CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRCS = src/main.c src/utils.c
OBJS = $(SRCS:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.h $(TARGET)

