CC = gcc  
MAINC = progress_bar2.c
EXEC = progress_bar2
CFLAGS = `pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0`

main:  
	$(CC)  $(MAINC)  -o $(EXEC) $(CFLAGS)
	
clean:
	rm $(EXEC) -rf