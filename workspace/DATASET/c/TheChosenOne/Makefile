CC=gcc


test: TheChosenOne.o
	$(CC) -o $@ $< -O0 

TheChosenOne.o: TheChosenOne.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
