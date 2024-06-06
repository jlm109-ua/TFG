CC=gcc


test: hash_sdbm.o
	$(CC) -o $@ $< -O0 

3DSurfaceArea.o: hash_sdbm.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
