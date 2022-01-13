/*calculator program with inline functions*/

#include <iostream>
#include <cmath>
using namespace std;

/*add function*/
inline float add(float a, float b){
    float sum= a+b;
    return sum;
}

/*multiplication function*/
inline float multi(float a, float b){
  float pro= a*b;
  return pro;
}

/*arithmetic modulo function*/
inline int rem(int a, int b){
  int modulo= a%b;
  return modulo;
}

/*decimal to binary function*/
inline int decimal_to_binary(int c){
  int B, r, i=1;
  while(c!=0){
    r= c%2;
    c= c/2;
    B= B+(r*i);
    i= i*10;
  }
  return B;
}

/*binary to decimal function*/
inline int binary_to_decimal(int d){
  int D=0, r, i=0;
  while(d!=0){
    r= d%10;
    d= d/10;
    D= D+(r*pow(2, i));
    i++;
  }
  return D;
}

/*function for interchanging 1 to 0 and vice-versa*/
inline char interchange(char j) {return (j == '0')? '1': '0';}

/*2's component function*/
inline char comp(string binary){
  int i;
  string X, Y;
  int n= binary.length();
      
  for(i=0; i<n; i++){
    X= X+ interchange(binary[i]);
  }

  Y=X;
  for(i=n-1; i>=0; i--){
    if(X[i]== '1'){
      Y[i]= '0';
    }
    else{
      Y[i]= '1';
      break;
    }
  }

  cout<<"2's componemt of "<<binary<<" is "<<Y<<endl;   

  return 0;
}

int main() {

  /*declare the variables*/
  float a, b;
  int c, r, i, d, choice;
  string binary;
  while(1){
    cout<<"\n1. Addition\n2. Multiplication\n3. Arithmetic modulo\n4. Decimal to Binary  \n5. Binary to Decimal\n6. 2’s complement\n7. Exit\n"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
      case 1:cout<<"Enter 1st number: ";
             cin>>a;
             cout<<"Enter 2nd number: ";
             cin>>b;
             cout<<"Sum is "<<add(a, b)<<endl; /*function call*/
             break;
      case 2:cout<<"Enter 1st number: ";
             cin>>a;
             cout<<"Enter 2nd number: ";
             cin>>b;
             cout<<"Product is "<<multi(a, b)<<endl; /*function call*/
             break;

      case 3:cout<<"Enter 1st number: ";
             cin>>a;
             cout<<"Enter 2nd number: ";
             cin>>b;
             cout<<"Remainder is "<<rem(a, b)<<endl; /*function call*/
             break;

      case 4:cout<<"Enter a decimal number: ";
             cin>>c;
             cout<<"Binary of "<<c<<" is "<<decimal_to_binary(c)<<endl; /*function call*/
             break;             

      case 5:cout<<"Enter a binary number: ";
             cin>>d;
             cout<<"Decimal of "<<d<<" is "<<binary_to_decimal(d)<<endl; /*function call*/
             break;

      case 6:cout<<"Enter a binary number: ";
             cin>>binary;
             comp(binary); /*function call*/             
             break;    

      case 7: cout<<"Program end!";
      exit(0);

      default: cout<<"Enter valid choice!\n";                                               
    }
  }
}
  