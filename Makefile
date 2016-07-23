CC=gcc

default: JPGDestroyer

JPGDestroyer: main.c
	$(CC) main.c -o JPGDestroyer

clean:
	rm JPGDestroyer
