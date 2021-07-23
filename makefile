TicTacToe:	main.o ui.o tictactoe.o board.o player.o
	g++ main.o ui.o tictactoe.o board.o player.o -o TicTacToe -std=c++14

main.o: main.cpp
	g++ -c main.cpp -std=c++14

ui.o: ui.cpp
	g++ -c ui.cpp -std=c++14

tictactoe.o: tictactoe.cpp
	g++ -c tictactoe.cpp -std=c++14

board.o: board.cpp
	g++ -c board.cpp -std=c++14

player.o: player.cpp
	g++ -c player.cpp -std=c++14

clean:
<<<<<<< HEAD
	rm *.o TicTacToe
=======
	rm *.o TicTacToe
>>>>>>> 706d6708864b897e88d05b755aa4605904f5dbde
