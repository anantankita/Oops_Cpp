/*function overloading and operator overloading to perform the operations on matrix*/

#include<iostream>
using namespace std;

/*size of both row and column */
#define r 3
#define c 3

class matrix{
 public:
 int x[r][c]; 
 matrix(){
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        x[i][j]=0;
      }
    }
  }

  matrix(int a[r][c]){
    for(int i=0;i<r;i++){
      for(int j=0;j<r;j++){
        x[i][j]=a[i][j];
      }
    }
  }

  /*taking the input from the user*/
  matrix get(){
    cout<<endl<<"Enter values for matrix"<<endl;
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        cin>>x[i][j];
      }
    }
    return x;
  }

  /*displaying the output*/
  void display(){
    cout<<endl;
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        cout<<x[i][j]<<"\t";
      }
      cout<<endl;
    }
  }

  /*addition of two matrix*/
  friend matrix operator+(matrix x1, matrix x2){
    matrix x3;
    cout<<endl<<"Addition";
    for(int i=0; i<r; i++){
      for(int j=0; j<c; j++){
        x3.x[i][j]=x1.x[i][j]+x2.x[i][j];
    }
  }
    return x3;
  }

  /*difference of two matrix*/
  friend matrix operator-(matrix x1, matrix x2){
    matrix x3;
    cout<<endl<<"Subtraction";
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        x3.x[i][j]=x1.x[i][j]-x2.x[i][j];
      }
    }
    return x3;
  }

  /*multilication of two matrix*/
  friend matrix operator*(matrix x1, matrix x2){
    matrix x3;
    cout<<endl<<"Multiplication";
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        x3.x[i][j]=0;
        for (int k=0;k<c;k++){
          x3.x[i][j]=x3.x[i][j]+x1.x[i][k]*x2.x[k][j]; 
        }
      }
    }
    return x3;
  }

  /*transpose of matrix*/
  matrix operator!(){
    matrix x3;
    cout<<endl<<"Transpose of matrix";
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
      x3.x[i][j]=x[j][i];
      }
    }
    return x3;
  }

  /*inverse of matrix*/
  void operator~(){
    cout<<endl<<endl<<"For displaying inverse";
    int i, j;
    float d =0;    
    for(i = 0; i < r; i++)    
    d = d + (x[0][i] * (x[1][(i+1)%r] * x[2][(i+2)%r] - x[1][(i+2)%r] *
    x[2][(i+1)%r]));
    cout<<endl<<"Determinant: "<<d;
    cout<<endl<<endl<<"Inverse"<<endl;
    for(i = 0; i < r; i++){
    for(j = 0; j < c; j++)
    cout<<((x[(j+1)%r][(i+1)%r] * x[(j+2)%r][(i+2)%r]) - (x[(j+1)%3][(i+2)%r] *
    x[(j+2)%r][(i+1)%r]))/ d<<"\t";
    cout<<endl;
    }
  }
 
  void swap(int mat[3][3], int r1, int r2, int cl){
    for (int i = 0; i < cl; i++){
      int temp = mat[r1][i];
      mat[r1][i] = mat[r2][i];
      mat[r2][i] = temp;
    }
  }

  /*rank of matrix*/
  void operator++(){
    int rank = 3;
    for (int R = 0; R<rank; R++){
      if (x[R][R]){
        for (int k=0; k<3; k++){
          if (c != r){
            double mult = (double)x[k][R] / x[R][R];
            for (int i = 0; i < rank; i++){
              x[k][i] -= mult * x[R][i];
            }
          } 
        }
      }
      else{
        bool reduce=true;
        for (int i=r+1; i<3; i++){
          if (x[i][R]){
            swap(x, r, i, rank);
            reduce=false;
            break ;
          }
        }
        if (reduce){
          rank--;
          for (int i=0; i<3; i++)
          x[i][R] = x[i][rank];
        }
        R--;
      }
    }
    cout<<endl<<"Rank: "<<rank<<endl;
  }
};

int main(){
  cout<<"Initially matrix has all elements are 0"<<endl;
  matrix M,N,x;
  M.display();

  M.get();
  M.display();

  N.get();
  N.display();

  x= M+N;
  x.display();

  x= M-N;
  x.display();

  M=!N;
  M.display();

  x= M*N;
  x.display();

  ~M;
  ++N;
  return 0;
} 