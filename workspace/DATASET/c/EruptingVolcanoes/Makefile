CC=gcc


test: EruptingVolcanoes.o
	$(CC) -o $@ $< -O0 

EruptingVolcanoes.o: EruptingVolcanoes.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
