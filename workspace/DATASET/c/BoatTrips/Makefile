CC=gcc


test: BoatTrips.o
	$(CC) -o $@ $< -O0 

BoatTrips.o: BoatTrips.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
