#include <bits/stdc++.h>
using namespace std;
  
void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++)     
      
    
    for (j = 0; j < n-i-1; j++) 
        if (arr[j] > arr[j+1]) 
            swap(&arr[j], &arr[j+1]); 
} 
  

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i = 0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
 
int main() 
{ 
    int arr[2000];
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ )
           {
              arr[i] = rand(); 
           }
    int n = sizeof(arr)/sizeof(arr[0]); 

    clock_t start, end;
    start = clock();

    bubbleSort(arr, n); 

    end = clock();
    
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    //cout<<"Sorted array: \n"; 
    //printArray(arr, n); 
    return 0; 
} 
  