CC=gcc


test: GemStones.o
	$(CC) -o $@ $< -O0 

GemStones.o: GemStones.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
