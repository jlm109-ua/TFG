CC=gcc


test: hash_xor8.o
	$(CC) -o $@ $< -O0 

hash_xor8.o: hash_xor8.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
