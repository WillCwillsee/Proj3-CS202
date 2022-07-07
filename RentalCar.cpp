#include "RentalCar.hpp"

/* Default RentalCar constructor using generic values */
RentalCar::RentalCar(){
    setYear(2012);
    setMake("Make");
    setModel("Model");
    setPrice(0);
    setAvailable(0);
}

/* Parameterized RentalCar constructor using the arguments passed to the constructor */
RentalCar::RentalCar(const int year, const char * make, const char * model, const float price, const bool available){
    setYear(year);
    setMake(make);
    setModel(model);
    setPrice(price);
    setAvailable(available);
}

/* Public Accesor method for the Year of the Car */
const int  RentalCar::getYear() const {
    return m_year;
}

/* Public Facilitator method for the Year of the Car */
void RentalCar::setYear(const int year) {
    m_year = year;
}

/* Public Accesor method for the Make of the Car */
const char * RentalCar::getMake()const{
    return m_make;
}

/* Public Facilitator method for the Make of the Car */
void RentalCar::setMake(const char * make){
    int n = 0;
    do {
        m_make[n] = make[n];
        n++;
    } while(make[n-1] != '\0');
}

/* Public Accesor method for the Model of the Car */
const char * RentalCar::getModel() const{
    return m_model;
}

/* Public Facilitator method for the Model of the Car */
void RentalCar::setModel(const char * model){
    int n = 0;
    do {
        m_model[n] = model[n];
        n++;
    } while(model[n-1] != '\0');
}

/* Public Accesor method for the Price of the Car */
const float RentalCar::getPrice() const{
    return m_price;
}

/* Public Facilitator method for the Price of the Car */
void RentalCar::setPrice(const float price){
    m_price = price;
}

/* Public Accesor method for the Availability of the Car */
const bool RentalCar::getAvailable() const{
    return m_available;
}

/* Public Facilitator method for the Availability of the Car */
void RentalCar::setAvailable(const bool available){
    m_available = available;
}
