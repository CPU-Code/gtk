CC = gcc  
MAINC = scrolled_window2.c
EXEC = scrolled_window2
CFLAGS = `pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0`

main:  
	$(CC)  $(MAINC)  -o $(EXEC) $(CFLAGS)

clean:
	rm $(EXEC) -rf