CC=gcc
CFLAGS=-Wall -Wextra -std=c11

all:
	$(CC) $(CFLAGS) main.c tasks.c -o devlog

clean:
	rm -f devlog temp.txt