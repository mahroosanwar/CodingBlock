//Search number x in matrix present or not

#include <iostream>
using namespace std;
void MatrixSearch(int a[][100], int n, int m, int Key){
    bool isNumFound = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j] == Key){
                isNumFound = true;
                cout << isNumFound;
            }
        }
    }
    if(isNumFound == false){
        cout << isNumFound;
    }
}
int main(){
    int a[100][100];
    int n,m;
    cin >> n >> m;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            cin >> a[row][col];
        }
    }
    int x;
    cin >> x;

    MatrixSearch(a,n,m,x);

    cout << endl;
    return 0;
}



// Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . Find if element x is present in the matrix or not.

// Input Format
// First line consists of two space separated integers N and M, denoting the number of element in a row and column respectively. Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major order. Third line of each test case contains a single integer x, the element to be searched.

// Constraints
// 1 <= N,M <= 30 0 <= A[i] <= 100

// Output Format
// Print 1 if the element is present in the matrix, else 0.

// Sample Input
// 3 3
// 3 30 38
// 44 52 54
// 57 60 69
// 62
// Sample Output
// 0
// Explanation
// Search the element in the sorted matrix. If the element is present print 1 otherwise print 0. In the sample input,in first case 62 is not present in the matrix so 0 is printed. Similarly, for second case 55 is present in the matrix so 1 is printed.
