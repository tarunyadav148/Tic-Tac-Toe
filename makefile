TicTactoe:	main.o ui.o tictactoe.o board.o player.o
	g++ main.o ui.o tictactoe.o board.o player.o -o TicTactoe -std=c++17

main.o: main.cpp
	g++ -c main.cpp -std=c++17

ui.o: ui.cpp
	g++ -c ui.cpp -std=c++17

tictactoe.o: tictactoe.cpp
	g++ -c tictactoe.cpp -std=c++17

board.o: board.cpp
	g++ -c board.cpp -std=c++17

player.o: player.cpp
	g++ -c player.cpp -std=c++17

clean:
	rm *.o TicTactoe