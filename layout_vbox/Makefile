CC = gcc  
MAINC = vbox.c
EXEC = vbox

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:  
	$(CC) $(MAINC) -o $(EXEC) $(CFLAGS)
clean:
	rm $(EXEC) -rf