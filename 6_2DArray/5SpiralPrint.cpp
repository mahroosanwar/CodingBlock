//Spilar print in array

#include <iostream>
using namespace std;

void SpiralPrint(int a[][100], int n, int m){
    int sr = 0, sc = 0, er = n-1, ec = m-1;

    while(sr<=er && sc<=ec){
        for(int col = sc; col<=ec; col++){
            cout << a[sr][col] << " ";
        }
        sr++;
        for(int row = sr; row<=er; row++){
            cout << a[row][ec] << " ";
        }
        ec--;
        if(sr<er){
            for(int col = ec; col>=sc; col--){
                cout << a[er][col] << " ";
            }
            er--;
        }
        if(sc<ec){
            for(int row = er; row>=sr; row--){
                cout << a[row][sc] << " ";
            }
            sc++;
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    int val = 1;
    int a[100][100];
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            a[row][col] = val;
            val++;
        }
    }
    
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            cout << a[row][col]<< " ";
        }
        cout << endl;
    }

    SpiralPrint(a,n,m);

    cout << endl;
    return 0;
}