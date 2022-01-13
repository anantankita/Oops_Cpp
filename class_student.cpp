#include <iostream>
using namespace std;
#define MAX 20

class student
{
  public:
      int rollno;
      char name[20];
      int pre_y, pre_m, pre_d, birth_y, birth_m, birth_d;
  

      int GetAgeOf_Student_val(int pre_y, int pre_m, int pre_d,int birth_y, int birth_m, int birth_d)
        {
          int y, m, d;
          int month_d[] = {31,28,31,30,31,30,31,31,30,31,30,31};

          /*if birth date is greater then present date*/
          if (birth_d > pre_d) {
            pre_d = pre_d + month_d[birth_m - 1];
            pre_m = pre_m - 1;
        }
 
    
          if (birth_m > pre_m) {
              pre_y= pre_y - 1;
              pre_m= pre_m + 12;
          }
      
          
          d = pre_d - birth_d;
          m = pre_m - birth_m;
          y = pre_y - birth_y;
      
          cout<<"Call by value"<<endl;
          cout <<"Student's age is: ";
          cout<< y << " years " << m << " months " << d << " days. "<<endl;

          return 0;
    }

    int GetAgeOf_Student_ref(int &pre_y, int &pre_m, int &pre_d,int &birth_y, int &birth_m, int &birth_d)
        {
          int y, m, d;
          int month_d[] = {31,28,31,30,31,30,31,31,30,31,30,31};

          /*if birth date is greater then present date*/
          if (birth_d > pre_d) {
            pre_d = pre_d + month_d[birth_m - 1];
            pre_m = pre_m - 1;
        }
 
    
          if (birth_m > pre_m) {
              pre_y= pre_y - 1;
              pre_m= pre_m + 12;
          }
      
          
          d = pre_d - birth_d;
          m = pre_m - birth_m;
          y = pre_y - birth_y;
      
          cout<<"Call by reference"<<endl;
          cout <<"Student's age is: ";
          cout<< y << " years " << m << " months " << d << " days. "<<endl;

          return 0;
    }

    int GetAgeOf_Student_add(int *p_y, int *p_m, int *p_d,int *b_y, int *b_m, int *b_d)
        {
          int y, m, d;
          int month_d[] = {31,28,31,30,31,30,31,31,30,31,30,31};

          /*if birth date is greater then present date*/
          if (*b_d > *p_d) {
            *p_d = *p_d + month_d[*b_m - 1];
            *p_m = *p_m - 1;
        }
 
    
          if (*b_m > *p_m) {
              *p_y= *p_y - 1;
              *p_m= *p_m + 12;
          }
      
          
          d = *p_d - *b_d;
          m = *p_m - *b_m;
          y = *p_y - *b_y;
      
          cout<<"Call by address"<<endl;
          cout <<"Student's age is: ";
          cout<< y << " years " << m << " months " << d << " days. "<<endl;

          return 0;
    }

    

      //member function to read details
      void readDetails(){
        cout<< "Enter Roll number:";
        cin>> rollno;
        cout<< "Enter Name:";
        cin>> name;
        cout<< "Enter today's date(yyyy mm dd):";
        cin>>pre_y>> pre_m >> pre_d;
        cout<< "Enter you date of birth(yyyy mm dd):";
        cin>>birth_y>> birth_m >> birth_d;
      }

      /*function to display details*/
      void printDetails(){
        cout<< "RollNo: " << rollno<<endl;
        cout<< "Name: " << name<<endl; 

        GetAgeOf_Student_val(pre_y, pre_m, pre_d, birth_y, birth_m, birth_d);

        GetAgeOf_Student_ref(pre_y, pre_m, pre_d, birth_y, birth_m, birth_d);  

        GetAgeOf_Student_add(&pre_y, &pre_m, &pre_d, &birth_y, &birth_m, &birth_d); 
      }

    
      
  };



int main()
{
    student std[10];    /*array of students object*/
    int n, i;
     
    cout << "Enter total number of students: ";
    cin >> n;
     
    for(i=0; i<n; i++){
        cout << "Enter details of student " << i+1 << ":\n";
        std[i].readDetails();
    }
    
    for(i=0; i<n; i++){
        cout << "\nDetails of student " << i+1 << ":\n";
        std[i].printDetails();
    }
    return 0;
}