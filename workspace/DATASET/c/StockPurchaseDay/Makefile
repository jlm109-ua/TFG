CC=gcc


test: StockPurchaseDay.o
	$(CC) -o $@ $< -O0 

StockPurchaseDay.o: StockPurchaseDay.c
	$(CC) -o $@ $< -O0 -c -g

clean: 
	rm *.o test
