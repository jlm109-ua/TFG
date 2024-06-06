CC=gcc


test: KekotheBrilliant.o
	$(CC) -o $@ $< -O0 

KekotheBrilliant.o: KekotheBrilliant.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
