# compiler 
CC = gcc

# compile option
CFLAGS = -Wall -g

# build execute file name 
TARGET = main

# basic execute file 
all: $(TARGET)

# Rule of execute file 
$(TARGET): main.c
	$(CC) $(CFLAGS) -o $@ main.c

# clean file
clean:
	rm -f $(TARGET)

