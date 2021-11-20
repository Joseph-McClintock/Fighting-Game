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
