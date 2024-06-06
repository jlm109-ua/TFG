CC=gcc


test: ExtraLongFactorials.o
	$(CC) -o $@ $< -O0 

ExtraLongFactorials.o: ExtraLongFactorials.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
