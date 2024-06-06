CC=gcc


test: LinkedListCycle.o
	$(CC) -o $@ $< -O0 

LinkedListCycle.o: LinkedListCycle.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
