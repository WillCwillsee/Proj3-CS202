#ifndef RentalCar_hpp
#define RentalCar_hpp
#include <iostream>
#include <fstream>

using namespace std;

const int ARR_SZ = 10;

class RentalCar{
  public:
    
    RentalCar();
    RentalCar(const int year, const char * make, const char * model, const float price, const bool available);
    
    const int getYear() const;
    void setYear(const int year);
    
    const char * getMake() const;
    void setMake(const char * make);
    
    const char * getModel() const;
    void setModel(const char * model);
    
    const float getPrice() const;
    void setPrice(const float price);
    
    const bool getAvailable() const;
    void setAvailable(const bool available);
    
  private:
    
    int m_year;
    char m_make[ARR_SZ];
    char m_model[ARR_SZ];
    float m_price;
    bool m_available;
};





#endif /* RentalCar_hpp */
