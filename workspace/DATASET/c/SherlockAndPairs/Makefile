CC=gcc


test: SherlockAndPairs.o
	$(CC) -o $@ $< -O0 

SherlockAndPairs.o: SherlockAndPairs.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
