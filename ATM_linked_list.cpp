/*program to store the withdrawal and password changes sequentially (default value as the first node) using Linked List.*/

#include <iostream>
using namespace std;

class atm;

class node1{
  public:
    int data;
    node1 *next;

friend class atm;
};

class node2{
  public:
    string p1;
    node2 *next;

    friend class atm;
};

class atm
{
  public:
    static int balance;
    static string p;
    node1* insert_end1(node1 *head, int balance);
    node2* insert_end2(node2 *head, string p);
    atm(node1 *head, node2 *root)
    {
      cout<<endl<<"---------------------------------"<<endl;
      cout<<"Welcome to My Bank ATM"<<endl;
      cout<<"---------------------------------"<<endl;
      cout<<endl<<"1.Withdraw Money\n2.Change your password\n3.Exit"<<endl;
      node1 *a;
      node2 *b;
      a=head;
      b=root;
      cout<<endl<<"Withdrawal: ";
      while(a!=NULL){
        cout<<a->data<<" -> ";
        a=a->next;
      }
      cout<<endl;
      cout<<"Password Change: ";
      while(b!=NULL){
        cout<<b->p1<<" -> ";
        b=b->next;
      }
      cout<<endl;
    }
    void withdraw(int w){
      if(w<balance)
      balance=balance-w;
    }
};

/*initializing the value of balance and password*/
int atm::balance=10000;
string atm::p="hello5787";

/*withdrawing money*/
node1* atm::insert_end1(node1 *head, int balance)
{
  node1 *temp, *a;
  temp=new node1();
  a=head;
  temp->data=balance;
  temp->next=NULL;
  while(a->next!=NULL){
    a=a->next;
  }
  a->next=temp;
  return head;
}

/*password change*/
node2* atm::insert_end2(node2 *head, string p)
{
  node2 *temp, *a;
  temp=new node2();
  a=head;
  temp->p1=p;
  temp->next=NULL;
  while(a->next!=NULL){
    a=a->next;
  }
  a->next=temp;
  return head;
} 


int main() {
  node1 *head;
  node2 *root;
  int choice, w;
  string old_p, new_p;  
  head=new node1();
  head->data=10000;
  head->next=NULL;
  root=new node2();
  root->p1="hello5787";
  root->next=NULL;
  do{
    atm a1(head,root);
    cout<<"Enter your choice"<<endl;
    cin>>choice;

    switch(choice){

      /*withdrawing money from current balance i.e. 10000*/
      case 1: cout<<"Enter the amount you need to withdraw"<<endl;
              cin>>w;
              if(a1.balance>= w){
                head= a1.insert_end1(head, w);
                a1.withdraw(w);
              }
              else{
                cout<<endl<<"Not enough money!"<<endl;
              }
              break;

      /*if entered password matches the old password then only it can be changed*/
      case 2: cout<<"Enter the old password"<<endl;
              cin>>old_p;                     
              if(old_p==a1.p){
                cout<<"Enter the new password"<<endl;
                cin>>new_p;
                cout<<endl<<"Password Changed Successfully!"<<endl;
                root=a1.insert_end2(root, new_p);
                a1.p=new_p;
              }
              else{
                cout<<endl<<"Password Cannot be changed as the old password entered is wrong!"<<endl;
              }
              break;

      case 3: cout<<endl<<"Thank You, Have a Great Day :)"<<endl;
              exit(1);
              break;

      default:cout <<endl<<"Enter a valid choice!"<<endl;         
      }
    }while(1);

  return 0;
}