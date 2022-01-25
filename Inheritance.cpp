/*program to demonstrate the concept of inheritance*/

#include <iostream>
using namespace std;

/*base class*/
class Vehicle{
  public:
    string make, model;
    Vehicle(){
      cout<<"Vehicle"<<endl;
      
      }
};

/*derived class*/
class Car: public Vehicle{
  public:
    int price, seating_capacity;
    string fule_type;
    Car(){
      cout<<"Car"<<endl;
    }
};

/*derived class*/
class Bike: public Vehicle{
  public:
    int cylinders, number_of_gears, fule_tank_size;
    Bike(){
      cout<<"Bike"<<endl;
    }
};

/*derived class*/
class Audi: public Car{
  public:
    int horse_power;
    Audi(){
      cout<<"Audi"<<endl<<endl;
    }
};

/*derived class*/
class Bajaj_Bike: public Bike{
  public:
    int engine_power;
    Bajaj_Bike(){
      cout<<"Bajaj Bike"<<endl;
    }
};

int main() {
  Audi a;
  Bajaj_Bike b;
  return 0;
}