//WAP to Digonal traversal\

#include <iostream>
using namespace std;

void DigonalTraversal(int a[][100], int m, int n){
    int i=0, j=0;

    bool isUP = true; 

    for(int k = 0; k<m*n;){

        if(isUP){
            for( ; i>=0 && j<n; i--, j++){
                cout << a[i][j] << " ";
                k++;
            }
            if(i<0 && j<n){
                i = 0;
            }

            if(j==n){
                i = i+2;
                j--;
            }
        }

        else{
            for( ; j>=0 && i<m; j--, i++){
                cout << a[i][j] << " ";
                k++;
            }

            if(j<0 && i<m){
                j = 0;
            }

            if(i==m){
                j = j+2;
                i--;
            }
        }

        isUP = !isUP; 
    }
}

int main(){
    int a[100][100];
    int m,n;
    cin >> m >> n;

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col];
        }
    }

    DigonalTraversal(a,m,n);

    cout << endl;
    return 0;
}


// Given an array of M x N elements (M rows, N columns), return all elements of the array in diagonal order .

// Input Format
// Two integers M(row) and N(column) and Second line contains N*M space separated integers denoting the elements of Array.

// Constraints
// The total number of elements of the given array will not exceed 10,000.

// Output Format
// display Diagonal

// Sample Input
// 3 3
// 1 2 3 4 5 6 7 8 9
// Sample Output
// 1 2 4 7 5 3 6 8 9 
