CC=gcc


test: CavityMap.o
	$(CC) -o $@ $< -O0 

CavityMap.o: CavityMap.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
