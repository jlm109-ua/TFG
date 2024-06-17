CC=gcc


test: fir_short.o
	$(CC) -o $@ $< -O0 

fir_short.o: fir_short.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
