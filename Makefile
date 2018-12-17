TARGET = cracker
CFLAGS = -Wall -Wextra -O0 -std=c11
CC = gcc

run: $(TARGET) cleanO

$(TARGET): cracker.o bruteforce.o dictionaryattack.o
	$(CC) $(CFLAGS) -o $(TARGET) cracker.o bruteforce.o dictionaryattack.o -lcrypt

cracker.o: cracker.c
	$(CC) $(CFLAGS) -c -o cracker.o cracker.c

bruteforce.o: bruteforce.c
	$(CC) $(CFLAGS) -c -o bruteforce.o bruteforce.c 

dictionaryattack.o: dictionaryattack.c
	$(CC) $(CFLAGS) -c -o dictionaryattack.o dictionaryattack.c

cleanO:
	rm *.o

clean:
	rm $(TARGET)

remake: clean run
