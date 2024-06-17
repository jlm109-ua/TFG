CC=gcc


test: insertsort.o
	$(CC) -o $@ $< -O0 

insertsort.o: insertsort.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
