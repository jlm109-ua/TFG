CC=gcc


test: counting_sort.o
	$(CC) -o $@ $< -O0 

counting_sort.o: counting_sort.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
