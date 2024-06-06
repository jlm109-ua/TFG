CC=gcc


test: lcs.o
	$(CC) -o $@ $< -O0 

lcs.o: lcs.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
