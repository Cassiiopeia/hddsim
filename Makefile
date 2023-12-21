# compiler 
CC = gcc

# compile option
CFLAGS = -Wall -g

# build execute file name 
TARGET = main

# basic execute file 
all: $(TARGET)

# compile files
SOURCES = main.c task_queue.c

# Rule of execute file 
$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

# clean file
clean:
	rm -f $(TARGET)

