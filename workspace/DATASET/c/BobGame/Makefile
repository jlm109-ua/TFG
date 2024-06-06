CC=gcc


test: BobGame.o
	$(CC) -o $@ $< -O0 

BobGame.o: BobGame.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
