CC=gcc


test: Salesman.o
	$(CC) -o $@ $< -O0 

Salesman.o: Salesman.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
