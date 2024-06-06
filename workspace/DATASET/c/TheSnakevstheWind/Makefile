CC=gcc


test: TheSnakevstheWind.o
	$(CC) -o $@ $< -O0 

TheSnakevstheWind.o: TheSnakevstheWind.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
