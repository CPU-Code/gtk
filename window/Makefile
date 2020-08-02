CC = gcc
MAINC = window.c
EXEC = window

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:
	$(CC) $(MAINC) -O $(EXEC) $(CFLAGS)

clean:
	rm $(EXEC) -rf