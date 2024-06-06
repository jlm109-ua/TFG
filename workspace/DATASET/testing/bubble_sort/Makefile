CC=gcc


test: bubble_sort.o
	$(CC) -o $@ $< -O0 

3DSurfaceArea.o: bubble_sort.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
