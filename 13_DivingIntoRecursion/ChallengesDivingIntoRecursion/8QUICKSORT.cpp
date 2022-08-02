//QUICK SORT

#include <iostream>
using namespace std;

int Partition(int *a, int s, int e){
    int i = s-1;
    
    for(int j=s; j<=e-1; j++){
        if(a[j] < a[e]){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i+1], a[e]);

    return i+1;
}

void QuickSort(int *a, int s, int e){
    //base case
    if(s >= e){
        return;
    }

    //recursive case

    int index = Partition(a, s, e);
    QuickSort(a, s, index-1);
    QuickSort(a, index+1, e);

}
int main(){
    int n;
    cin  >> n;
    int a[n];

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    QuickSort(a, 0, n-1);
    
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    return 0;
}


// Given an array A, of N elements. Sort the array using quicksort algorithm.(Note : Use randomized quicksort, otherwise worst case will not pass).

// Input Format
// A single integer, N, denoting the number of elements in array. Next line contains N integers, denoting the elements of array.

// Constraints
// 1<=N<=2*10^5
// |Ai|<=10^9

// Output Format
// Print in a single line, N spaced integers, denoting the elements of array A in sorted order.

// Sample Input
// 5
// 3 6 4 1 2
// Sample Output
// 1 2 3 4 6 
