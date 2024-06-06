CC=gcc


test: LetPlayaGame.o
	$(CC) -o $@ $< -O0 

LetPlayaGame.o: LetPlayaGame.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
