CC=gcc


test: CostlyIntervals.o
	$(CC) -o $@ $< -O0 

CostlyIntervals.o: CostlyIntervals.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
