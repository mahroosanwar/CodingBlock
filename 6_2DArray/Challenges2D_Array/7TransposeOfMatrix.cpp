//WAP to find the transpose of matrix

#include <iostream>
using namespace std;

void Transpose(int a[][100], int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i<j){
                swap(a[i][j], a[j][i]);
            }
        }
    }

    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << " ";
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

    Transpose(a,n);

    cout << endl;
    return 0;
}



// Given a square matrix, print its transpose.

// Input Format
// First line contains the N ,size of the square matrix. Next N lines contains N integers each denoting the elements of the matrix

// Constraints
// 1 <= N <= 10^3

// Output Format
// Print N lines each containing N elements. These are the elements of the new matrix.

// Sample Input
// 5
// 1 46 4 60 100 
// 28 52 97 80 59 
// 6 33 62 42 12 
// 57 31 56 89 47 
// 1 50 73 53 99 
// Sample Output
// 1 28 6 57 1 
// 46 52 33 31 50 
// 4 97 62 56 73 
// 60 80 42 89 53 
// 100 59 12 47 99 
