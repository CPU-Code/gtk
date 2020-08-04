CC = gcc
MAINC = fixed.c
EXEC = fixed

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:
	$(CC) $(MAINC) -o $(EXEC) $(CFLAGS)
clead:
	rm $(EXEC) -rf