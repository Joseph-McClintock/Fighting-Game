//#include <iostream>
//#include <fstream>
//#include "MovesRoster.h"
//#include "moves.h"
//#include <iostream>
//using namespace std;
//
//MovesRoster::MovesRoster() {
//	this->numMoves = numMoves;
//	this->currentIndex = currentIndex;
//	this->movesRosterVector = movesRosterVector;
//	this->movesRosterVectorLocation = movesRosterVectorLocation;
//}
//
//MovesRoster::~MovesRoster() {
//
//}
//
//void MovesRoster::parseMoves(std::string row) {
//
//	size_t rhs = row.find(", ");
//	std::string name = row.substr(0, rhs);
//
//	size_t lhs = rhs + 1;
//	rhs = row.find(", ", lhs);
//	int baseDamage = stoi(row.substr(lhs, rhs - lhs));
//
//	lhs = rhs + 1;
//	rhs = row.find(", ", lhs);
//	int baseHitChance = stoi(row.substr(lhs, rhs - lhs));
//
//	lhs = rhs + 1;
//	rhs = row.find(", ", lhs);
//	int baseReduceHitChance = stoi(row.substr(lhs, rhs - lhs));
//
//	
//
//	int currentIndex{ 0 };
//	movesRosterVector.push_back(Move(name, baseDamage, baseHitChance, baseReduceHitChance));
//	//std::cout << name << "\n" << baseDamage << "\n" << baseHitChance << "\n" << baseReduceHitChance << endl;
//	currentIndex++;
//	int temp = 0;
//	movesRosterVectorLocation.push_back(temp+1);
//
//}
//
//void MovesRoster::print() {
//	
//	for (std::vector<int>::size_type i = 0; i != movesRosterVector.size(); i++) {
//		movesRosterVector[i].printMoveInfo();
//	}
//}
//
//void MovesRoster::remove(std::string name) {
//
//	bool found = false;
//	for (int i : movesRosterVectorLocation)
//	{
//		if (this->classRosterArray[i]->getStudentID() == studentID)
//		{
//			for (int j = i; j < (numStudents - 1); j++) {
//				classRosterArray[j] = classRosterArray[j + 1];
//			}
//			found = true;
//			i--;
//			numStudents--;
//		}
//	}
//	if (found == false) {
//		cout << "\nRemoving: " << studentID << " again" << endl;
//		cout << "\nThe student with the ID: " << studentID << " was not found." << endl;
//	}
//	else {
//		cout << "\nRemoving " << studentID << ":" << endl;
//	}
//}