CC=gcc


test: affine.o
	$(CC) -o $@ $< -O0 

affine.o: affine.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
