#pragma once
#include "moves.h"
#include <string>

struct Fighter {

	std::string name;
	int health;
	int atkPower;
	int defense;
	std::vector<Move> moves;

	std::vector<Fighter> fighterRoster;

	Fighter();
	Fighter(std::string name, int health, int atkPower, int defense, std::vector<Move> moves);
	
	std::string getName() const;
	int getHealth() const;

	void parseFighters();
	Fighter selectFighter(Fighter *playerInput);
	void displayInfo(Fighter player, Fighter enemy);
	void printFighterData();
	int pickAttack();
	int calculateAttackDmg(int attack);

	//AI functions
	Fighter selectAIFighter(Fighter* aiChoice);
	int selectAIAttack();

};
