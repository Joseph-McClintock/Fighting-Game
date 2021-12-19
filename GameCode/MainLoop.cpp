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

			while (playerTurn && !gameOver) {
				player.displayInfo(player, enemy);

				currentAttack = player.pickAttack();
				enemy.health = enemy.health - player.calculateAttackDmg(currentAttack);

				playerTurn = false;
				system("cls");

				if (enemy.health <= 0) {
					player.displayInfo(player, enemy);
					std::cout << "\nGAME OVER YOU WIN!!!" << std::endl;
					gameOver = true;
				}		
			}

			while (!playerTurn && !gameOver) {
				enemy.displayInfo(player, enemy);

				currentAttack = enemy.pickAttack();
				player.health = player.health - enemy.calculateAttackDmg(currentAttack);

				playerTurn = true;
				system("cls");

				if (player.health <= 0) {
					enemy.displayInfo(player, enemy);
					std::cout << "\nGAME OVER YOU LOSE..." << std::endl;
					gameOver = true;
				}
			}	
		}
		int playAgain{ };
		std::cout << "Would you like to play again? 1 for yes 2 for no: ";
		std::cin >> playAgain;

		if (playAgain == 1) {
			gameOver = false;
			system("cls");
		}
		else if (playAgain == 2) {
			quit = true;
		}
	}
}