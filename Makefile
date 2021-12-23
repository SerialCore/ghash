all: ghash.c fileio.c table.c hash.c
	gcc ghash.c fileio.c table.c hash.c -o ghash

install:
	sudo cp ghash /usr/local/bin