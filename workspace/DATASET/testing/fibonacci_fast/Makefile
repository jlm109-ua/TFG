CC=gcc


test: fibonacci_fast.o
	$(CC) -o $@ $< -O0 

3DSurfaceArea.o: fibonacci_fast.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
