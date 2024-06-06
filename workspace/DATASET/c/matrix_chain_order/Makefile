CC=gcc


test: matrix_chain_order.o
	$(CC) -o $@ $< -O0 

matrix_chain_order.o: matrix_chain_order.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
