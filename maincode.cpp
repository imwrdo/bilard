
#include "Game.h"


using namespace std;
using namespace sf;


int main(){
	cout << "Game started succesfully" << endl;
	// init game engine
	Game game;

	// game loop
	while (game.running()) {
		// update
		game.update();

		// render
		game.render();
	}

	// game end 
	cout << "\nGame ended totally" << endl;
	return 0;
}