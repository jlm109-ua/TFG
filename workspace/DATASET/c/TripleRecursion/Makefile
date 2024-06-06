CC=gcc


test: TripleRecursion.o
	$(CC) -o $@ $< -O0 

TripleRecursion.o: TripleRecursion.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
