CC=gcc


test: KthMinimum.o
	$(CC) -o $@ $< -O0 

KthMinimum.o: KthMinimum.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
