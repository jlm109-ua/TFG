CC=gcc


test: MinimumHeightTriangle.o
	$(CC) -o $@ $< -O0 

MinimumHeightTriangle.o: MinimumHeightTriangle.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
