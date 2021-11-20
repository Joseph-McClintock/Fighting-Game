#include <iostream>
#include <fstream>
#include <vector>
#include "fighters.h"
#include "moves.h"
//#include "MovesRoster.h"


//using namespace std;

int main()
{

    //Opens Fighter Info text file
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
    

    //Opens Move Info text file
    std::ifstream myFile2;
    std::vector<std::string> moveInfo;
    myFile2.open("moveinfo.txt", std::ios::in);
    if (myFile2.is_open()) {
        std::string line2;
        while (getline(myFile2, line2)) {
            moveInfo.push_back(line2);
        }
        myFile2.close();
    }

    Move* moveRoster = new Move();

    for (std::vector<int>::size_type i = 0; i != moveInfo.size(); i++) {
        moveRoster->parseMoves(moveInfo[i]);
    }

    moveRoster->print();

    int input{};

    moveRoster->printMoveByID(input);

    std::cout << "Hello World!\n";


}
