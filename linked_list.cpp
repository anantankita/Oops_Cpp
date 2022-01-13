/*program to implement a linked list with different operations*/

#include <iostream>
using namespace std;

class node{
  public:
    int num;
    node *next;
    node(){
      next = NULL;
    }
};

class linked_list{
  node *head;
  public:
    
    linked_list(){
      head = NULL;
    }

    void Ins_beg(int num)
   {
    node *temp= new node();
    temp->num=num;
    temp->next=head;
    head=temp;
    cout<<"Insertion successfull!"<<endl;
   }

   void Ins_end(int num)
   {
    node *temp= new node();
    temp->num=num;
    temp->next=NULL;
    if(head==NULL){
      head=temp;
    }
    else
    {
      node *t=head;
      while(t->next!=NULL)
        t=t->next;
      t->next=temp;
    }
   }

   void Del_beg()
   {
    if(head==NULL)
      cout<<"Empty List, Deletion failed"<<endl;
      else
      {
        node *temp=head;
        head=head->next;
        temp->next=NULL;
        free(temp);
      }
   }
   
   void Del_end()
   {
    if(head==NULL)
      cout<<"List empty, deletion failed"<<endl;
    else if(head->next==NULL)
    {
      cout<<"Deleted element:"<<head->num<<endl;
      head=NULL;
      free(head);
    }
    else
    {
      node *temp=head;
      while(temp->next->next!=NULL)
      {
        temp=temp->next;
      }
      cout<<"Deleted element:"<<temp->next->num<<endl;
      free(temp->next); 
      temp->next=NULL;  
    }
  }

  void Display()
  {  
    if(head==NULL)
      cout<<"List is empty!"<<endl;
    else
    {
      node *temp = head;
      cout<<"List is: ";
      while(temp!=NULL)
      {
        cout<<temp->num<<" -> ";
        temp=temp->next;
      }
    }
    cout<<endl;
  }

  void Display_last(){
     struct node *temp;
    if (head == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = head;
     do
    {
        if(temp->next==NULL)
        cout<<"Last element is: "<<temp->num<<endl;
        temp = temp->next;
    }while(temp != NULL);
    cout<<endl;
  }

  void Display_first(){
    if(head==NULL)
      cout<<"List is empty!"<<endl;
    else
    {
      node *temp = head;
      cout<<"First element is: ";
      cout<<head->num<<endl;
    }
    cout<<endl;
  }

  void Reverse(){
    node* current = head;
    node *previous = NULL, *next = NULL;
    while (current != NULL) {            
      next = current->next; 
      current->next = previous;
      previous = current;
      current = next;
    }        
    head = previous;
    node* temp = head;
    while (temp != NULL) {
      cout << temp->num <<" -> ";
      temp = temp->next;
    }
  }

  
};

class CircularLinkedList {
  node * head;
  public:  
    CircularLinkedList() {
    head = NULL;
  }

  void Ins_beg(int num){
    node *temp;
    temp=new node;
    temp->num=num;
    temp->next=NULL;
    if(head==NULL)
    {
      head=temp;
      head->next=head;
    }
    else
    {
      temp->next=head->next;
      head->next=temp;
    }
  }

  void Ins_end(int num){
    node *temp;
    temp=new node;
    temp->num=num;
    temp->next=NULL;
    if(head==NULL)
    {
      temp->next=temp;
      head=temp;
    }
    else
    {
      temp->next=head->next;
      head->next=temp;
      head=temp;
    }
  }

  void Del_beg(){
    node *temp=new node;
    temp=head->next;
    if(head==NULL)
     {
     cout<<"Empty List, Deletion failed\n";
    }
    else if(head->next==head)
    {
      temp=head;
      head=NULL;
      free (temp);
    }
    else
    {
      head->next=temp->next;
      free (temp);
    }
  }

  void Del_end(){
    if(head==NULL)
      cout<<"List empty, deletion failed"<<endl;
    else if(head->next==NULL)
    {
      cout<<"Deleted element:"<<head->num<<endl;
      head=NULL;
      free(head);
    }
    else
    {
      node *temp=head;
      while(temp->next->next!=NULL)
      {
        temp=temp->next;
      }
      cout<<"Deleted element:"<<temp->next->num<<endl;
      free(temp->next); 
      temp->next=NULL;  
    }
  }

  void Display(){
    node *temp;
    temp=head->next;
     if(head==NULL)
      {
        cout<<"Empty List\n";
      }
    cout<<"List is: ";
    while(temp!=head)
    {
      cout<<temp->num<<" -> ";
      temp=temp->next;
    }
    if(temp==head)
    {
      cout<<temp->num;
    }
    free(temp);
    cout<<endl;
  }

  void Display_last(){
     struct node *temp;
    if (head == NULL)
    {
        cout<<"The List is Empty"<<endl;
        return;
    }
    temp = head;
     do
    {
      if(temp->next==NULL)
      cout<<"Last element is: "<<temp->num<<endl;
      temp = temp->next;
    }while(temp != NULL);
    cout<<endl;
  }

  void Display_first(){
    if(head==NULL)
      cout<<"List is empty!"<<endl;
    else
    {
      node *temp = head;
      cout<<"First element is: ";
      cout<<head->num<<endl;
    }
    cout<<endl;
  }

  void Reverse(node **head){
    struct node *previous, *temp, *next, *last;
    if (*head == NULL)
    {
      cout<<"List is empty\n";
      return;
    }
    last= *head;
    previous= *head;
    temp   = (*head)->next;
    *head = (*head)->next;
    while (*head != last)
    {
      *head = (*head)->next;
      temp->next = previous;
      previous = temp;
      temp  = *head;
    }
    temp->next = previous;
    *head = previous;  
    while(temp != NULL) {
      cout << temp->num <<" -> ";
      temp = temp->next;
    }  
  }
  

};
 

int main() {
  node *head = NULL;
  int choice1, choice2, num;
  linked_list l;
  CircularLinkedList c;
  cout<<"1.Singly Linked List"<<endl;
  cout<<"2.Circular Linked List"<<endl;   
  cout<<"\nEnter your choice: ";
  cin>>choice1;
  
  switch (choice1)
    {
      case 1:
      do{
        cout<<"\n1.Insert at beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Display\n6.Display last element\n7.Display first element\n8.Reverse list"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice2;
        /*for singly linked list*/
        switch(choice2){  
          case 1: cout<<"\nEnter number to be inserted: ";
                  cin>>num;
                  l.Ins_beg(num);
                  break;
  
          case 2: cout<<"\nEnter number to be inserted: ";
                  cin>>num;
                  l.Ins_end(num);
                  break;                  
            
          case 3: l.Del_beg();
                  break; 
              
          case 4: l.Del_end();
                  break;  

          case 5: l.Display();    
                  break;

          case 6: l.Display_last();
                  break;

          case 7: l.Display_first();
                  break;  

          case 8: l.Reverse();
                  break;                          

          default: cout<<"\nEnter a valid choice!"<<endl;        
        }
      }while(1);

      case 2:
      do{
        cout<<"\n1.Insert at beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from end\n5.Display\n6.Display last element\n7.Display first element\n8.Reverse list"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice2;
        /*for circular linked list*/
        switch(choice2){  
          case 1: cout<<"\nEnter number to be inserted: ";
                  cin>>num;
                  c.Ins_beg(num);
                  break;
  
          case 2: cout<<"\nEnter number to be inserted: ";
                  cin>>num;
                  c.Ins_end(num);
                  break;                  
            
          case 3: c.Del_beg();
                  break; 
              
          case 4: c.Del_end();
                  break;  

          case 5: c.Display();    
                  break;    

          case 6: c.Display_last();
                  break;

          case 7: c.Display_first();
                  break; 

          case 8: c.Reverse(&head);
                  break;        

          default: cout<<"\nEnter a valid choice!"<<endl;        
        }
      }while(1);
    }
}

