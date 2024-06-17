CC=gcc


test: ef_exp.o
	$(CC) -o $@ $< -O0 

ef_exp.o: ef_exp.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
