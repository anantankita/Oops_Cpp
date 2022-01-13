/*program for ATM withdrawal System without using any function except main()*/

#include <iostream>
using namespace std;

class atm{
  public:

    /*initializing variables*/
    string password= "hello5787";
    int balance=10000, choice;

    atm(int withdraw, int total, string old_p, string new_p){
      do{
        cout<<"Welcome to My Bank ATM"<<endl;
        cout<<"Your Account Balance is: "<<balance<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"1.Withdraw Money\n2.Change your password\n3.Exit"<<endl;        
        cout<<"---------------------------------"<<endl;
        cout<<"---------------------------------"<<endl;
        cout<<"Enter you choice"<<endl;
        cin>>choice;

        switch(choice){

          /*withdrawing money from current balance i.e. 10000*/
          case 1: cout<<"Enter the amount you want to withdraw"<<endl;
                  cin>>withdraw;
                  if(withdraw<balance){
                    total=balance-withdraw;
                    balance= total;
                    cout<<"Thank You for using My ATM, Please Collect Money"<<endl;
                    cout<<"Your Updated Balance is: "<<balance<<endl;
                  }
                  else{
                    cout<<"Not enough money!"<<endl;
                  }
                  cout<<"---------------------------------"<<endl;
                  cout<<"---------------------------------"<<endl;
                  break;

          /*if entered password matches the old password then only it can be changed*/
          /*old password is: hello5787*/
          case 2: cout<<"Enter the old Password"<<endl;
                  cin>>old_p;
                  if(old_p==password){
                    cout<<"Enter the new password"<<endl;
                    cin>>new_p;
                    password=new_p;
                    cout<<endl<<"Password Changed Successfully!"<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<"---------------------------------"<<endl;
                  }
                  else{
                    cout<<endl<<"Password Cannot be changed as the old password entered is wrong!"<<endl;
                    cout<<"---------------------------------"<<endl;
                    cout<<"---------------------------------"<<endl;
                  }         
                  break; 

          case 3: cout<<"Thank You, Have a Great Day :)"<<endl; 
                  cout<<"---------------------------------"<<endl;
                  cout<<"---------------------------------"<<endl;  
                  exit(1);
                  break;

          default:cout <<endl<<"Enter a valid choice!"<<endl<<endl;  
        }
      }while(1);
    }    
};

int main() {

  /*initialization of variables*/
  int withdraw, total=0;
  string old_p, new_p;
  atm a(withdraw, total, old_p, new_p);
}