CC=gcc


test: int_to_string.o
	$(CC) -o $@ $< -O0 

int_to_string.o: int_to_string.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
