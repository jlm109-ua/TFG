CC=gcc


test: TwoStrings.o
	$(CC) -o $@ $< -O0 

TwoStrings.o: TwoStrings.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
