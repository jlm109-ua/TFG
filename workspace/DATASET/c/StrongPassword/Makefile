CC=gcc


test: StrongPassword.o
	$(CC) -o $@ $< -O0 

StrongPassword.o: StrongPassword.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
