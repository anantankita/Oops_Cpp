/*program to write a method similarity score*/

#include <iostream>
using namespace std;

int main() {

  /*declare the variables*/
  char strA[1000], strB[1000];  
  int i, j, count=0, l1, l2;
  double threshold, similarity1, similarity2; 

  /*taking 2 strings from user*/
  cout<<"Enter string A: ";
  cin>>(strA);
  cout<<"Enter string B: ";
  cin>>(strB);

  for(l1=0; strA[l1]!='\0'; l1++);
  for(l2=0; strB[l2]!='\0'; l2++);

  /*taking threshold percentage from user*/  
  cout<<"Enter the threshold %: ";
  cin>>threshold;
  cout<<endl;  

  for(i=0; i<l1; i++){
    for(j=0; j<l2; j++){
      if(strA[i]==strB[j]){
        count++;
      }
    }
  }

  similarity1= (count*100)/l1;
  similarity2= (count*100)/l2;

  if(similarity1>=threshold && similarity2>=threshold){
    cout<<"True";
  }
  else{
    cout<<"False";
  }
}