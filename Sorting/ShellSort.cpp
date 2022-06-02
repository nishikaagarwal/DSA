#include  <iostream>
#include <bits/stdc++.h>
using namespace std;
 
int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {

        for (int i = gap; i < n; i += 1)
        {
            
            int temp = arr[i];
 
            
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             

            arr[j] = temp;
        }
    }
    return 0;
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
 
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
 
 
    shellSort(arr, n);

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
 
    //cout << "\nArray after sorting: \n";
    //printArray(arr, n);
 
    return 0;
}    