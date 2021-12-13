#include"Main.h"
#include"Board.h"
#include"Game.h"
#include"Pipe.h"

int main() {
	Game game;
	char command[GUI_STRING_LENGTH];
	//connect to GUI
	Pipe pipe;

	ShellExecute(NULL, NULL, "chessGraphics.exe", NULL, NULL, SW_SHOW);
	do {
		Sleep(ONE_SECOND);
	} while (!pipe.connect());

	strcpy(command, game.getGuiStr().c_str());
	pipe.sendMessageToGraphics(command);
	while (true) {
		std::cout << "\n\ncommand: ";
		game.move(pipe.getMessageFromGraphics());

		strcpy(command, game.getGuiStr().c_str());
		pipe.sendMessageToGraphics(command);
	}

	pipe.close();

	std::cin;
	return 0;
}