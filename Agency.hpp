#ifndef Agency_h
#define Agency_h
#include "RentalCar.hpp"

const int MAX_SIZE = 256;

struct Agency{
    char name[MAX_SIZE];
    int zipcode[5];
    RentalCar inventory[5];
};

#endif /* Agency_h */
