// Max value In Array

#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void MaxValue(int a[], int n){
    int max = INT_MIN;
    
    for(int i = 0; i<n-1; i++){
        for(int j=0; j<n-1; j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    cout << a[n-1];
}
int main(){
    int a[1000];
    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    MaxValue(a,n);
    cout << endl;
    return 0;
}


// Take as input N, the size of array. Take N more inputs and store that in an array. Write a function which returns the maximum value in the array. Print the value returned.

// 1.It reads a number N.

// 2.Take Another N numbers as input and store them in an Array.

// 3.calculate the max value in the array and return that value.

// Input Format
// First line contains integer n as size of array. Next n lines contains a single integer as element of array.

// Constraints
// N cannot be Negative. Range of Numbers can be between -1000000000 to 1000000000

// Output Format
// Print the required output.

// Sample Input
// 4
// 2
// 8
// 6
// 4
// Sample Output
// 8
// Explanation
// Arrays= {2, 8, 6, 4} => Max value = 8 .
