CC=gcc


test: CastleTowers.o
	$(CC) -o $@ $< -O0 

CastleTowers.o: CastleTowers.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
