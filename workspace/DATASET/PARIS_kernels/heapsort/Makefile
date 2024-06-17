CC=gcc


test: heapsort.o
	$(CC) -o $@ $< -O0 

heapsort.o: heapsort.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
