#ifndef menu_hpp
#define menu_hpp
#include "Agency.hpp"


using namespace std;

void userMenuPrompt();

void readCars(ifstream & inputStream, char * inputFile, Agency * Agency);

void printAgenciesToTerminal(Agency * arrAgency);

void estimateRentalCost(Agency * arrAgency);

void findCheapestRental(Agency * arrAgency);

void reserveCar(Agency * arrAgency);


#endif /* menu_hpp */
