CC=gcc


test: binary_to_decimal.o
	$(CC) -o $@ $< -O0 -lm

binary_to_decimal.o: binary_to_decimal.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
