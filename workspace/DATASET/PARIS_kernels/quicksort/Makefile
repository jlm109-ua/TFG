CC=gcc


test: quicksort.o
	$(CC) -o $@ $< -O0 

quicksort.o: quicksort.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
