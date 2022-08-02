// Arrays Linear Search

#include <iostream>
using namespace std;

void LinearSearch(long long int a[], int n, long long int M){
    for(int i=0; i<=n; i++){        // i<=n beacuse when i==n m not found it 
        if(a[i]==M){                // returns -1
            cout << i;
            break;
        }
        if(i==n)
            cout << -1;
        
    }
}

int main(){
    long long int a[1000];
    int n;
    cin >>n;

    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    int M;
    cin >> M;

    LinearSearch(a,n,M);

    cout << endl;
    return 0;
}

// Take as input N, the size of an array. Take N more inputs and store that in an array. Take another number’s input as M. Write a function which returns the index on which M is found in an array, in case M is not found -1 is returned. Print the value returned.

// 1. It reads a number N.
// 2. Take Another N numbers as an input and store them in an Array.
// Take another number M as an input.
// 3. If M is found in the Array the index of M is returned else -1 is returned and print the value returned.
// Input Format
// Constraints
// N cannot be Negative. Range of Numbers can be between -1000000000 to 1000000000. M can be between -1000000000 to 1000000000.

// Output Format
// Sample Input
// 5
// 2
// 4
// 6
// 9
// 17
// 17
// Sample Output
// 4
// Explanation
// Given array = {2, 4, 6, 9, 17}. Target number = 17. Index = 4.
