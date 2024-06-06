CC=gcc


test: TwoArrays.o
	$(CC) -o $@ $< -O0 

TwoArrays.o: TwoArrays.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
