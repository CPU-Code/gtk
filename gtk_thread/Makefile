CC = gcc  
MAINC = gtk_thread.c
EXEC = gtk_thread

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:  
	$(CC)  $(MAINC)  -o $(EXEC) $(CFLAGS) -lgthread-2.0
clean:
	rm $(EXEC) -rf