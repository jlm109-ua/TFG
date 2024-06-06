CC=gcc


test: MarchoftheKing.o
	$(CC) -o $@ $< -O0 

MarchoftheKing.o: MarchoftheKing.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
