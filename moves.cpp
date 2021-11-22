#include <iostream>
//#include "MovesRoster.h"
#include "moves.h"
#include "fighters.h"

Move::Move() {
	/*name = "Base Move";
	baseDamage = 1;
	baseHitChance = 90;
	baseReduceHitChance = 0;*/
}
Move::Move(std::string name, int baseDamage, int baseHitChance, int baseReduceHitChance) {
	this->name = name;
	this->baseDamage = baseDamage;
	this->baseHitChance = baseHitChance;
	this->baseReduceHitChance = baseReduceHitChance;
	this->movesRosterVector = movesRosterVector;
	//this->movesRosterVectorLocation = movesRosterVectorLocation;
}

//Getters

std::string Move::getName() const {
	return name;
}
int Move::getBaseDamage() const {
	return baseDamage;
}
int Move::getBaseHitChance() const {
	return baseHitChance;
}
int Move::getBaseReduceHitChance() const {
	return baseReduceHitChance;
}

//Setters

void Move::setName(std::string name) {
	this->name = name;
}
void Move::setBaseDamage(int baseDamage) {
	this->baseDamage = baseDamage;
}
void Move::setBaseHitChance(int baseHitChance) {
	this->baseHitChance = baseHitChance;
}
void Move::setBaseReduceHitChance(int baseReduceHitChance) {
	this->baseReduceHitChance = baseReduceHitChance;
}

void Move::parseMoves(std::string row) {

	size_t rhs = row.find(", ");
	std::string name = row.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = row.find(", ", lhs);
	int baseDamage = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(", ", lhs);
	int baseHitChance = stoi(row.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = row.find(", ", lhs);
	int baseReduceHitChance = stoi(row.substr(lhs, rhs - lhs));

	int currentIndex{ 0 };
	movesRosterVector.push_back(Move(name, baseDamage, baseHitChance, baseReduceHitChance));
	currentIndex++;

	/*int temp = 0;
	movesRosterVectorLocation.push_back(temp + 1);*/

}

void Move::print() {

	for (std::vector<int>::size_type i = 0; i != movesRosterVector.size(); i++) {
		movesRosterVector[i].printMoveInfo();
	}
}

void Move::printMoveInfo() {

	std::cout << "First name: " << name << "\t";
	std::cout << "Base damage: " << baseDamage << "\t";
	std::cout << "Base hit chance: " << baseHitChance << "\t";
	std::cout << "Base reduce hit chance: " << baseReduceHitChance << std::endl;

}

void Move::printMoveByID(int ID) {
	
	std::cout << "Pick a number between 1 and 6: ";
	std::cin >> ID;
	movesRosterVector[ID].printMoveInfo();

}