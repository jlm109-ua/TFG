CC=gcc


test: adaline_learning.o
	$(CC) -o $@ $< -O0 

adaline_learning.o: adaline_learning.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
