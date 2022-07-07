#include "menu.hpp"
#include <iostream>
#include <fstream>

using namespace std;

ifstream inputStream;
ofstream outputStream;

/*  The Menu prompt which is seen by the user in the terminal.  Continues to prompt until the number 6 is entered by the user. */
void userMenuPrompt(){
    cout << "\n     | Menu Options | \n" << endl;
    cout << "1) Enter input file name" << endl;
    cout << "2) Print Rental Cars " << endl;
    cout << "3) Estimate rental cost " << endl;
    cout << "4) Find cheapest car " << endl;
    cout << "5) Reserve a Car" << endl;
    cout << "6) Exit" << endl;
}

/*  Takes 3 inputs, the ifstream, a char array of the input file name, and a pointer to the Rental Agency array of structs in which you want to store the input file data.  */
void readCars(ifstream & inputStream, char * inputFile, Agency * arrAgency){
    Agency * p_Agency = arrAgency;
    RentalCar * p_Car = arrAgency->inventory;
    int tempZip, tempYear = 0;
    char tempMake[10], tempModel[10];
    float tempPrice;
    bool tempAvailable;
    
    for (int i = 0; i < 3; i++){
        
        inputStream >> p_Agency->name;
        inputStream >> tempZip;
        
        for (int i = 0; i < 5; i++) {
            
            p_Agency->zipcode[4-i] = tempZip % 10;
            tempZip /= 10;
        }
        for(int i = 0; i < 5; i++){
            
            inputStream >> tempYear;
            p_Car->setYear(tempYear);
            p_Car++;
            
            inputStream >> tempMake;
            p_Car->setMake(tempMake);
            p_Car++;
    
            inputStream >> tempModel;
            p_Car->setModel(tempModel);
            p_Car++;
    
            inputStream >> tempPrice;
            p_Car->setPrice(tempPrice);
            p_Car++;
    
            inputStream >> tempAvailable;
            p_Car->setAvailable(tempAvailable);
            p_Car++;
        }
        p_Agency++;
    }
}

/* Takes 1 input, the Rental Agency array of structs which contains the car data to be printed */
void printAgenciesToTerminal(Agency * arrAgency){
    Agency * p_Agency = arrAgency;
    RentalCar * p_Car = arrAgency->inventory;
    
    for ( int i = 0; i < 3; i++){
        cout << p_Agency->name << " ";
        
        for ( int i = 0; i < 5; i++){
            cout << p_Agency->zipcode[i];
        }
        
        cout << endl << endl;
        
        for(int i = 0; i < 5; i++){
            cout << p_Car->getYear() << " ";
            p_Car++;
            
            cout << p_Car->getMake() << " ";
            p_Car++;
            
            cout << p_Car->getModel() << ", $";
            p_Car++;
            
            cout << p_Car->getPrice() << " per day, ";
            p_Car++;
            
            cout << "Available: " << boolalpha << p_Car->getAvailable() << endl << endl;
            p_Car++;
        }
        p_Agency++;
    }
}

/* Takes one input, a pointer to the Rental Agency array of structs.  Prompts the user for a Rental Agelncy, a Car, and a number of days to rent that specific car.  It then uses that info to calculate the rental price of that car for that number of days*/
void estimateRentalCost(Agency * arrAgency){
    Agency * p_Agency = arrAgency;
    RentalCar * p_Car = arrAgency->inventory;
    int choice = 0, daysToRent = 0;
    float rentalCost = 0;
    
    cout << endl << "|| Choose a Rental Agency ||" << endl << "||  Enter a number 1-3    ||" << endl << endl;
    
    for(int i = 1; i < 4; i++){
        cout << "       " << "[" << i << "]  " << p_Agency->name << endl << endl;
        p_Agency++;
    }
    
    p_Agency = arrAgency;
    cin >> choice;
    p_Car += (choice-1)*25;
    cout << endl << "         ||   Choose a Car     ||" << endl  << "         || Enter a number 1-5 ||" << endl << endl;
    
    for(int i = 1; i <= 5; i++){
        cout << "[" << i << "] " << p_Car->getYear() << " ";
        p_Car++;
        
        cout << p_Car->getMake() << " ";
        p_Car++;
        
        cout << p_Car->getModel() << ", $";
        p_Car++;
        
        cout << p_Car->getPrice() << " per day, ";
        p_Car++;
        
        cout << "Available: " << boolalpha << p_Car->getAvailable() << endl << endl;
        p_Car++;
    }
    
    cin >> choice;
    p_Car += ((choice-1)*5)-25;
    cout << endl << "How many days would you like to rent it for? "  << endl << endl;
    cin >> daysToRent;
    p_Car += 3;
    
    rentalCost = p_Car->getPrice()*daysToRent;
    cout << endl << "That will cost $" << rentalCost << " for " << daysToRent << " days" << endl << endl;
}

/* Takes 1 input, a pointer to the Rental Agency array of structs and finds the cheapest available car of all 3 agencies.  It then prints that cars info to the terminal */
void findCheapestRental(Agency * arrAgency){
    RentalCar * p_Price = arrAgency->inventory;
    RentalCar * p_Cheapest = arrAgency->inventory;
    float cheapestCar = 0;
    
    p_Price += 3;
    cheapestCar = p_Price->getPrice();
    p_Price += 5;
    
    for(int i = 0; i < 12; i++){
        p_Price++;
        
        if( p_Price->getAvailable() == 1){
            p_Price--;
            
            if(cheapestCar > p_Price->getPrice()){
                cheapestCar = p_Price->getPrice();
                p_Cheapest = p_Price;
            }
        }
        else{
            p_Price--;
        }
        p_Price +=5;
    }
    
    p_Cheapest -= 3;
    cout << endl << "The cheapest care available at the moment is:" << endl << p_Cheapest->getYear() << " ";
    p_Cheapest++;
    
    cout << p_Cheapest->getMake() << " ";
    p_Cheapest++;
    
    cout << p_Cheapest->getModel() << ", $";
    p_Cheapest++;
    
    cout << p_Cheapest->getPrice() << " per day, ";
    p_Cheapest++;
    
    cout << "Available: " << boolalpha << p_Cheapest->getAvailable() << endl << endl;
    p_Cheapest++;
}

/* Takes one input, a pointer to the Rental Agency array of structs.  Prompts the user for a Rental Agelncy and a Car.  If that car is not available, the user is informed and asked to try again.  If an available car is chosen, it's availability bool will be changed to 0 and the updated Rental List will be printed to the terminal */
void reserveCar(Agency * arrAgency){
    Agency * p_Agency = arrAgency;
    RentalCar * p_Car = arrAgency->inventory;
    RentalCar * p_Choice = p_Car;
    int choice = 0;
    bool end = false;
    
    cout << endl << "|| Choose a Rental Agency ||" << endl << "||  Enter a number 1-3    ||" << endl << endl;
    
    for(int i = 1; i < 4; i++){
        cout << "       " << "[" << i << "]  " << p_Agency->name << endl << endl;
        p_Agency++;
    }
    
    p_Agency = arrAgency;
    cin >> choice;
    p_Car += (choice-1)*25;
    
    cout << endl << "         ||   Choose a Car     ||" << endl  << "         || Enter a number 1-5 ||" << endl << endl;
    
    for(int i = 1; i <= 5; i++){
        cout << "[" << i << "] " << p_Car->getYear() << " ";
        p_Car++;
        
        cout << p_Car->getMake() << " ";
        p_Car++;
        
        cout << p_Car->getModel() << ", $";
        p_Car++;
        
        cout << p_Car->getPrice() << " per day, ";
        p_Car++;
        
        cout << "Available: " << boolalpha << p_Car->getAvailable() << endl << endl;
        p_Car++;
    }
    
    p_Choice = p_Car;
    cin >> choice;
    p_Car += ((choice-1)*5)-25;
    p_Car += 4;
    
    do{
        if ( p_Car->getAvailable() == 0){
            cout << endl << "************************************************\n";
            cout << "That car is not available, please select another " << endl;
            cout << "*************************************************\n" << endl;
            
            cin >> choice;
            p_Car = p_Choice;
            p_Car += ((choice-1)*5)-25;
            p_Car += 4;
        }
        else if (p_Car->getAvailable() == 1){
            p_Car->setAvailable(0);
            printAgenciesToTerminal(arrAgency);
            end = true;
        }
    }while(!end);
}
