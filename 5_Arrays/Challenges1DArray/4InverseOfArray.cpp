// Inverse Of An Array

#include <iostream>
using namespace std;

void InverseArray(int a[], int n, int f[]){
    int j;
    for(int i=0; i<n; ++i){
            j = a[i];
            f[j] = i;  
    }
    
    for(j = 0; j<n; j++){
        cout << f[j] << " ";
    }
}

int main(){

    int n;
    cin >> n;
    
    int a[n],f[n];      //added f an array

    for(int i; i<n; i++){
        cin >> a[i];
    }

    InverseArray(a,n,f);
    

    cout << endl;
    return 0;
}


// Take as input N, a number. Take N more inputs and store that in an array. Write a recursive function which inverses the array. Print the values of inverted array

// Input Format
// Enter a number N and take N more inputs

// Constraints
// None

// Output Format
// Display the values of the inverted array in a space separated manner

// Sample Input
// 5
// 0 2 4 1 3
// Sample Output
// 0 3 1 4 2
// Explanation
// Swap element with index

// for eg : element 4 at index 2 becomes element 2 at index 4
