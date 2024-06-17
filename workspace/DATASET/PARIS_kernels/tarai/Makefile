CC=gcc


test: tarai.o
	$(CC) -o $@ $< -O0 

tarai.o: tarai.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
