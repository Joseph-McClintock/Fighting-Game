#pragma once
#include "moves.h"
#include <string>

class Fighter {

public:
	int health;
	int atkPower;
	int defense;
	Move move1;
	Move move2;
	Move move3;

public:
	std::string name;
	Fighter();
	Fighter(std::string name, int health, int atkPower, int defense, Move move1, Move move2, Move move3);

	void openFighterData();
	void mainMenu();
	int pickFighter(int playerChoice);
	void startBattleSequence(Fighter);
	void displayChosenFighter();

};
