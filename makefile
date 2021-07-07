TicTactoe:	main.o ui.o tictactoe.o board.o player.o
	g++ main.o ui.o tictactoe.o board.o player.o -o TicTactoe

main.o: main.cpp
	g++ -c main.cpp

ui.o: ui.cpp
	g++ -c ui.cpp

tictactoe.o: tictactoe.cpp
	g++ -c tictactoe.cpp

board.o: board.cpp
	g++ -c board.cpp

player.o: player.cpp
	g++ -c player.cpp

clean:
	rm *.o TicTactoe