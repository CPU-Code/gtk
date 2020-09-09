CC = gcc  
MAINC = read_directory.c
EXEC = read_directory

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:  
	$(CC)  $(MAINC)  -o $(EXEC) $(CFLAGS)
clean:
	rm $(EXEC) *.o -rf