CC=g++ -std=c++11

all: pusher

pusher: main.o Pusher.o
	$(CC) -o pusher main.o Pusher.o
	rm -rf *.o

main.o: main.cpp
	$(CC) -c main.cpp

Pusher.o: Pusher.cpp
	$(CC) -c Pusher.cpp
