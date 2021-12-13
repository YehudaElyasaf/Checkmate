#include"Main.h"
#include"Board.h"
#include"Game.h"
#include"Pipe.h"

int main() {
	Game game;
	char initCommand[GUI_INIT_STRING_LENGTH];
	char command[GUI_STRING_LENGTH] = {'0', '\0'};
	//connect to GUI
	Pipe pipe;

	ShellExecute(NULL, NULL, "chessGraphics.exe", NULL, NULL, SW_SHOW);
	do {
		Sleep(ONE_SECOND);
	} while (!pipe.connect());

	strncpy(initCommand, game.getGuiStr().c_str(), GUI_INIT_STRING_LENGTH);
	pipe.sendMessageToGraphics(initCommand);
	while (true) {
		command[0] = game.move(pipe.getMessageFromGraphics());
		pipe.sendMessageToGraphics(command);
	}

	pipe.close();

	std::cin;
	return 0;
}