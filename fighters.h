#pragma once
#include "moves.h"
#include <string>

class Fighter {

public:
	std::string name;
	int health;
	int atkPower;
	int defense;
	Move move1;
	Move move2;
	Move move3;

	std::vector<Fighter> movesFighterVector;

public:
	
	Fighter();
	Fighter(std::string name, int health, int atkPower, int defense, Move move1, Move move2, Move move3);

	std::string getName() const;
	int getHealth() const;
	

	void parseFightersAndMoves();
	Fighter selectFighter();
	void battleSequence();
	void openFighterData();
	void displayChosenFighter();
	void printDefualtFighterData();

};
