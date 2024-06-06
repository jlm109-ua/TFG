CC=gcc


test: BreakingSticks.o
	$(CC) -o $@ $< -O0 

BreakingSticks.o: BreakingSticks.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
