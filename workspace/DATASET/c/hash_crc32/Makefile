CC=gcc


test: hash_crc32.o
	$(CC) -o $@ $< -O0 

hash_crc32.o: hash_crc32.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
