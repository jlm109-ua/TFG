CC=gcc


test: MaximizeProfit.o
	$(CC) -o $@ $< -O0 

MaximizeProfit.o: MaximizeProfit.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
