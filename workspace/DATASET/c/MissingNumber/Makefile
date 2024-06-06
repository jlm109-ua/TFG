CC=gcc


test: MissingNumber.o
	$(CC) -o $@ $< -O0 

MissingNumber.o: MissingNumber.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
