CC=gcc


test: MaximumPalindromes.o
	$(CC) -o $@ $< -O0 

MaximumPalindromes.o: MaximumPalindromes.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
