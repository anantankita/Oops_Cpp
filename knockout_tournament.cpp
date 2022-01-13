/*program to find the winning team of the knockout tournament*/

#include <iostream>
using namespace std;

int compare(int A1[], int A2[]){
    int i, count1=0, count2=0;

    /*comparing team's strength in a specific unit*/
    for(i=0; i<5; i++){
        if(A1[i]<A2[i]){
          count1++;
        }
        if(A1[i]>A2[i]){
          count2++;
        }
        else{
          count2++;
        }
    }
    if(count2>count1){
      return 1;
    }
    else{
      return -1;
    } 
}


int main() {

  /*declare the variables*/
  int n, m=0, k, l;
  cout << "Number of teams participating in the tournament: ";
  cin>>n;

  cout<<endl<<"Enter values in order of Batting, Bowling, Fielding, All-rounder's performance, Captain's performance respectively."<<endl<<endl;

  int A[n][5];

  cout<<"Individual team statistic/ performance: "<<endl;

  int winner[n+1];
  for(int i=1; i<=n; i++){
    winner[i-1]=i;
  }
  
  for(int i=0;i<n;i++){
    cout<<"Team"<<i+1<<": ";
    for(int j=0;j<5;j++){
      cin>>A[i][j];
    } 
  }

  k=n;
  while(k>1){
    m=0;
    for(l=0; l<k; l=l+2){
      if(compare(A[winner[l]-1],A[winner[l+1]-1])==1)/*function calling*/ { 
        winner[m]= winner[l];
        m++;
      }
      else{
        winner[m]= winner[l+1];
        m++;
      }            
    }
    k=k/2;
  }

  cout<<endl<<"The winner is Team "<<winner[0];    
              
}
