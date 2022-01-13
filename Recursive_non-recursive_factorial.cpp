/*program to calculate the factorial of a number by both recursive and non-recursive method*/

#include <iostream>
using namespace std;

class factorial{
  int f;
  public:

    /*recursive method*/
    int recursive(int n){
      f=1;
      if(n==0||n==1){
        return 1;
      }
      else{
        f= n* recursive(n-1);
        return f;
      }
    }

    /*non-recursive method*/
    int non_recursive(int n){
      int i;
      if(n==0||n==1){
        return 1;
      }
      else{
        f=1;
        for(i=1; i<=n; i++){
          f= f*i;
        }
        return f;
      }
    }
};

int main() {
  int n;
  factorial fact;
  cout<<"Enter a number: ";
  cin>>n;

  cout<<"Factorial of "<<n<<" recursively is "<<fact.recursive(n)<<endl;
  
  cout<<"Factorial of "<<n<<" non-recursively is "<<fact.non_recursive(n)<<endl;
}