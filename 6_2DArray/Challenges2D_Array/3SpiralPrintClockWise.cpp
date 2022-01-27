//Spiral print ClockWise

#include <iostream>
using namespace std;

void SpiralPrintClockWise(int a[][10], int m, int n){
    int sr =0, sc = 0, er = m-1, ec = n-1;
    while(sc<=ec && sr<=er){
        int col, row;
        for(col=sc; col<=ec; col++){
            cout << a[sr][col] << ", ";
        }
        sr++;
        for(row=sr; row<=er; row++){
            cout << a[row][ec] << ", ";
        }
        ec--;
        if(sr <=  er){
            for(col=ec; col>=sc; col--){
                cout << a[er][col] << ", ";
            }
        er--;
        }
        if(sc<= ec){
            for(row=er; row>=sr; row--){
                cout << a[row][sc] << ", ";
            }
            sc++;
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
    SpiralPrintClockWise(a,m,n);
    cout << endl;
    return 0;
}