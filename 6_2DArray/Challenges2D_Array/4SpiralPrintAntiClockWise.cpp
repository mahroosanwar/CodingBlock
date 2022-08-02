//Spiral Print AnticlockWise

#include <iostream>
using namespace std;

void SpiralPrintAntiClockWise(int a[][10], int m, int n){
    int sr = 0, sc = 0, er = m-1, ec = n-1;

    while(sr <= er && sc <= ec){
        for(int row=sr; row<=er; row++){
            cout << a[row][sc] << ", ";
        }
        sc++;
        for(int col=sc; col<=ec; col++){
            cout << a[er][col] << ", ";
        }
        er--;
        if(sc<=ec){
            for(int row=er; row>=sr; row--){
                cout << a[row][ec] << ", ";
            }
        ec--;
        }
        if(sr<=er){
            for(int col=ec; col>=sc; col--){
                cout << a[sr][col] << ", ";
            }
        sr++;
        }
    }
    cout << "END";
}
int main(){
    int a[10][10];
    int m, n;
    cin>>m >> n;

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col];
        }
    }
    
    SpiralPrintAntiClockWise(a,m,n);
    
    cout << endl;
    return 0;
}


// Take as input a 2-d array. Print the 2-D array in spiral form anti-clockwise.

// Input Format
// Two integers M(row) and N(colomn) and further M * N integers(2-d array numbers).

// Constraints
// Both M and N are between 1 to 10.

// Output Format
// All M * N integers separated by commas with 'END' written in the end(as shown in example).

// Sample Input
// 4 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44
// Sample Output
// 11, 21, 31, 41, 42, 43, 44, 34, 24, 14, 13, 12, 22, 32, 33, 23, END
// Explanation
// For spiral level anti-clockwise traversal, Go for first column-> last row ->last column-> first row and then do the same traversal for the remaining matrix .
