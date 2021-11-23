#include <iostream>
#include <fstream>
#include <vector>
#include "fighters.h"


Fighter::Fighter() {
	name = "Default";
	health = 10;
	atkPower = 1;
	defense = 1;
}

Fighter::Fighter(std::string name, int health, int atkPower, int defense, Move move1, Move move2, Move move3) {
	this->name = name;
	this->health = health;
	this->atkPower = atkPower;
	this->defense = defense;
	this->move1 = move1;
	this->move2 = move2;
	this->move3 = move3;
	this->movesFighterVector = movesFighterVector;
}



void Fighter::parseFightersAndMoves() {

	//Parse Moves
	Move* moveRoster = new Move();
	moveRoster->parseMoves();


	std::ifstream myFile;
	std::vector<std::string> fighterInfo;
	myFile.open("fighterinfo.txt", std::ios::in);
	if (myFile.is_open()) {
		std::string line;
		while (getline(myFile, line)) {
			fighterInfo.push_back(line);
		}
		myFile.close();
	}

	for (std::vector<int>::size_type i = 0; i != fighterInfo.size(); i++) {
		size_t rhs = fighterInfo[i].find(", ");
		std::string name = fighterInfo[i].substr(0, rhs);

		size_t lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		int health = std::stoi(fighterInfo[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		int atkPower = std::stoi(fighterInfo[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		int defense = std::stoi(fighterInfo[i].substr(lhs, rhs - lhs));

		//Fix

		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		std::string move1 = fighterInfo[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		std::string move2 = fighterInfo[i].substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		std::string move2 = fighterInfo[i].substr(lhs, rhs - lhs);

		int currentIndex{ 0 };
		movesFighterVector.push_back(Fighter(name, health, atkPower, defense, move1, move2, move3));
		currentIndex++;
	}
	

}

void mainMenu() {

}

void pickFighter(int playerChoice) {

}

void displayChosenFighter() {
	
}

void startBattleSequence(Fighter) {

}

void Fighter::openFighterData() {

	std::ifstream myFile;
	std::vector<std::string> fighterInfo;
	myFile.open("info.txt", std::ios::in);
	if (myFile.is_open()) {
		std::string line;
		while (getline(myFile, line)) {
			fighterInfo.push_back(line);
		}
		myFile.close();
	}

}
