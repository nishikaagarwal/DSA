#include <bits/stdc++.h>
using namespace std;
 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;
 
        swap(&arr[min_idx], &arr[i]);
    }
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
int main()
{
    int arr[500];
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++ )
           {
              arr[i] = rand(); 
           }
    int n = sizeof(arr)/sizeof(arr[0]); 
    //printArray(arr, n);

    clock_t start, end;
    start = clock();

    selectionSort(arr, n);

    end = clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;

    //cout << "Sorted array: \n";
    //printArray(arr, n);
    return 0;
}