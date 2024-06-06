CC=gcc


test: hash_blake2b.o
	$(CC) -o $@ $< -O0 

hash_blake2b.o: hash_blake2b.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
