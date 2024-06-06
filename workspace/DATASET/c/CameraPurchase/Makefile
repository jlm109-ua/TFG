CC=gcc


test: CameraPurchase.o
	$(CC) -o $@ $< -O0 

CameraPurchase.o: CameraPurchase.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
