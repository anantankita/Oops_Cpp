/*program to demonstrate the concept of function overriding*/

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
    int engine_power;
    Audi(){
      cout<<"Audi"<<endl;
    }
    void printDetails(){
      cout<<"Details"<<endl;
      cout<<" Brand of vehicle is "<<make<<endl;  
      cout<<" Model of vehicle is "<<model<<endl;    
      cout<<" Price is Rs."<<price<<endl;     
      cout<<" Seating capacity is "<<seating_capacity<<endl;     
      cout<<" Fule type is "<<fule_type<<endl;      
      cout<<" Engine power(in cc) is "<<engine_power<<endl<<endl;
    }
};

/*derived class*/
class Bajaj_Bike: public Bike{
  public:
    int engine_power;
    Bajaj_Bike(){
      cout<<"Bajaj Bike"<<endl;
    }
    void printDetails(){
      cout<<"Details"<<endl;
      cout<<" Brand of vehicle is "<<make<<endl;  
      cout<<" Model of vehicle is "<<endl;
      cout<<" Number of cylinders are "<<cylinders<<endl;      
      cout<<" Number of gears a are "<<number_of_gears<<endl;      
      cout<<" Size of fule tank is "<<fule_tank_size<<endl;  
      cout<<" Engine power(in cc) is "<<engine_power<<endl; 
    }
};

int main() {
  Audi a;
  cout<<" Enter the brand of vehicle: ";
  cin>>a.make;
  cout<<" Enter the model of vehicle: ";
  cin>>a.model;
  cout<<" Enter price: ";
  cin>>a.price;
  cout<<" Enter seating capacity: ";
  cin>>a.seating_capacity;
  cout<<" Enter fule type: ";
  cin>>a.fule_type;
  cout<<" Enter engine power(in cc): ";
  cin>>a.engine_power;
  cout<<endl;

  /*printing information of Audi*/
  a.printDetails();

  cout<<endl;

  Bajaj_Bike bb;

  cout<<" Enter the brand of vehicle: ";
  cin>>bb.make;
  cout<<" Enter the model of vehicle: ";
  cin>>bb.model;
  cout<<" Enter number of cylinders: ";
  cin>>bb.cylinders;
  cout<<" Enter number of gears: ";
  cin>>bb.number_of_gears;
  cout<<" Enter fule tank size: ";
  cin>>bb.fule_tank_size;
  cout<<" Enter engine power(in cc): ";
  cin>>bb.engine_power; 
  cout<<endl;

  /*printing information of Bajaj Bike*/
  bb.printDetails();

  return 0;
  }