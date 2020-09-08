CC = gcc  
MAINC = button_switch.c
EXEC = button_switch

CFLAGS = `pkg-config --cflags --libs gtk+-2.0`

main:  
	$(CC)  $(MAINC)  -o $(EXEC) $(CFLAGS) -lgthread-2.0
clean:
	rm $(EXEC) -rf