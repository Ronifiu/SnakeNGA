#include "menu.h"
#include "gamemode.h"
#include "game.h"
#include "rng.h"


int main() {
	Random rng;
	Menu menu;
	GameMode mode = menu.menu();
	if (mode == GameMode::HUMAN) {
	        Game game(rng, 30, 30);
	        game.run();
	}

	return 0;
}
