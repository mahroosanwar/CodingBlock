// Reversing the array

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void ReverseArray(int a[], int n){
    for(int i =0; i<n/2; i++){
        swap(a[i],a[n-1-i]);
    }
    for(int i=0; i<n; i++){
        cout << a[i]<< endl;
    }
}

int main(){
    
    int a[1000];
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    ReverseArray(a,n);
    cout << endl;
    return 0;
}


// Take as input N, the size of array. Take N more inputs and store that in an array. Write a function that reverses the array. Print the values in reversed array.

// 1.It reads a number N.
// 2.Take Another N numbers as input and store them in an Array.
// 3.Reverse the elements in the Array.
// 4.Print the reversed Array.

// Input Format
// First-line contains a single integer n denoting the size of the array.
// Next, N line contains a single integer denoting the elements of the array.

// Constraints
// N cannot be Negative. Range of Numbers can be between -1000000000 to 1000000000.

// Output Format
// Print the elements of the reversed array

// Sample Input
// 5
// 0
// 4 
// 6 
// 8 
// 9
// Sample Output
// 9 
// 8 
// 6 
// 4 
// 0 
// Explanation
// In the sample case , arr=[0,4,6,8,9] is reversed to arr=[9,8,6,4,0].
