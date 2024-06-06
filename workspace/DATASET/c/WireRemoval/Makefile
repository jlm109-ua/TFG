CC=gcc


test: WireRemoval.o
	$(CC) -o $@ $< -O0 

WireRemoval.o: WireRemoval.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
