/*program to to decide whether a given year is a leap year or not*/

#include <iostream>
using namespace std;

class constructer{
  public:
    int n;    
    constructer(){
      cout<<"Enter a year: ";
      cin>>n;
      cout<<"Constructer"<<endl;

      /*check whether leap year or not*/
      if(n%400!=0){
        if((n%100!=0)&&(n%4==0)){
          cout<<n<<" is a leap year."<<endl<<endl;
        }
        else{
          cout<<n<<" is not a leap year."<<endl<<endl;
        }
      }
      else{
        cout<<n<<" is a leap year."<<endl<<endl;
      }
    }   

    ~constructer(){
      cout<<"Destructer"<<endl;
      if(n%400!=0){
        if((n%100!=0)&&(n%4==0)){
          cout<<n<<" is a leap year."<<endl<<endl;
        }
        else{
          cout<<n<<" is not a leap year."<<endl<<endl;
        }
      }
      else{
        cout<<n<<" is a leap year."<<endl<<endl;
      }
    } 
};

int main() {  
  constructer obj;
  return 0;
}