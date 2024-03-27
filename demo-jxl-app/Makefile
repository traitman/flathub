CC = gcc
CFLAGS = -Wall -Wextra
LDFLAGS = -ljxl

TARGET = jxl_info_dump
SRCS = main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

