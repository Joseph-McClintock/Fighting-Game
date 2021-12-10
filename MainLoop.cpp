#include <iostream>
#include "fighters.h"
#include "MainLoop.h"

void MainLoop::run() {

	Fighter* fighterRoster = new Fighter();
	fighterRoster->parseFighters();

	//Assigning the players fighter to playerChoice
	int playerChoice{};
	fighterRoster->selectFighter(&playerChoice);
	fighterRoster->displayPlayerData(playerChoice);

	//std::cout << "Health: " << movesFighterVector[playerChoice].health << "\t";
	//movesFighterVector[playerChoice].health = movesFighterVector[playerChoice].health - 50;
	//std::cout << "Health: " << movesFighterVector[playerChoice].health << "\t";

}