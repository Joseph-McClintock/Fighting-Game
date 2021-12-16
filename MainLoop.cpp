#include <iostream>
#include "fighters.h"
#include "MainLoop.h"

void MainLoop::run() {

	Fighter* fighterRoster = new Fighter();
	fighterRoster->parseFighters();

	bool quit{ false };
	while (!quit) {

		//Assigning the players fighter to playerChoice - find a better way to do this
		Fighter player;
		fighterRoster->selectFighter(&player);
		player.printFighterData();

		//Assigning the ai a fighter
		Fighter enemy;
		fighterRoster->selectAIFighter(&enemy);
		std::cout << "The AI has selected: " << std::endl;
		enemy.printFighterData();
		system("pause");
		system("cls");

		bool gameOver{ false };
		while (!gameOver) {

			std::cout << player.getName() << " ------- vs ------- " << enemy.getName() << std::endl;
			std::cout << player.getHealth() << " ------- Health ------- " << enemy.getHealth() << std::endl;

			player.pickAttack();

			gameOver = true;
		}

		//std::cout << playerChoice.getName() << std::endl;

		//std::cout << "Health: " << playerChoice.health << "\t";
		//playerChoice.health = playerChoice.health - playerChoice.move2.getBaseDamage();
		//std::cout << "Health: " << playerChoice.health << "\t";
		quit = true;
	}
}