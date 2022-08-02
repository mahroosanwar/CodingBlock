// Is Array Sorted?

#include <iostream>
using namespace std;

bool isSorted(int *a, int n){
    //base case
    if(n==0 || n==1){
        return true;
    }

    //Recursive case 
    bool isSmallerSorted = isSorted(a+1, n-1);

    if(isSmallerSorted && a[0] <= a[1]){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    int n;
    cin >> n;
    int a[n];
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    bool ans = isSorted(a,n);
    if(ans){
        cout << "true";
    }
    else{
        cout << "false";
    }
    return 0;
}



// Take as input N, the size of array. Take N more inputs and store that in an array. Write a recursive function which returns true if the array is sorted and false otherwise. Print the value returned.

// Input Format
// Enter a number N and take N more inputs and store in an array

// Constraints
// None

// Output Format
// Display the Boolean result

// Sample Input
// 4
// 1
// 2
// 3
// 4
// Sample Output
// true
