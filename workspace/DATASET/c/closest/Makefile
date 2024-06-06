CC=gcc


test: closest.o
	$(CC) -o $@ $< -O0 

closest.o: closest.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
