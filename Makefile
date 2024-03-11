CC = g++
TARGET = add-nbo
OBJS = main.o

all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $(TARGET) main.cpp
.c.o:
	$(CC) -c -o $(TARGET) main.cpp
clean:
	rm -rf $(OBJS) $(TARGET)
