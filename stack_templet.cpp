/*program to implement the Stack operations using Template*/

#include <iostream>
using namespace std;

template<class Type>
class Stack{
  Type s[30];
  int n, top;
  public:
  Stack(){
    top=-1;
    cout<<"Enter the size of Stack: ";
    cin>>n;
    cout<<endl;
  }

  void push(Type element){
    if(top<n-1){
      s[++top]=element;
    }
    else{
      cout<<"Stack Overflow"<<endl;
    }
  }
  void pop(){
    if(top<0){
      cout<<"Stack Underflow";
    }
    else{
      cout<<"Element popped: "<<s[top--];
    }
  }
  void operation();
};

template<class Type>
void Stack<Type>::operation(){
  int choice=1, i;
  Type element;
  while(choice>0 && choice<3){
    cout<<"\n1.Push\n2.Pop\n3.Exit\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
      case 1 : 
      /*push operation*/
        cout<<"\n\nEnter the element to push : ";
        cin>>element;
        push(element);
        cout<<endl;
        for(i=0;i<=top;i++)
        cout<<s[i]<<"\t";
        cout<<endl;
        break;

      case 2 : 
      /*pop operation*/
        pop();
        cout<<endl;
        for(i=0;i<=top;i++)
        cout<<s[i]<<"\t";
        cout<<endl;
        break;

      case 3:
        cout<<"Program ended"<<endl;
        break;

      default:
        cout<<"Enter valid choice"<<endl;
    }
  }while(choice!=3);
}

int main(){
  /*taking two data type integer and float*/
  cout<<"For Int\n";
  Stack<int> s1;
  cout<<"For Float\n";
  Stack<float> s2;
  int ch;
  while(1){
    cout<<"\n1.Int Stack\n2.Float Stack\n3.Exit\n";
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch){
      case 1 :
        s1.operation();
        break;

      case 2 :
        s2.operation();
        break;

      case 3:
        cout<<"Program ended"<<endl;
        exit(0);

      default:
        cout<<"Enter valid choice"<<endl;
    }
  }while(ch!=3);
}