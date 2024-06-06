CC=gcc


test: floyd_cycle_detection_algorithm.o
	$(CC) -o $@ $< -O0 

floyd_cycle_detection_algorithm.o: floyd_cycle_detection_algorithm.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
