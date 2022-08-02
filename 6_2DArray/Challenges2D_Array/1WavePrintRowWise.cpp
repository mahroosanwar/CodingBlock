//WAP wave print of 2D array row wise

#include <iostream>
using namespace std;

void WavePrintRowWise(int a[][10], int m, int n){
    int sr = 0, sc = 0, er = m-1, ec = n-1;
    while(sr<=er){
        if(sr%2==0){
            int col;
            for(col = sc; col<=ec; col++){
                cout << a[sr][col] << ", ";
            }
          
        sr++;
        }

        else{
            int col;
            for(col = ec; col>=sc; col--){
                cout << a[sr][col] << ", ";
            }
        sr++;
        }
    }
    cout << "END";                  
}

int main(){
    int a[10][10];
    int m,n;
    cin >> m >> n;

    for(int row=0; row<m; row++){
        for(int col=0; col<n; col++){
            cin >> a[row][col];
        }
    }

    WavePrintRowWise(a,m,n);
    
    cout << endl;
    return 0;
}


// Take as input a two-d array. Wave print it row-wise.

// Input Format
// Two integers M(row) and N(column) and further M * N integers(2-d array numbers).

// Constraints
// Both M and N are between 1 to 10.

// Output Format
// All M * N integers are seperated by commas with 'END' written in the end(as shown in example).

// Sample Input
// 4 4
// 11 12 13 14
// 21 22 23 24
// 31 32 33 34
// 41 42 43 44
// Sample Output
// 11, 12, 13, 14, 24, 23, 22, 21, 31, 32, 33, 34, 44, 43, 42, 41, END
