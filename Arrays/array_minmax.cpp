#include <iostream>
using namespace std;

struct res {
    int max;
    int min;
};

res getMinMax(int arr[], int n){
    struct res minmax;
    if (n == 1)
    {
        minmax.max = arr[0];
        minmax.min = arr[0];    
        return minmax;
    }
     
    if (arr[0] > arr[1])
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    else
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
     
    for(int i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)    
            minmax.max = arr[i];
             
        else if (arr[i] < minmax.min)    
            minmax.min = arr[i];
    }
    return minmax;
}

int main() {
    int k;
    cout<<"Enter number of testcases\n";
    cin>>k;
    int n;
    int arr[1000];
    
    for (int j=0; j<k; j++) {
    	cout<<"Enter number of elements\n";
    	cin>>n;
    	cout<<"Enter elements\n";
    	for(int i=0; i<n; i++){
    	    cin>>arr[i];
    	}
    	
    	struct res minmax = getMinMax(arr, n);
         
        cout << "Minimum element is "
             << minmax.min << endl;
        cout << "Maximum element is "
             << minmax.max << endl;
              
    }
	return 0;
}