/*program to enumerate the Top-C ranked participants after C iterations.*/
#include <iostream>
using namespace std;

int A[20][20];

class TopC{    
       
  public:
    void ranking(int n) {
      int i, j, k;
      int iteration = 1;
      double R[20];
      double outgoing_link= 0;
      double temp[20];   
      double initial_rank = 1.0 / n;
      
      cout<<endl<<"Initial Rank of all participants: "<<initial_rank<<endl<<endl;        
            
      for (k=1; k<=n; k++) {
        R[k]= initial_rank;
      }
        
      cout<<"Iteration 0"<<endl;
      for (k=1; k<=n; k++){
        cout<<"Rank of participant "<<k<<" is: "<<R[k]<<endl;
      }
          
      while(iteration<= 2){
        for (k=1; k<= n; k++){
          temp[k]= R[k];
          R[k]= 0;
        }
        
        /*traverseing and counting the no. of outgoing links for the external node*/  
        for (i=1; i<=n; i++){
          for (j=1; j<=n; j++){
            if (A[j][i] == 1){
              k = 1;
              outgoing_link= 0; 
              while(k<= n){
                if (A[j][k]== 1){
                  outgoing_link++; 
                }
                k++;
              }                  
              R[i]= R[i]+ temp[j]*(1.0/outgoing_link);
            }
          }
        }
          
        cout<<endl<<"Iteration "<<iteration<<endl;
        
        for (k=1; k<=n; k++){
          cout<<"Rank of participant "<<k<<" is: "<<R[k] <<endl;
        }        
        iteration++;
      }
          
      cout<<endl<<"Rank at iteration 2"<<endl;
      for (k=1; k<= n; k++) {
        cout<<"Rank of participant " <<k<< " is: " <<R[k]<<endl;
      }      
    }
};

int main(){
  int n, i, j;    
  cout<<"Enter number of participants: ";    
  cin>>n;    
  cout<<endl<<"Enter adjacency matrix of graph:"<<endl;    
  for(i=1; i<=n; i++){
    for(j=1; j<=n; j++){
      cin>>A[i][j];
    }
  }
  
  TopC t;
  t.ranking(n);
}