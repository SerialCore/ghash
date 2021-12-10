all: ghash.c table.c
	gcc ghash.c table.c -o ghash

install:
	sudo cp ghash /usr/local/bin