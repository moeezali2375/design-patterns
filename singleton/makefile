CC = g++
CFLAGS = -Wall -std=c++11

all: 1 2 3 4 5

1: 1.cpp
	$(CC) $(CFLAGS) 1.cpp -o 1

2: 2.cpp
	$(CC) $(CFLAGS) 2.cpp -o 2

3: 3.cpp
	$(CC) $(CFLAGS) 3.cpp -o 3

4: 4.cpp
	$(CC) $(CFLAGS) 4.cpp -o 4 -pthread

5: 5.cpp
	$(CC) $(CFLAGS) 5.cpp -o 5 


clean:
	rm -f 1 2 3 4 5