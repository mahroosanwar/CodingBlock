//First Index

#include <iostream>
using namespace std;

int FirstIndex(int *a, int n, int i, int M){
     //Base Case
    if(i == n){
        return -1;
    }
    //Recursive Case
    if(a[i] == M){
        return i;
    }
    int index = FirstIndex(a, n, i+1, M);

    return index;
}
int main(){
    int n;
    cin >> n;
    int a[n];
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int M;
    cin >> M;

    int ans = FirstIndex(a, n, 0, M);
    cout << ans;
    return 0;
}



// Take as input N, the size of array. Take N more inputs and store that in an array. Take as input M, a number. Write a recursive function which returns the first index at which M is found in the array and -1 if M is not found anywhere. Print the value returned.

// Input Format
// Enter a number N and add N more elements to an array, then enter a number M

// Constraints
// None

// Output Format
// Display the first index at which number M is found

// Sample Input
// 5
// 3
// 2
// 1
// 2
// 2
// 2
// Sample Output
// 1
