CC = gcc
CFLAGS = -Wall
EXEC = mycp

all: $(EXEC)

mycp: mycp.o myio.o
	$(CC) -o $@ $^

mycp.o: myio.h

myio.o: myio.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
