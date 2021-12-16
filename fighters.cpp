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

Fighter::Fighter(std::string name, int health, int atkPower, int defense, std::vector<Move> moves) {
	this->name = name;
	this->health = health;
	this->atkPower = atkPower;
	this->defense = defense;
	this->moves = moves;
	this->fighterRoster = fighterRoster;
}

std::string Fighter::getName() const {
	return name;
}

int Fighter::getHealth() const {
	return health;
}

void Fighter::parseFighters() {

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


		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		int move1 = std::stoi(fighterInfo[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		int move2 = std::stoi(fighterInfo[i].substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = fighterInfo[i].find(", ", lhs);
		int move3 = std::stoi(fighterInfo[i].substr(lhs, rhs - lhs));
		
		std::vector<Move> movesList = { moveRoster->addMoveData(move1), moveRoster->addMoveData(move2), moveRoster->addMoveData(move3) };

		int currentIndex{ 0 };
		fighterRoster.push_back(Fighter(name, health, atkPower, defense, movesList));
		currentIndex++;

	}
	

}

//Player functions -------------

Fighter Fighter::selectFighter(Fighter *playerInput) {

	int playerChoice{};
	std::cout << "Displaying the 3 default fighters: " << std::endl;

	for (int i = 1; i < 4; i++) {
		std::cout << "\nFighter " << i << std::endl;
		fighterRoster[i].printFighterData();
	}

	while (playerChoice < 1 || playerChoice > 3) {
		std::cout << "\nChoose a fighter: ";
		std::cin >> playerChoice;

		if (playerChoice < 1 || playerChoice > 3) {
			std::cout << "Try again pick 1, 2, or 3";
		}
	}
	system("cls");
	std::cout << "You have picked: " << fighterRoster[playerChoice].name << "!" << std::endl;

	*playerInput = fighterRoster[playerChoice];
	return *playerInput;
}

void Fighter::printFighterData() {

	std::cout << "\nName: " << name << "\t";
	std::cout << "Health: " << health << "\t";
	std::cout << "Attack power: " << atkPower << "\t";
	std::cout << "Defense: " << defense << "\t" << std::endl;
	for (int i = 0; i < 3; i++) {
		moves[i].printMoveInfo();
	}
	std::cout << std::endl;
	
}

void Fighter::pickAttack() {

	int playerChoice{};

	std::cout << std::endl;
	for (int i = 0; i < 3; i++) {
		moves[i].printMoveInfo();
	}

	while (playerChoice < 1 || playerChoice > 3) {
		std::cout << "\nPick an attack 1 - 3: ";
		std::cin >> playerChoice;

		if (playerChoice < 1 || playerChoice > 3) {
			std::cout << "Try again pick 1, 2, or 3";
		}
	}
}

//AI functions -------------

Fighter Fighter::selectAIFighter(Fighter* aiChoice) {

	int ai{};
	std::srand(time(0));
	ai = (rand() % fighterRoster.size());

	if (ai == 0) {
		ai++;
	}
	
	*aiChoice = fighterRoster[ai];
	return *aiChoice;
}