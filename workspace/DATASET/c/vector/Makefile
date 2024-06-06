CC=gcc


test: vector.o
	$(CC) -o $@ $< -O0 

vector.o: vector.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
