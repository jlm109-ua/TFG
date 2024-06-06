CC=gcc


test: LonelyInteger.o
	$(CC) -o $@ $< -O0 

LonelyInteger.o: LonelyInteger.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
