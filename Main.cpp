#include"Board.h"
#include"Game.h"

int main() {
	Game game;
	std::string command = "";
	while (true) {
		std::cout << "\n\nEnter command: ";
		std::cin >> command;
		std::cout << "Game returned " << game.move(command);
	}

	std::cin;
	return 0;
}