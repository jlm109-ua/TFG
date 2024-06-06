CC=gcc


test: DefiniteRandomWalks.o
	$(CC) -o $@ $< -O0

DefiniteRandomWalks.o: DefiniteRandomWalks.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
