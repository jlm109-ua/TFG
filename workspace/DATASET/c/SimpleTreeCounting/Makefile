CC=gcc


test: SimpleTreeCounting.o
	$(CC) -o $@ $< -O0 

SimpleTreeCounting.o: SimpleTreeCounting.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
