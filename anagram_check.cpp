/*program to check if two strings are anagram of each other or not*/

#include <iostream>
#include <string.h>
using namespace std;

/*function declaration*/
void anagram_check(char[], char[]);

int main () {
  char str1[100], str2[100];
  cout<<"Enter 1st string: ";
  cin.getline(str1, 100);
  cout<<"Enter 2nd string: ";
  cin.getline(str2, 100); 

  cout<<endl;   
  
  /*function calling*/
  anagram_check(str1, str2); 
   
  return 0;
}

void anagram_check(char str1[], char str2[]){

  /*declare the variables*/  
  int i, j, k=0, p, q, r=0, l1, l2, x=0, count=0;  
  char temp1, temp2;

  /*removing spaces from string 1*/
  for(i=0;str1[i];i++)
  {
    str1[i]=str1[i+k];
  
        
    if(str1[i]==' '|| str1[i]=='\t')
    {
    k++;
    i--;
    }
        
  }

  /*removing spaces from string 2*/
  for(p=0;str2[p];p++)
  {
    str2[p]=str2[p+r];
  
        
    if(str2[p]==' '|| str2[p]=='\t')
    {
    r++;
    p--;
    }
        
  }  

  /*length of string 1*/
  l1= strlen(str1);

  /*length of string 2*/
  l2= strlen(str2);

  if(l1!=l2){
    cout<<"Strings are not Anagram of each other";
  }

  else{

    /*sorting the string 1*/
    for (i = 0; i < l1; i++) {
      for (j = i+1; j < l1; j++) {
        if (str1[i] > str1[j]) {
            temp1 = str1[i];
            str1[i] = str1[j];
            str1[j] = temp1;
        }
      }
    }
    
    /*sorting the string 2*/
    for (p= 0; p<l2; p++) {
      for (q= p+1; q<l2; q++) {
        if (str2[p] > str2[q]) {
            temp2 = str2[p];
            str2[p] = str2[q];
            str2[q] = temp2;
        }
      }
    }
    
    /*checking both string*/
    while(str1[x]!='\0' || str2[x]!='\0')
    {
        if(str1[x]!=str2[x])
        {
            count = 1;
            break;
        }
        x++;
    }
    if(count==0)
        cout<<"Strings are Anagram of each other";
    else
        cout<<"Strings are not Anagram of each other"; 
    
  }
   
        
}