CC=gcc


test: SherlockAndSquares.o
	$(CC) $< -lm -o $@  -O0 

SherlockAndSquares.o: SherlockAndSquares.c
	$(CC) $< -lm -o $@ -O0 -c -g

clean: 
	rm *.o test
