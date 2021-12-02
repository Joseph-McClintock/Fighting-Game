#include <iostream>
#include <fstream>
#include "moves.h"
#include "fighters.h"

Move::Move() {
	/*name = "Base Move";
	baseDamage = 1;
	baseHitChance = 90;
	baseReduceHitChance = 0;*/
}
Move::Move(int id, std::string name, int baseDamage, int baseHitChance, int baseReduceHitChance) {
	this->id = id;
	this->name = name;
	this->baseDamage = baseDamage;
	this->baseHitChance = baseHitChance;
	this->baseReduceHitChance = baseReduceHitChance;
	this->movesRosterVector = movesRosterVector;
}

//Getters


int Move::getMoveID() const {
	return id;
}
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

void Move::parseMoves() {

	std::ifstream myFile;
	std::vector<std::string> moveInfo;
	myFile.open("moveinfo.txt", std::ios::in);
	if (myFile.is_open()) {
		std::string line2;
		while (getline(myFile, line2)) {
			moveInfo.push_back(line2);
		}
		myFile.close();
	}

	for (std::vector<int>::size_type i = 0; i != moveInfo.size(); i++) {

		size_t rhs = moveInfo[i].find(", ");
		int id = std::stoi(moveInfo[i].substr(0, rhs));

		size_t lhs = rhs + 1;
		rhs = moveInfo[i].find(", ", lhs);
		std::string name = moveInfo[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = moveInfo[i].find(", ", lhs);
		int baseDamage = std::stoi(moveInfo[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = moveInfo[i].find(", ", lhs);
		int baseHitChance = std::stoi(moveInfo[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = moveInfo[i].find(", ", lhs);
		int baseReduceHitChance = std::stoi(moveInfo[i].substr(lhs, rhs - lhs));

		int currentIndex{ 0 };
		movesRosterVector.push_back(Move(id, name, baseDamage, baseHitChance, baseReduceHitChance));
		currentIndex++;

	}

}

Move Move::addMoveData(int id) {

	bool found = false;
	for (std::vector<int>::size_type i = 0; i != movesRosterVector.size(); i++)
	{
		if (movesRosterVector[i].getMoveID() == id)
		{
			for (std::vector<int>::size_type j = 0; j != movesRosterVector.size(); j++) {
				movesRosterVector[j];
			}
			found = true;
		}
	}
	if (found == false) {
		std::cout << "Move not found error: " << std::endl;
	}
	else {
		return movesRosterVector[id];
	}
}

void Move::printMoveName(std::string name) {

	for (std::vector<int>::size_type i = 0; i != movesRosterVector.size(); i++) {
		if (movesRosterVector[i].getName() == name) {
			movesRosterVector[i].printMoveInfo();
		}
	}
}

/// TEST FUNCTIONS BELOW
/// DELETE LATER

void Move::print() {

	for (std::vector<int>::size_type i = 0; i != movesRosterVector.size(); i++) {
		movesRosterVector[i].printMoveInfo();
	}
}

void Move::printMoveInfo() {

	//std::cout << "Index: " << id << "\t";
	std::cout << "" << name << "\t";
	std::cout << "Damage: " << baseDamage << "\t";
	std::cout << "Hit chance: " << baseHitChance << "\t";
	if (baseReduceHitChance > 0) {
		std::cout << "Reduces enemy hit chance by: " << baseReduceHitChance << "%\n" << std::endl;
	}
	else {
		std::cout << std::endl;
	}

}

void Move::printMoveByID(int id) {
	
	std::cout << "Pick a number between 1 and 6: ";
	std::cin >> id;
	movesRosterVector[id].printMoveInfo();

}