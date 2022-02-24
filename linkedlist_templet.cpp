/*program to implement the Linked List operations using Template*/

#include <iostream>
using namespace std;

template<typename T>
class node{
  public:
    T num;
    node<T> *next;
    node(){
      next = NULL;
    }
};

template<typename T>
class linked_list{
  node<T> *head;
  public:
    linked_list(){
      head = NULL;
    }

    void Ins_beg(int num){
    node<T> *temp= new node<T>();
    temp->num=num;
    temp->next=head;
    head=temp;
    cout<<"Insertion successfull!"<<endl;
   }

   void Del_beg(){
    if(head==NULL)
      cout<<"Empty List, Deletion failed"<<endl;
      else{
        node<T> *temp=head;
        head=head->next;
        temp->next=NULL;
        free(temp);
      }
   }

  void Display(){  
    if(head==NULL)
      cout<<"List is empty!"<<endl;
    else{
      node<T> *temp = head;
      cout<<"List is: ";
      while(temp!=NULL){
        cout<<temp->num<<" -> ";
        temp=temp->next;
      }
    }
    cout<<endl;
  }  
};

int main(){
  int choice, num;
  linked_list<int> l;
  
  do{
    cout<<"\n1.Insert at beginning\n2.Delete from beginning\n3.Display\n4.Exit"<<endl;
    cout<<"\nEnter your choice: ";
    cin>>choice;
    switch(choice){
      case 1: 
      /*inserting at beginning*/
        cout<<"\nEnter number to be inserted: ";
        cin>>num;
        l.Ins_beg(num);
        break;

      case 2:
      /*deletion from beginning*/
        l.Del_beg();
        break; 
      
      case 3: 
      /*displaying the list*/
        l.Display();    
        break;

      case 4: 
        cout<<"Program end!";
        exit(0);

      default: 
        cout<<"Enter valid choice"<<endl;
    }
  }while(choice!=4);
}

