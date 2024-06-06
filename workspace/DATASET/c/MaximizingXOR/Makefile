CC=gcc


test: MaximizingXOR.o
	$(CC) -o $@ $< -O0 

MaximizingXOR.o: MaximizingXOR.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
