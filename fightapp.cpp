#include <iostream>
#include <fstream>
#include <vector>
#include "fighters.h"
#include "moves.h"


//using namespace std;

int main()
{ 

    //Opens Move Info text file
    
    Fighter* fighterRoster = new Fighter();
    fighterRoster->parseFightersAndMoves();

    fighterRoster->displayChosenFighter();

    std::cout << "Hello World!\n";


}
