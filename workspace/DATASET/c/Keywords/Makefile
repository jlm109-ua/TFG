CC=gcc


test: Keywords.o
	$(CC) -o $@ $< -O0 

Keywords.o: Keywords.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
