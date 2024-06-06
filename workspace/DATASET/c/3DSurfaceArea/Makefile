CC=gcc


test: 3DSurfaceArea.o
	$(CC) -o $@ $< -O0 

3DSurfaceArea.o: 3DSurfaceArea.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
