CC=gcc


test: CountPairs.o
	$(CC) -o $@ $< -O0 

CountPairs.o: CountPairs.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
