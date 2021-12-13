#include"Main.h"
#include"Board.h"
#include"Game.h"
#include"Pipe.h"

int main() {
	Game game;

	//connect to GUI
	Pipe pipe;
	if (!pipe.connect())
	{
		std::cerr << "Couldn't connect to GUI!\n";
		return CONNECTION_ERROR;
	}

	pipe.sendMessageToGraphics(game.getGuiStr());
	while (true) {
		std::cout << "\n\ncommand: ";
		std::cout << "Game returned " << game.move(pipe.getMessageFromGraphics());
		pipe.sendMessageToGraphics(game.getGuiStr());
	}

	pipe.close();

	std::cin;
	return 0;
}