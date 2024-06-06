CC=gcc


test: ConstructtheArray.o
	$(CC) -o $@ $< -O0 

ConstructtheArray.o: ConstructtheArray.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
