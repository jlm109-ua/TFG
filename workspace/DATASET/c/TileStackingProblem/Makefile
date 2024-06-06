CC=gcc


test: TileStackingProblem.o
	$(CC) -o $@ $< -O0 

TileStackingProblem.o: TileStackingProblem.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
