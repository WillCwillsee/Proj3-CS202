#include "menu.hpp"
#include "my_string.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    /* Variable initialization*/
    ifstream inputStream;
    ofstream outputStream;
    int selection = 0;
    char inputFile[20];
    bool end = false;
    Agency arrAgency[5] = { };
    
    /* Options menu with 6 inputs, including an exit function*/
    do {
        userMenuPrompt();
        cin >> selection;
        
        switch (selection)
        {
                
                /* Prompts the user for the name of the input file and stores that value in the char array inputFile. */
            case 1:
                cout << "\n Enter the name of the input file from which you wish to store the Rental Car data" << endl;
                cin >> inputFile;
                inputStream.open(inputFile);
                readCars(inputStream, inputFile, arrAgency);
                inputStream.close();
                break;
                
                /* Prints the Rental Agency information, stored in a struct/class array, to the terminal*/
            case 2:
                printAgenciesToTerminal(arrAgency);
                break;
           
                /* Prompts the user for input: 1) a Rental Agency
                                               2) a Car
                                               3) the number of days to rent that car
                    It then returns an estimate for the cost of that car */
            case 3:
                estimateRentalCost(arrAgency);
                break;
                
                /*  Finds the cheapest, available car out of all 3 Rental Agencies */
            case 4:
                findCheapestRental(arrAgency);
                break;
                
                /*  Prompts the user for input: 1) a Rental Agency
                                                2) a Car
                                                3) the number of days to rent that car
                    It then reserves that car by changing the availability to False */
            case 5:
                reserveCar(arrAgency);
                break;
                
                /*  Ends the menu loop and exits the program. */
            case 6:
                
                end = true;
                break;
                
                /*  The default switch action which sends an error message if the user has entered a number other than 1-7. */
            default:
                cout << "\n****************************************************** \n";
                cout << "Invalid entry number. Please choose an option from 1-7 " << endl;
                cout << "****************************************************** \n" << endl;
                break;
                
        }
        
    } while(!end);
    
    
    return 0;
}
