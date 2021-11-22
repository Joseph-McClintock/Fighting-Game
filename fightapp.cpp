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
    
    Fighter* fighterRoster = new Fighter();
    fighterRoster->parseFightersAndMoves();

    std::cout << "Hello World!\n";


}
