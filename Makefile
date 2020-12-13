

tictac: main.o tic-tac-toe.o
	g++ main.o tic-tac-toe.o -o tictac

main.o: main.cpp
	g++ -c main.cpp

tic-tac-toe.o: tic-tac-toe.cpp tic-tac-toe.h
	g++ -c tic-tac-toe.cpp

clean:
	rm *.o tictac
