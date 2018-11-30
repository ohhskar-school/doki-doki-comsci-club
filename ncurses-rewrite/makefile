CC=gcc
CFLAGS=-lncurses -I. -lm
DEPS = gameInfo.h
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

game: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)