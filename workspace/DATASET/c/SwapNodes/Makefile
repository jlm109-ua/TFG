CC=gcc


test: SwapNodes.o
	$(CC) -o $@ $< -O0 

SwapNodes.o: SwapNodes.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
