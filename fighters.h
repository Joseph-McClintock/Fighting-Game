#pragma once
#include "moves.h"
#include <string>

class Fighter {

public:
	std::string name;
	int health;
	int atkPower;
	int defense;
	std::vector<Move> moves;

	std::vector<Fighter> fighterRoster;

public:
	
	Fighter();
	Fighter(std::string name, int health, int atkPower, int defense, std::vector<Move> moves);

	std::string getName() const;
	int getHealth() const;
	
	void parseFighters();

	Fighter selectFighter(Fighter *playerInput);

	void printFighterData();

	void pickAttack();

	Fighter selectAIFighter(Fighter* aiChoice);

};
