output: test.o Draw.o Ball.o Mutex.o
	g++ test.o Draw.o Ball.o Mutex.o -lncurses -pthread -o output

test.o: test.cpp
	g++ -c test.cpp

Draw.o: Draw.cpp Draw.h 
	g++ -c Draw.cpp 

Ball.o: Ball.cpp Ball.h
	g++ -c Ball.cpp
Mutex.o: Mutex.cpp Mutex.h
	g++ -c Mutex.cpp
clean:
	rm*.o output
