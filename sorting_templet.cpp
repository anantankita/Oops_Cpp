/*program to implement the sorting using Template*/

#include <iostream>
using namespace std;

template<class T>
/*bubble sort*/
void BubbleSort(T array[], int n){
  int i, j;
	for(i=0;i<n-1;++i){
		for(j=0;j<n-i-1;++j){
			if(array[j]>array[j+1]){
				T temp = array[j+1];
				array[j+1] = array[j];
				array[j] = temp;
			}
		}
	}
}

template <class T>
/*insertion sort*/
void InsertionSort(T array[], int n){
	int i, j;
	T temp;
	for(i=1; i<n; ++i){
		temp=array[i];
		j=i-1;
		while(j>= 0 && array[j] > temp){
			array[j + 1]=array[j];
			j--;
		}
		array[j+1] = temp;
	}
}

template <class T>
int Partition(T array[], int l, int h){
	int i, j = l;
	int pivot = h;
	for(i=l;i<h;++i){
		if(array[i]<array[pivot]){
			swap(array[i],array[j]);
			++j;
		}
	}
	swap(array[j],array[pivot]);
	return j;
}

template <class T>
/*quick sort*/
void Quicksort(T array[], int l, int h ){
	if(l<h){
		int p = Partition(array,l,h);
		Quicksort(array,l,p-1);
		Quicksort(array,p+1,h);
	}
}

template<class T>
void PrintArray(T array[], int n){
  for (int i = 0; i < n; ++i){
    cout << array[i] << " ";
  }
  cout << "\n\n";
}

int main() {
  int array[100], n, i, d, temp;
  int choice;
  cout<<"Enter number of elements: ";
  cin>>n;
  cout<<"Enter "<<n<<" integers: ";
  for (i=0; i<n; i++){
    cin>>array[i];
  }
  char arr[] = { 'D','R','E','G','S','A','Y','U','F','J','K','V'};
  
  while(1){
    cout<<"\n1.Bubble Sort\n2.Insertion Sort\n3.Quick Sort\n4.All sorting in char type\n5.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    switch(choice){
      case 1 :
        BubbleSort(array, n); 
        cout<<endl<<"Bubble sort" << endl;
        PrintArray(array, n);
        break;

      case 2 :
        InsertionSort(array, n);
        cout<<endl<<"Insertion sort" << endl;
        PrintArray(array, n);
        break;

      case 3:
        Quicksort(array,0,n-1);
        cout<<endl<<"Quick sort" << endl;
        PrintArray(array, n);
        break;

      case 4:
      /*to sort the char type array*/
	      n = sizeof(arr)/sizeof(char);
        BubbleSort(arr, n); 
        cout<<endl<<"Bubble sort" << endl;
        PrintArray(arr, n);
     
        InsertionSort(arr, n);
        cout<<endl<<"Insertion sort" << endl;
        PrintArray(arr, n);
  
        Quicksort(arr,0,n-1);
        cout<<endl<<"Quick sort" << endl;
        PrintArray(arr, n);
        break;       


      case 5:
        cout<<"Program ended"<<endl;
        exit(0);

      default:
        cout<<"Enter valid choice"<<endl;
    }
  }while(choice!=5);
  
} 