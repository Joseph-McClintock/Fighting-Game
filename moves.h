#pragma once
//#include "MovesRoster.h"
#include <vector>
#include <string>

class Move {

private:

	std::string name;
	int baseDamage;
	int baseHitChance;
	int baseReduceHitChance;
	std::vector<Move> movesRosterVector;
	std::vector<int> movesRosterVectorLocation;

public:

	Move();
	Move(std::string name, int baseDamage, int baseHitCHance, int baseReduceHitChance);

	//Getters

	std::string getName() const;
	int getBaseDamage() const;
	int getBaseHitChance() const;
	int getBaseReduceHitChance() const;

	// Setters

	void setName(std::string name);
	void setBaseDamage(int baseDamage);
	void setBaseHitChance(int baseHitChance);
	void setBaseReduceHitChance(int baseReduceHitChance);

	//Print info

	void printMoveInfo();
	void parseMoves(std::string row);
	void print();
	void printMoveByID(int ID);

};

