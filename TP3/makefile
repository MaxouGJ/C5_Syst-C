CC=gcc
CFLAGS=-Wall
EXEC=myecho

all: $(EXEC)

myecho: strlib.o myecho.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
