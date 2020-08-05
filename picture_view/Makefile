CC = gcc  
MAINC = picture_view.c
EXEC = picture_view

CFLAGS = `pkg-config --cflags --libs gtk+-2.0 gmodule-export-2.0`
main:  
	$(CC)  $(MAINC)  -o $(EXEC) $(CFLAGS)
clean:
	rm $(EXEC) -rf