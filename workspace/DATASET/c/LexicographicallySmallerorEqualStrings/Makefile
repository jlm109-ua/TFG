CC=gcc


test: LexicographicallySmallerorEqualStrings.o
	$(CC) -o $@ $< -O0 

LexicographicallySmallerorEqualStrings.o: LexicographicallySmallerorEqualStrings.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
