CC=gcc

test: dijkstra.o
	$(CC) -o $@ $< -O0 

3DSurfaceArea.o: dijkstra.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
