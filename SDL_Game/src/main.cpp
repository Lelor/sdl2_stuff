#include <SDL.h>
#include "Game.h"
#include "Log.h"

int main( int argc, char* args[] )
{
	logger.setLevel(LogLevel::DEBUG);
	Game game(640, 480);
	game.Run();
	game.CleanUp();
	return 0;
}
