CC=gcc


test: ImpressiveTree.o
	$(CC) -o $@ $< -O0 

ImpressiveTree.o: ImpressiveTree.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
