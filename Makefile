CC ?= cc
CFLAGS ?= -O2 -g
CFLAGS += -std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wshadow
LDLIBS += -lm

TARGET := freefall
OBJECTS := freefall.o

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

freefall.o: freefall.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) 0.1 10

clean:
	$(RM) $(TARGET) $(OBJECTS)
