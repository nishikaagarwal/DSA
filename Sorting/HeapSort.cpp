#include <bits/stdc++.h>
 
using namespace std;
 
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
 
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
   
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
   
    if (largest != i) {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}
 

void heapSort(int arr[], int n)
{
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}
 

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver code
int main()
{
    int arr[500];
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ )
           {
              arr[i] = rand(); 
           }
    int n = sizeof(arr)/sizeof(arr[0]); 

    clock_t start, end;
    start = clock();
 
 
    heapSort(arr, n);

    end = clock();
 
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
 
    //cout << "Sorted array is \n";
    //printArray(arr, n);
}