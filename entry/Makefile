CC = gcc
MAINC = entry.c
EXEC = entry

CFLAGS = `pkg-config -cflags --libs gtk+-2.0`

main:
	$(CC) $(MAINC) -o $(EXEC) $(CFLAGS)
clean:
	rm $(EXEC) -rf