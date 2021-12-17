#pragma once
#include <vector>
#include <string>

class Move {

private:

	int id;
	std::string name;
	int baseDamage;
	int baseHitChance;
	int baseReduceHitChance;
	std::vector<Move> moveRoster;

public:

	Move();
	Move(int id, std::string name, int baseDamage, int baseHitCHance, int baseReduceHitChance);

	//Getters

	int getMoveID() const;
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

	void parseMoves();
	Move addMoveData(int ID);
	void printMoveInfo();

};

