CC=gcc
CCFLAGS=-Wall
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)
TARGET=main

FILES_PATH_COMMON


all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c %.h
		$(CC) $(CCFLAGS) -c $<

%.o: %.c
		$(CC) $(CCFLAGS) -c $<

clean:
		rm -f *.o $(TARGET)