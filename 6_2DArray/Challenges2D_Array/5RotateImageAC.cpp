//Rotate Image(2D array)Anti clock Wise

#include <iostream>
using namespace std;
void RotateImage(int a[][100], int n){
    //first swap the column
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n/2; col++){
            swap(a[row][col], a[row][n-1-col]);
        }
    }

    //then Transpose
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<j){
                swap(a[i][j], a[j][i]);
            }
        }
    }
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cout << a[row][col] << " "; 
        }
        cout << endl;
    }
}
int main(){
    int a[100][100];
    int n;
    cin >> n;

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col]; 
        }
    }

    RotateImage(a,n);

    cout << endl;
    return 0;
}



// Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.



// Input Format
// First line contains a single integer N. Next N lines contain N space separated integers.

// Constraints
// N < 1000

// Output Format
// Print N lines with N space separated integers of the rotated array.

// Sample Input
// 4
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16
// Sample Output
// 4 8 12 16 
// 3 7 11 15 
// 2 6 10 14 
// 1 5 9 13 
// Explanation
// Rotate the array 90 degrees anticlockwise.
