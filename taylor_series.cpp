/*program to calculate taylor series*/

#include <iostream>
using namespace std;
int main() {

  /*declare the variables*/
  int a, x, n, p1= -1, p2, i, f;  
  double ans=0, r, x1;

  /*taking upper-limit of summation from user*/
  cout<<"Enter value of a: ";
  cin>>a;

  /*taking the degree from user*/
  cout<<"Enter the value of x: ";
  cin>>x;

  /*converting degree to radian*/
  r= x*3.14/180;
  cout<<endl;  
  
  for(n=0; n<=a; n++){
    p1= p1*(-1);
    p2= (2*n)+1;        
    f=1;
    x1=1;
    for(i=1; i<=(2*n)+1; i++){
      x1= x1*r;
      f= f*i;         
    }
    
    /*displaying the series expansion*/
    cout<<" (-1)^"<<n<<" X ("<<r<<")^"<<(p2)<<"/"<<(p2)<<"! +";  

    ans= ans+ p1*(x1)/f;
  }
  cout<<endl<<endl<<"Sin("<<x<<"): "<<ans;
}