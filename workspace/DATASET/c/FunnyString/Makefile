CC=gcc


test: FunnyString.o
	$(CC) -o $@ $< -O0 

FunnyString.o: FunnyString.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
