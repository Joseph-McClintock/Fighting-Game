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

			int currentAttack{};
			bool playerTurn = { true };

			while (playerTurn) {
				std::cout << player.getName() << " ------- vs ------- " << enemy.getName() << std::endl;
				std::cout << player.getHealth() << " ------- Health ------- " << enemy.getHealth() << std::endl;

				currentAttack = player.pickAttack();
				enemy.health = enemy.health - player.calculateAttackDmg(currentAttack);

				playerTurn = false;
			}

			while (!playerTurn) {
				std::cout << player.getName() << " ------- vs ------- " << enemy.getName() << std::endl;
				std::cout << player.getHealth() << " ------- Health ------- " << enemy.getHealth() << std::endl;

				currentAttack = enemy.pickAttack();
				player.health = player.health - enemy.calculateAttackDmg(currentAttack);

				playerTurn = true;
			}
			gameOver = true;
		}
		quit = true;
	}
}