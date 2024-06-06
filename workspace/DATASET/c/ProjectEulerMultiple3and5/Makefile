CC=gcc


test: ProjectEulerMultiple3and5.o
	$(CC) -o $@ $< -O0 

ProjectEulerMultiple3and5.o: ProjectEulerMultiple3and5.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
