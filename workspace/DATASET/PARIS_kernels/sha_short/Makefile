CC=gcc


test: sha_short.o
	$(CC) -o $@ $< -O0 

sha_short.o: sha_short.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
