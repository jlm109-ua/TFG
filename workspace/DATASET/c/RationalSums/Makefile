CC=gcc


test: RationalSums.o
	$(CC) -o $@ $< -O0 

RationalSums.o: RationalSums.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
