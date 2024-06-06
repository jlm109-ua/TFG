CC=gcc


test: MinimumEdgesinaLayeredGraph.o
	$(CC) -o $@ $< -O0 

MinimumEdgesinaLayeredGraph.o: MinimumEdgesinaLayeredGraph.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
