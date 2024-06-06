CC=gcc


test: AngryChildrens.o
	$(CC) -o $@ $< -O0 

AngryChildrens.o: AngryChildrens.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
