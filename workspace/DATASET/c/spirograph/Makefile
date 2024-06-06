CC=gcc


test: spirograph.o
	$(CC) -o $@ $< -O0 -lm

spirograph.o: spirograph.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
