CC=gcc


test: PrimeNumberandQueries.o
	$(CC) -o $@ $< -O0 

PrimeNumberandQueries.o: PrimeNumberandQueries.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
