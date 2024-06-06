CC=gcc


test: demonetization.o
	$(CC) -o $@ $< -O0 

3DSurfaceArea.o: demonetization.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
