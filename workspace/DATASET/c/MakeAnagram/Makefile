CC=gcc


test: MakeAnagram.o
	$(CC) -o $@ $< -O0 

MakeAnagram.o: MakeAnagram.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
