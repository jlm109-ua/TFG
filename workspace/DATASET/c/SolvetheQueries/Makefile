CC=gcc

test: SolvetheQueries.o
	$(CC) $< -lm -o $@  -O0 

SolvetheQueries.o: SolvetheQueries.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
