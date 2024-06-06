CC=gcc


test: stack.o
	$(CC) -o $@ $< -O0 

stack.o: stack.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
