CC=gcc


test: alaw.o
	$(CC) -o $@ $< -O0 

alaw.o: alaw.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
