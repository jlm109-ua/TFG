CC=gcc


test: BoxOperations.o
	$(CC) -o $@ $< -O0 

BoxOperations.o: BoxOperations.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
