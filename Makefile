CC ?= cc
CFLAGS ?= -O2 -g
CFLAGS += -std=c17 -Wall -Wextra -Wpedantic -Wconversion -Wshadow
LDLIBS += -lm

TARGET := freefall
OBJECTS := freefall.o

.PHONY: all clean distclean run convergence plot

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

freefall.o: freefall.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET) 0.1 10

convergence: $(TARGET) genera_convergenza.sh
	./genera_convergenza.sh ./$(TARGET) > convergenza.dat

plot: convergence plot_convergenza.gp
	gnuplot plot_convergenza.gp
	test -s convergenza.png

clean:
	$(RM) $(TARGET) $(OBJECTS)

distclean: clean
	$(RM) convergenza.dat convergenza.png convergenza-rigenerato.dat fit.log
