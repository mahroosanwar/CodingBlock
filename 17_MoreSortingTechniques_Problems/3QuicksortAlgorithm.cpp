//Quicksort Algorithm

#include <iostream>
using namespace std;

int partition(int *a, int s, int e){
    
    //Inplace (cann't take extra array)
    //so use two pointer approach

    int i = s-1, j = s;

    for(; j<=e-1;){
        if(a[j] <= a[e]){
            //merge the smaller elements in the region 1
            i++;
            swap(a[i], a[j]);
        }

        //else expand the larger region
        j++;
    }

    //place the pivot element in the correct index

    swap(a[e], a[i+1]);

    return i+1;
}

void QuickSort(int *a, int s, int e){
    //base case
    if(s>=e){
        return;
    }

    //recursive case
    // correct index for pivot element
    int p = partition(a, s, e);

    //Quicksort left part
    QuickSort(a, s, p-1);

    //QuickSort right part
    QuickSort(a, p+1, e);
}

int main(){
    int arr[] = {2,7,8,6,1,5,4};
    int n = sizeof(arr)/sizeof(int);

    QuickSort(arr, 0, n-1);

    //print the array
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    return 0;
}