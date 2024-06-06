CC=gcc


test: LuckyPurchase.o
	$(CC) -o $@ $< -O0 

LuckyPurchase.o: LuckyPurchase.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
