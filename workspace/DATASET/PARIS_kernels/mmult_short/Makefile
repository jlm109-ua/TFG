CC=gcc


test: mmult_short.o
	$(CC) -o $@ $< -O0 

mmult_short.o: mmult_short.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
